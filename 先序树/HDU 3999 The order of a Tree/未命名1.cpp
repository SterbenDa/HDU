#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TREE
{
    struct TREE *l,*r;
    int num;
} tree;

tree *creat(tree *t,int x)
{
    if(t == NULL)
    {
        t = (tree*)malloc(sizeof(tree));
        t->num = x;
        t->l = t->r = NULL;
        return t;
    }
    if(t->num > x)
        t->l = creat(t->l,x);
    else
        t->r = creat(t->r,x);
    return t;
}

void libian(tree *t,int x)
{
    if(x == 1)
        printf("%d",t->num);
    else
        printf(" %d",t->num);
    if(t->l!=NULL)
        libian(t->l,2);
    if(t->r!=NULL)
        libian(t->r,2);
}

int main()
{
    int i,m,n;   
    while(~scanf("%d",&n))
    {
    	tree *t = NULL;
        for(i = 0;i<n;i++)
        {
            scanf("%d",&m);
            t = creat(t,m);
        }
        libian(t,1);
        printf("\n");
    }
    return 0;
}


