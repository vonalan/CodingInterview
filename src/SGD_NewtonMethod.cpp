#include <iostream>
#include <cmath>

double func(double x){
    // f(x) = x^4 - 4 * x^3 + x^2 + 10;
    double x2 = x * x;
    double x3 = x2 * x, x4 = x2 * x2;

    return x4 - 4 * x3 + x2 + 10.0;
}

double D1(double x){
    // f^1(x) = 4 * x^3 - 12 * x^2 + 2 * x;
    double x2 = x * x;
    double x3 = x2 * x;

    return 4 * x3 - 12 * x2 + 2 * x;
}

double D2(double x){
    // f^2(x) = 12 * x^2 - 24 * x + 2;
    double x2 = x * x;

    return 12 * x2 - 24 * x + 2.0;
}

void SGD(){
    std::cout << "SGD" << std::endl;

    double learning_rate = 0.01;

    double x = 2.0;

    while(1){
        double f_x = func(x);
        double g_x = D1(x);
        std::cout << "x: " << x << " " << "func: " << f_x << std::endl;
        if(std::abs(g_x) <= 1e-6) break;

        x = x - learning_rate * g_x;
    }
}

void NewtonMethod(){
    std::cout << "Newton Method" << std::endl;

    double x = 2.0;

    while(1){
        double f_x = func(x);
        double g_x = D1(x);
        double h_x = D2(x);
        std::cout << "x: " << x << " " << "func: " << f_x << std::endl;
        if(std::abs(g_x) <= 1e-6 || std::abs(h_x) <= 1e-6) break;

        x = x - g_x / h_x;
    }
}

int main(int argc, char **argv){
    SGD();
    NewtonMethod();
    return 0;
}
