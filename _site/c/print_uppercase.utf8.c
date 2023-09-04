#include <glib.h>

void print_uppercase_words(const gchar *string)
{
  /* Print all uppercase-only words. */

  GRegex *regex;
  GMatchInfo *match_info;

  regex = g_regex_new("[A-Z]+", 0, 0, NULL);
  g_regex_match(regex, string, 0, &match_info);

  while (g_match_info_matches(match_info))
    {
      gchar *word = g_match_info_fetch(match_info, 0);
      g_print("Found %s\n", word);
      g_free(word);
      g_match_info_next(match_info, NULL);
    }

  g_match_info_free(match_info);
  g_regex_unref(regex);
}

int main()
{
  gchar *string = "My body is a cage.  My mind is THE key.";

  print_uppercase_words(string);
}
