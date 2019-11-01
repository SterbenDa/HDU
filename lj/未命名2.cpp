#include <cstdio>
#include <string.h>
#include <math.h>
#include <iostream>
using  namespace  std;   
const double pai=3.1415926;
const double e=2.718281828459;
//const  int N =5000001;
//double a[N];
double quick_pow(double a,int b){
	double ans=1;
	while(b){
		if(b&1){
			ans=log10(ans)+log10(a);
			b--;
		}
		b=b>>1;
		a=log10(a)+log10(a);
	}
	return ans;
}
int main()      
{      
      int t,n,i;
     //  a[1]=log10(1);
    // for(i=2;i<N;i++)
    //   a[i]=a[i-1]+log10(i);
     cin>>t;
     while(t--){
     	cin>>n;
     //	double hehe=0;
     //	for(i=1;i<=n;i++)
     //	   hehe+=log10(i);
     //	cout<<(long long)hehe+1<<endl;
     //	if(n>5000000)
  cout<<(long long)log10(sqrt(2*pai*n))
  +(long long)quick_pow((double)n/e,n)+1<<endl;
     //	else
     //	cout<<(int)a[n]+1<<endl;
	 }
    return 0;   
}




/*
#include <cstdio>
#include <string.h>
#include <math.h>
#include <iostream>
using  namespace  std;         
const  int N =10000000+10;
float a[N];  
int main()      
{      
     int t,n,i;
      a[1]=log10(1);
     for(i=2;i<N;i++)
       a[i]=a[i-1]+log10(i);
     cin>>t;
     while(t--){
     	cin>>n;
     	cout<<(int)a[n]+1<<endl;
	 }
    return 0;   
}
*/

