#include <iostream>
#include <cstdio>
using namespace std;
const int N=50000+5;
struct Node{
	int l,r,num,sum;
}node[N*3];
//int where[N];
void Init(int now,int le,int ri){
		node[now].l=le;
		node[now].r=ri;
	if(le==ri){
		scanf("%d",&node[now].num);
		node[now].sum=node[now].num;
	//	where[le]=now;
     	return;
	}
	int mid=(le+ri)>>1,next=now<<1;
	Init(next,le,mid);
	Init(next+1,mid+1,ri);   
	node[now].sum=node[next].sum+node[next+1].sum;
}
void Add(int now,int a ,int b){
	int next=now<<1,mid=(node[now].l+node[now].r)>>1;
	if(node[now].l==node[now].r&&node[now].l==a)
	{
		node[now].num+=b;
		node[now].sum+=b;
		return;
	}
	if(a<=mid)
	  Add(next,a,b);
	  else 
	  Add(next+1,a,b);
	node[now].sum=node[next].sum+node[next+1].sum;
}

int GetSum(int now,int le,int ri){
	int next=now<<1,mid=(node[now].l+node[now].r)>>1;
	if(node[now].l==le&&node[now].r==ri)
		return node[now].sum;
	if(ri<=mid)
	return GetSum(next,le,ri);
	else if(le>mid)
	  return GetSum(next+1,le,ri);
	  else 
	  return GetSum(next,le,mid)+GetSum(next+1,mid+1,ri);
}
int main(){
	int t,n,a,b;
	char s[8];
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		Init(1,1,n);
		printf("Case %d:\n",i);
		while(scanf("%s",s)==1){
			if(s[0]=='E')
			   break;
			scanf("%d%d",&a,&b);		
			if(s[0]=='A')
			    Add(1,a,b);
			//node[where[a]]+=b;
			else if(s[0]=='S')
				Add(1,a,-b);
			else if(s[0]=='Q')
				printf("%d\n",GetSum(1,a,b));
		}
	}
	return 0;
}
