 ///
 /// \file
 /// \brief Solves equations (quadratic or linear)
 /// \author Daniil Zelenov
 /// \version 1.3
 /// \date 22.08.2023
 ///
 /// This program takes 3 input values (type double) that represent coefficients of quadratic equation (ax^2 + bx + c = 0) and solves it
 ///

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

const int SS_INF_ROOTS = -1;
const int SS_EQUAL_ROOTS = 3;
const double DELTA = 0.0000000001;

///
/// \brief Checks if the number is zero
/// \param num Input number
/// \return Returns true if the number equals to zero and false if the number does not equal to zero
///
bool is_zero(const double num) {

    assert(isfinite(num));
    assert(!isnan(num));

    return (fabs(num) <= DELTA);

}

///
/// \brief Solves linear equation bx + c = 0
///
/// Takes in 2 coefficients of the equation and a pointer to the variable, where the answer will be stored, and solves the equation
/// \param b, c Coefficients of the equation
/// \param x Pointer to the variable, where the answer is stored
/// \return Returns the amount of roots or SS_INF_ROOTS if there are infinite amount of roots
///
int solve_linear(const double b, const double c, double* x){

    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(b));
    assert(!isnan(c));

    if (is_zero(b)) {

        if (is_zero(c)) {

            return SS_INF_ROOTS;

        } else {

            return 0;

        }
    } else {

        *x = - c / b;
        return 1;

    }
}

///
/// \brief Solves quadratic equation ax^2 + bx + c = 0
/// Takes in 3 coefficients of the equation and 2 pointers to the variables, where the answers will be stored, and solves the equation
/// \param a, b, c Coefficients of the equation
/// \param x1, x2 Pointers to the variables, where the answer is stored
/// \return Returns the amount of roots or SS_EQUAL_ROOTS if the roots are equal
///
int solve_square(const double a, const double b, const double c, double* x1, double* x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    double disc = b * b - 4 * a * c;

    if (is_zero(disc)) {

        *x1 = - b / (2 * a);
        return SS_EQUAL_ROOTS;

    } else if (disc < 0) {

        return 0;

    } else {

        *x1 = (- b - sqrt(disc)) / (2 * a);
        *x2 = (- b + sqrt(disc)) / (2 * a);
        return 2;

    }
}

///
/// \brief Determines the type of the equation (quadratic or linear) and solves it
/// Takes in 3 coefficients of the equation and 2 pointers to the variables, where the answer will be stored, determines the type of equation and solves it using solve_linear and solve_square functions
/// \param a, b, c Coefficients of the equation
/// \param x1, x2 Pointers to the variables, where the answer is stored
/// \return Returns the number of roots, SS_INF_ROOTS if there are infinite amount of roots and SS_EQUAL_ROOTS if the roots are equal
///
int solve(const double a, const double b, const double c, double* x1, double* x2) {

    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    if (is_zero(a)) {

        return solve_linear(b, c, x1);

    } else {

         return solve_square(a, b, c, x1, x2);

    }
}

///
/// \brief Prints out the roots
/// Takes in the amount of roots, the roots and prints out the corresponding answer:
/// - no real solutions
/// - 1 solution and its value
/// - 2 solutions but they're equal and their value
/// - 2 different solutions and their value
/// - infinite amount of solutions
/// \param num_of_roots Amount of roots
/// \param x1, x2 The roots
///
void print_roots(int const num_of_roots, const double x1, const double x2) {

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

    double x1 = 0, x2 = 0;
    int num_of_roots = solve(a, b, c, &x1, &x2);

    print_roots(num_of_roots, x1, x2);

}
