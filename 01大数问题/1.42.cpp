/*
https://blog.csdn.net/ysz171360154/article/details/88918627
大数乘法
不能计算负数
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
 
#define M 10005
 
void mul(int c[],int len);
void mul1(int len1,int len2,char s1[],char s2[]);//正数
void mul2(int len1,int len2,char s1[],char s2[]);//s1为负
void mul3(int len1,int len2,char s1[],char s2[]);//s2为负
void mul4(int len1,int len2,char s1[],char s2[]);//都为负
 
char s1[M]={0},s2[M]={0};
int a[M],b[M],c[M];
 
void mul1(int len1,int len2,char s1[],char s2[])
{
    int i,j,len;
 
    len=len1+len2; //保证相乘后的位数不会大于len
 
    for(i=0;i<len1;i++)
        a[i]=s1[len1-i-1]-'0';  //将数字字符转化为数字；
    for(i=0;i<len2;i++)
        b[i]=s2[len2-i-1]-'0';  //把字符串s1和s2逆序用数字排列
 
 
    for(i=0; i<len1; i++)
    {
        for(j=0; j<len2; j++)
        {
            c[i+j]=c[i+j]+a[i]*b[j];  //乘运算
        }
    }
    mul(c,len);
}
void mul2(int len1,int len2,char s1[],char s2[])
{
    int i,j,len;
 
    len=len1+len2-1; //保证相乘后的位数不会大于len
 
    for(i=0;i<len1-1;i++)
        {
            a[i]=s1[len1-i-1]-'0';
        }//将数字字符转化为数字；
    for(i=0;i<len2;i++)
        b[i]=s2[len2-i-1]-'0';  //把字符串s1和s2逆序用数字排列
 
 
    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len2; j++)
        {
            c[i+j]=c[i+j]+a[i]*b[j];  //乘运算
        }
    }
    printf("-");
    mul(c,len);
}
void mul3(int len1,int len2,char s1[],char s2[])
{
    int i,j,len;
 
    len=len1+len2-1; //保证相乘后的位数不会大于len
 
    for(i=0;i<len1;i++)
        a[i]=s1[len1-i-1]-'0';  //将数字字符转化为数字；
    for(i=0;i<len2-1;i++)
        b[i]=s2[len2-i-1]-'0';  //把字符串s1和s2逆序用数字排列
 
 
    for(i=0; i<len1; i++)
    {
        for(j=0; j<len2-1; j++)
        {
            c[i+j]=c[i+j]+a[i]*b[j];  //乘运算
        }
    }
    printf("-");
    mul(c,len);
}
void mul4(int len1,int len2,char s1[],char s2[])
{
    int i,j,len;
 
    len=len1+len2-2; //保证相乘后的位数不会大于len
 
    for(i=0;i<len1-1;i++)
        a[i]=s1[len1-i-1]-'0';  //将数字字符转化为数字；
    for(i=0;i<len2-1;i++)
        b[i]=s2[len2-i-1]-'0';  //把字符串s1和s2逆序用数字排列
 
 
    for(i=0; i<len1-1; i++)
    {
        for(j=0; j<len2-1; j++)
        {
            c[i+j]=c[i+j]+a[i]*b[j];  //乘运算
        }
    }
    mul(c,len);
}
 
void mul(int c[],int len)
{
    int i,j;
    for(i=0;i<=len;i++)
    {
        if(c[i]>=10)
        {
            c[i+1]=c[i+1]+c[i]/10;//进位运算
            c[i]=c[i]%10;
        }
    }
 
    i=len;
 
    while(c[i]==0)//去除前导0
    {
        i--;
    }
    for(; i>=0; i--)  //倒序输出
        printf("%d",c[i]);
 
    printf("\n");
}
 
int main()
{
    int i,len1,len2,m,m1=0,m2=0;
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        memset(a,0,sizeof(a));//初始化数据为0；
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        len1=strlen(s1);
        len2=strlen(s2);
        int m1=0,m2=0,m=0;
 
        for(i=0;i<len1;i++)//判断s1或s2是否为0
        {
            if(s1[i]!='0')
                m1=1;
        }
        for(i=0;i<len2;i++)
        {
 
            if(s2[i]!='0')
                m2=1;
        }
        if(m1==0||m2==0)//s1或s2为0
            printf("0\n");
 
        if(m1==1&&m2==1)//s1,s2都不为0
        {
            if(s1[0]!='-'&&s2[0]!='-')
                mul1(len1,len2,s1,s2);
            if(s1[0]=='-'&&s2[0]!='-')
                mul2(len1,len2,s1,s2);
            if(s1[0]!='-'&&s2[0]=='-')
                mul3(len1,len2,s1,s2);
            if(s1[0]=='-'&&s2[0]=='-')
                mul4(len1,len2,s1,s2);
        }
 
    }
    return 0;
}
