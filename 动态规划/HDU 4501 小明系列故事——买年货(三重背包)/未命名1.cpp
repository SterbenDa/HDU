/*
   三维背包   
*/

#include<iostream>
#include <string.h>
using namespace std;
int dp[105][105][105];
int main() 
{ 
    int n,v1,v2,k;
    int a,b,c,re,i,j,l,z;
    while(cin>>n>>v1>>v2>>k){
    	memset(dp,0,sizeof(dp));
    	re=0;
    	
    	for(i=0;i<n;i++){
    		cin>>a>>b>>c;  		
    		for(z=k;z>=0;z--)
    		//注意这里不能是j>=a和l>=b 因为j<a的时候要考虑l的所有状态也成立啊 
    		for(j=v1;j>=0;j--)   
			for(l=v2;l>=0;l--){
				int tmp=0;
				if(z>0)  //可以免费拿 再更新 
				 tmp=max(tmp,dp[z-1][j][l]+c);
				if(j>=a)
				 tmp=max(tmp,dp[z][j-a][l]+c);
				if(l>=b)
				 tmp=max(tmp,dp[z][j][l-b]+c);
				dp[z][j][l]=max(tmp,dp[z][j][l]);
			}			
		} 
		
		
		/*不知道为什么用这种写法是错的 
		for(i=0;i<n;i++){
    		cin>>a>>b>>c;
    		for(z=k;z>=0;z--)
    		//注意这里不能是j>=a和l>=b 因为j<a的时候要考虑l的所有状态也成立啊 
    		for(j=v1;j>=0;j--)   
			for(l=v2;l>=0;l--){
				if(z>0)  //可以免费拿 再更新 
				 dp[z][j][l]=max(dp[z][j][l],dp[z-1][j][l]+c);
				if(j>=a)
				 dp[z][j][l]=max(dp[z][j][l],dp[z][j-a][l]+c);
				if(l>=b)
				 dp[z][j][l]=max(dp[z][j][l],dp[z][j][l-b]+c);
			}			
		}	
		*/
		cout<<dp[k][v1][v2]<<endl;
	}
    return 0;
}


/*
#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
  
struct node  
{  
    int a,b,w;  
} s[200];  
  
int dp[10][200][200];  
  
int main()  
{  
    int n,v1,v2,k,i,j,x,y,z;  
    while(~scanf("%d%d%d%d",&n,&v1,&v2,&k))  
    {  
        for(i = 1; i<=n; i++)  
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].w);  
        memset(dp,0,sizeof(dp));  
        for(i = 1; i<=n; i++)  
        {  
            for(x = k; x>=0; x--)  
            {  
                for(y = v1; y>=0; y--)  
                {  
                    for(z = v2; z>=0; z--)  
                    {  
                        int tem = 0;  
                        if(x-1>=0)  
                            tem = max(tem,dp[x-1][y][z]+s[i].w);  
                        if(y-s[i].a>=0)  
                            tem = max(tem,dp[x][y-s[i].a][z]+s[i].w);  
                        if(z-s[i].b>=0)  
                            tem = max(tem,dp[x][y][z-s[i].b]+s[i].w);  
                            dp[x][y][z] = max(dp[x][y][z],tem);  
                    }  
                }  
            }  
        }  
        printf("%d\n",dp[k][v1][v2]);  
    }  
  
    return 0;  
}  
*/
