#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int N=1e5+10;
struct Node{
	int h,x;
}node[N];
int re[N],sum[N*4];
bool cmp(Node a,Node b){
	return a.h<b.h;
}
void Build(int now,int le,int ri){
	if(le==ri)
	{
		sum[now]=1;  //这个点还没被用 
		return;
	}
	int mid=(le+ri)>>1;
	int ne=now<<1;
	Build(ne,le,mid);
	Build(ne+1,mid+1,ri);
	sum[now]=sum[ne+1]+sum[ne];   //这段区间有多少个点没被用 
}
void Update(int now,int le,int ri,int pos,int val){
	if(le==ri){
		sum[now]=0;   //该点被使用 
		re[le]=val;   //插入位置 
		/*for(int i=1;i<=3;i++)
			 printf(" %d",re[i]);
			 printf("\n");*/
		return;
	}
	int mid=(le+ri)>>1;
	int ne=now<<1;
	if(pos<=sum[ne])    //这个区间段未使用的点够，则进入 
	  Update(ne,le,mid,pos,val);
	else  //不够，则进入右子树，要减去前面左子树未使用的点，因为左子树在前面     
	  Update(ne+1,mid+1,ri,pos-sum[ne],val); 
	sum[now]=sum[ne+1]+sum[ne];
}
int main(){
	int t,i,n,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++){
		bool ok=1;
	//	memset(sum,0,sizeof(sum));
	//	memset(re,0,sizeof(re));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		scanf("%d%d",&node[i].h,&node[i].x);
		Build(1,1,n);
		sort(node+1,node+n+1,cmp);
		for(i=1;i<=n;i++){
			int m=n-i;   
			//还有多少个比现在的高 因为前面的人矮  不能算 要n-i 
			int temp=m-node[i].x;  
			if(temp<0)
			{
			   ok=0;
			   break; 
			} 
			//temp指后面方向高Node[i].x人的话的位置在哪
			// Node[i].x指前面方向的话位置在哪；
			//然后2个选靠前的 即更小的
			 if(node[i].x<=temp) 
			  //在前面预留node[i].x人  插入到 node[i].x+1位置 
			  //如果存在就一直往后推，这个在Update里实现 
			 	Update(1,1,n,node[i].x+1,node[i].h);
			 else
			 	Update(1,1,n,temp+1,node[i].h);
		} 
		printf("Case #%d:",j);
		if(ok){
			for(i=1;i<=n;i++)
			 printf(" %d",re[i]);
			 printf("\n");
		}
		else
		printf(" impossible\n");
	}
	return 0;
}

/*
99
8
1 0
2 3
3 1
4 2
5 3
6 2
7 1
8 0
*/

