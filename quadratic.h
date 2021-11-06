// Complex coefficients

/* Computes the complex number del such that del^2 = delta
 * For the equation a0 + a1*x + a2*x^2 = 0
 * coefs - list of coefficents in order [a0, a1, a2]
 * return - del the "square root" of delta
 */
double complex cdelta(double complex* coefs);

/* Computes the solutions of a quadratic equation - complex coefficients
 * For the equation a0 + a1*x + a2*x^2 = 0
 * coefs - list of coefficents in order [a0, a1, a2]
 * sol - an array of at least 2 complex numbers, to store the solutions
 */
void csolutions(double complex* coefs, double complex* sol);


// Real coefficients

/* Same as rdelta but with real coefficents instead
 * coefs - list of coefficients in order [a0, a1, a2]
 * return - del, "square root" of delta
 */
double complex rdelta(double* coefs);

/* Computes the solutions of a quadratic equation - real coefficients
 * It modifies the value of the array sol in this way:
 *   - one solution -> stored in the first part of the array
 *   - 2 real solutions -> stored positive delta, then negative
 *   - complex solutions -> stored real part, then imaginary part
 * Then it returns an int value based on the situation (see solution).
 * coefs - list of coefficients in order [a0, a1, a2]
 * sol - an array of at least 2 double, to store the solutions
 * return - an int with the situation
 */
enum solution rsolutions(double* coefs, double* sol);

enum solution{one, real, comp};
