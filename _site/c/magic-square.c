/*************************************************************************
  > File Name: ../codesnip/c/magic-square.c
  */


#include<stdio.h>
int a[17],b[17],m;
void s(int i)
{  /*搜索全部四階幻方，C代碼,運行時間7秒*/
    int n=0,j=0;
    while(++j<17)
        if(!a[j])
        {
            a[b[i]=j]=1;
            switch(i)
            {
                case 1:case 2:case 3:case 5:case 6:case 7:case 9:case 10:s(i+1);break;
                case 11:if(b[6]+b[7]+b[10]+b[11]==34)s(12);break;
                case 4:case 8:case 12:if(b[i-3]+b[i-2]+b[i-1]+b[i]==34)s(i+1);break;
                case 13:if(b[1]+b[5]+b[9]+b[13]==34&&b[4]+b[7]+b[10]+b[13]==34)s(14);break;
                case 14:case 15:if(b[i-12]+b[i-8]+b[i-4]+b[i]==34)s(i+1);break;
                case 16:for(printf("\n"),++m;++n<17;n%4?0:printf("\n"))printf("%2d ",b[n]);
             }
             a[j]=0;
        }
}
int main(void)
{
    s(1);
    printf("四階幻方總數量:%d (含旋轉反射相同)\n",m);
    return 0;
}
