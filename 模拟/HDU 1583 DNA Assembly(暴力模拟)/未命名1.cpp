/*
��Ŀ��˼������ƴ���ַ�����ʹ�������٣� 
˼·��
��һ������N��С��ֱ�ӱ���ģ�⣬��N���ַ�������ȫ���У������ԣ������������ȣ�
������ͼ�ۣ�
��i���ַ�����Ϊ��i,ö��i���������Ƿ����ƴ�ӣ������ԣ�������ߣ�ȨֵΪ��������
�����ȣ����ڽӱ�vector
�����Ϊ0����Ϊ���ö�٣���˷��ǵ��Ƿ���ʹ����ۼ�Ȩֵ���sum
�����ַ����ĳ���-��󹫹�����=��� 
*/
/*�õķ�1  ��֪Ϊ��wa?  ֪�������֪*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s[10];
int a[10];
int map[10][10]; 
int n,sum,re;
inline int check(int x,int y){
	int i,j;
     for(i=0;i<s[x].length();i++){
     	for(j=0;j<s[y].length()&&i+j<s[x].length();j++){
     		 if(s[x][i+j]!=s[y][j])
     		    break;
		 }	
		 	if(i+j==s[x].length()) //ǰ�߱��뵽��β�� 
		 	  return j;
	 }
	 return -1;
}
int main()
{  
    while(cin>>n){
    	sum=0;  //�ַ����ܳ� 
    	re=-99999999;   //��������� 
    	for(int i=0;i<n;i++){
    		cin>>s[i];
    		sum+=s[i].length();
    		a[i]=i;
		}
		for(int i=0;i<n;i++){   //һ�㵽������Ĺ�������; 
			for(int j=0;j<n;j++){
				if(j==i){
					map[i][j]=-1;
					continue;
				}				 
				map[i][j]=check(i,j);			
			}		
		}		
		/*	for(int i=0;i<n;i++){   
			for(int j=0;j<n;j++)
				cout<<map[i][j]<<" ";
			cout<<endl;*/		
		do{
		    bool ok=1;
		    int tmp=0;
		    for(int i=0;i<n-1;i++){
		    	if(map[a[i]][a[i+1]]==-1)
		    	  {
		    	  	 ok=0;
		    	  	 break;
				  }	
				 else{
				 	tmp+=map[a[i]][a[i+1]];
				 }	 
			}
			if(ok){
				if(re<tmp)
				  re=tmp;
			}
		}while(next_permutation(a,a+n));
		cout<<sum-re<<endl; 
	}
	return 0;
}


