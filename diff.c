#include <stdio.h>
#include <string.h>
#include <complex.h>

#ifndef QUAD
#define QUAD
#include "quadratic.h"
#endif

// Defining strings used
const char* all_solutions = "General solution (with A and B real numbers):\n";
const char* default_mode = "No arguments, entering default mode\n";



void second_order_differential(double* coefs)
{
    double solutions[2];
    enum solution type;

    double quad_coeff[3] = {1, coefs[0], coefs[1]};
    type = rsolutions(quad_coeff, solutions);
    switch (type){
    case one:
        printf("%s(At + b)*exp(%.3f *t)\n\n",
                all_solutions,
                solutions[0]);
        break;
    case real:
        printf("%sA*exp(%.3f *t) + B*exp(%.3f *t)\n\n",
                all_solutions,
                solutions[0], solutions[1]);
        break;
    case comp:
        printf("%sexp(%.3f *t) * (A*cos(%.3f * t) + B*sin(%.3f*t)\n\n",
                all_solutions,
                solutions[0], solutions[1], solutions[1]);
        break;
    }
}

int main(int argc, char** argv)
{
    if (argc == 1){
        printf("%s", default_mode);
        double coeff_one[] = {2,1};
        double coeff_real[] = {3,1};
        double coeff_comp[] = {1,1};
        second_order_differential(coeff_one);
        second_order_differential(coeff_real);
        second_order_differential(coeff_comp); 
    }
    else{
        printf("Huzzah! something that's not done yet!");
    }
    return 0;
}
