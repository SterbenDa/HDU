/*
˼·����Ŀ����˼�Ǹ���һ��1*N��ľ�壬����n��1*ai��ģ�壬���������ٵ�ȥƴ
�����¾ͺ� 
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


