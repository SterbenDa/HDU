/*#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct Node{
	int j,f;
	double hehe;
};
	bool operator <(Node a,Node b){
		return a.hehe>b.hehe;
	}


int main(){
	int m,n,i;
	Node node[1005];
	while(cin>>m>>n){
		if(m==-1&&n==-1)
		break;
		double result=0;
		for(i=0;i<n;i++){
			cin>>node[i].j>>node[i].f;
			node[i].hehe=(double)node[i].j/node[i].f;
		}
		sort(node,node+n);
	//	for(i=0;i<n;i++){
	//		cout<<node[i].j<<" "<<node[i].f<<" "<<	node[i].hehe<<endl;
	//	}
		for(i=0;i<n&&m>0;i++){
			if(m>node[i].f){
					m-=node[i].f;
					result+=node[i].j;
			}
			else{
				while(m>0){
					m-=1;
					result+=node[i].hehe;
				}
			}		
		}
		cout<<fixed<<setprecision(3)<<result<<endl;
	}
	return 0;
}*/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
struct Node{
	int j,f;
	double hehe;
};	
bool cmp(Node a,Node b){
		return a.hehe>b.hehe;
}
int main(){
	int m,n,i;
	Node node[1005];
	while(cin>>m>>n){
		if(m==-1&&n==-1)
		break;
		double result=0;
		for(i=0;i<n;i++){
			cin>>node[i].j>>node[i].f;
			node[i].hehe=(double)node[i].j/node[i].f;
		}
		sort(node,node+n,cmp);
	/*	for(i=0;i<n;i++){
			cout<<node[i].j<<" "<<node[i].f<<" "<<	node[i].hehe<<endl;
		}*/
		for(i=0;i<n&&m>0;i++){
			if(m>node[i].f){
					m-=node[i].f;
					result+=node[i].j;
			}
			else{
				while(m>0){
					m-=1;
					result+=node[i].hehe;
				}
			}		
		}
		cout<<fixed<<setprecision(3)<<result<<endl;
	}
	return 0;
}
