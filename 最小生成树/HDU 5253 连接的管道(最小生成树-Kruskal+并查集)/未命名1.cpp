/*
    ˼·��һ��1000*1000*2���� 
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
int pre[N*N]; //��i�ĸ��ڵ� 
int n,m;   //���󳤿� 
int len;   //����Ŀ 
int map[N][N];   
int step[2][2]={{0,1},{1,0}};  //�Һ��� 
inline void Init(){
	for(int i=0;i<=n*m;i++)
	  pre[i]=i;
} 
inline int find(int x){
	int r=x;
	while(pre[r]!=r)   //�Ҹ��ڵ�
	   r=pre[r];
	//����r�Ǹ��ڵ� 
	int i=x,j; 
	while(i!=r){   //·��ѹ�� 
		j=pre[i];
		pre[i]=r;
		i=j;
	} 
	return r; 
}
inline bool join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){  //�����ڻ�· 
		pre[fx]=fy;
		return true;
	}
	return false;
}
inline int kruskal(){
	int i,count=1,sum=0;
	Init();
	sort(node,node+len,cmp);
	for(i=0;count<n*m;i++){    //��С������n���㣬���ܹ�n-1����
	//����n*m���㣬��n*m-1���� 
		if(join(node[i].s,node[i].end)){
			sum+=node[i].w;
			count++;
		}
	}
	return sum;  //��С������ 
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
		for(int i=0;i<n;i++)    //ö�ٱ� ����ÿ���㣬ö�ٺ��ұ����ߺ���������� 
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<2;k++){
				int a=i+step[k][0];
				int b=j+step[k][1];
				if(b>=m||a>=n)
				  continue;
				Node tmp;
				tmp.s=i*m+j;  //��� 
				tmp.end=a*m+b;    //�յ� 
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





