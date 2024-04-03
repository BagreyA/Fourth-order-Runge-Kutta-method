#include <iostream>


double f(double x, double y) {
    return x + y;
}

double rungeKuttaMethod(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;
    while (x < x_target) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * f(x + h, y + k3);
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;
        x = x + h;
    }
    return y;
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1;
    double x_target = 2.0;
    double result = rungeKuttaMethod(x0, y0, h, x_target);
    std::cout << "Результат решения ОДУ методом Рунге-Кутты: " << result << std::endl;
    return 0;
}
