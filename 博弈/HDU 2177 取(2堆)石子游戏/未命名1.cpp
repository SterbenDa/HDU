/*
�����������������ȷ��������ô��Է�������ƣ������߱�ʤ����֮���������ȡʤ��
��ô�θ�һ�����ƣ�a��b���������ж����ǲ�����������أ����������¹�ʽ��
ak =[k��1+��5��/2]��bk= ak + k ��k=0��1��2��...n �����ű�ʾȡ������)
��k=b-a  (b>=a)
if((int)(k*x)==a)  �������
else  ��������� 
*/
#include <iostream>
#include <cstdio>
#include <math.h>
const double x=(1+sqrt(5))/2;
using namespace std;
int main(){
	int n,m,i,k,j;
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
		break;
		if(n>m){
			int tmp=n;
			n=m;
			m=tmp;
		}
		k=n-m;
		if((int)(k*x)==n){   //������� 
			printf("0\n");
			continue;
		}
	}
	return 0;
}
