#include<iostream>
using namespace std;
int main(void)
{
    long N,a,b,i,j=0,k=0;
    N=9999;
    //cout<<"请输入e位数(不超过100000)\n",cin>>N,N+=5;
    long *e=new long[N],*c=new long[N];
    while(++j<N)e[j]=c[j]=0;
    for(*c=i=1;k<N;i++)
    {
        while(!c[k])k++;
        for(b=0,j=k-1;++j<N;b=a%i)e[j]+=(c[j]=(a=b*10+c[j])/i);
    }
    for(;--j;e[j]%=10)e[j-1]+=e[j]/10;
    for(cout<<"2.";++j<N-5;)cout<<e[j];
    delete[]e,delete[]c;
    return 0;
}
