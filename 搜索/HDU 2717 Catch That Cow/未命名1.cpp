/*����AC��  */
//���˱��˵Ĵ��� ��ʵ�����ýṹ��  ������������Ƿ������  ����N������ô��
//N=100000+10�͹��� ��Ϊ̫��Ҳ�������Ǵ�
//�Ż��ռ���Ըĳ�  N=100000+10   
//����֪��ÿ�β鳤����Ҫʱ�䲻�� Ҫ�Ļ��ĳɽṹ�����ʡʱ�� 
#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
const int N=100000*6+10;
queue<int> q;
bool book[N];
int main(){
	int a,b,re,tmp,i;
	while(scanf("%d%d",&a,&b)==2){
		while(!q.empty()) q.pop();
		re=0;
		memset(book,0,sizeof(book));
		book[a]=1;
		 q.push(a);
		 while(!q.empty()){
		 	int len=q.size();
		 	for(i=0;i<len;i++){
		 	   tmp=q.front();
		 	   	q.pop();	
		 	   if(tmp==b)
		 	     goto AC;
				  if(!book[tmp+1]){
				     book[tmp+1]=1;
				  		q.push(tmp+1);
				  }   
			 if(tmp>0&&!book[tmp-1]){
				     book[tmp-1]=1;
				  	q.push(tmp-1);
				  }
			if(tmp*2<N&&!book[tmp*2]){
				     book[tmp*2]=1;
				  	q.push(tmp*2);
				  }	 	 		
			 }	 
			 re++;	 	
		 }
		 AC:;
		  printf("%d\n",re);
	}
	return 0;
}


/*�������ڴ�
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int N=100000;
struct Node{
	int v,t;
}node,tmp;
queue<Node> q;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)==2){
		while(!q.empty()) q.pop();
		 node.v=a;
		 node.t=0;
		 q.push(node);
		 while(!q.empty()){
		 	node=q.front();
		 	q.pop();
		 	if(node.v==b)
		 	break;
		 	tmp.v=node.v+1;
		 	tmp.t=node.t+1;
		 	q.push(tmp);
		 	tmp.v=node.v-1;
		 	tmp.t=node.t+1;
		 	q.push(tmp);
		 	tmp.v=node.v*2;
		 	tmp.t=node.t+1;
		 	q.push(tmp);
		 }
		  printf("%d\n",node.t);
	}
	return 0;
}
*/

/*��ˮһ�� ˮ����  TLE
#include <iostream>
#include <cstdio>
using namespace std;
const int N=100000;
int b,re;
void dfs(int now,int sum){
	if(sum>re)
	return;
	else if(now==b){
		if(sum<re)
		  re=sum;
		  return;
	}
	dfs(now+1,sum+1);
	dfs(now-1,sum+1);
	dfs(now*2,sum+1);
}
int main(){
	int a;
	while(scanf("%d%d",&a,&b)==2){
		  re=0;
		  int tmp=a;
		  while(tmp<b){
		  	  tmp*=2;
		  	  re++;
		  }
		  re+=tmp-b;
		  dfs(a,0);
		  printf("%d\n",re);
	}
	return 0;
}
*/
