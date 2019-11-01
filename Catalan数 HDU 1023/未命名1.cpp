#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include <math.h>
#include <iostream>
using  namespace  std;      
     
const  int MAXL = 100+1;      
struct  BigNum      
{      
BigNum(){
  memset(num,0,sizeof(num));
}
    int  num[MAXL];      
    int  len;      
};      
//�߾��ȳ��Ե;��ȣ���b�ܴ�ʱ���ܻᷢ�����int��Χ,��������������      
//���b�ܴ���Կ��ǰ�b���ɸ߾���      
BigNum Mul1(BigNum &a, int b)      
{      
    BigNum c;      
    int  i, len;      
    len = a.len;      
    
    //����0��ֱ�ӷ���0      
    if(b == 0)       
    {      
        c.len = 1;      
        return  c;      
    }      
    for(i = 0; i < len; i++)      
    {      
        c.num[i] += (a.num[i]*b);      
        if(c.num[i] >= 10)      
        {      
            c.num[i+1] = c.num[i]/10;      
            c.num[i] %= 10;      
        }      
    }      
    while(c.num[len] > 0)      
    {      
        c.num[len+1] = c.num[len]/10;      
        c.num[len++] %= 10;      
    }      
    c.len = len;       
    return  c;      
}      
//�߾��ȳ��Ե;���,���Ľ��Ϊc, ����Ϊf      
void Div1(BigNum &a, int b, BigNum &c)      
{      
    int  i, len = a.len;      
    memset(c.num, 0, sizeof(c.num));      
    int f = 0;      
    for(i = a.len-1; i >= 0; i--)      
    {      
        f = f*10+a.num[i];      
        c.num[i] = f/b;      
        f %= b;      
    }      
    while(len > 1 && c.num[len-1] == 0)
		len--;      
    c.len = len;      
}      
void  print(BigNum &a)   //�������   
{      
    int  i;      
    for(i = a.len-1; i >= 0; i--)      
        printf("%d", a.num[i]);            
}      
void Init(BigNum &a, char *s)   //���ַ���ת��Ϊ����
{   
    int  i = 0, j = strlen(s); 
    a.len = j;
    for(; s[i] != '\0'; i++, j--)
        a.num[j-1] = s[i]-'0';
}   
  
int main(void)      
{      
    BigNum a[MAXL],tmp;   
    int i,n,yushu;
	Init(a[0],"1");
    for(i=1;i<MAXL;i++){
    	tmp=Mul1(a[i-1],4*i-2);
    	Div1(tmp,i+1,a[i]);
	}
    while(cin>>n)   
    {       
     if(n==-1)
       break;
        print(a[n]);   
        cout<<endl;  
    }   
    return 0;   
}














/*����̫�� ��� Ҫ�ô��� 
#include <iostream>
using namespace std;
long long  a[101];
int main(){
	long long n,i;
	a[0]=1;
	for(i=1;i<101;i++)
	   a[i]=a[i-1]*(4*i-2)/(i+1);
	while(cin>>n){
		cout<<a[n]<<endl;
	}
	return 0;
}
*/
