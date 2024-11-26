#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>
#include <cstdio>

std::vector<std::vector<int32_t>> getMaze();

int main() {
    std::vector<std::vector<int32_t>> maze(getMaze());
    
    for (std::vector<int32_t> i : maze) {
        for (int32_t x : i) {
            std::cout << std::to_string(x) + "\n";
        }
        std::cout << "\n";
    }

    return 0;
}

std::vector<std::vector<int32_t>> getMaze() {
    std::vector<std::vector<int32_t>> maze;
    int n;
    std::cin >> n;
    std::cout << n;

    u_int64_t x;

    int tempIndex = n-1;

    for (int i = 0; i < n; i++) {
        tempIndex = n;
        std::cin >> x;
        std::cout << x;
        while (tempIndex != 0) {
            maze[i][tempIndex] = x % 10;
            x = x / 10;
            std::cout << x;
            tempIndex --;
        }
    }
    return maze;
}