#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

const int SS_INF_ROOTS = -1;
const int SS_EQUAL_ROOTS = 3;
const double DELTA = 0.0000000001;

// Checks if the number is zero
bool iszero(const double& num) {

    return (fabs(num) <= DELTA);

}

// Solves linear equation bx + c = 0
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

int solve_square(const double& a, const double& b, const double& c, double& x1, double& x2) {

    double disc = b * b - 4 * a * c;

        if (iszero(disc)) {

            x1 = - b / (2 * a);
            return SS_EQUAL_ROOTS;

        } else if (disc < 0) {

            return 0;

        } else {

            x1 = (- b - sqrt(disc)) / (2 * a);
            x2 = (- b + sqrt(disc)) / (2 * a);
            return 2;

        }
}

// Determines the type of the equation (quadratic or linear) and solves it
int solve(const double& a, const double& b, const double& c, double& x1, double& x2) {

    if (iszero(a)) {

        return solve_linear(b, c, x1);

    } else {

         return solve_square(a, b, c, x1, x2);

    }
}

// Prints out the roots of the equation if there are any
void print_roots(int const num_of_roots, const double& x1, const double& x2) {

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

    case SS_EQUAL_ROOTS:
        printf("The equation has 2 equal solutions x = %lg\n", x1);
        break;

    case SS_INF_ROOTS:
        printf("This equation has infinite amount of solutions");
        break;

    }

}

int main() {

    printf("This program solves a quadratic equation\nEnter coefficients a b c:\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    double x1 = 0, x2 = 0;
    int num_of_roots = solve(a, b, c, x1, x2);

    assert(isfinite(x1));
    assert(isfinite(x2));
    assert(!isnan(x1));
    assert(!isnan(x2));

    print_roots(num_of_roots, x1, x2);

}
