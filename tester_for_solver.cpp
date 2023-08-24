///
/// \file
/// \brief Unit tests for solve() function
/// \author Daniil Zelenov
/// \version 1.0
/// \date 24.08.2023
///
/// This program uses an array of references to test the solve() function
///

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solver_head.h"
#include "solver_functions.cpp"

int main() {

    printf("Testing the quadratic solver\n");

    Ref_For_Test all_test_ref[NUM_OF_TESTS] = {{.a=0, .b=0, .c=0, .x1=0, .x2=0, .num_of_roots=SS_INF_ROOTS},    //1
                                               {.a=1, .b=0, .c=0, .x1=0, .x2=0, .num_of_roots=SS_EQUAL_ROOTS},  //2
                                               {.a=0, .b=1, .c=0, .x1=0, .x2=0, .num_of_roots=1},               //3
                                               {.a=1, .b=1, .c=0, .x1=-1, .x2=0, .num_of_roots=2},              //4
                                               {.a=1, .b=2, .c=1, .x1=-1, .x2=0, .num_of_roots=SS_EQUAL_ROOTS}, //5
                                               {.a=1, .b=2, .c=-3, .x1=-3, .x2=1, .num_of_roots=2},             //6
                                               {.a=1, .b=0, .c=-4, .x1=-2, .x2=2, .num_of_roots=2},             //7
                                               {.a=2, .b=6, .c=9, .x1=0, .x2=0, .num_of_roots=0},               //8
                                               {.a=0, .b=0, .c=1, .x1=0, .x2=0, .num_of_roots=0},               //9
                                               {.a=0, .b=1, .c=2, .x1=-2, .x2=0, .num_of_roots=1},              //10
                                               {.a=1, .b=7, .c=12, .x1=-4, .x2=-3, .num_of_roots=2},            //11
                                               {.a=4, .b=20, .c=-56, .x1=-7, .x2=2, .num_of_roots=2},           //12
                                               {.a=13, .b=11, .c=-5, .x1=-1.1738162, .x2=0.3276624, .num_of_roots=2}, //13
                                               {.a=13, .b=11, .c=7, .x1=0, .x2=0, .num_of_roots=0},                   //14
                                               {.a=13, .b=11, .c=1, .x1=-0.7425625, .x2=-0.1035914, .num_of_roots=2}, //15
                                               {.a=9, .b=12, .c=4, .x1=-0.6666666666666, .x2=0, .num_of_roots=SS_EQUAL_ROOTS}, //16
                                               {.a=9, .b=12, .c=3, .x1=-1, .x2=-0.33333333333, .num_of_roots=2},               //17
                                               {.a=9, .b=122, .c=13, .x1=-13.4481471, .x2=-0.1074084, .num_of_roots=2},        //18
                                               {.a=0, .b=122, .c=-13, .x1=0.10655737, .x2=0, .num_of_roots=1},                 //19
                                               {.a=1, .b=12222, .c=-513, .x1=-12222.0419733, .x2=0.0419733, .num_of_roots=2},  //20
                                               {.a=3, .b=1234567890, .c=-9876543, .x1=-411522630.007999999, .x2=0.00799999, .num_of_roots=2}}; //21

    test_on_all_ref(all_test_ref);

}
