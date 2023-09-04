#include <stdio.h>
#include <locale.h>
#include <libintl.h>

#define _(String) gettext (String)

int main () {

    char *my_name="Aaron";
//printf(gettext("My name is %s.\n"), my_name);


  setlocale (LC_MESSAGES, "fr");


///gettext string
    printf(_("My name is %s.\n"), my_name);

    return(0);
}
