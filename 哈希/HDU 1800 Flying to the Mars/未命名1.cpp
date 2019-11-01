//AC
/*
#include <iostream>
#include<map>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int i;
        map<int,int> mp;
        int max=INT_MIN;
        for(i=0;i<n;i++)
        {
            int level;
            scanf("%d",&level);
            mp[level]++;
            if(mp[level]>max)
            {
                max=mp[level];                     
            }
        }
        printf("%d\n",max);
    }
    return 0;
} 
*/


#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
const long long mod=100003; 
const long long key=103;
int sum[mod*10];  //����������������Ĵ��� 
long long next_[32];  //�����ϣ���� 
int len;  //�������� 
inline void Init()
{
	int i=0;
	next_[0]=1;
	for(i=1;i<32;i++)
	next_[i]=next_[i-1]*key%mod;
}
inline void hash_(long long a){
	long long s=0;
	int now=0;
	while(a!=0){
		s+=a*next_[now]%mod;
		s%=mod;
		a/=10;
		now++;
	}
	s%=mod;
     sum[s]++; 
     if(sum[s]>len)
     len=sum[s];
} 
int main(){
	int n,i;
	long long tmp;
	Init();
	while(scanf("%d",&n)==1){
		memset(sum,0,sizeof(sum));
		len=0;
		for(i=0;i<n;i++){
		 scanf("%lld",&tmp);
		  hash_(tmp);	
		}
    	printf("%d\n",len);
	}
	return 0;
}



//��Ŀ˵����30digits  ��ָ30λ Ӣ�ﲻ������ȥ����  
//����Ҫ�������ֻ�ܹ�ϣ������ 
/*���ù�ϣ  ����û������Ŀ Ч�ʺܵ� ����wa  ��ĿӦ����������������Ǹ� 
������ʱ����Ҳ��ʱ */ 
/*
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
const int mod=1003; 
const int key=103;
const int N=3000;
bool book[N][mod+5];
int next_[32];
int len;
inline void Init()
{
	int i=0;
	next_[0]=1;
	for(i=1;i<32;i++)
	next_[i]=next_[i-1]*key%mod;
}
inline void hash_(long long a){
	long long s=0;
	int now=0;
	while(a!=0){
		s+=a*next_[now]%mod;
		a/=10;
		now++;
	}
	now=0;
	s%=mod;
	while(book[now][s]==1)
	  now++;
     book[now][s]=1;
     if(len<now)
     len=now;
} 
int main(){
	int n,i;
	long long tmp;
	Init();
	while(scanf("%d",&n)==1){
		memset(book,0,sizeof(book));
		len=0;
		for(i=0;i<n;i++){
			scanf("%lld",&tmp);
		  hash_(tmp);	
		}
    	printf("%d\n",len+1);
	}
	return 0;
}
*/








/*
//��Ŀ˵����30digits  ��ָ30λ Ӣ�ﲻ������ȥ����  
//����Ҫ�������ֻ�ܹ�ϣ������ 
#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
using namespace std;
const int N=3000+10;
const int M=30+2;
bool book[N][M];
int main(){
	int n,i,now,tmp,len;
	while(scanf("%d",&n)==1){
		memset(book,0,sizeof(book));
		len=0;
		for(i=0;i<n;i++){
			now=0;
			scanf("%d",&tmp);
			while(book[now][tmp]==1)
				now++;
			book[now][tmp]=1;
			if(len<now)
			 len=now;
		}
	printf("%d\n",len+1);
	}
	return 0;
}
*/
