#include <cmath>
#include <vector>
#include <algorithm>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

extern "C" {
    __declspec(dllexport) double my_calculate(const char* expression);
    __declspec(dllexport) double my_sqrt(double x);
    __declspec(dllexport) double my_pi();
    __declspec(dllexport) double my_cosTheta(double angle);
    __declspec(dllexport) double my_sinTheta(double angle);
    __declspec(dllexport) double my_tanTheta(double angle);
    __declspec(dllexport) double my_cosh(double x);
    __declspec(dllexport) double my_sinh(double x);
    __declspec(dllexport) double my_tanh(double x);
    __declspec(dllexport) double my_cubeRoot(double x);
    __declspec(dllexport) double my_exp(double x);
    __declspec(dllexport) double my_power(double base, double exponent);
    __declspec(dllexport) double my_factorial(int n);
    __declspec(dllexport) double my_ln(double x);
    __declspec(dllexport) double my_log10(double x);
    __declspec(dllexport) double my_degrees(double radians);
    __declspec(dllexport) double my_radians(double degrees);
    __declspec(dllexport) double my_mean(const double* numbers, int size);
    __declspec(dllexport) double my_median(const double* numbers, int size);
    __declspec(dllexport) double my_stddev(const double* numbers, int size);
}

double my_calculate(const char* expression) {
    // Simplified parser and evaluator for mathematical expressions
    return std::atof(expression); // For illustration only
}

double my_sqrt(double x) {
    return std::sqrt(x);
}

double my_pi() {
    return M_PI;
}

double my_cosTheta(double angle) {
    return std::cos(angle * M_PI / 180.0);
}

double my_sinTheta(double angle) {
    return std::sin(angle * M_PI / 180.0);
}

double my_tanTheta(double angle) {
    return std::tan(angle * M_PI / 180.0);
}

double my_cosh(double x) {
    return std::cosh(x);
}

double my_sinh(double x) {
    return std::sinh(x);
}

double my_tanh(double x) {
    return std::tanh(x);
}

double my_cubeRoot(double x) {
    return std::cbrt(x);
}

double my_exp(double x) {
    return std::exp(x);
}

double my_power(double base, double exponent) {
    return std::pow(base, exponent);
}

double my_factorial(int n) {
    if (n < 0) return 0; // Factorial is not defined for negative numbers
    if (n <= 1) return 1; // Base case
    return n * my_factorial(n - 1); // Recursive case
}

double my_ln(double x) {
    return std::log(x);
}

double my_log10(double x) {
    return std::log10(x);
}

double my_degrees(double radians) {
    return radians * 180.0 / M_PI;
}

double my_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

double my_mean(const double* numbers, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum / size;
}

double my_median(const double* numbers, int size) {
    std::vector<double> sorted(numbers, numbers + size);
    std::sort(sorted.begin(), sorted.end());
    if (size % 2 == 0) {
        return (sorted[size / 2 - 1] + sorted[size / 2]) / 2;
    }
    return sorted[size / 2];
}

double my_stddev(const double* numbers, int size) {
    double mean_value = my_mean(numbers, size);
    double sum_squared_diff = 0;
    for (int i = 0; i < size; ++i) {
        sum_squared_diff += std::pow(numbers[i] - mean_value, 2);
    }
    return std::sqrt(sum_squared_diff / size);
}
