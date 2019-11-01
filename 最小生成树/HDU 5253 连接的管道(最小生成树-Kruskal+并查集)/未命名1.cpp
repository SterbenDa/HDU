/*
    思路：一共1000*1000*2条边 
*/
#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1000+10;
struct Node{
	int s,end,w;
}node[N*N*2];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int pre[N*N]; //点i的父节点 
int n,m;   //矩阵长宽 
int len;   //边数目 
int map[N][N];   
int step[2][2]={{0,1},{1,0}};  //右和下 
inline void Init(){
	for(int i=0;i<=n*m;i++)
	  pre[i]=i;
} 
inline int find(int x){
	int r=x;
	while(pre[r]!=r)   //找父节点
	   r=pre[r];
	//现在r是父节点 
	int i=x,j; 
	while(i!=r){   //路径压缩 
		j=pre[i];
		pre[i]=r;
		i=j;
	} 
	return r; 
}
inline bool join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){  //不存在回路 
		pre[fx]=fy;
		return true;
	}
	return false;
}
inline int kruskal(){
	int i,count=1,sum=0;
	Init();
	sort(node,node+len,cmp);
	for(i=0;count<n*m;i++){    //最小生成树n个点，就总共n-1条边
	//这里n*m个点，就n*m-1条边 
		if(join(node[i].s,node[i].end)){
			sum+=node[i].w;
			count++;
		}
	}
	return sum;  //最小花费树 
}
int main() 
{ 
    int t,re,now;
	scanf("%d",&t);
	for(now=1;now<=t;now++){
		re=0;
		len=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		   scanf("%d",&map[i][j]);
		for(int i=0;i<n;i++)    //枚举边 对于每个点，枚举和右边连边和下面的连边 
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<2;k++){
				int a=i+step[k][0];
				int b=j+step[k][1];
				if(b>=m||a>=n)
				  continue;
				Node tmp;
				tmp.s=i*m+j;  //起点 
				tmp.end=a*m+b;    //终点 
			    tmp.w=abs(map[a][b]-map[i][j]);
			    node[len++]=tmp;  
			}			
		}
		re=kruskal();
		printf("Case #%d:\n",now);
		printf("%d\n",re); 
	} 	
    return 0;
}





