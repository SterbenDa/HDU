#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;
int re,len;
bool ok;
char s[20];
char result[6];
bool book[20];
bool cmp(char a,char b){
	return a>=b;
}
void dfs(int sum,int now){
	if(ok) return ;
	if(now==5){
		if(sum==re)	
			ok=1;
			return ;		
	}
	int i;	
	for(i=0;i<len;i++){
		if(book[i]==1)
		continue;
		book[i]=1;
		result[now]=s[i];
		if(now==0)
		   dfs(sum+s[i]-'A'+1,now+1);
	  else if(now==1)
	    dfs(sum-(s[i]-'A'+1)*(s[i]-'A'+1),now+1);
	  else if(now==2)
	  dfs(sum+(s[i]-'A'+1)*(s[i]-'A'+1)*(s[i]-'A'+1),now+1);
	  else if(now==3)
	  dfs(sum-(s[i]-'A'+1)*(s[i]-'A'+1)*(s[i]-'A'+1)*
	  (s[i]-'A'+1),now+1);
	  else if(now==4)
	  dfs(sum+(s[i]-'A'+1)*(s[i]-'A'+1)*(s[i]-'A'+1)*
	  (s[i]-'A'+1)*(s[i]-'A'+1),now+1);
	  book[i]=0;
	  if(ok)
	  return ;
	}
}
int main(){
    int i,j;
    while(scanf("%d%s",&re,s)==2){
    	if(re==0&&strcmp(s,"END")==0)
    	break;
    	len=strlen(s);
    	ok=0;
    	memset(book,0,sizeof(book));
    	sort(s,s+strlen(s),cmp);
    	dfs(0,0);
    	if(ok)
    	  printf("%s\n",result);
    	  else
    	printf("no solution\n");
	}
	return 0;
}
