#include <cstdio>
#include <string.h>
#include <iostream>
using  namespace  std;      
     
const  int MAXL = 1100;      
struct  BigNum      
{      
   BigNum(){
      memset(num,0,sizeof(num));
   }
    int  num[MAXL];      
    int  len;      
};      
//高精度加法      
BigNum  Add(BigNum &a, BigNum &b)      
{      
    BigNum c;      
    int  i, len;      
    len = (a.len > b.len) ? a.len : b.len;          
    for(i = 0; i < len; i++)      
    {      
        c.num[i] += (a.num[i]+b.num[i]);      
        if(c.num[i] >= 10)      
        {      
            c.num[i+1]++;      
            c.num[i] -= 10;      
        }      
    }      
    if(c.num[len])
		len++;      
    c.len = len;      
    return  c;      
}      


void  print(BigNum &a)   //输出大数   
{      
    int  i;      
    for(i = a.len-1; i >= 0; i--)      
        printf("%d", a.num[i]);        
}  

void Init(BigNum &a, char *s)   //将字符串转化为大数
{   
    int  i = 0, j = strlen(s); 
    a.len = j;
    for(; s[i] != '\0'; i++, j--)
        a.num[j-1] = s[i]-'0';
}   
  
int main(void)      
{      
     int t=1,n;
    BigNum a, b;   
    char  s1[1100], s2[1100];   
    scanf("%d",&n);
    while(n--)   
    {   
      scanf("%s%s", s1, s2) ;
        Init(a, s1);    //将字符串转化为大数
        Init(b, s2);   
        BigNum c=Add(a,b);  
        printf("Case %d:\n",t++);
        print(a);
        printf(" + ");
         print(b);
        printf(" = ");
        print(c);
        printf("\n");
        if(n>0)
        printf("\n");
    }   
    return 0;   
}


