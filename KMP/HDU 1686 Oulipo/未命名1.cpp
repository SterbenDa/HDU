#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int N=10000+10;
char text[N*100];
char pat[N];
int tlen,plen;
int nextKmp[N];
inline void getNext(){
	int j=0,k=-1;
	nextKmp[0]=-1;
	while(j<plen){
		if(k==-1||text[j]==pat[k])
		  nextKmp[++j]=++k;
		else
		  k=nextKmp[k];
	}
}
inline int find(){
    int i=0,j=0,re=0;
     while(i<tlen){
		if(j==-1||text[i]==pat[j])
		{
			i++;
			j++;
		}
		else
		   j=nextKmp[j];
		if(j==plen)
		 re++;
	}	
	return re;
}

int main(){ 
    int n,re;
    scanf("%d",&n);
    while(n--){
    	scanf("%s",pat);
		scanf("%s",text);
    	plen=strlen(pat);
    	tlen=strlen(text);
    	getNext();
    	re=find();
        printf("%d\n",re);
	}
	return 0;
}


