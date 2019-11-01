#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
	map<string,int> m;
	int n,i;
	string a[1010];
	while(cin>>n){
		if(n==0)
		break;
		int big=-99999999;
		string result="";
		for(i=0;i<n;i++){
			cin>>a[i];
		   m[a[i]]++;
		}
		for(i=0;i<n;i++)
		{
			if(m[a[i]]>big){
				big=m[a[i]];
				result=a[i];
			}
		}
		cout<<result<<endl;
		m.clear();
	}
	return 0;
}
