#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int main(){
    int n,m,i,a1,an;
    while(cin>>n>>m){
    	if(n==0&&m==0)
    	break;
    	for(i=sqrt(2*m);i>=1;i--){
    		a1=(2*m-i*i+i)/(2*i);
    		an=a1+(i-1);
    		if(an<=n&&(a1+an)*i==2*m)
    		  cout<<"["<<a1<<","<<an<<"]"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
