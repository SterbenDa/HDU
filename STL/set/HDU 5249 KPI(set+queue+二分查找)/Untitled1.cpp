/*��ʱ 
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=10000+10;
int a[N],b[N];
int len,now;
string s;
int c;
int main(){
	int n,t=1;
	while(cin>>n){
		len=0;
		now=0;
	    cout<<"Case #"<<t<<":"<<endl;
	    while(n--){
	       cin>>s;
		   if(s=="in"){
		       cin>>c;
			   a[len++]=c;  	
		   }else if(s=="out"){
		   	    now++;
		   }else if(s=="query"){
		   	    int ll=0;
				   for(int i=now;i<len;i++){	
					   b[ll++]=a[i];
		   	    }
		   	    sort(b,b+ll);
		        cout<<b[ll/2]<<endl;
		   }
	    }	
	}
	return 0;
}*/

/*��Ϊ����C���Ծ��ܹ� ��ʱ���������� 
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N=10000+10;
int a[N],b[N];
int len,now;
string s;
int c;
int main(){
	int n,t=1;
	while(scanf("%d",&n)==1){
		len=0;
		now=0;
	    printf("Case #%d:\n",t++);
	    while(n--){
	       cin>>s;
		   if(s=="in"){
		       scanf("%d",&c);
			   a[len++]=c;  	
		   }else if(s=="out"){
		   	    now++;
		   }else if(s=="query"){
		   	    int ll=0;
				   for(int i=now;i<len;i++){	
					   b[ll++]=a[i];
		   	    }
		   	    sort(b,b+ll);
		        printf("%d\n",b[ll/2]);
		   }
	    }	
	}
	return 0;
}
*/

/*����ת�� д�ĺܺ�
ԭ����ַ ��http://blog.csdn.net/letterwuyu/article/details/46316599 
*/
/*
ԭ����������ת�صģ� 
�������������2015�ٶ�֮�ǳ���1��4��
����ⲻ��̫�ѵ�ʱ�����������ˣ����������ϴ󾢣���ʵ�Ҵ����ܹ���ȡ��ѵ�ģ�
ԭ���ǣ���һ�������������ݽṹ�ģ�Ȼ��Ͷ������һ�����ֲ��ң����Ǵ���
������һϵ�е����⣺
���ȴ����������ǲ����ô����±�����飬��Ϊ��Ŀ�е������ǿ�ɾ��������������
����Ļ�ʱ�临�Ӷ����൱�ߵģ���Ϊ�������С���룬��Ҫ�ƶ��������ݣ������
β����ӣ���Ҫ����������Ϊ�������е����Ե�Ҫ��ģ����������Ļ����Բ��ƶ�
���ݣ����м���룬�������Ļ����ֲ�����ô�죬û��������һ�����±����鷳��
��������ε���������Ƿ����˶��ֲ��ң�����ֱ�ӱ�����������棬�ҷ��������
�����Ļ���������ֱ�Ӽ�¼ÿ������ǰ���������Ϳ�ʵ�������ܣ�����д���൱
���ģ����Խ��Խû����
����֪���������м�ֵ�����������ö��ֲ��ң�����洢�ķ�����ÿ����һ��������
�ҵ��������������λ�ã����벢�����λ�ÿ�ʼ�����е�ĩβ�������һλ���ķ���
���ˡ�
��ʵ���ǵ�����һ��˼·�����������ά����һ���������������һ�������������
1�����ö������洢������������ģ�����̫�鷳����ûʵ�֣������Ժ���һ��set����
���������������set�����Ƕ���˳��洢�ģ����Բ���Ҳ�Ƕ��ֲ��ҵģ��ⲻ�к���
��ѽ����set�������˺ö��ˣ���һֱ���Լ���ѧͼ�۵ģ��������ݽṹ�ģ�������������
��ֻ����һЩ�뷨���У��������ˡ�
���ϴ��룺
�������룺*/
/*
#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=10000+10;
int num[maxn];
int bcnt;
int add(int t)
{
    int i;
    int flash=0,k;
    if(bcnt==0)
    {
        num[++bcnt]=t;
        return 0;
    }
    if(num[bcnt]<t)
    {
        num[++bcnt]=t;
        return 0;
    }
    int left=1,right=bcnt;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(num[mid]<t) 
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    k=t;
    bcnt++;
    for(i=left;i<=bcnt;i++)
    {
        int x=k;
        k=num[i];
        num[i]=x;
    }
    return 0;
}
int fun(int t)
{
    int i,flash=0;
    int left=1,right=bcnt;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(num[mid]<t)
        {
            left=mid+1;
        }
        else if(num[mid]==t)
        {
            left=mid;
            break;
        }
        else right=mid-1;
    }
    bcnt--;
    for(i=left;i<=bcnt;i++)
    num[i]=num[i+1];
    return 0;
}
int main()
{
    int n,i,j,a,d=1;
    char str[20];
    while(~scanf("%d",&n))
    {
        queue<int>Q;
        bcnt=0;
        printf("Case #%d:\n",d++);
        for(i=1;i<=n;i++)
        {
            scanf("%s",str);
            if(str[0]=='i')
            {
                scanf("%d",&a);
                Q.push(a);
                add(a);
            }
            else if(str[0]=='q')
            {
                printf("%d\n",num[(bcnt/2)+1]);
            }
            else if(str[0]=='o')
            {
                int x=Q.front();
                Q.pop();
                fun(x);
            }
        }
    }
    return 0;
}
*/
/*
����*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
set<int>stL,stR;
//set<int>::iterator it;
queue<int>Q;
int main()
{
    int n,x,t=0;
    char str[20];
    while(~scanf("%d",&n))
    {
        stL.clear();
        stR.clear();
        while(!Q.empty())Q.pop();
        printf("Case #%d:\n",++t);
        while(n--)
        {
            scanf("%s",str);
            if(str[0]=='i')
            {
                scanf("%d",&x);
                Q.push(x);
                if(*stR.begin()<x||stR.size()==0)
                stR.insert(x);
                else
                stL.insert(x);
            }
            else if(str[0]=='q')
            {
                printf("%d\n",*stR.begin());
            }
            else
            {
                int fir=Q.front();
                Q.pop();
                if(stR.find(fir)!=stR.end())
                stR.erase(fir);
                else
                stL.erase(fir);
            }
            while(stL.size()>stR.size())
            {   
                stR.insert(*(--stL.end()));
                stL.erase(--stL.end());
            }
            while(stL.size()+1<stR.size()) 
            {   
                stL.insert(*(stR.begin()));
                stR.erase(stR.begin());
            }
        }
    }
    return 0;
}
