//#include <stdio.h>
#include <complex.h>
#ifndef QUAD
#define QUAD
#include "quadratic.h"
#endif

// Real coefficients

double complex rdelta(double*  coefs)
{
    double complex delta;
    double a0, a1, a2;
    a0 = coefs[0];
    a1 = coefs[1];
    a2 = coefs[2];
    delta = a1*a1 - 4*(a2*a0);
    return csqrt(delta);
}

enum solution rsolutions(double* coefs, double* sol)
{
    double complex del;
    del = rdelta(coefs);

    double a1, a2;
    a1 = coefs[1];
    a2 = coefs[2];

    if (del == 0){   // double root
        sol[0] = -a1 / 2*a2;
        return one;
    }
    else if (cimag(del) == 0){      // ie del is real
        sol[0] = (-a1 + del) / (2*a2);
        sol[1] = (-a1 - del) / (2*a2);
        return real;
    }
    else {      // del is pure imaginary
        sol[0] = -a1 / (2*a2);  // real part
        sol[1] = cimag(del) / (2*a2);  // absolute of imaginary part
        return comp;
    }
}

// Complex coefficients

double complex cdelta(double complex* coefs)
{
    double complex delta;
    double complex a0, a1, a2;
    a0 = coefs[0];
    a1 = coefs[1];
    a2 = coefs[2];
    delta = a1*a1 - 4*(a2*a0);
    return csqrt(delta);
}

void csolutions(double complex* coefs,
        double complex* sol)
{ 
    double complex del;
    del = cdelta(coefs);

    double complex a1, a2;
    a1 = coefs[1];
    a2 = coefs[2]; 

    sol[0] = (-a1 + del) / (2*a2);
    sol[1] = (-a1 - del) / (2*a2);
}

/*void cdisp(double complex z)
{
    printf("%f + %fi\n", creal(z), cimag(z));
}

int main(int argc, char** argv)
{
    double coeff[3];
    coeff[0] = 1;
    coeff[1] = 1;
    coeff[2] = 1;

    double sol[2];
    enum solution type;
    type = rsolutions(coeff, sol);
    switch (type) {
    case one:
        printf("Double solution: %f\n", sol[0]);
        break;
    case real:
        printf("First: %f\n", sol[0]);
        printf("Second: %f\n", sol[1]);
        break;
    case comp:
        printf("Real: %f\n", sol[0]);
        printf("Complex: %f\n", sol[1]);
        break;
    }
    cdisp(sol[0]);
    cdisp(sol[1]);
    return 0;
}*/ 
