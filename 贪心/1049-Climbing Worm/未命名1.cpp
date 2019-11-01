#include "iostream"
using namespace std;
int main(){
	int n,u,d;
	while(cin>>n>>u>>d){
		if(n==0&&u==0&&d==0)
		break;
		int now=0;
		int time;
		for(time=1;now<n;time++){
			if(time%2==1)
               now+=u;
               else
               now-=d;
		}
		cout<<time-1<<endl;
	}
	return 0;
}
