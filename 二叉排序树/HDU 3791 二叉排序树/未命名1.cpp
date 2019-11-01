#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <math.h>
#include <cstring>
using namespace std;
char str[15];
int num[15],len;
struct Tree{
	Tree *l,*r;
	int value;
};
Tree *root,*tmp;

void creat(Tree *t,int value){
	if(t==NULL){
		t=(Tree*)malloc(sizeof(Tree));
		t->l=NULL;
		t->r=NULL;
		t->value=value;
		return;
	}
	if(value<t->value)
	  creat(t->l,value);
	else 
       creat(t->r,value);
}
void inOrder(Tree *t,int &a[]){
	 if(t!=NULL){
	 	inOrder(t->l);
	 	printf("%d")
	 	inOrder(t->r);
	 }
}
int main(){ 
    int n;
    while(scanf("%d",&n)==1){
    	if(n==0)
    	break;
    	scanf("%s",str);
    	
    	len=strlen(str);
    	
    	root=NULL;
    	for(int i=0;i<len;i++){
    		creat(root,str[i]-'0');
		}
    	
	}
	return 0;
}
