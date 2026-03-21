#include <string>
#include <iostream>
#include <sstream>
#include <initializer_list>
#include <vector>
#include <utility>

namespace termfmt {

    // different styles
    enum class border_style {
        simple,
        boxed
    };

    class table {
      private:
        int cols;
        int w; // width of each column
        border_style style = border_style::simple;
        
        std::vector<std::string> header_row;
        std::vector<std::vector<std::string>> rows;

        // Dynamically print separators based on style
        void print_separator(int width) const;

        template<typename T>
        std::string to_string_any(const T& value) {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }

      public:
        table(int columns, int width) : cols(columns), w(width) {};

        void header(std::initializer_list<std::string> h) {

            header_row.assign(h.begin(), h.end());
        }

        template<typename... Args>
        void add_row(Args&&... args) {

            std::vector<std::string> v;
                
            v.reserve(sizeof...(args));
            
            (v.push_back(to_string_any(std::forward<Args>(args))), ...);

            rows.push_back(v);
        }

        void set_style(border_style s) {
            style = s;
        }

        void print() const {
            
            int width = w;
            for (const auto& cell : header_row) {
                if (cell.length() > width) {
                    width = cell.length();
                }
            }

            print_separator(width);

            // Header row
            std::cout << '|';
            for (const auto& cell : header_row) {
                std::cout << center(cell, width) << '|';
            }

            std::cout << '\n';
            print_separator(width);
            
            // Data rows
            for (const auto& row : rows) {
                std::cout << '|';
                for (const auto& cell : row) {
                    std::cout << center(cell, width) << '|';
                }
                std::cout << '\n';
            }

            print_separator(width);
        }
    };

    void table::print_separator(int width) const {
            
            switch (style)
            {
                case border_style::simple: {

                    int total_width = cols * (w + 1) + 1;
                    std::cout << line(total_width);
                    break;
                }
                case border_style::boxed: {
                    std::cout << '+';
                    
                    for (int i = 0; i < cols; i++) {
                        std::cout << std::string(width, '-') << '+';
                    }
                    
                    std::cout << '\n';
                    break;
                }
            }
        };
}