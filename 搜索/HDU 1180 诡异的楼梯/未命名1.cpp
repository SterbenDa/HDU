







//改用数组模拟队列后  没发现内存超出 但是超时  ！！我的去
/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <string>
using namespace std;
const int N=20+5;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//               0上    1下   2左    3右
char map[N][N];
bool book[N][N];
int n,m,head,tail;
struct Node{ 
    int x,y,sum;
}tmp,node;
Node q[N*N]; 
int main(){
    int i,j;
    char c[N];
    bool ok;
    while(scanf("%d%d",&n,&m)==2){
         tail=head=0;
        for(i=0;i<n;i++){
            scanf("%s",c);
            for(j=0;j<m;j++)
            {
                map[i][j]=c[j];
                book[i][j]=0;
                if(map[i][j]=='S'){
                    node.x=i;
                    node.y=j;
                    node.sum=0;
                    book[i][j]=1;
                }
            }
        }
        q[tail++]=node;
        while(head<tail){
            node=q[head];
          //  printf("%d %d %d\n",node.x, node.y,node.sum);
            head++;
            if(map[node.x][node.y]=='T')           
                break;           
            for(i=0;i<4;i++){
                int a=node.x+step[i][0];
                int b=node.y+step[i][1];
                if(a<0||a>=n||b<0||b>=m||book[a][b]==1||map[a][b]=='*')
                continue;
                if(map[a][b]=='|'){
                    if((i<=1&&(node.sum)%2==0)||                                                                
					 (i>=2&&(node.sum)%2==1))           
                       {
                       	tmp.sum=node.sum+1;
                       	tmp.x=a+step[i][0];
                        tmp.y=b+step[i][1];
						}                 
                   else
                    {
                       tmp.sum=node.sum+1;
                       tmp.x=node.x;
                       tmp.y=node.y;
                       q[tail++]=tmp;
                       continue;
					}
                }
                else if(map[a][b]=='-'){
                    if((i<=1&&(node.sum)%2==1)                      
                 ||(i>=2&&(node.sum)%2==0)){
                 	 tmp.sum=node.sum+1;
                 	 	tmp.x=a+step[i][0];
                        tmp.y=b+step[i][1];
				 }                    
                    else
                    {
                       tmp.sum=node.sum+1;
                       tmp.x=node.x;
                       tmp.y=node.y;
                       q[tail++]=tmp;
                       continue;
					}
                }
                else{
                    tmp.x=a;
                    tmp.y=b;
                    tmp.sum=node.sum+1;
                }                
                book[tmp.x][tmp.y]=1;
                q[tail++]=tmp;
            }
        }    
         printf("%d\n",node.sum);
    }
    return 0;
}  
*/






#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#include <string>
using namespace std;
const int N=20+5;
int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//               0上    1下   2左    3右
char map[N][N];
bool book[N][N];
int n,m;
struct Node{ 
    int x,y,sum;
}tmp,node;
queue<Node> q;
int main(){
    int i,j;
    char c[N];
    bool ok;
    while(scanf("%d%d",&n,&m)==2){
        while(!q.empty()) q.pop();
        for(i=0;i<n;i++){
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            {
                book[i][j]=0;
                if(map[i][j]=='S'){
                    node.x=i;
                    node.y=j;
                    node.sum=0;
                    book[i][j]=1;
                }
            }
        }
        q.push(node);
        while(!q.empty()){
            node=q.front();
          //  printf("%d %d %d\n",node.x, node.y,node.sum);
            q.pop();
            if(map[node.x][node.y]=='T')           
                break;          
            for(i=0;i<4;i++){
                int a=node.x+step[i][0];
                int b=node.y+step[i][1];
                if(a<0||a>=n||b<0||b>=m||book[a][b]==1||map[a][b]=='*')
                continue;
                if(map[a][b]=='|'){
                    if((i<=1&&(node.sum)%2==0)||                                                                
					 (i>=2&&(node.sum)%2==1))           
                    {                    
                       	a=a+step[i][0];
                        b=b+step[i][1];
                        //判断梯子对面走过没  （重点  坑死我了） 
                        if(a<0||a>=n||b<0||b>=m||book[a][b]==1||map[a][b]=='*')
                         continue;
                        tmp.x=a;
                        tmp.y=b;
                        tmp.sum=node.sum+1;
					}                 
                   else
                    {
                       tmp.sum=node.sum+1;
                       tmp.x=node.x;
                       tmp.y=node.y;
					}
                }
                else if(map[a][b]=='-'){
                    if((i<=1&&(node.sum)%2==1)                      
                 ||(i>=2&&(node.sum)%2==0)){
                 		a=a+step[i][0];
                        b=b+step[i][1];
                        //判断梯子对面走过没  （重点  坑死我了） 
                        if(a<0||a>=n||b<0||b>=m||book[a][b]==1||map[a][b]=='*')
                         continue;
                        tmp.x=a;
                        tmp.y=b;
                        tmp.sum=node.sum+1;
				 }                    
                    else
                    {
                       tmp.sum=node.sum+1;
                       tmp.x=node.x;
                       tmp.y=node.y;
					}
                }
                else{
                    tmp.x=a;
                    tmp.y=b;
                    tmp.sum=node.sum+1;
                }                
                book[tmp.x][tmp.y]=1;
                q.push(tmp);
            }
        }    
         printf("%d\n",node.sum);
    }
    return 0;
}  
  

