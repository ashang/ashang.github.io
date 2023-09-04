#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
    /* Locale is set to "C" before this. This call sets it
       to the "current locale" by reading environment variables: */
    setlocale(LC_ALL, "");

    const struct lconv * const currentlocale = localeconv();

    printf("In the current locale, the default currency symbol is: %s\n",
        currentlocale->currency_symbol);

    return EXIT_SUCCESS;
}
