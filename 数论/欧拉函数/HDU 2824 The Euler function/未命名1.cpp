#include <iostream>
#include <cstdio>
using namespace std;
const int N=3000000+10;
long long phi[N];
inline void Init(){
	long long i,j;
	phi[0]=0;
	for(i=1;i<N;i++)  phi[i]=i;
	for(i=2;i<N;i+=2)  phi[i]/=2;
	for(i=3;i<N;i+=2) 
	if(phi[i]==i){
		for(j=i;j<N;j+=i)
	   phi[j]=phi[j]/i*(i-1);
	}
}
int main(){
	Init();
	int a,b,i;
	long long sum;
	while(cin>>a>>b){
		sum=0;
		for(i=a;i<=b;i++)
		 sum+=phi[i];
		cout<<sum<<endl;
	}
	return 0;
}
