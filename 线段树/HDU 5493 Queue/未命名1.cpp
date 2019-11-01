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
		sum[now]=1;  //����㻹û���� 
		return;
	}
	int mid=(le+ri)>>1;
	int ne=now<<1;
	Build(ne,le,mid);
	Build(ne+1,mid+1,ri);
	sum[now]=sum[ne+1]+sum[ne];   //��������ж��ٸ���û���� 
}
void Update(int now,int le,int ri,int pos,int val){
	if(le==ri){
		sum[now]=0;   //�õ㱻ʹ�� 
		re[le]=val;   //����λ�� 
		/*for(int i=1;i<=3;i++)
			 printf(" %d",re[i]);
			 printf("\n");*/
		return;
	}
	int mid=(le+ri)>>1;
	int ne=now<<1;
	if(pos<=sum[ne])    //��������δʹ�õĵ㹻������� 
	  Update(ne,le,mid,pos,val);
	else  //�������������������Ҫ��ȥǰ��������δʹ�õĵ㣬��Ϊ��������ǰ��     
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
			//���ж��ٸ������ڵĸ� ��Ϊǰ����˰�  ������ Ҫn-i 
			int temp=m-node[i].x;  
			if(temp<0)
			{
			   ok=0;
			   break; 
			} 
			//tempָ���淽���Node[i].x�˵Ļ���λ������
			// Node[i].xָǰ�淽��Ļ�λ�����ģ�
			//Ȼ��2��ѡ��ǰ�� ����С��
			 if(node[i].x<=temp) 
			  //��ǰ��Ԥ��node[i].x��  ���뵽 node[i].x+1λ�� 
			  //������ھ�һֱ�����ƣ������Update��ʵ�� 
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

