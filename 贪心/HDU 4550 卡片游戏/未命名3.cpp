/*
1
011110122
好贱的测试数据 
*/
#include <cstdio>
#include <iostream>
using namespace std;
int slen;
string s;

inline int find(int a,char now){     
    	 
	int i,flag=-1;  
	int small=99999999;  
	char f='0';
	for(i=a+1;i<slen;i++){
		if(s[i]=='0')
		continue;
		if(s[i]-'0'<=small)  //注意这里如果相同，选择靠后面的 
		{
			 small=s[i]-'0';
			 f=s[i];
			 flag=i;
		}
	}
	if(f<=now)  
	  return flag;  
	 else
	   return -1; 
	 
}
int main(){
	int t,i,len,j;
	string re;
	cin>>t;
	while(t--){
		cin>>s;
		re="";
		len=0;
		slen=s.length();
		for(i=0;i<slen;i++){
		
			if(s[i]=='0'){
				int he;
		         if(re.length()==0)
		         he=find(i,'9');
		         else
				he=find(i,re[0]);
				if(he==-1)  
				   re=re+s[i];
				else{
					re=s[i++]+re; 
				 for(;i<he;i++) {
				 
				  if(s[i]!='0') 
				    re=re+s[i] ;
				    else
				    re=s[i]+re;				  
				} 
				  
				 re=s[i]+re; 
				 for(++i;i<slen;i++)
				   re=re+s[i];
				}
			} else{
			
				if(s[i]==re[0]){
					for(j=0;re[j]!='\0';j++){
						if(re[j]<s[i])
						  {
						  	re=re+s[i];
						  	break;
						  }
						else if(re[j]>s[i])
						  {
						  	re=s[i]+re;
						  	break;
						  }
					}
					if(re[j]=='\0')
					   re=re+s[i];
				}
				else if(s[i]<re[0]){
				
					re=s[i]+re; 
				}else{
				
					re=re+s[i];
				}
			}
		}
		cout<<re<<endl;
	}
	return 0;
}

/*
1
011110122
好贱的测试数据 
*/
/*
#include <cstdio>
#include <iostream>
using namespace std;
int slen;
string s;

inline int find(int a,char now){     
     
	 //0放不放前面的条件是到结尾有没比当前首字符小的 ,找到个最小的，
	// 然后把途中非0的丢后面，0丢前面 
	 
	int i,flag=-1;  //标记位置 
	int small=99999999;  //标记最小的 
	char f='0';
	for(i=a+1;i<slen;i++){
		if(s[i]=='0')
		continue;
		if(s[i]-'0'<=small)  //注意这里如果相同，选择靠后面的
		{
			 small=s[i]-'0';
			 f=s[i];
			 flag=i;
		}
	}
	if(f<=now)  //0放前 
	  return flag;  
	 else
	   return -1; 
	//返回应放在0前面的下标 
}
int main(){
	int t,i,len,j;
	string re;
	cin>>t;
	while(t--){
		cin>>s;
		re="";
		len=0;
		slen=s.length();
		for(i=0;i<slen;i++){
			//是0
			if(s[i]=='0'){
			int he;
		         if(re.length()==0)
		         he=find(i,'9');
		         else
				 he=find(i,re[0]);
				if(he==-1)  //放尾巴 
				   re=re+s[i];
				else{
					re=s[i++]+re; //0放前 
				 for(;i<he;i++) {
				  //遍历到标志位置前非0都放后 
				  if(s[i]!='0') 
				    re=re+s[i] ;
				    else
				    re=s[i]+re;
				} 
				    //把标记位置放前
				 re=s[i]+re; 
				 for(++i;i<slen;i++)
				   re=re+s[i];
				}
			} else{
				//判断是否和首字符相同 
				if(s[i]==re[0]){
					for(j=0;re[j]!='\0';j++){
						if(re[j]<s[i])
						  {
						  	re=re+s[i];
						  	break;
						  }
						else if(re[j]>s[i])
						  {
						  	re=s[i]+re;
						  	break;
						  }
					}
					if(re[j]=='\0')
					   re=re+s[i];
				}
				else if(s[i]<re[0]){
					//比首字符小
					re=s[i]+re; 
				}else{
					//比首字符大 
					re=re+s[i];
				}
			}
		}
		cout<<re<<endl;
	}
	return 0;
}

*/
