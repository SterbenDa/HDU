#include <iostream>
#include <string.h>
#include <string>
#include <map>
using namespace std;
const int N=1005;
map<string,int> ma;
bool book[N];
inline void Init(){
	memset(book,1,sizeof(book));
	ma.clear();
}
int main(){
	int t,i,n;
	string s1,s2;
	while(cin>>t){
		if(t==0)
		break;
		n=0;
		Init();
		for(i=0;i<t;i++){
			cin>>s1>>s2;
			if(ma.count(s1)==0)			
				ma[s1]=n++;			
			if(ma.count(s2)==0)
				ma[s2]=n++;
			book[ma[s2]]=0;
		}
		int sum=0;
		for(i=0;i<n;i++)
		   if(book[i]==1)
		   sum++;
		if(sum==1)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}
