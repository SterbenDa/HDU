#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
using namespace std;
map<string,string> ma;
int main(){
	int i;
	char word1[12],word2[12];
	string s,tmp;
	scanf("%s",word1);
	while(scanf("%s",word1)==1){
		if(word1[0]=='E'&&word1[1]=='N'&&word1[2]=='D'&&strlen(word1)==3)
		break;
		scanf("%s",word2);
		ma[word2]=word1;
	}
	scanf("%s",word1);
	char c=getchar();
	while(getline(cin,s)){
		if(s=="END")
		break;
		tmp="";
		for(i=0;s[i]!='\0';i++){
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			   tmp+=s[i];
			else
			   {
			   	if(ma.count(tmp)!=0)
			   	  cout<<ma[tmp];
			   	  else
			   	   cout<<tmp;
			   	printf("%c",s[i]);
			   	tmp="";
			   }
		}
		printf("\n");
	}
	return 0;	
}
