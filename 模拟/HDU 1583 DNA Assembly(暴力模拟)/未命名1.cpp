/*
题目意思：让你拼接字符串，使长度最少； 
思路：
法一：由于N好小，直接暴力模拟，对N个字符串进行全排列，若可以，则算出结果长度；
法二：图论：
第i个字符串作为点i,枚举i到其他点是否可以拼接，若可以，则有向边，权值为公共长度
标记入度，和邻接表vector
对入度为0的作为起点枚举，回朔标记点是否访问过，累加权值最大sum
所有字符串的长度-最大公共长度=结果 
*/
/*用的法1  不知为何wa?  知道的求告知*/
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
		 	if(i+j==s[x].length()) //前者必须到结尾完 
		 	  return j;
	 }
	 return -1;
}
int main()
{  
    while(cin>>n){
    	sum=0;  //字符串总长 
    	re=-99999999;   //最长公共部分 
    	for(int i=0;i<n;i++){
    		cin>>s[i];
    		sum+=s[i].length();
    		a[i]=i;
		}
		for(int i=0;i<n;i++){   //一点到其他点的公共长度; 
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


