/*
https://blog.csdn.net/ysz171360154/article/details/88918627
大数乘法
不能计算负数
*/

     
    #include<stdio.h>
    #include<math.h>
    #include<string.h>
     
    #define M 10005
     
    char s1[M],s2[M],s[M];
    int a[M],b[M],c[M];
     
    int main()
    {
        int i,j,len1,len2,len;
     
        while(scanf("%s %s",s1,s2)!=EOF)
        {
            memset(a,0,sizeof(a));//初始化数据为0；
            memset(b,0,sizeof(b));
            memset(c,0,sizeof(c));
     
            len1=strlen(s1);
    	    len2=strlen(s2);
     
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
                    //这里内部加的c[i+j]实现的是相同权重上的两个乘数的相加。
                }
            }
     
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
     
            if(i<0)   //当两个数是0时，判断两个非负数之积是否为0，以及逆序打印c[]
    			printf("0");
     
            else
            {
                for(; i>=0; i--)  //倒序输出
                    printf("%d",c[i]);
            }
            printf("\n");
        }
        return 0;
    }
