//复习一下c++的getline的用法格式
//while(getline(cin,s)){} 
#include <iostream>
#include <string> 
using namespace std;
int main(){
	int handle(int now,int floor);
	string s;
	int i; 
   while(getline(cin,s)){  //getline的用法格式 
    if(s=="0")
        break;
     int sum=0,floor=0,now=0;
   	  for(i=0;s[i]!='\0';i++){
   	  	 if(s[i]==' '){
   	  	 	sum+=handle(now,floor);	 
   	  	 	floor=now;
			now=0;
   	  	 }
   	  	 else{
   	  	 	now=now*10+s[i]-'0';
   	  	 }
   	  }
   	  sum+=handle(now,floor)+5;
		 	cout<<sum<<endl;
   }
	return 0;
}
int handle(int now,int floor){
	if(floor<now)
	  return 6*(now-floor);
	  else if(floor==now)
	  return 5;
	  else if(floor>now)
	  return 4*(floor-now);
}
