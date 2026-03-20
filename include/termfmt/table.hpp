#include <string>
#include <iostream>
#include <sstream>
#include <initializer_list>
#include <vector>
#include <utility>

namespace termfmt {

    class table {
      private:
        int cols;
        int w; // width of each column
        
        std::vector<std::string> header_row;
        std::vector<std::vector<std::string>> rows;

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

        void print() const {
            
            int width = w;
            for (const auto& cell : header_row) {
                if (cell.length() > width) {
                    width = cell.length();
                }
            }
            int total_width = cols * (width + 1) + 1;

            std::cout << line(total_width);

            // Header row
            std::cout << '|';
            for (const auto& cell : header_row) {
                std::cout << center(cell, width) << '|';
            }

            std::cout << '\n' << line(total_width);
            
            // Data rows
            for (const auto& row : rows) {
                std::cout << '|';
                for (const auto& cell : row) {
                    std::cout << center(cell, width) << '|';
                }
                std::cout << '\n';
            }

            std::cout << line(total_width);
        }
    };
    
}