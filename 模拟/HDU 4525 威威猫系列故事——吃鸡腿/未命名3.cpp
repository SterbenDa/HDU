//��ѽ  ɵ�ư���������ʽ�ϲ�sum[i+1]=(k1+k2)*sum[i]��  
//һֱģ�ⳬʱ�����ƴ����� 
//��k1+k2��<=1&&&��k1+k2��>=-1  ���Խ��ԽС inf
//����Ḻ����������һ�λ���Ȼ��为�����Ż���� 
#include<stdio.h>
int main()
{
    int t,cas,i,n;
    double k,k1,k2,j;
    scanf("%d",&cas);
    for(t=1;t<=cas;t++)
    {
         double sumk;  double sum;
         scanf("%d %lf %lf %lf",&n,&k1,&k2,&k);
         sumk=k1+k2;
         sum=0;
         for(i=0;i<n;i++)
         {
              scanf("%lf",&j);
              sum+=j;
         }
         if(sum>k) {printf("Case #%d: 0\n",t);continue;}

        if(sumk<=1&&sumk>=-1)
        {
            printf("Case #%d: inf\n", t);
            continue;
        }
         int cnt=0;
         while(1)
         {
              cnt++;
              sum=sum*sumk;
              if(sum>k) break;
         }
         printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}


