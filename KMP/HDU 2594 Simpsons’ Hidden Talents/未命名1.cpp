//���⣺��һ���ַ�����ǰ׺ ����һ���ַ����ĺ�׺����ж�����ͬ��
//���Բ�Ҫ����ģʽ���ĳ��ȣ�ֱ��ѭ��ĸ�����������������һ��ƥ���
//�͸պ���ĸ���ĺ�׺ 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
const int N=50000+10;
char pat[N],text[N];
int next_[N];
int plen,tlen;
inline void getNext(){
	int j=0,k=-1;
	next_[0]=-1;
	while(j<plen){
		if(k==-1||pat[j]==pat[k])
		 next_[++j]=++k;
		 else
		   k=next_[k];
	}
}
inline int kmp(){
       int i=0,j=0;     
       while(i<tlen){
       	  if(j==-1||text[i]==pat[j])
       	     {
       	     	i++;
       	     	j++;    	
			}
			else{								
				j=next_[j];
			}
	   }
	   return j;
}
int main(){ 
    while(gets(pat)){
    	  gets(text);
    	 plen=strlen(pat);
    	 tlen=strlen(text);
    	 getNext();
    	 int re=kmp();
    	if(re==0)
		 cout<<0<<endl;
		 else
		 {
		 	for(int i=0;i<re;i++)
		 	  cout<<pat[i];
		 	  cout<<" "<<re<<endl;
		  } 
	}
	return 0;
}
