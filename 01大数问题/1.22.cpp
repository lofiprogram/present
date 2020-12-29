/*
https://blog.csdn.net/ysz171360154/article/details/85006990
大数加法(考虑前导0)
如果考虑前导0 ，那么0+0=0是就会是一个特殊情况。
需要特别列出或者用其他方法解决。
*/



#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];//通过字符串对大数进行输入并储存
    int len1,len2,len;
    while(scanf("%s %s",a,b))
    {
        int x[100]={0},y[100]={0},z[105]={0};//将数组元素全部初始化为
        int i,j=0,k=0;
        len1=strlen(a);
        len2=strlen(b);
        if(a[0]==0&&len1==1&&b[0]==0&&len2==1)//因为后面要去前置0，这里是0+0的特殊情况
        {
            printf("0");
        }
        else
        {
        for(i=len1-1;i>=0;i--)//将两个字符串中的字符转化为数字，并倒序储存到数组中，即字符串为123456，则数组为654321
        {
            x[j++]=a[i]-'0';
        }
        for(i=len2-1;i>=0;i--)
        {
            y[k++]=b[i]-'0';
        }
        if(len1>len2)
            len=len1;
        else
            len=len2;
        int m=0;
        for(i=0;i<len;i++)
        {
            z[i]=(x[i]+y[i]+m)%10;//将所得数的个位存到数组z[i]中去
            if((x[i]+y[i]+m)>=10)
                m=1;
            else
                m=0;
        }
        if((x[i-1]+y[i-1]+m)>=10)//判断运算的最大位的和是否>=10
            z[i]=1;//进位
        else
            i=i-1;
        while(j=i)//除去前置0
        {
            if(z[j]==0)
                i--;
            else
                break;
        }
        for(k=i;k>=0;k--)//倒序输出数组
            printf("%d",z[k]);
        }
        printf("\n");
    }
    return 0;
}


