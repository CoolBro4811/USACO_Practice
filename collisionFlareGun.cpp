// v1,m1,v2,m2

#include <iostream>
#include <cstring>
#include <vector>

double get_finalV_inelastic(double m_1, double m_2, double v_1, double v_2);

int main() {
    std::cout << "test";
    double m_1; 
    double m_2;
    double v_1;
    double v_2;
    std::cout << "test";
    
    std::string input;
    std::getline(std::cin, input);
    std::cout << "test";
    std::vector<std::string> test;

    // m_1, m_2, v_1, v_2; 
    int i = 0;
    while (input.find(",") != -1) {
        std::cout << input.substr(0, input.find(","));
        test[i] = input.substr(0, input.find(","));
        input = input.substr(input.find(",")+1, input.length());
        i++;
    }

    m_1 = std::stod(test[0]);
    v_1 = std::stod(test[1]);
    m_2 = std::stod(test[2]);
    v_2 = std::stod(test[3]);

    for (int i = 0; i < test.size(); i++) {
        std::cout << test[i];
    }

    std::cout << get_finalV_inelastic(m_1, m_2, v_1, v_2);

    return 0;
}

double get_finalV_inelastic(double m_1, double m_2, double v_1, double v_2) {
    return (m_1*v_1 + m_2*v_2)/(m_1 + m_2);
}