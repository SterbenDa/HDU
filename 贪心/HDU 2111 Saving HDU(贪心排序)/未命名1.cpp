/*
˼·����Ŀ��˼�����Ϊv�Ŀڴ�װ�����ֵ��p��ʾÿ������ۣ�v��ʾ�����Ʒ�ж������
���Էָ� 
*/
#include<iostream>
#include <algorithm>
using namespace std;
struct Thing{
	int p,v;
}thing[100+5];
bool cmp(Thing a,Thing b){
	return a.p>b.p;
}
int main()
{   
    int v,n,re;
    while(cin>>v){
    	if(v==0)
    	 break;
    	 re=0;
    	 cin>>n;
    	 for(int i=0;i<n;i++){
    	 	cin>>thing[i].p>>thing[i].v;
		 }
		 sort(thing,thing+n,cmp);
		 for(int i=0;i<n&&v!=0;i++){
		 	  if(v>=thing[i].v){
		 	  	   re+=thing[i].v*thing[i].p;
		 	  	   v-=thing[i].v;
			   }
			   else{
			   	   re+=v*thing[i].p;
			   	   v=0;
			   }
		 }
		 cout<<re<<endl;
	}
	return 0;
}


