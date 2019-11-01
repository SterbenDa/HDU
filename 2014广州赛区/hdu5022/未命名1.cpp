#include <iostream>
#include <string.h>
using namespace std;
const int len=1000000000;
int p;
bool book[len];
bool judge[len];
int main(){
	long long pow(long long a,long long b);
	int i;
	long long M,A,B,s,t,tmp;
	while(cin>>M>>A>>B>>s>>t>>p){
		if(M+A+B+s+t+p==0)
		break;
		memset(book,0,sizeof(book));
		memset(judge,0,sizeof(judge));
		int begin=pow(B,s);
		book[begin]=1;
		for(i=s+1;i<=t;i++){
			begin=begin*B%p;
			book[begin]=1;
		}
		begin=1;
		for(i=0;;i++){
		  if(i==0)
		  	judge[M]=1;
		  else{
		  	begin=begin*A%p;
		  	tmp=begin*M%p;
		  	if(book[tmp]==1&&judge[tmp]==0){
		  		cout<<i<<endl;
		  			break;
		  	}		  	
		  	else if(judge[tmp]==1){
		  		cout<<"impossible"<<endl;
		  		break;
		  	}		  	   
		  }
		  judge[tmp]=1;
		}
	}
	return 0;
}
long long pow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1){
			ans=ans*a%p;
			b--;
		}
		b>>1;
		a=a*a%p;
	}
	return ans;
}
