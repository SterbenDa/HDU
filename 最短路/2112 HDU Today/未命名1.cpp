#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
map<string ,int > SS;
int mapp[160][160];
void init(){
    for(int i=0; i<=150; i++)
        for(int j=0; j<=150; j++)
            mapp[i][j]=99999999;
    SS.clear();
}
int main(){
    int n;
    while(scanf("%d",&n)&&n+1){
        init();
        string s,e;
        cin >> s>>e;
        int num = 1;
        for(int i = 0;i<n;i++){
            string x,y;
			int t;
            cin >>x>>y>>t;
            int xx,yy;
            if(SS[x]) {
                xx = SS[x];
            } else {
                SS[x] = xx = num++;
            }
            if(SS[y]) {
                yy = SS[y];
            } else {
                SS[y] = yy = num++;
            }
            if(mapp[xx][yy]>t){
                mapp[xx][yy] = mapp[yy][xx] = t;
            }
        }
        if(s==e) {
            puts("0");
        } else {
            for(int i=1; i<num; i++)
                for(int t=1; t<num; t++)
                    for(int k=1; k<num; k++)
                        if(mapp[t][i]+mapp[i][k]<mapp[t][k])
                            mapp[t][k]=mapp[t][i]+mapp[i][k];
            if(mapp[SS[s]][SS[e]] == 99999999) {
                puts("-1");
            } else {
                printf("%d\n",mapp[SS[s]][SS[e]]);
            }
        }
    }
}
/*
#include<cstdio>
#include <iostream>
#include<vector>
#include <map>
#include <string.h>
#include<deque>  //双向队列  push_back()  push_front()等 
#define MAXV 20010
#define INF 1000000000 //此处建议不要过大或过小,过大易导致运算时溢出,过小可能会被判定为真正的距离
 using namespace std;
struct Edge{
	int v; //边权
	int to; //连接的点
};
vector<Edge> e[MAXV]; //由于一般情况下E<<V*V,故在此选用了vector动态数组存储,也可以使用链表存储
int dist[MAXV]; //存储到原点0的距离,可以开二维数组存储每对节点之间的距离
int cnt[MAXV]; //记录入队次数,超过V则退出
deque<int> buff; //队列,用于存储在SPFA算法中的需要松弛的节点
bool done[MAXV]; //用于判断该节点是否已经在队列中
bool book[200][200];
int V; //节点数
int E; //边数
 
bool spfa(const int st){ //返回值:TRUE为找到最短路返回,FALSE表示出现负环退出
	for(int i=1;i<=V;i++){ //初始化:将除了原点st的距离外的所有点到st的距离均赋上一个极大值
		if(i==st){
			dist[st]=0; //原点距离为0;
			continue;
		}
		dist[i]=INF; //非原点距离无穷大
	}
	buff.push_back(st); //原点入队
	done[st]=1; //标记原点已经入队
	cnt[st]=1; //修改入队次数为1
	while(!buff.empty()){ //队列非空,需要继续松弛
		int tmp=buff.front(); //取出队首元素
		buff.pop_front();//弹出队首节点
		for(int i=0;i<(int)e[tmp].size();i++){ //枚举该边连接的每一条边
			Edge *t=&e[tmp][i]; //由于vector的寻址速度较慢,故在此进行一次优化
			if(dist[tmp]+(*t).v<dist[(*t).to]){ //更改后距离更短,进行松弛操作
				dist[(*t).to]=dist[tmp]+(*t).v; //更改边权值
				if(!done[(*t).to]){ //没有入队,则将其入队
			if(!buff.empty()){
				//注意这里比较的是front tmp已经出队了 
				if(dist[(*t).to]>dist[buff.front()])
					buff.push_back((*t).to); //将节点压入队列
					else
					buff.push_front((*t).to);
					}
					else
					buff.push_front((*t).to);	 
					done[(*t).to]=1; //标记节点已经入队
					cnt[(*t).to]+=1; //节点入队次数自增
					if(cnt[(*t).to]>V){ //已经超过V次,出现负环
						while(!buff.empty())buff.pop_front(); //清空队列,释放内存
						return false; //返回FALSE
					}
				}
			}
		}
		//之前的tmo刚出队  执行完前面才取消标记 
		done[tmp]=0;//将队首节点标记为未入队
	}
	return true; //返回TRUE
} //算法结束
 
int main(){ //主函数
    int n,i,nn,t;
    map<string,int> ma;
    Edge edge;
	char start[40],end[40];
	char s1[40],s2[40];
	while(scanf("%d",&n)==1) {//读入点数和边数
	memset(book,0,sizeof(book));
	   if(n==-1)
		break;
	   scanf("%s%s",start,end);
	   nn=1;
		for(i=0;i<n;i++){
			scanf("%s%s%d",s1,s2,&t);
		   	if(ma[s1]==0)
		   	 ma[s1]=nn++;
		    if(ma[s2]==0)
		    ma[s2]=nn++;
		    if(book[ma[s1]][ma[s2]]==1)
		     continue;
		     book[ma[s1]][ma[s2]]=1;
		    book[ma[s2]][ma[s1]]=1;
		   edge.to=ma[s2];
		   edge.v=t;
	    e[ma[s1]].push_back(edge);	
		  edge.to=ma[s1];
	    e[ma[s2]].push_back(edge);
	}   
//	map<string,int>::iterator it;
 // for(it=ma.begin();it!=ma.end();++it)
 //  cout<<"key:"<<it->first<<"  value:"<<it->second<<endl;
	  V=nn-1;
	  E=n;
	 // cout<<V<<" "<<E<<endl;
	//输入源点 
	if(!spfa(ma[start]))//出现负环
		printf("-1\n");
	else//存在最短路
		printf("%d\n",dist[ma[end]]); 
	for(int i=1;i<=V;i++){  //初始化 
	   	cnt[i]=0;
	    done[i]=0;
	    e[i].clear(); //清空vector数组 
	   }
	   ma.clear();
}
	return 0;
}
*/


