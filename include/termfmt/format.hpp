#include <sstream>
#include <ostream>
#include <string>

namespace termfmt {

    namespace detail {

        // Center helper
        struct center_t {
            std::string str;
            int width;
            char fill;
    
            center_t(std::string s, int w, char f = ' ') : str(s), width(w), fill(f) {};
        };
        
        // Line helper
        struct line_t {
            int width;
            char fill;
    
            line_t(int w, char f = '-') : width(w), fill(f) {};
        };
        
        std::ostream& operator<<(std::ostream& os, const center_t& c) {
    
            const std::string& str = c.str;
            int width = c.width;
            char fill = c.fill;
    
            // Print normally if there's no width
            if (width <= 0) {
                return os << str;
            }
    
            // Calculate padding
            int len = str.length();
            int pad = width - len;
    
            // Return and print normally if length exceeds width
            if (pad <= 0) {
                return os << str;
            }
    
            // Calculate left and right padding
            int left = pad / 2;
            int right = pad - left;
    
    
            // Print centered text
            return os << std::string(left, fill)
                      << str
                      << std::string(right, fill);
        };

        std::ostream& operator<<(std::ostream& os, const line_t& l) {
    
            if (l.width <= 0) {
                return os;
            }
    
            return os << std::string(l.width, l.fill) << '\n';
        };
    }

    template<typename T>
    inline detail::center_t center(const T& value, int width, char fill = ' ') {
        std::ostringstream oss;
        oss << value;

        return detail::center_t(oss.str(), width, fill);
    }

    inline detail::line_t line(int width, char fill = '-') {
        return detail::line_t(width, fill);
    }
}
