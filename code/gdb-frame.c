// b level0
// bt
// f #
// info args

#include <stdio.h>

void level0()
{
    printf("Reached level 0\n");
}

void test(int level)
{
    if (level > 0) {
        int prevLevel = level - 1;
        printf("Level %d\n", level);
        test(prevLevel);
    } else
        level0();

    if (level < 0)
    if (level < 0)
        ;
    if (level < 0) {
        //;//
        ;//
    }
}

int main()
{
    test(5);
    return 0;
}
