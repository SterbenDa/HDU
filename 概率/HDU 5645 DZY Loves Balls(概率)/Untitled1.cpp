/*
˼·���������������� 
ȡ�������һ�β��Żأ����п��ܵ����Ϊn*(n-1)������ÿһ����ö�ٱ���������λ��j��
n-j��Ϊ�ȵ�һ��������Ŀa��a/(n*(n-1))����Ϊÿһ�εĸ��ʣ��ۼӼ�Ϊ��� 
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
		 for(i=0;i<n;i++){  //ö��ÿһ���� 
		 	for(j=i+1;j<n;j++){   //�ҵ��ȵ�һ������λ�� 
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
