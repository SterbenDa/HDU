/*
̰�ģ����ڳ�n,��m,����
1: n,m   +1;
2: max(m,n-m),min(m,n-m) +1;
3:  .... 
ֱ��n==n-m; 
   ����ټ�һ��ʣ�µ� 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m; 
int main(){
    int t,re;
    cin>>t;
    while(t--){
    	re=1;
    	cin>>n>>m;
    	if(n==m){
    		cout<<re<<endl;
    		continue;
    	}
    	else if(n<m){
    		int tmp=n;
    		n=m;
    		m=tmp;
    	}
    	while(n!=m){
    		re++;
    		n=n-m;
			if(n<m){
    		int tmp=n;
    		n=m;
    		m=tmp;
    	}		
    	}
    	cout<<re<<endl;
    }
	return 0;
}
