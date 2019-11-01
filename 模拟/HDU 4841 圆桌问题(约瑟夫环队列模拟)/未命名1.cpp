#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int a[2*n];
		queue<int>root;
		for(int i=0;i<2*n;i++)
		{
			a[i]=1;
			root.push(i); 
		}
		int sum=0;
		while(root.size()!=n)
		{
			int x=root.front();
			sum++;
			if(sum==m)
			{
				root.pop();
				a[x]=0;
				sum=0;
			}
			else
			{
				root.pop();
				root.push(x); 
			}
		}
		for(int i=0;i<2*n;i++)
		{
			if(a[i]) cout<<"G";
			else cout<<"B";
			if((i+1)%50==0) cout<<endl;
		}
		cout<<endl<<endl;
	}
	return 0;
}

