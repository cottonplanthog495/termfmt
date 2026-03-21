#include <iostream>
#include <termfmt.hpp>

int main() {
    using termfmt::center;
    using termfmt::line;
    using termfmt::table;
    using termfmt::border_style;

    // ===== Section: Basic Formatting =====
    std::cout << "\n";
    std::cout << center(" termfmt v1.2 ", 85, '=') << '\n';
    std::cout << center("Composable Terminal Formatting for C++", 85) << '\n';
    std::cout << line(85) << '\n';

    // ===== Section: Centering Various Types =====
    std::cout << "\n";
    std::cout << center(" Centering Examples ", 85, '-') << '\n';

    std::cout << center("Hello, World!", 85) << '\n';
    std::cout << center(12345, 85) << '\n';
    std::cout << center(3.14159, 85) << '\n';
    std::cout << center('A', 85) << '\n';

    // ===== Section: Custom Fill Characters =====
    std::cout << "\n";
    std::cout << center(" Custom Fill Characters ", 85, '-') << '\n';

    std::cout << center(" Section Divider ", 85, '=') << '\n';
    std::cout << center(" Warning ", 85, '!') << '\n';
    std::cout << center(" Highlight ", 85, '*') << '\n';

    // ===== Section: Table Rendering =====
    std::cout << "\n";
    std::cout << center(" Table Example ", 85, '-') << '\n';

    table t(4, 20);

    t.header({"ID", "Name", "Department", "Performance"});

    t.add_row("#001", "John Smith", "Management", 900);
    t.add_row("#002", "Alice Raje Johnson", "Human Resource", 850);
    t.add_row("#003", "Ethane H", "Finance", 920);
    t.add_row("#004", "Sidhit Singh", "Transport", 880);

    // Use different styles from here
    // t.set_style(border_style::simple);
    // t.set_style(border_style::boxed)

    t.print();
    std::cout << '\n';
    std::cout << center(" More Features Coming Soon! ", 85, '-') << '\n';
    std::cout << '\n';

    return 0;
}
