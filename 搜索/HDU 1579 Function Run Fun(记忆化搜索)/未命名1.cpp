/*
if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
  1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
  w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
  w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

数组开三维22就行 

*/
#include<iostream>
#include <string.h>
using namespace std;
int num[22][22][22]; 
int w(int a,int b,int c){
	if(a<=0||b<=0||c<=0)
	  return 1;
	if(a>20||b>20||c>20)
	  return num[20][20][20]=w(20,20,20);
	if(num[a][b][c]!=-1)
	   return num[a][b][c];
	if(a<b&&b<c)
	  return num[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
	return num[a][b][c]=w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
int main()
{  
    int a,b,c; 
    memset(num,-1,sizeof(num));
    while(cin>>a>>b>>c){
    	if(a==-1&&b==-1&&c==-1)
    	 break;
    	cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
	}
	return 0;
}


