int main (int argc, char **argv)
{
    char a1[] = "abc";
    char a2[] = "abc";
    const char b1[] = "abc";
    const char b2[] = "abc";
    const char *c1 = "abc";
    const char *c2 = "abc";
    cout << (a1 == a2) << "\n";
    cout << (b1 == b2) << "\n";
    cout << (c1 == c2) << "\n";
}

