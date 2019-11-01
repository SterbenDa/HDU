#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=1000+5;
int pre[N];
bool book[N];
inline void init(int n){
	for(int i=1;i<=n;i++)
	 pre[i]=i;
}
inline int find(int x){
	int r=x;
	while(pre[r]!=r)      //找到根路径 
	  r=pre[r];
	int i=x,j;
	while(i!=r){   //路径压缩 
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

inline void join(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
	//	if(fx>fy)
	//	   pre[fy]=fx;
    //	else
		 pre[fx]=fy;
	}
	    
}
void dfs(int n){
	 book[n]=1;
	 if(pre[n]!=n)
	   dfs(pre[n]);
}
int main(){ 
    int n,m,re,a,b;
    while(scanf("%d",&n)==1){
    	if(n==0)
    	 break;
    	 re=0;
    	init(n);
    	memset(book,0,sizeof(book));
    	scanf("%d",&m);
    	 for(int i=0;i<m;i++){
    	 	scanf("%d%d",&a,&b);
    	 	join(a,b);
		 }
		// for(int i=1;i<=n;i++)
	  //   cout<<i<<"---"<<pre[i]<<endl;
		 for(int i=1;i<=n;i++){
		 	 if(pre[i]==i) 
		 	    re++;			   	 
		 }
	   printf("%d\n",re-1);
	}
	return 0;
}
/*网上答案更简单 不用压缩路径  结果有几个根节点是自己就是几个 结果-1就行 */


