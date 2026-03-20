#include <ostream>
#include <string>

namespace termfmt {

    struct center_t {
        std::string str;
        int width;
        char fill;

        center_t(std::string s, int w, char f = ' ') : str(s), width(w), fill(f) {};
    };

    center_t center(std::string str, int width, char fill = ' ') {
        return center_t(str, width, fill);
    }

    std::ostream& operator<<(std::ostream& os, const center_t& c) {

        std::string str = c.str;
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
}
