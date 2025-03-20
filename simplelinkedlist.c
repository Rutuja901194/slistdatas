#include<stdio.h>
#include<stdlib.h>

typedef struct node
{   
    int data;
    struct node * next;
}NODE;

typedef struct slist
{
    NODE * st;
    NODE * ed;
}SLIST;

void init(SLIST *t)
{
    NODE *st=NULL;
    NODE *ed=NULL;
}

NODE *createnode(int d)
{
    NODE *a;
    a=(NODE *)malloc(sizeof(NODE));
    a->data=d;
    a->next==NULL;
    return a;
}

void addend(SLIST *t,int d)
{
    NODE *a=createnode(d);
    NODE *b;
    if(t->st==NULL)
        t->st=a;
    else
    {
        b=t->ed;
        b->next=a;      
    }
    t->ed=b;
}

void display(SLIST *t)
{
    NODE*a=t->st;
    if(t->st==NULL)
        printf("\n Empty list");
    else
        {
            printf("\n Data");
            while(a!=NULL)
            {
                printf("%4d",a->data);
                 a=a->next;
            }
        }

    printf("Summation : ");
    scanf("%d");    
}

void sum(SLIST *t)
{
   int sum=0;
   NODE *a=t->st;
   while (a!=NULL)
   {
     sum+=a->data;
     a->next;
     a=t->st;
   }
   return sum;
}
void main()
{
   SLIST p,t;
   addend(&p,20);
   addend(&p,30);
   addend(&p,40);
   sum(&p);
}

