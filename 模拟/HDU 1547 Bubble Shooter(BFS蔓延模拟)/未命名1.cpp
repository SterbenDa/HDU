/*
��Ŀ��˼�ǣ� ����һ��H*W�ľ���������w����ż����w-1���ַ���
E����գ�a-z����Ĳ�ͬ����ɫ������һ����ʼ����h,w����Ϊ�����ȥ�����ݣ�
�����Χ�����������������Լ����������ŵ�һ��ը�����ʣ�µ�û���Ŷ���
Ҳ������������ж��ٵ����� 
����ע�⣺
���⣺��ʵ��������������Ϸ��������ʼ�ĵ�ͼ���Լ��մ��ȥ�����ݵ�λ�ã�
�����մ�����������������������ڵ���3������������ͬ��ɫ�����ݻ��������
֮��û���붥������ֱ�ӻ�������������Ҳ����������ʵ����������������� 
*/
/*
˼·������ʼ���ݽ��й��ѣ���ǣ�Ȼ��ö�ٶ�����ڵ����ݹ��ѽ���Ⱦɫ��ʣ�µ�
�͸ղű�ը�ļ�Ϊ�������� 
ע�⣺�������ˣ���
��ż�е����ӵ㲢��һ���� ��ͼ������������ķ�����
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
//������ˣ�����Ҫ��ͼ ���е�ʱ���ǽ����
//����ż����ʱ
/*
0 1 1
0 X 1
1 1 1
//������ʱ
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
	    while(!q.empty()){   //���ѷ����������� 
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
		//ע��
		//ע��
		//ע�� 
		//�����3�����������ݱ�ը����������������  
		//- _ -!! ���������Ǵ���ģ�
		//��Ϊ1�� num<3 ��
		//��ôҪ��֮ǰ�ı�������
		//�ҳ��붥������ֱ������������������������ans��
		//all-ans���Ǵ��ˡ���������һ�����������
	   //	������Ϊnum<3�Ļ���ֱ��������Ϳ����ˣ�����ʵ���п��ܣ�
	   //	��ʹ�������������ʼ�ĵ�ͼҲ����һЩ���ݻ�������� 
		 if(re<3)
		   {
		   	 //cout<<0<<endl;
		   	// continue;
		   	//���ＴΪ��������ݲ��ᱬը�����½���ͼ��ʼ��Ϊ0��ö�ٶ���
			   re=0;
			   memset(book,0,sizeof(book)); 
			} 
					
		//���Ѷ�������  ��� 			
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
		 //����ʣ�µ�
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
����������
4 5 4 4
abbbb
abbb
aabcb
aaab
��10
*/
/*
wa��  ����Ҫ���ԣ��� 
*/

