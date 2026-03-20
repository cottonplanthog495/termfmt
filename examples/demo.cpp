#include <iostream>
#include <termfmt.hpp>
using namespace std;

int main() {
    using termfmt::center;

    cout << center("Hello World", 50) << '\n';
    cout << center("termfmt v1.0", 50, '-') << '\n';
}