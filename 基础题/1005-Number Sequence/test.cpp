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
			cout<<i<<" ---- "<<now<<endl; 
		//通过观察可以看出 每一行都有属于自己规律 
		}
		cout<<now<<endl;
	}
	return 0;
}
