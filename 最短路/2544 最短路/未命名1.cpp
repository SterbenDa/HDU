#include <iostream>
#include <cstdio>
#include <string.h>
#include <deque>
#include <vector>
const int N=100+10;
const int M=N*100+10;
const int INF=1000000000;
using namespace std;
deque<int> q;
struct Edge{ 
	int to,v;
}edge;
bool book[N][N];  //去重边 
bool done[N];  //是否进队列 
int cnt[N];    //进了几次队列 
vector<Edge> ve[N];
int dis[N];
int V,E;  //V点  E边 
inline void Init(int n){
	int i,j;
	V=n; 
	for(i=1;i<=n;i++){
		ve[i].clear();
		done[i]=0;
		cnt[i]=0;
		dis[i]=INF;
		for(j=1;j<=n;j++)
		book[i][j]=0;
	}
	while(!q.empty()) q.pop_front();
}
bool Spfa(int x){
	dis[x]=0;
	cnt[x]=1;
	done[x]=1;
	q.push_back(x);
	while(!q.empty()){
		int tmp=q.front();
		q.pop_front();
		for(int i=0;i<ve[tmp].size();i++){
			Edge *e=&ve[tmp][i];
			if(dis[(*e).to]>dis[tmp]+(*e).v){
					dis[(*e).to]=dis[tmp]+(*e).v;
				if(done[(*e).to]!=1){  //不在队列里 
					if(!q.empty()){
						if(dis[(*e).to]>dis[q.front()])
						   q.push_back((*e).to);
						else
						q.push_front((*e).to);
					}
					else
					  q.push_back((*e).to); 
					  cnt[(*e).to]++;
					  done[(*e).to]=1;
				}
				if(cnt[(*e).to]>V)
			        return false;
			}	        
		}
		done[tmp]=0;
	}
	return true;
}
int main(){
	int i,a,b,t, n,m;
	Edge edge;
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
		break;
		Init(n);
		for(i=0;i<m;i++){
			scanf("%d%d%d",&a,&b,&t);
			if(book[a][b]==1)
			continue;
			book[a][b]=1;
			book[b][a]=1;
			edge.to=b;
			edge.v=t;
			ve[a].push_back(edge);
			edge.to=a;
			ve[b].push_back(edge);
		}
		if(Spfa(1)==0)
		printf("\n");
		else
		printf("%d\n",dis[n]);		
	}
	return 0;
}
