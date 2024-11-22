#include <iostream>
#include <cstdint>
#include <cstdio>


int main() {
    u_int64_t x, y, count;
    scanf("%lu", &count);
    while (count >= 0) {
        count--;
        u_int64_t temp = x+y;
        x = y;
        y = temp;
        printf("%lu", &temp);
    }
}