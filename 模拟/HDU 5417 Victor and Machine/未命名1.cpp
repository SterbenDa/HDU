#include <iostream>
using namespace std;
int main(){
	int x,y,w,n,i,now,time,j;
	while(cin>>x>>y>>w>>n){
		//i  ����ʱ��Ҫֹͣ
		//j ÿw��һ���� 
		for(i=0,j=0,time=0,now=1;now<n;time++){
			i++;
			j++;
			if(i==x){
				time+=y;
				i=0;
				j=0;
				now++;
			}
			if(j==w){
				j=0;
				now++;
		
			}
		}
		cout<<time<<endl;
	}
	return 0;
}
