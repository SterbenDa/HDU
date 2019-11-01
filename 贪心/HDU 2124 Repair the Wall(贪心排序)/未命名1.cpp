/*
思路：题目的意思是给你一个1*N的木板，给你n个1*ai的模板，叫你用最少的去拼
排序下就好 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N=500+5;
int a[N]; 
int main()
{   
     int l,n,re;
     bool ok;
     while(cin>>l>>n){
     	ok=0;
     	re=0;
     	for(int i=0;i<n;i++)
     	  cin>>a[i];
     	sort(a,a+n);
     	for(int i=n-1;i>=0;i--){
     		 if(a[i]>=l){
     		 	ok=1;
     		 	re+=1;
     		 	break;
			  }
			  else
			  {
			  	re+=1;
			  	l-=a[i];
			  }
		 }
		 if(ok)
		   cout<<re<<endl;
		   else
		   cout<<"impossible"<<endl;
	 }
	return 0;
}


