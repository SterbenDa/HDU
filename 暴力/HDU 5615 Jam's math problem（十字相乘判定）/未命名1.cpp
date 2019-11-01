/*
思路：题目意思是判定 ax2+bx+c能不能分解成 pqx2+(qk+mp)x+km=(px+k)(qx+m)，
其中参数都是正整数  即十字相乘， 
刚看到这个题目第一感觉就是把复杂度降下来，枚举p,k就行，两重循环，刚开始误以为p枚举
1到sqrt(a)就行 ，这样是错误的，因为p,q代表不同角色，可能是大小反过来，所以枚举的 
时候i若能被a整除，则另一个p是a/i这样才对。

参考网上思路1： 
为了降低复杂度，将2个循环先分开处理一下，将不能整除的先去掉，这样就行 

参考网上思路2：
对于形如ax2+bx+c的多项式，在判定它能否使用十字分解法分解因式时，
可以使用Δ=b2-4ac进行判定。
当Δ为完全平方数时，可以在整数范围对该多项式进行十字相乘。
*/
/*解法1*/
/*
#include <iostream>
#include <math.h>
using namespace std;
const int N=2*10000+5;
int nump[N],numk[N];
int lenp,lenk;
int main()
{	
	int t,a,b,c,p,q,k,m;
	int n1,n2;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		n1=sqrt(a);
		n2=sqrt(c);
		bool ok=0;
		lenp=0;
		lenk=0;
	  for(p=1;p<=n1;p++){
	     if(a%p==0){
	    	nump[lenp++]=p;
	    		nump[lenp++]=a/p; 
		 }
	  }
	  for(k=1;k<=n2;k++){
	     if(c%k==0){
	    	numk[lenk++]=k;
	    		numk[lenk++]=c/k; 
		 }
	  }
	  for(int i=0;i<lenp;i++){
	  	  for(int j=0;j<lenk;j++){
	  	    p=nump[i];
	  	    k=numk[j];
	  	    q=a/nump[i];
	  	    m=c/numk[j];
	  	    if(q*k+m*p==b){
	  	    	ok=1;
	  	    	break;
			  }						  
	  }
	     if(ok)
	      break;
	  }
	  
		if(ok)
		 cout<<"YES"<<endl;
		 else
		 cout<<"NO"<<endl;
	}
	return 0;
}*/

/*解法2*/ 
#include <iostream>
#include <math.h>
using namespace std;
int main()
{	
	long long a,b,c; 
	int t;
	cin>>t;
	while(t--){
		bool ok=0;
		cin>>a>>b>>c;
		long long tmp=sqrt(b*b-4*a*c);
		if(tmp*tmp==b*b-4*a*c)
	            ok=1;
		if(ok)
		 cout<<"YES"<<endl;
		 else
		 cout<<"NO"<<endl;
	}
	return 0;
}
          
