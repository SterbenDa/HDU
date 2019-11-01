#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
const int N=1000+100;
const int INF=1000000000;
struct Edge{
	int to,v;
}edge;
int cnt[N];
int map[N][N];
bool done[N];
vector<Edge> ve[N];
int dis[N];
int home[N],want[N];
deque<int> q;
int V,E;  //点和边 
inline void init(){
	int i,j;
	V=0;
	for(i=0;i<N;i++){
		 ve[i].clear();
		 done[i]=0;
		 cnt[i]=0;
		 dis[i]=INF;
		 for(j=0;j<N;j++)
		   map[i][j]=INF;
	}	
	while(!q.empty()) q.pop_front();
}
inline bool spfa(){
	while(!q.empty()){
		int tmp=q.front();
		q.pop_front();
		for(int i=0;i<ve[tmp].size();i++){
			  Edge *e=&ve[tmp][i];
			  if(dis[(*e).to]>dis[tmp]+(*e).v){
			  	  dis[(*e).to]=dis[tmp]+(*e).v;
			  	  if(done[(*e).to]!=1){
			  	  	   done[(*e).to]=1;
			  	  	   cnt[(*e).to]++;	
			  	  	   if(!q.empty()){
			  	  	   		if(dis[(*e).to]>dis[q.front()])
						      q.push_back((*e).to);
					     	else
					     	 q.push_front((*e).to);
						   }
						 else  //忘了加！！结果wa 
						     q.push_back((*e).to);									   		  	  	   
					}	
					//if(cnt[i]>V){
					//	return false;
					}			
			  }
			  	done[tmp]=0;
		}
	return true;
}
int main(){ 
    int n,m,a,b,t,i,j;
    while(cin>>E>>n>>m){
    	init();
    	
        for(i=0;i<E;i++){  //解决多条路  取最小值 
        	cin>>a>>b>>t;
        	V=max(max(a,b),V);
             if(t<map[a][b]){
             	map[a][b]=t;
             	map[b][a]=t;
			 }		
		}
		
		for(i=0;i<=V;i++)
		  for(j=0;j<=V;j++){
		  	if(map[i][j]!=INF){
		  		edge.to=j;
        	    edge.v=map[i][j];
        	  ve[i].push_back(edge);      	    
			  }
		  } 
		
		
		for(i=0;i<n;i++){
		//	 cin>>home[i];
		   cin>>a;
		   done[a]=1;
		   cnt[a]++;
		   dis[a]=0;
		   q.push_back(a);
		}
		   		
		for(i=0;i<m;i++)
		  cin>>want[i];
		
		if(spfa()){
				int re=INF;
		for(i=0;i<m;i++){
			if(dis[want[i]]<re)
			  re=dis[want[i]];
		}		
		cout<<re<<endl;
		}
			
	}
	return 0;
}



