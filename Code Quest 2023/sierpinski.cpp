#include <iostream>
#include <cstdint>
#include <cmath>

int main() {
    u_long width;
    long iterations;

    std::cin >> width;
    std::cin >> iterations;

    std::cout << std::to_string(width * width * std::sqrt(3.0) / 4.0 * std::pow(3.0/4.0, iterations)) + "\n";

    std::cout << std::pow(std::pow(2, -1*iterations) * width, 2) * std::sqrt(3) / 4 * std::pow(3, iterations);
}