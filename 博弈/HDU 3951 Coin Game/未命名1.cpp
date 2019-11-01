/*
（转分析：）
 题意：有N个硬币围成一圈，两个人每次只能取连续的1~K个硬币。
 问先手有没有必胜策略。
解法：当K==1：结果只与N的奇偶有关。
     当K>=2：如果N<=K，那么很显然先手必胜。
             当N>K时，先手一下子取不完，设剩余M个，
   	如果M<=K则后手一下全部取完，后手必胜；
	当M>K，即此时M>=3且K>=2，
	那么后手就可以在剩下的一排里取中间留两边然后以后就对称取，
	就一定必胜；所有此时后手必胜；
*/
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int t,i,n,k,now;
	scanf("%d",&t);
       for(now=1;now<=t;now++){ 
		scanf("%d%d",&n,&k);
		printf("Case %d: ",now);
		if(k==1){
			if(n%2==1)
			printf("first\n");	
			else
			printf("second\n");	
		}
		else{
          if(k>=n)
			printf("first\n");		
		 else
		printf("second\n");	
	}
	}
	return 0;
} 









