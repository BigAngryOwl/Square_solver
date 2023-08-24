#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solver_head.h"
#include <windows.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

bool is_zero(const double num) {

    assert(isfinite(num));
    assert(!isnan(num));

    return (fabs(num) <= DELTA);

}

bool is_equal(const double a, const double b) {
    assert(isfinite(b));
    assert(isfinite(a));
    assert(!isnan(b));
    assert(!isnan(a));

    return (fabs(a - b) <= DELTA);
}

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


void print_roots(int const num_of_roots, const double x1, const double x2) {

    assert(isfinite(x1));
    assert(isfinite(x2));
    assert(!isnan(x1));
    assert(!isnan(x2));

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

int test_on_one_ref(const Ref_For_Test* one_ref, const int test_num){

    assert(isfinite(one_ref -> a));
    assert(isfinite(one_ref -> b));
    assert(isfinite(one_ref -> c));
    assert(isfinite(one_ref -> x1));
    assert(isfinite(one_ref -> x2));
    assert(isfinite(one_ref -> num_of_roots));
    assert(!isnan(one_ref -> a));
    assert(!isnan(one_ref -> b));
    assert(!isnan(one_ref -> c));
    assert(!isnan(one_ref -> x1));
    assert(!isnan(one_ref -> x2));
    assert(!isnan(one_ref -> num_of_roots));

    double x1 = 0, x2 = 0;

    int num_of_roots = solve(one_ref -> a, one_ref -> b, one_ref -> c, &x1, &x2);

    if (is_equal(one_ref -> x1, x1) && is_equal(one_ref -> x2, x2) && ((one_ref -> num_of_roots) == num_of_roots)) {

        return 1;

    } else {

        SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_INTENSITY);

        printf("ERROR: Test %d\n", test_num);

        SetConsoleTextAttribute(handle, (WORD)7);

        if ((one_ref -> num_of_roots) != num_of_roots) {

            printf("| num_of_roots is not equal to reference num_of_roots (num_of_roots = %d, ref num_of_roots = %d) |\n", num_of_roots, (one_ref -> num_of_roots));

        }

        if (!is_equal(one_ref -> x1, x1)) {

            printf("| x1 is not equal to reference x1 (x1 = %lg, ref x1 = %lg) |\n", x1, (one_ref -> x1));

        }

        if (!is_equal(one_ref -> x2, x2)) {

            printf("| x2 is not equal to reference x2 (x2 = %lg, ref x2 = %lg) |\n", x2, (one_ref -> x2));

        }

        printf("\n");

        return 0;

    }

}

void test_on_all_ref(const Ref_For_Test all_ref[]) {

    int good_count = 0;

    for(int i = 0; i < NUM_OF_TESTS; i++) {

        good_count += test_on_one_ref(&all_ref[i], i);

    }

    if (good_count == NUM_OF_TESTS) {

        SetConsoleTextAttribute(handle, BACKGROUND_GREEN | BACKGROUND_INTENSITY);

        printf("All good!");

        SetConsoleTextAttribute(handle, (WORD)7);

    } else {

        SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_INTENSITY);

        printf("^ Those things went wrong ^");

        SetConsoleTextAttribute(handle, (WORD)7);

    }

}
