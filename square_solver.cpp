#include <TXLib.h>
#include <stdio.h>
#include <math.h>
const int SS_INF_ROOTS = -1;
const double DELTA = 0.0000000001;

// Проверяет, является ли число нулём
bool iszero(const double& num) {
    if (abs(num) <= DELTA) {
        return true;
    } else {
        return false;
    }
}

// Решает линейное уравнение вида bx + c = 0
int solve_linear(const double& b, const double& c, double& x){
    if (iszero(b)) {
        if (iszero(c)) {
            return SS_INF_ROOTS;
        } else {
            return 0;
        }
    } else {
        x = - c / b;
        return 1;
    }
}

// Решает квадратное уравнение вида ax^2 + bx + c = 0
int solve_square(const double& a, const double& b, const double& c, double& x1, double& x2) {
    if (iszero(a)) {
        return solve_linear(b, c, x1);
    } else {
        double disc = b * b - 4 * a * c;

        if (iszero(disc)) {
            x1 = - b / (2 * a);
            return 3;
        } else if (disc < 0) {
            return 0;
        } else {
            x1 = (- b - sqrt(disc)) / (2 * a);
            x2 = (- b + sqrt(disc)) / (2 * a);
            return 2;
        }
    }
}

int main() {
    printf("This program solves a quadratic equation\nEnter coefficients a b c:\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;

    int num_of_roots = solve_square(a, b, c, x1, x2);

    switch(num_of_roots) {
    case 0:
        printf("No real solutions\n");
        break;
    case 1:
        printf("The only solution is x = %lg\n", x1);
        break;
    case 2:
        printf("The solutions are x1 = %lg and x2 = %lg", x1, x2);
        break;
    case 3:
        printf("The equation has 2 equal solutions x = %lg\n", x1);
        break;
    case SS_INF_ROOTS:
        printf("This equation has infinite amount of solutions");
        break;
    default:
        printf("ERROR in main() of square_solver()");
    }
}
