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
#include<deque>  //˫�����  push_back()  push_front()�� 
#define MAXV 20010
#define INF 1000000000 //�˴����鲻Ҫ������С,�����׵�������ʱ���,��С���ܻᱻ�ж�Ϊ�����ľ���
 using namespace std;
struct Edge{
	int v; //��Ȩ
	int to; //���ӵĵ�
};
vector<Edge> e[MAXV]; //����һ�������E<<V*V,���ڴ�ѡ����vector��̬����洢,Ҳ����ʹ������洢
int dist[MAXV]; //�洢��ԭ��0�ľ���,���Կ���ά����洢ÿ�Խڵ�֮��ľ���
int cnt[MAXV]; //��¼��Ӵ���,����V���˳�
deque<int> buff; //����,���ڴ洢��SPFA�㷨�е���Ҫ�ɳڵĽڵ�
bool done[MAXV]; //�����жϸýڵ��Ƿ��Ѿ��ڶ�����
bool book[200][200];
int V; //�ڵ���
int E; //����
 
bool spfa(const int st){ //����ֵ:TRUEΪ�ҵ����·����,FALSE��ʾ���ָ����˳�
	for(int i=1;i<=V;i++){ //��ʼ��:������ԭ��st�ľ���������е㵽st�ľ��������һ������ֵ
		if(i==st){
			dist[st]=0; //ԭ�����Ϊ0;
			continue;
		}
		dist[i]=INF; //��ԭ����������
	}
	buff.push_back(st); //ԭ�����
	done[st]=1; //���ԭ���Ѿ����
	cnt[st]=1; //�޸���Ӵ���Ϊ1
	while(!buff.empty()){ //���зǿ�,��Ҫ�����ɳ�
		int tmp=buff.front(); //ȡ������Ԫ��
		buff.pop_front();//�������׽ڵ�
		for(int i=0;i<(int)e[tmp].size();i++){ //ö�ٸñ����ӵ�ÿһ����
			Edge *t=&e[tmp][i]; //����vector��Ѱַ�ٶȽ���,���ڴ˽���һ���Ż�
			if(dist[tmp]+(*t).v<dist[(*t).to]){ //���ĺ�������,�����ɳڲ���
				dist[(*t).to]=dist[tmp]+(*t).v; //���ı�Ȩֵ
				if(!done[(*t).to]){ //û�����,�������
			if(!buff.empty()){
				//ע������Ƚϵ���front tmp�Ѿ������� 
				if(dist[(*t).to]>dist[buff.front()])
					buff.push_back((*t).to); //���ڵ�ѹ�����
					else
					buff.push_front((*t).to);
					}
					else
					buff.push_front((*t).to);	 
					done[(*t).to]=1; //��ǽڵ��Ѿ����
					cnt[(*t).to]+=1; //�ڵ���Ӵ�������
					if(cnt[(*t).to]>V){ //�Ѿ�����V��,���ָ���
						while(!buff.empty())buff.pop_front(); //��ն���,�ͷ��ڴ�
						return false; //����FALSE
					}
				}
			}
		}
		//֮ǰ��tmo�ճ���  ִ����ǰ���ȡ����� 
		done[tmp]=0;//�����׽ڵ���Ϊδ���
	}
	return true; //����TRUE
} //�㷨����
 
int main(){ //������
    int n,i,nn,t;
    map<string,int> ma;
    Edge edge;
	char start[40],end[40];
	char s1[40],s2[40];
	while(scanf("%d",&n)==1) {//��������ͱ���
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
	//����Դ�� 
	if(!spfa(ma[start]))//���ָ���
		printf("-1\n");
	else//�������·
		printf("%d\n",dist[ma[end]]); 
	for(int i=1;i<=V;i++){  //��ʼ�� 
	   	cnt[i]=0;
	    done[i]=0;
	    e[i].clear(); //���vector���� 
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

