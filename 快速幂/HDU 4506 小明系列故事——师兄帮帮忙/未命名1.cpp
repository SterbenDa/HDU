/*
思路：求k的t次幂,然后乘以每个数，然后按(i+t)%n 排列位置 
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int Mod=1e+9+7;
const int N=1e+4+5;
long long re[N]; 
long long quick_pow(long long a,long long b){
      long long ans=1;
	  while(b!=0){
	  	 if(b&1){
	  	 	ans=ans*a%Mod;
	  	 	b--;
		 }
		 b=b>>1;
		 a=a*a%Mod;
	  } 
	  return ans;
} 
int main(){ 
    int t,i;
    int n,m;
     long long k,a;
    cin>>t;
    while(t--){
    	cin>>n>>m>>k;	
    	long long sum=quick_pow(k,m);
    	for(i=0;i<n;i++){
    		cin>>a;
    		re[(i+m)%n]=a*sum%Mod;
	    }
	      cout<<re[0];
			for(i=1;i<n;i++)
			 cout<<" "<<re[i];
			 cout<<endl;		
	}
	return 0;
}
