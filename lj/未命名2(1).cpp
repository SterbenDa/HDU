#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std; 
const int N=100+5;
const double e=1e-6;
double a[N];
int main() 
{ 
    int t,i,n,v,now_v;
    double p,now_c;
    cin>>t;
    while(t--){
    	cin>>n>>v>>p;
    	p/=100;
    	for(i=0;i<n;i++){
    		cin>>a[i];
    		a[i]/=100;
		}  		
    	sort(a,a+n);
    	now_c=0;
    	now_v=0;
    	for(i=0;i<n;i++){
    		if((double)(now_c*now_v+a[i]*v)/(now_v+v)-e<=p)
    		  {
    		  	 now_c=(double)(now_c*now_v+a[i]*v)/(now_v+v);
    		  	 now_v+=v;
			  }
			  else
			  break;
		}
		if(now_c-e<=p)
		cout<<now_v<<" "<<setprecision(2)<<fixed<<now_c<<endl;
		else
		cout<<0<<" "<<"0.00"<<endl;
	}
    return 0; 
}
