#include <iostream>
#include <cstdio>
using namespace std;
const int N=10000+1;
long long num[N];
int main()
{
	 long long i;
	 num[0]=0;
	 for(i=1;i<N;i++)
	    num[i]=num[i-1]+i*i*i;
	int t,a,b;
	cin>>t;
     for(i=1;i<=t;i++){
     	cin>>a>>b;
     	cout<<"Case #"<<i<<": ";
     	cout<<num[b]-num[a-1];
     	cout<<endl;
	 }
			
	return 0;
}
