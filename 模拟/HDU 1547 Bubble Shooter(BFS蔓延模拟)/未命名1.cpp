/*
题目意思是： 给你一个H*W的矩阵，奇数行w个，偶数行w-1个字符，
E代表空，a-z代表的不同的颜色，给你一个起始坐标h,w，作为新射进去的泡泡，
如果周围连着有三个（算上自己），则连着的一起爆炸，如果剩下的没连着顶行
也会掉下来，问有多少掉下来 
网上注解：
题意：其实就是泡泡龙的游戏，给你起始的地图，以及刚打出去的泡泡的位置，
如果与刚打出的泡泡相连的泡泡数大于等于3，则相连的相同颜色的泡泡会掉下来，
之后，没有与顶层泡泡直接或间接相连的泡泡也会掉下来。问掉下来的泡泡总数。 
*/
/*
思路：对起始泡泡进行广搜，标记，然后枚举顶层存在的泡泡广搜进行染色，剩下的
和刚才爆炸的即为掉下来的 
注意：坑死我了！！
奇偶行的连接点并不一样啊 看图！！！和下面的分析！
*/
#include<iostream>
#include <string.h>
#include <queue>
using namespace std;
const int N=100+5;
char map[N][N];
bool book[N][N];
int re;
struct Node{
	int x,y;
}node,tmp;
queue<Node> q;
//方向错了！这里要看图 排列的时候是交叉的
//例如偶数行时
/*
0 1 1
0 X 1
1 1 1
//奇数行时
1 1 0
1 X 1
1 1 0
*/
int step2[6][2]={{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}}; //odd
int step1[6][2]={{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}};
int main()
{  
    int n,m,x,y;
    while(cin>>n>>m>>x>>y){
    	re=0;
    	while(!q.empty())  q.pop();
    	memset(book,0,sizeof(book));
    	for(int i=0;i<n;i++){
    		cin>>map[i];
    		if((i+1)%2==0)
    		  map[i][m-1]='E';
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
			cout<<map[i][j];
			cout<<endl;
		}*/		   
		   	x--;
		   	y--;
	    node.x=x;
	    node.y=y;
	    book[x][y]=1;
	    re++;
	    q.push(node);
	    while(!q.empty()){   //广搜发射的起点泡泡 
	    	tmp=q.front();
	    	q.pop();
	    	for(int i=0;i<6;i++){
	    		int a,b;
	    		if((tmp.x+1)%2==1){
	    			a=tmp.x+step1[i][0];  
	    		     b=tmp.y+step1[i][1];
				}
	    	   else{
	    	     	 a=tmp.x+step2[i][0];  
	    		    b=tmp.y+step2[i][1];
			   }
	    		if(a<0||b<0||a>=n||b>=m)
	    		 continue;
			    if(book[a][b]||map[a][b]=='E')
				  continue;
				  if(map[a][b]!=map[tmp.x][tmp.y])
				   continue;
				   re++;
				  node.x=a;
				  node.y=b;
				  book[a][b]=1;
				  q.push(node);		
			}
		}
		//注意
		//注意
		//注意 
		//如果有3个或以上泡泡爆炸，则继续，否则结束  
		//- _ -!! 这种做法是错误的？
		//因为1） num<3 。
		//那么要将之前的标记清除，
		//找出与顶层泡泡直接相连或间接相连的泡泡总数ans，
		//all-ans就是答案了。这里解决了一个特殊情况，
	   //	本来以为num<3的话，直接输出０就可以了，但其实很有可能，
	   //	即使ｎｕｍ＜３，但起始的地图也会有一些泡泡会掉下来。 
		 if(re<3)
		   {
		   	 //cout<<0<<endl;
		   	// continue;
		   	//这里即为发射的泡泡不会爆炸，重新将地图初始化为0，枚举顶层
			   re=0;
			   memset(book,0,sizeof(book)); 
			} 
					
		//广搜顶层泡泡  标记 			
		  for(int i=0;i<m;i++){
		 	 if(book[0][i]!=1&&map[0][i]!='E')
		 	   {
		 	      book[0][i]=1;
				   node.x=0;
				   node.y=i;
				   q.push(node);	
				   while(!q.empty()){
				   	tmp=q.front();
				   	q.pop();
				   	int a,b;
				   	for(int j=0;j<6;j++){
				   			if((tmp.x+1)%2==1){
	    	    	a=tmp.x+step1[j][0];  
	    		     b=tmp.y+step1[j][1];
				}
	    	   else{
	    	     	a=tmp.x+step2[j][0];  
	    		    b=tmp.y+step2[j][1];
			   }
				if(a>=n||a<0||b<0||b>=m)
				   			continue;				
			    if(book[a][b]||map[a][b]=='E')
				    continue;  
				    book[a][b]=1;
					node.x=a;
					node.y=b;
					q.push(node); 
					}
				   
				   }
			  }
		 } 
		 //查找剩下的
		 for(int i=0;i<n;i++){
		 	for(int j=0;j<m;j++){
		 		  if(book[i][j]==0&&map[i][j]!='E')
		 		  re++;
			 }
		 } 	
		 cout<<re<<endl;
		
	}
	return 0;
}
/*
随便给组数据
4 5 4 4
abbbb
abbb
aabcb
aaab
答案10
*/
/*
wa了  方向要看对！！ 
*/

