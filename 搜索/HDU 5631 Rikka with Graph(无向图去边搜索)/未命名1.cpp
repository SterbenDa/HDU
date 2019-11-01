/*
˼·����Ŀ��˼��һ��n���������ͼ������n+1���ߣ����ж�����ɾ���취��ʹ��ͼ������ͨ
����ɾ��һ����
�ҵ�˼·�ǣ�n���㣬Ҫ��ͨ��������n-1���ߣ��������ɾ��2����ö��ÿһ���ߣ�ɾ������ͨ
�����ԣ�+1������ö����һ���߱�ɾ�����ܲ��ܼ�����ͨ 
*/

  /*
  ��ʱ 
  û���ڽӱ�  ���Ӷ�O��n*n���ĵݹ�
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
int map[N][N];  //��¼����   ��int�����ۼ� 
bool book[N];
int n;
void dfs(int now){   //���� 
	book[now]=1;
	check++;
	for(int i=1;i<=n;i++){     //����ʱ�临�Ӷ�n^2 
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


/*����ÿ�γ�ʼ��vector���飬�Ҿ�˵�ҵĸ��ӶȲ��߰� ����AC��
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
int map[N][N];  //��¼����   ��int�����ۼ� 
bool book[N];
int check; 
int n;
void dfs(int now){   //���� 
	book[now]=1;
	check++;
	for(int i=0;i<ve[now].size();i++){     //�ڽӱ��Ż�  ���Ӷȼ�����O(n*n) 
		if(book[ve[now][i]])
          continue;     
		 if(map[now][ve[now][i]]>0)
		  dfs(ve[now][i]);
	}
}

//��һ��ȫ�ֱ��������жϣ����Ӷȼ���O(n)
//inline bool check(){      //����ͨ 
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
		 	  dfs(1);  //������� 
		 	  if(check==n)   //�ж���ͨͼ���ѵݹ����ǲ���n�� 
		 	   {
		 	   	  re++;
		 	   	  for(int j=i+1;j<n+1;j++){
		 	   	  	    map[node[j].x][node[j].y]--;
		 	   	  	    map[node[j].y][node[j].x]--;
		 	   	  	    memset(book,0,sizeof(book)); 
		 	   	  	    check=0;  
					    dfs(1);  //������� 
					     if(check==n)   //�ж���ͨͼ���ѵݹ����ǲ���n�� 
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



