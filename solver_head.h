#ifndef SOLVER_HEAD
#define SOLVER_HEAD

#define SS_INF_ROOTS -1
#define SS_EQUAL_ROOTS 3
#define DELTA 0.000001
#define NUM_OF_TESTS 21

struct Ref_For_Test {
    double a, b, c;
    double x1, x2;
    int num_of_roots;
};

///
/// \brief Check if the number is zero
/// \param num Input number
/// \return Return true if the number equals to zero and false if the number does not equal to zero
///
bool is_zero(const double num);

///
/// \brief Check if two double numbers are equal
///
/// \param a, b
/// \return Return true if two numbers are equal and false if not
///
bool is_equal(const double a, const double b);

///
/// \brief Solve linear equation bx + c = 0
///
/// Take in 2 coefficients of the equation and a pointer to the variable, where the answer will be stored, and solve the equation
/// \param b, c Coefficients of the equation
/// \param x Pointer to the variable, where the answer is stored
/// \return Return the amount of roots or SS_INF_ROOTS if there are infinite amount of roots
///
int solve_linear(const double b, const double c, double* x);

///
/// \brief Solves quadratic equation ax^2 + bx + c = 0
/// Takes in 3 coefficients of the equation and 2 pointers to the variables, where the answers will be stored, and solves the equation
/// \param a, b, c Coefficients of the equation
/// \param x1, x2 Pointers to the variables, where the answer is stored
/// \return Returns the amount of roots or SS_EQUAL_ROOTS if the roots are equal
///
int solve_square(const double a, const double b, const double c, double* x1, double* x2);

///
/// \brief Determines the type of the equation (quadratic or linear) and solves it
/// Takes in 3 coefficients of the equation and 2 pointers to the variables, where the answer will be stored, determines the type of equation and solves it using solve_linear and solve_square functions
/// \param a, b, c Coefficients of the equation
/// \param x1, x2 Pointers to the variables, where the answer is stored
/// \return Returns the number of roots, SS_INF_ROOTS if there are infinite amount of roots and SS_EQUAL_ROOTS if the roots are equal
///
int solve(const double a, const double b, const double c, double* x1, double* x2);

///
/// \brief Print out the roots
/// Take in the amount of roots, the roots and print out the corresponding answer:
/// - no real solutions
/// - 1 solution and its value
/// - 2 solutions but they're equal and their value
/// - 2 different solutions and their value
/// - infinite amount of solutions
/// \param num_of_roots Amount of roots
/// \param x1, x2 The roots
///
void print_roots(int const num_of_roots, const double x1, const double x2);

///
/// \brief Test solve() function using one reference
///
/// Take in a reference for the solve() function and test if the result of the solve() function matches the reference
/// If something went wrong, print out the number of test at which the error occured and which varuables did not match
/// \param one_ref Reference for the solve() function
/// \param test_num Number of test
/// \return 1 if everithing went good and 0 if something did not match
int test_on_one_ref(const Ref_For_Test* one_ref, const int test_num);

///
/// \brief Test solve() function using an array of references
///
/// Take in an arrray of references for the solve() function and test it using test_on_one_ref() function
/// If everything is good, print out "All good!"
/// If something went wrong, print out the number of test at which the error occured and which varuables did not match
/// \param all_ref[] An array of Ref_For_Test structures
void test_on_all_ref(const Ref_For_Test all_ref[]);

#endif
