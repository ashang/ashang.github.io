#include <stdio.h>

#include <math.h>

#include <float.h>

#include <fenv.h>

#include <tgmath.h>

#include <stdbool.h>

#include <assert.h>


double compute_fn(double z)  // [1]

{

        #pragma STDC FENV_ACCESS ON  // [2]


        assert(FLT_EVAL_METHOD == 2);  // [3]


        if (isnan(z))  // [4]

                puts("z is not a number");


        if (isinf(z))

                puts("z is infinite");


        long double r = 7.0 - 3.0/(z - 2.0 - 1.0/(z - 7.0 + 10.0/(z - 2.0 - 2.0/(z - 3.0)))); // [5, 6]


        feclearexcept(FE_DIVBYZERO);  // [7]


        bool raised = fetestexcept(FE_OVERFLOW);  // [8]


        if (raised)

                puts("Unanticipated overflow.");


        return r;

}


int main(void)

{

        #ifndef __STDC_IEC_559__

        puts("Warning: __STDC_IEC_559__ not defined. IEEE 754 floating point not fully supported."); // [9]

        #endif


        #pragma STDC FENV_ACCESS ON


        #ifdef TEST_NUMERIC_STABILITY_UP

        fesetround(FE_UPWARD);                   // [10]

        #elif TEST_NUMERIC_STABILITY_DOWN

        fesetround(FE_DOWNWARD);

        #endif


        printf("%.7g\n", compute_fn(3.0));

        printf("%.7g\n", compute_fn(NAN));


        return 0;

}


/*
https://en.wikipedia.org/wiki/C99

    Compile with: gcc -std=c99 -mfpmath=387 test_c99_fp.c -lm
    As the IEEE 754 status flags are manipulated in this function, this #pragma is needed to avoid the compiler incorrectly rearranging such tests when optimising.
    C99 defines a limited number of expression evaluation methods: the current compilation mode can be checked to ensure it meets the assumptions the code was written under.
    The special values such as NaN and positive or negative infinity can be tested and set.
    long double is defined as IEEE 754 double extended or quad precision if available. Using higher precision than required for intermediate computations can minimize round-off error[11] (the typedef double_t can be used for code that is portable under all FLT_EVAL_METHODs).
    The main function to be evaluated. Although it appears that some arguments to this continued fraction, e.g., 3.0, would lead to a divide-by-zero error, in fact the function is well-defined at 3.0 and division by 0 will simply return a +infinity that will then correctly lead to a finite result: IEEE 754 is defined not to trap on such exceptions by default and is designed so that they can very often be ignored, as in this case. (If FLT_EVAL_METHOD is defined as 2 then all internal computations including constants will be performed in long double precision; if FLT_EVAL_METHOD is defined as 0 then additional care is need to ensure this, including possibly additional casts and explicit specification of constants as long double.)
    As the raised divide-by-zero flag is not an error in this case, it can simply be dismissed to clear the flag for use by later code.
    In some cases, other exceptions may be regarded as an error, such as overflow (although it can in fact be shown that this cannot occur in this case).
    __STDC_IEC_559__ is to be defined only if "Annex F IEC 60559 floating-point arithmetic" is fully implemented by the compiler and the C library (users should be aware that this macro is sometimes defined while it shouldn't be).
    The default rounding mode is round to nearest (with the even rounding rule in the halfway cases) for IEEE 754, but explicitly setting the rounding mode toward + and - infinity (by defining TEST_NUMERIC_STABILITY_UP etc. in this example, when debugging) can be used to diagnose numerical instability.[12] This method can be used even if compute_fn() is part of a separately compiled binary library. But depending on the function, numerical instabilities cannot always be detected.
*/
