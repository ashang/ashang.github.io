#include <stdio.h>
#include <stdlib.h>


int
main (int argc, char **argv)
{
  int a=1,b=1;
  printf("After month %s \n", argv[1]);


  // 检测溢出
// 有输入，则用
// 无输入，求输入，未输入，回车，则20个月
// 结果入数组，最后fmtc输出
//go版本

  for (int i = 0; i < atoi(argv[1]); i++)
    {
      printf("%d %d ", a, b);
      a+=b;
      b+=a;
    }
  printf("\n");
  return 0;
}


// https://www.google.com/search?client=firefox-b-d&q=c+convert+string+to+integer
