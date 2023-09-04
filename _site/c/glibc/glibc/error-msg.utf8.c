#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *
open_sesame (char *name)
{
  FILE *stream;

  errno = 0;
  stream = fopen (name, "r");
  if (stream == NULL)
    {
      fprintf (stderr, "%s: Couldn't open file %s; %s\n",
               program_invocation_short_name, name, strerror (errno));
      exit (EXIT_FAILURE);
    }
  else
    return stream;
}

int main () {
  open_sesame ("name");
}
// {
//   char *line = NULL;
//   size_t len = 0;
//   unsigned int lineno = 0;
// 
//   error_message_count = 0;
//   while (! feof_unlocked (fp))
//     {
//       ssize_t n = getline (&line, &len, fp);
//       if (n <= 0)
//         /* End of file or error.  */
//         break;
//       ++lineno;
// 
//       /* Process the line.  */
//       鈥