#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n,m,t;
char map[15][15];
int next_step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool ok;
bool book[15][15];
int ex,ey; 
int main(){
    void dfs(int x,int y,int sum);
    int i,j,ax,ay;
    while(cin>>n>>m>>t){
        if(n==0&&m==0&&t==0)
        break;   
        ok=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            book[i][j]=0;
              cin>>map[i][j];
              if(map[i][j]=='S'){
                  ax=i;ay=j;
              }
               if(map[i][j]=='D'){
                  ex=i;ey=j;
              }
        }
         if(n*m<t||(int)(abs(ax-ay)+abs(ex-ey))%2!=t%2){
        	cout<<"NO"<<endl;
        	continue;
        }
        book[ax][ay]=1;
        dfs(ax,ay,0);
        if(ok)
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl; 
    }
    return 0;
}
void dfs(int x,int y,int sum){
    int i;
    if(sum>t||ok)
    return;
    if(map[x][y]=='D'&&sum==t){
        ok=1;
        return;
    }
    if((int)(abs(x-y)+abs(ex-ey))%2!=(t-sum)%2)
       return;
    for(i=0;i<4;i++){
        int a=x+next_step[i][0];
        int b=y+next_step[i][1];
        if(a<0||a>=n||b<0||b>=m||map[a][b]=='X'||book[a][b]==1)
        continue;
        book[a][b]=1;
        dfs(a,b,sum+1);
        if(ok)
        return;
        book[a][b]=0;
    }
}












/* C++   传统DFS做法，没有有效剪枝，超时 
#include <iostream>
#include <string>
using namespace std;
int n,m,t;
char map[15][15];
int next_step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool ok;
bool book[15][15];
int main(){
    void dfs(int x,int y,int sum);
    int i,j,ax,ay;
    while(cin>>n>>m>>t){
        if(n==0&&m==0&&t==0)
        break;
        ok=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            book[i][j]=0;
              cin>>map[i][j];
              if(map[i][j]=='S'){
                  ax=i;ay=j;
              }
        }
        book[ax][ay]=1;
        dfs(ax,ay,0);
        if(ok)
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl; 
    }
    return 0;
}
void dfs(int x,int y,int sum){
    int i;
    if(sum>t||ok)
    return;
    if(map[x][y]=='D'&&sum==t){
        ok=1;
        return;
    }
    for(i=0;i<4;i++){
        int a=x+next_step[i][0];
        int b=y+next_step[i][1];
        if(a<0||a>=n||b<0||b>=m||map[a][b]=='X'||book[a][b]==1)
        continue;
        book[a][b]=1;
        dfs(a,b,sum+1);
        if(ok)
        return;
        book[a][b]=0;
    }
}


*/


/*  C 传统DFS做法，没有有效剪枝，超时 
#include <stdio.h>
int n,m,t;
char map[15][15];
int next_step[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int ok;
int book[15][15];
int main(){
    void dfs(int x,int y,int sum);
    int i,j,ax,ay;
    char s[15];
    while(scanf("%d%d%d",&n,&m,&t)==3){
        if(n==0&&m==0&&t==0)
        break;
        ok=0;
        for(i=0;i<n;i++){
            scanf("%s",s);
        for(j=0;j<m;j++){
            book[i][j]=0;
             map[i][j]=s[j];
              if(map[i][j]=='S'){
                  ax=i;ay=j;
              }
        }
    }
        book[ax][ay]=1;
        dfs(ax,ay,0);
        if(ok)
    printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
void dfs(int x,int y,int sum){
    int i;
    if(sum>t||ok)
    return;
    if(map[x][y]=='D'&&sum==t){
        ok=1;
        return;
    }
    for(i=0;i<4;i++){
        int a=x+next_step[i][0];
        int b=y+next_step[i][1];
        if(a<0||a>=n||b<0||b>=m||map[a][b]=='X'||book[a][b]==1)
        continue;
        book[a][b]=1;
        dfs(a,b,sum+1);
        if(ok)
        return;
        book[a][b]=0;
    }
}
*/