/*wawawa
#include <iostream>
#include <cstdio>
#include <string.h>
#include <map>
using namespace std;
const int M=10010*2;
const int INF=99999999;
int w[M],from[M],to[M];
int dis[M/2],book[M/2];
int main(){
	int n,i,t,nn,mm,k;
	map<string,int> ma;
	char start[40],end[40];
	char s1[40],s2[40];
	while(scanf("%d",&n)==1){
		if(n==-1)
		break;
		mm=1;
		nn=1;
		scanf("%s%s",start,end);
		if(strcmp(start,end)==0)
		{
			for(i=0;i<n;i++)
			scanf("%s%s%d",s1,s2,&t);
			printf("0\n");
			continue;
		}
		for(i=0;i<n;i++){
			scanf("%s%s%d",s1,s2,&t);
		   	if(ma[s1]==0)
		   	 ma[s1]=nn++;
		    if(ma[s2]==0)
		    ma[s2]=nn++;
	    	from[mm]=ma[s1];
	    	to[mm]=ma[s2];
	    	w[mm]=t;
	    	mm++;
	    	from[mm]=ma[s2];
	    	to[mm]=ma[s1];
	    	w[mm]=t;
	      	mm++;
		}		
		for(i=1;i<nn;i++)
		  dis[i]=INF;
		dis[ma[start]]=0;
		//bellman-ford
		for(k=1;k<=nn-1;k++){
			for(i=1;i<nn;i++)
			 book[i]=dis[i];
			
			 for(i=1;i<mm;i++)
			 	if(dis[to[i]]>dis[from[i]]+w[i])
			 	  dis[to[i]]=dis[from[i]]+w[i];
			 	 
			 bool check=0;			 	  
				   for(i=1;i<nn;i++)
			 	    if(book[i]!=dis[i]){
			 	    	check=1;
			 	    	break;
					 }
					 if(check==0)
					 break;
		}
		bool flag=0;
		 for(i=1;i<mm;i++){
		 	if(dis[to[i]]>dis[from[i]]+w[i])
		 	  {
		 	  	flag=1;
		 	  	break;
			   }
		 }
		if(dis[ma[end]]==INF||flag)
		 printf("-1\n");
		 else
		  printf("%d\n",dis[ma[end]]);
		ma.clear();
	}
	return 0;
}*/

