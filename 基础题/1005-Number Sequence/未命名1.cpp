#include "iostream"
using namespace std;
const int MOD=7;
int f[1000];
int main(){
	int a,b,n,i;
	int result;
	f[1]=1;
	f[2]=1;
	while(cin>>a>>b>>n){
		if(a==0&&b==0&&n==0)
		break;
		if(n<=2){
			cout<<1<<endl;
			continue;
		}	
		for(i=3;i<=n;i++){
			f[i]=(a*f[i-1]+b*f[i-2])%MOD;
		//	cout<<i<<"----"<<f[i]<<endl;
			if(i>4&&f[i]==f[4]&&f[i-1]==f[3])//����ӵ���Ҫi>4 ���˺þô��� 
			break;
		}
		if(i<n){
			int tmp=(n-2)%(i-2-2);
			if(tmp!=0)
			result=f[tmp+2];
			else 
			result=f[i-2];
		}
		else
		result=f[n];
		cout<<result<<endl;
	}
	return 0;
}



//��ʱ�� �����ԣ� 
/*
#include "iostream"
using namespace std;
const int MOD=7;
int main(){
	int a,b,n,i;
	while(cin>>a>>b>>n){
		if(a==0&&b==0&&n==0)
		break;
		if(n<=2){
			cout<<1<<endl;
			continue;
		}
		int last1=1,last2=1,now;
		for(i=3;i<=n;i++){
			now=(a*last2+b*last1)%MOD;
			last1=last2;
			last2=now;
		//	cout<<i<<" ---- "<<now<<endl; 
		//ͨ���۲���Կ��� ÿһ�ж��������Լ����� 
		}
		cout<<now<<endl;
	}
	return 0;
}
*/

//�ڴ泬��  ��Ҫ������ 
/*#include "iostream"
using namespace std;
const int MOD=7;
int f[100000005];
int main(){
	int a,b,n,i;
	f[1]=1;
	f[2]=1;
	while(cin>>a>>b>>n){
		if(a==0&&b==0&&n==0)
		break;
		for(i=3;i<=n;i++){
			f[i]=(a*f[i-1]+b*f[i-2])%MOD;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}*/
