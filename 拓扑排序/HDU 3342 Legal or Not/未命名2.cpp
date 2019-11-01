#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
const int N=110;
int n,m;
int indegree[N];  //入度 
bool map[N][N];  //去除重复 并且判断有没2个关系不清的 
vector<int> ve[N];  
queue<int> q;
inline void Init(){
	int i;
	memset(map,0,sizeof(map));
		for(i=0;i<n;i++){
			ve[i].clear();
			indegree[i]=0;
		}
	while(!q.empty()) q.pop();
} 
inline void topoSort(){
	int i,tmp;
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		indegree[tmp]--;
		for(i=0;i<ve[tmp].size();i++){
			indegree[ve[tmp][i]]--;
			if(indegree[ve[tmp][i]]==0)
			q.push(ve[tmp][i]);
		}
	}
	//检查
	for(i=0;i<n;i++)
		if(indegree[i]!=-1)
		{
			printf("NO\n");
			return;
	} 
	printf("YES\n");
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
			 if(map[b][a]==1)
			 	ok=0;
	   }
	   if(ok==0){
	   	printf("NO\n");
	   	continue;
	   }
	   for(i=0;i<n;i++){
	   	if(indegree[i]==0)
	   	q.push(i);
	   }
	   topoSort();
	}
	return 0;
}
