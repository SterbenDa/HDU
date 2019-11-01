/*
先把a+b的情况全部列出来，放在ab[]这个数组中（数组大小为500*500）。
然后查s-c[]在ab[]中是否存在，用二分查找。
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=500+5;
int ab[N*N];
int a[N],b[N],c[N];
inline bool find(int begin,int end,int s){
	 if(begin==end&&ab[begin]!=s)
	  return false;
	 int mid=(begin+end)>>1;	 
	 if(ab[mid]==s)
	  return true;
	else if(ab[mid]<s)
	   return find(mid+1,end,s);
	else 
	  return find(begin,mid,s);
}

int main(){ 
   int alen,blen,clen,ablen;
   int i,j,k,n,now=1;
   bool ok;
    while(cin>>alen>>blen>>clen){
    	
           for(i=0;i<alen;i++)
            cin>>a[i];
            
            for(i=0;i<blen;i++)
            	cin>>b[i];  
				        
			for(i=0;i<clen;i++)
			  cin>>c[i];
			  
			ablen=0; 
			for(i=0;i<alen;i++)
			{
				for(j=0;j<blen;j++){
					ab[ablen++]=a[i]+b[j];
				}
			}
			
		sort(ab,ab+ablen);
		
		cin>>n;
		cout<<"Case "<<now++<<":"<<endl;
		  while(n--){
		  	  ok=0;
		  	  int s;
		  	  cin>>s;
		  	  for(i=0;i<clen;i++){
		  	  	   if(find(0,ablen,s-c[i])){
		  	  	   	ok=1;
		  	  	   	break;
					   }
				}
		  	  
		  	  if(ok)
		  	    cout<<"YES"<<endl;
		  	  else
		  	  cout<<"NO"<<endl;
		  }
	}
	
	return 0;
}


