///
/// \file
/// \brief Solves equations (quadratic or linear)
/// \author Daniil Zelenov
/// \version 1.4
/// \date 24.08.2023
///
/// This program takes 3 input values (type double) that represent coefficients of quadratic equation (ax^2 + bx + c = 0) and solves it
///

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solver_head.h"
#include "solver_functions.cpp"

int main() {

    printf("This program solves a quadratic equation\nEnter coefficients a b c:\n");

    double a = 0, b = 0, c = 0;
    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int num_of_roots = solve(a, b, c, &x1, &x2);

    print_roots(num_of_roots, x1, x2);

}
