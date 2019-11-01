/*
思路：题目意思是一个n个点的无向图，给你n+1条边，求有多少种删除办法，使得图还能连通
至少删除一条边
我的思路是，n个点，要连通，至少是n-1条边，所以最多删除2条，枚举每一条边，删除求连通
若可以，+1，尝试枚举下一条边被删，看能不能继续连通 
*/

  /*
  超时 
  没用邻接表  复杂度O（n*n）的递归
  */
  /*
#include<iostream>
#include <string.h>
using namespace std;
const int N=100+5;
struct Node{
	int x,y;
}node[N];
int check; 
int map[N][N];  //记录边数   用int可以累加 
bool book[N];
int n;
void dfs(int now){   //深搜 
	book[now]=1;
	check++;
	for(int i=1;i<=n;i++){     //这里时间复杂度n^2 
		if(book[i])
          continue;
		 if(map[now][i]>0)
		  dfs(i);
	}
}
int main()
{  
    int t,re;
	cin>>t;
	while(t--){
		  re=0;
		 cin>>n;
		 memset(map,0,sizeof(map));
		 for(int i=0;i<n+1;i++){
		 	 cin>>node[i].x>>node[i].y;
		 	 map[node[i].x][node[i].y]++;
		 	 map[node[i].y][node[i].x]++;
		 }
		 for(int i=0;i<n+1;i++){
		 	  map[node[i].x][node[i].y]--;
		 	  map[node[i].y][node[i].x]--;
		 	  memset(book,0,sizeof(book)); 
		 	  check=0;
		 	  dfs(1);
		 	  if(check==n)
		 	   {
		 	   	  re++;
		 	   	  for(int j=i+1;j<n+1;j++){
		 	   	  	    map[node[j].x][node[j].y]--;
		 	   	  	    map[node[j].y][node[j].x]--;
		 	   	  	    memset(book,0,sizeof(book)); 
		 	   	  	    check=0;
					    dfs(1);
					     if(check==n)
					     	 re++;
					    map[node[j].x][node[j].y]++;
					    map[node[j].y][node[j].x]++;
					  }
		 	   	  
				}
				map[node[i].x][node[i].y]++;
		 	  map[node[i].y][node[i].x]++;
		 }
		 cout<<re<<endl;
	} 
	return 0;
}
*/


/*忘了每次初始化vector数组，我就说我的复杂度不高啊 终于AC了
16772534 2016-04-04 22:34:00 Accepted 5631 78MS 1784K 3734 B C++ Sterben 
*/

#include<iostream>
#include <vector> 
#include <cstdio>
#include <string.h>
using namespace std;
const int N=100+5;
struct Node{
	int x,y;
}node[N];
vector<int> ve[N];
int map[N][N];  //记录边数   用int可以累加 
bool book[N];
int check; 
int n;
void dfs(int now){   //深搜 
	book[now]=1;
	check++;
	for(int i=0;i<ve[now].size();i++){     //邻接表优化  复杂度减少了O(n*n) 
		if(book[ve[now][i]])
          continue;     
		 if(map[now][ve[now][i]]>0)
		  dfs(ve[now][i]);
	}
}

//用一个全局变量减少判断，复杂度减少O(n)
//inline bool check(){      //求连通 
//	for(int i=1;i<=n;i++)
//	  if(!book[i])
//	     return false;
 //   return true;
//}


int main()
{  
    int t,re;
	scanf("%d",&t);
	while(t--){
		  re=0;
		 scanf("%d",&n);
		 memset(map,0,sizeof(map));
		 for(int i=1;i<=n;i++){
		  ve[i].clear();
	}
		 for(int i=0;i<n+1;i++){
		 	scanf("%d%d",&node[i].x,&node[i].y);
		 	// cin>>node[i].x>>node[i].y;
		 	 ve[node[i].x].push_back(node[i].y);
		 	  ve[node[i].y].push_back(node[i].x);
		 	 map[node[i].x][node[i].y]++;
		 	 map[node[i].y][node[i].x]++;
		 }
		 memset(book,0,sizeof(book)); 
		check=0;
		 dfs(1);
		 if(check!=n){
		 	printf("0\n");
		 	continue;
		 }
		 for(int i=0;i<n+1;i++){
		 	  map[node[i].x][node[i].y]--;
		 	  map[node[i].y][node[i].x]--;
		 	  memset(book,0,sizeof(book)); 
		 	  check=0;
		 	  dfs(1);  //深搜起点 
		 	  if(check==n)   //判断连通图深搜递归标记是不是n个 
		 	   {
		 	   	  re++;
		 	   	  for(int j=i+1;j<n+1;j++){
		 	   	  	    map[node[j].x][node[j].y]--;
		 	   	  	    map[node[j].y][node[j].x]--;
		 	   	  	    memset(book,0,sizeof(book)); 
		 	   	  	    check=0;  
					    dfs(1);  //深搜起点 
					     if(check==n)   //判断连通图深搜递归标记是不是n个 
					     	 re++;
					    map[node[j].x][node[j].y]++;
					    map[node[j].y][node[j].x]++;
					  }
		 	   	  
				}
				map[node[i].x][node[i].y]++;
		 	     map[node[i].y][node[i].x]++;
		 }
		 //cout<<re<<endl;
		 printf("%d\n",re);
	} 
	return 0;
}



