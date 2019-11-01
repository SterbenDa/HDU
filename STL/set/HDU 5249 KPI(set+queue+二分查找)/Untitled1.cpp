/*超时 
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

/*以为换了C语言就能过 超时！方法不对 
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

/*网上转载 写的很好
原贴地址 ：http://blog.csdn.net/letterwuyu/article/details/46316599 
*/
/*
原贴分析：（转载的） 
分析：这道题是2015百度之星初赛1的4题
这道题不算太难当时队友做出来了，不过费了老大劲，其实我从中能够吸取教训的，
原因是，我一看这道题就是数据结构的，然后和队友想的一样二分查找，但是从中
遇到了一系列的问题：
首先储存数据我们不能用带有下标的数组，因为题目中的数据是可删可添的这样如果用
数组的话时间复杂度是相当高的，因为如果按大小插入，就要移动其他数据，如果在
尾部添加，就要对其排序，因为二分是有单调性的要求的，如果用链表的话可以不移动
数据，在中间插入，但这样的话二分查找怎么办，没有了数组一样的下表会很麻烦。
在万般无奈的情况下我们放弃了二分查找，尔是直接遍历，用链表存，我发现如果是
这样的话不用链表，直接记录每个数的前驱后驱，就可实现链表功能，但是写的相当
恶心，最后越巧越没劲了
我们知道焦点在中间值，最终我们用二分查找，数组存储的方法，每插入一个数，而
找到离他最近的数的位置，插入并从这个位置开始到序列的末尾都向后以一位，的方法
过了。
其实我们当初的一个思路是找另个集合维护着一个集合里的数比另一个集合里的数多
1个，用二叉树存储，而且是有序的，但是太麻烦当初没实现，完事以后我一想set容器
不久有这个特性吗，set里面是二叉顺序存储的，所以查找也是二分查找的，这不中好吗
哎呀，我set容器用了好多了，我一直想自己是学图论的，他是数据结构的，这题他正合适
我只在提一些想法就行，我萨比了。
献上代码：
比赛代码：*/
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
赛后：*/
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
