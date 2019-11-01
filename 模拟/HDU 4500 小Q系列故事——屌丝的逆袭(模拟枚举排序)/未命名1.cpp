#include<iostream>
#include <algorithm>
using namespace std;
const int N=20+5;
int map[N][N];
struct Node{
	int x,y,va;
}node[N*N],tmp;
int step[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool cmp(Node a,Node b){
	if(a.va==b.va){
		if(a.x==b.x)
		   return a.y<b.y;
		return a.x<b.x;
	}
	return a.va>b.va;
}

int main() 
{ 
    int n,m,len;
    while(cin>>n>>m){
    	if(n==0&&m==0)
    	  break;
    	  for(int i=0;i<n;i++)
    	  for(int j=0;j<m;j++)
    	  	  cin>>map[i][j];
	    len=0;
	    for(int i=0;i<n;i++)
    	  for(int j=0;j<m;j++)
		  {
		  	 tmp.x=i;
		  	 tmp.y=j;
		  	 tmp.va=0;
		  	for(int z=0;z<4;z++){
		  		int a=i+step[z][0];
		  		int b=j+step[z][1];
		  		if(a<0||a>=n||b<0||b>=m)
		  		  continue;
		  		 if(map[i][j]>0){
		  		 	  if(map[a][b]>0){
		  		 	  	   tmp.va-=abs(map[a][b]);
						 }else{
						 	tmp.va+=abs(map[a][b]);
						 }
				   }else{
				   	   if(map[a][b]>0){
		  		 	  	    tmp.va+=abs(map[a][b]);
						 }else{
						 	tmp.va-=abs(map[a][b]);
						 }
				   }
			  }
			  node[len++]=tmp;
		  }
		  sort(node,node+len,cmp);
		  cout<<node[0].x+1<<" "<<node[0].y+1<<" "<<node[0].va<<endl;
	}
    return 0;
}





