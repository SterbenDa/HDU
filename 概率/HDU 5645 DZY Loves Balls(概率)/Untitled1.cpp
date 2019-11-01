/*
思路：对求号码进行排序 
取两次球第一次不放回，所有可能的情况为n*(n-1)，对于每一个球，枚举比他大的球的位置j，
n-j即为比第一次球大的数目a，a/(n*(n-1))，即为每一次的概率，累加即为结果 
*/
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=300+5;
int a[N];
int main(){
	int t,i,j,n;
	double re;
	cin>>t;
	while(t--){
		cin>>n;
		re=0;
		for(i=0;i<n;i++)
		   cin>>a[i];
		sort(a,a+n);
		 for(i=0;i<n;i++){  //枚举每一个球 
		 	for(j=i+1;j<n;j++){   //找到比第一个球大的位置 
		 		if(a[i]<a[j]){
		 			break;
		 		}
		 	}
		 	re+=(double)(n-j)/(n*(n-1));
		 }
		 printf("%.6lf\n",re);
	}
	return 0;
}
