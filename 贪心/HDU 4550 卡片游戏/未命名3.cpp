/*
1
011110122
�ü��Ĳ������� 
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
		if(s[i]-'0'<=small)  //ע�����������ͬ��ѡ�񿿺���� 
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
�ü��Ĳ������� 
*/
/*
#include <cstdio>
#include <iostream>
using namespace std;
int slen;
string s;

inline int find(int a,char now){     
     
	 //0�Ų���ǰ��������ǵ���β��û�ȵ�ǰ���ַ�С�� ,�ҵ�����С�ģ�
	// Ȼ���;�з�0�Ķ����棬0��ǰ�� 
	 
	int i,flag=-1;  //���λ�� 
	int small=99999999;  //�����С�� 
	char f='0';
	for(i=a+1;i<slen;i++){
		if(s[i]=='0')
		continue;
		if(s[i]-'0'<=small)  //ע�����������ͬ��ѡ�񿿺����
		{
			 small=s[i]-'0';
			 f=s[i];
			 flag=i;
		}
	}
	if(f<=now)  //0��ǰ 
	  return flag;  
	 else
	   return -1; 
	//����Ӧ����0ǰ����±� 
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
			//��0
			if(s[i]=='0'){
			int he;
		         if(re.length()==0)
		         he=find(i,'9');
		         else
				 he=find(i,re[0]);
				if(he==-1)  //��β�� 
				   re=re+s[i];
				else{
					re=s[i++]+re; //0��ǰ 
				 for(;i<he;i++) {
				  //��������־λ��ǰ��0���ź� 
				  if(s[i]!='0') 
				    re=re+s[i] ;
				    else
				    re=s[i]+re;
				} 
				    //�ѱ��λ�÷�ǰ
				 re=s[i]+re; 
				 for(++i;i<slen;i++)
				   re=re+s[i];
				}
			} else{
				//�ж��Ƿ�����ַ���ͬ 
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
					//�����ַ�С
					re=s[i]+re; 
				}else{
					//�����ַ��� 
					re=re+s[i];
				}
			}
		}
		cout<<re<<endl;
	}
	return 0;
}

*/
