/*
˼·����Ŀ��˼���ж� ax2+bx+c�ܲ��ֽܷ�� pqx2+(qk+mp)x+km=(px+k)(qx+m)��
���в�������������  ��ʮ����ˣ� 
�տ��������Ŀ��һ�о����ǰѸ��ӶȽ�������ö��p,k���У�����ѭ�����տ�ʼ����Ϊpö��
1��sqrt(a)���� �������Ǵ���ģ���Ϊp,q����ͬ��ɫ�������Ǵ�С������������ö�ٵ� 
ʱ��i���ܱ�a����������һ��p��a/i�����Ŷԡ�

�ο�����˼·1�� 
Ϊ�˽��͸��Ӷȣ���2��ѭ���ȷֿ�����һ�£���������������ȥ������������ 

�ο�����˼·2��
��������ax2+bx+c�Ķ���ʽ�����ж����ܷ�ʹ��ʮ�ַֽⷨ�ֽ���ʽʱ��
����ʹ�æ�=b2-4ac�����ж���
����Ϊ��ȫƽ����ʱ��������������Χ�Ըö���ʽ����ʮ����ˡ�
*/
/*�ⷨ1*/
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

/*�ⷨ2*/ 
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
          
