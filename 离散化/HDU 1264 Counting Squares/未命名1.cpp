#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 105
int ax,bx,ay,by,a;
bool xy[N][N];
int i,j,cover;
int main()
{
    while(~scanf("%d%d%d%d",&ax,&ay,&bx,&by))
    {
        if(ax==ay&&ax==bx&&ax==by&&(ax==-1||ax==-2))
        {
            for(i=0,cover=0;i<N;i++) for(j=0;j<N;j++)
                cover+=xy[i][j];
            printf("%d\n",cover);
            if(ax==-2) break;
            memset(xy,0,sizeof(xy));
        }
        else
        {
            if(ax>bx) {a=ax;ax=bx;bx=a;}
            if(ay>by) {a=ay;ay=by;by=a;}
            for(i=ax;i<bx;i++) for(j=ay;j<by;j++) xy[i][j]=1;
        }
    }
    return 0;
}

/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 105
int ax,bx,ay,by,a;
struct TPoint
{
    int x1,x2,y1,y2;
}ply[10*N];
int n,m,yans[10*N],xans[10*N];
bool xy[10*N][10*N];
int i,j,k,i1,i2,j1,j2,cover;
int main()
{
    n=0; m=0;
    while(~scanf("%d%d%d%d",&ax,&ay,&bx,&by))
    {
        if(ax==ay&&ax==bx&&ax==by&&(ax==-1||ax==-2))
        {
            yans[0]=-1; xans[0]=-1;
            sort(yans,yans+m+1);
            sort(xans,xans+m+1);
            memset(xy,0,sizeof(xy));
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=m;j++)
                    if(xans[j]==ply[i].x1) {i1=j;break;}
                for(j=1;j<=m;j++)
                    if(yans[j]==ply[i].y1) {j1=j;break;}
                for(j=1;j<=m;j++)
                    if(xans[j]==ply[i].x2) {i2=j;break;}
                for(j=1;j<=m;j++)
                    if(yans[j]==ply[i].y2) {j2=j;break;}
                for(j=i1;j<i2;j++) for(k=j1;k<j2;k++)
                    xy[j][k]=1;
            }
            for(i=1,cover=0;i<=m;i++) for(j=1;j<=m;j++)
                cover+=xy[i][j]*(xans[i+1]-xans[i])*(yans[j+1]-yans[j]);
            printf("%d\n",cover);
            if(ax==-2) break;
            n=m=0;
        }
        else
        {
            if(ax>bx) {a=ax;ax=bx;bx=a;}
            if(ay>by) {a=ay;ay=by;by=a;}
            n++; ply[n].x1=ax; ply[n].y1=ay; ply[n].x2=bx; ply[n].y2=by;
            yans[++m]=ay; xans[m]=ax;
            yans[++m]=by; xans[m]=bx;
        }
    }
    return 0;
}*/
