 
#include <iostream>
using namespace std;
char map[7][7];
bool book[7][7];
int n;
int big;
bool check(int x,int y);
int main(){
	void dfs(int a,int sum);
	int i,j;
	while(cin>>n){
		if(n==0)
		break;
		big=0;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			cin>>map[i][j];
			book[i][j]=0;
		}		
		for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(map[i][j]!='X'){
				book[i][j]=1;
				dfs(i*n+j+1,1);
				book[i][j]=0;
			}			
		}
	cout<<big<<endl;	    	
	}
	return 0;
}
void dfs(int a,int sum){
	if(a>=n*n)
	{
		if(sum>big)
		big=sum;
		return;
	}
	int x=a/n;
	int y=a%n;
	if(map[x][y]!='X'&&check(x,y)){
			book[x][y]=1;
			dfs(a+1,sum+1);
			book[x][y]=0;
	}
	dfs(a+1,sum);			
}

bool check(int x,int y){
	int i;
	//вС 
	for(i=y-1;i>=0;i--){
		if(map[x][i]=='X')
		break;
		else if(book[x][i]==1)
		return false;
	}
	//ср 
	for(i=y+1;i<n;i++){
		if(map[x][i]=='X')
		break;
		else if(book[x][i]==1)
		return false;
	}
	//ио 
	for(i=x-1;i>=0;i--){
		if(map[i][y]=='X')
		break;
		else if(book[i][y]==1)
		return false;
	}
	//об 
	for(i=x+1;i<n;i++){
		if(map[i][y]=='X')
		break;
		else if(book[i][y]==1)
		return false;
	}
	return true;
}



