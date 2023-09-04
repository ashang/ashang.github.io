/* strtol example */
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* strtol */

int main ()
{
  char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char * pEnd;
  long int li1, li2, li3, li4;
  li1 = strtol (szNumbers,&pEnd,10);
  li2 = strtol (pEnd,&pEnd,16);
  li3 = strtol (pEnd,&pEnd,2);
  li4 = strtol (pEnd,NULL,0);
  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
  return 0;
}


/*

<cstdlib>
strtol
long int strtol (const char* str, char** endptr, int base);
Convert string to long integer
Parses the C-string str interpreting its content as an integral number of the specified base, which is returned as a long int value. If endptr is not a null pointer, the function also sets the value of endptr to point to the first character after the number.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes as many characters as possible that are valid following a syntax that depends on the base parameter, and interprets them as a numerical value. Finally, a pointer to the first character following the integer representation in str is stored in the object pointed by endptr.

If the value of base is zero, the syntax expected is similar to that of integer constants, which is formed by a succession of:
An optional sign character (+ or -)
An optional prefix indicating octal or hexadecimal base ("0" or "0x"/"0X" respectively)
A sequence of decimal digits (if no base prefix was specified) or either octal or hexadecimal digits if a specific prefix is present

If the base value is between 2 and 36, the format expected for the integral number is a succession of any of the valid digits and/or letters needed to represent integers of the specified radix (starting from '0' and up to 'z'/'Z' for radix 36). The sequence may optionally be preceded by a sign (either + or -) and, if base is 16, an optional "0x" or "0X" prefix.

If the first sequence of non-whitespace characters in str is not a valid integral number as defined above, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

For locales other than the "C" locale, additional subject sequence forms may be accepted.

Parameters
str
C-string beginning with the representation of an integral number.
endptr
Reference to an object of type char*, whose value is set by the function to the next character in str after the numerical value.
This parameter can also be a null pointer, in which case it is not used.
base
Numerical base (radix) that determines the valid characters and their interpretation.
If this is 0, the base used is determined by the format in the sequence (see above).

Return Value
On success, the function returns the converted integral number as a long int value.
If no valid conversion could be performed, a zero value is returned (0L).
If the value read is out of the range of representable values by a long int, the function returns LONG_MAX or LONG_MIN (defined in <climits>), and errno is set to ERANGE.
*/
