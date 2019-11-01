/*
��������̰�Ľ����Ѫ���ٹ����ߵ�Ҫ������������HP/DPS��Ϊ�������򣬼�
�����еĵ��˸���DPS/HP�Ӵ�С���������ȣ���HP��С��������
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node
{
    int dps;
    int hp;
}a[30];

int cmp(Node x,Node y)
{
    return x.hp*y.dps<y.hp*x.dps;//�������ţ�����С�������Խ�ʽ�ӽ���ת��
}

int main()
{
    int t,i;
    int sum,ans;
    while(~scanf("%d",&t))
    {
        sum = ans = 0;
        for(i = 0;i<t;i++)
        {
            scanf("%d%d",&a[i].dps,&a[i].hp);
            sum+=a[i].dps;
        }
        sort(a,a+t,cmp);
        for(i = 0;i<t;i++)
        {
            ans+=sum*a[i].hp;
            sum-=a[i].dps;
        }
        printf("%d\n",ans);
    }

    return 0;
}

