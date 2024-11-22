#include <iostream>
#include <cstdio>

std::string getOutput();

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        printf("%s", (getOutput() + "\n").c_str());
    }
    return 0;
}

std::string getOutput() {
    double v, x;
    scanf("%lf:%lf", &v, &x);

    double time = x/v;

    if (time <= 1) {
        return "SWERVE";
    }
    else if (time <= 5) {
        return "BRAKE";
    }
    else {
        return "SAFE";
    }
}