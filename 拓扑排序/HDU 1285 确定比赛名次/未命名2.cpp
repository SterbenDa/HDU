#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
const int N=510;
int n,m;
bool book[N];   //检查用 
int indegree[N];  //入度 
bool map[N][N];  //去除重复 并且判断有没2个关系不清的 
vector<int> ve[N]; 
int re[N],len; 
struct cmp{
    bool operator ()(int &a,int &b){
        return a>b;//最小值优先
    }
};
priority_queue<int,vector<int>,cmp>q;
inline void Init(){
	int i;
	len=0;
	memset(map,0,sizeof(map));
		for(i=1;i<=n;i++){
			ve[i].clear();
		//	book[i]=0;
			indegree[i]=0;
		}
	while(!q.empty()) q.pop();
} 
inline void topoSort(){
	int i,tmp;
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		re[len++]=tmp;
		//printf("%d ",tmp);
		//book[tmp]=1; 
		for(i=0;i<ve[tmp].size();i++){
			indegree[ve[tmp][i]]--;
			if(indegree[ve[tmp][i]]==0)
			q.push(ve[tmp][i]);
		}
	}
	//检查
/*	for(i=0;i<n;i++)
		if(book[i]==0)
		{
			printf("NO\n");
			return;
	} 
	printf("YES\n");*/
}
int main(){
	int i,j,a,b;
	char c[5];
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
		break;
		bool ok=1;
		Init();
	   for(i=0;i<m;i++){
	   	scanf("%d%d",&a,&b);
	     	if(map[a][b]==0){
	     		map[a][b]=1;
	     		ve[a].push_back(b);
	     		indegree[b]++;
			 }			 
	   }
	   for(i=1;i<=n;i++){
	   	if(indegree[i]==0)
	   	q.push(i);
	   }
	   topoSort();
	   for(i=0;i<len-1;i++)
	      printf("%d ",re[i]);
	    printf("%d",re[i]);
	   printf("\n");
	}
	return 0;
}
