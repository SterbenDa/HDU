/*
两个人如果都采用正确操作，那么面对非奇异局势，先拿者必胜；反之，则后拿者取胜。
那么任给一个局势（a，b），怎样判断它是不是奇异局势呢？我们有如下公式：
ak =[k（1+√5）/2]，bk= ak + k （k=0，1，2，...n 方括号表示取整函数)
设k=b-a  (b>=a)
if((int)(k*x)==a)  奇异局势
else  非奇异局势 
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
		if((int)(k*x)==n){   //奇异局势 
			printf("0\n");
			continue;
		}
	}
	return 0;
}
