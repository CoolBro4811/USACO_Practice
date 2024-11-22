#include <cstdio>
#include <cstdint>
#include <vector>

std::vector<int64_t> getOutput();

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int64_t add, mult;
        std::vector<int64_t> output = getOutput();
        add = output[0];
        mult = output[1];
        printf("%ld %ld%s", add, mult, "\n");
    }
}

std::vector<int64_t> getOutput() {
    int64_t x, y;
    scanf("%ld %ld", &x, &y);
    std::vector<int64_t> temp(2);
    temp[0] = x+y;
    temp[1] = x*y;
    return temp;
}