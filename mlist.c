
//multipal list:-

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
typedef struct MLIST
{
    NODE *st;
}MLIST;
void init(MLIST *t)
{
    t->st=NULL;
    
}
NODE *createNode(int d)
{
    NODE *a;
    a=(NODE*)malloc(sizeof(NODE));
    a->data=d;
    a->next=NULL;
    return a;
}

//function to delete all nodes
void delAll(MLIST *t)
{
    NODE *a=t->st;
    while(t->st!=NULL)
    {
        t->st=a->next;
        free(a);
        a=t->st;
    }
}

//fun to display

void display(MLIST *t)
{
    NODE *a=t->st;
    if(t->st==NULL)
     printf("\n empty list");
     else{
        printf("\n data: \n");
        while (a!=NULL)
        {
            printf("%4d",a->data);
            a=a->next;
        }
     }
}

//fun to create node

void createList(MLIST *t)
{
    NODE *a,*b;
    int val;
    while (1)
    {
       printf("\n data: ");
       scanf("%d",&val);
       if(val==0)
       break;
       a=createNode(val);
       if(t->st==NULL)
       t->st=a;
       else 
         b->next=a;
        b=a;
    }
    
}

//fun to sort list
void sort(MLIST *t)
{
    NODE *a=t->st,*b,*c;
    int tmp;
    while (a->next!=NULL)
    {
      c=a;
      for(b=a->next;b!=NULL;b=b->next)
      {
        if(b->data<c->data)
        c=b;
      }
      if(a!=c)
      {
        tmp=a->data;
        a->data=c->data;
        c->data=tmp;
      }
      a=a->next;
    }
    
}


//fun to copy list

MLIST copyList(const MLIST *t)
{
    NODE *a,*b;
    MLIST q;
    int val;
    init(&q);
    a=t->st;
    while(a!=NULL)
    {
        val=a->data;
        if(q.st==NULL)
        {
            q.st=b=createNode(val);
        }
        else{
            b->next=createNode(val);
            b=b->next;
        }
        a=a->next;
    }
    return q;
}


void appendList(MLIST *d,MLIST *s)
{
    NODE*a=s->st,*b=d->st,*c;
    if(b!=NULL)
    {
        while(b->next!=NULL)
        b=b->next;
    }
    while (a!=NULL)
    {
        c=createNode(a->data);
        if(d->st==NULL)//destination empty
            d->st=c;
        else
            b->next=c;
        b=c;
        a=a->next;
    }
    
} 

/*void main()
{
    MLIST p,q;
    init(&p);
    init(&q);
    createList(&p);
    display(&p);
    sort(&p);
    display(&p);
    q=copyList(&p);
    display(&q);
}*/

/*int main()
{
    MLIST p,q,r;
    init(&p);init(&r);
    init(&q);
    createList(&p);
    createList(&q);
    appendList(&r,&p);
     appendList(&r,&q);
     display(&p);
     display(&q);
     display(&r);
     return 0;
}
*/
//marging of two orderd list to 3rd list
MLIST merge(MLIST *p,MLIST *q)
{
    MLIST r;
    init(&r);
    int d;
    NODE *a=p->st,*b=q->st;
    NODE *c;
    sort(p);
    sort(q);
    while (a && b)
    {
        if(a->data<b->data)
        {
            d=a->data;
            a=a->next;
        }
        else
        {
          if(b->data<a->data)
          {
            d=b->data;
            b=b->next;
          }
          else{
            d=a->data;
            a=a->next;
            b=b->next;
         }
        }
       
      if(r.st==NULL)
      {
      r.st=c=createNode(d);
      }
      else
      {
        c->next=createNode(d);
        c=c->next;
      }

    }
    while (a!=NULL)
    {
        d=a->data;
        c->next=createNode(d);
        c=c->next;
        a=a->next;

    }
    while (b!=NULL)
    {
       d=b->data;
        c->next=createNode(d);
        c=c->next;
        b=b->next; 
    }
    return r;    
}
/*void main()
{
    MLIST p,q,r;
      init(&p);
      init(&q);
      init(&r);
      createList(&p);
      createList(&q);
      r=merge(&p,&q);
      display(&p);
      display(&q);
      display(&r);
}*/

//unionlist 

MLIST unionlist(MLIST *p,MLIST *q)
{
    MLIST r;
    init(&r);
    int d;
    NODE *a=p->st,*b=q->st;
    NODE *c;
    sort(p);
    sort(q);
    while (a && b)
    {
        if(a->data<b->data)
        {
            d=a->data;
            a=a->next;
        }
        else
        {
          if(b->data<a->data)
          {
            d=b->data;
            b=b->next;
          }
          else{
            d=a->data;
            a=a->next;
            b=b->next;
         }
        }
       
      if(r.st==NULL)
      {
      r.st=c=createNode(d);
      }
      else
      {
        if(d!=c->data)
        {
        c->next=createNode(d);
        c=c->next;
        }
      }

    }
    while (a!=NULL)
    {
        d=a->data;
        if(d!=c->data)
        {
        c->next=createNode(d);
        c=c->next;
        }
        a=a->next;

    }
    while (b!=NULL)
    {
       d=b->data;
       if(d!=c->data)
       {
        c->next=createNode(d);
        c=c->next;
       }
        b=b->next; 
    }
    return r;    
}
/*void main()
{
    MLIST p,q,r;
      init(&p);
      init(&q);
      init(&r);
      createList(&p);
      createList(&q);
      r=unionlist(&p,&q);
      display(&p);
      display(&q);
      display(&r);
}*/

//intersection

MLIST intersection(MLIST *p,MLIST *q)
{
    MLIST r;
    init(&r);
    int d;
    NODE *a=p->st,*b=q->st;
    NODE *c;
    sort(p);
    sort(q);
    while (a && b)
    {
        if(a->data<b->data)
        {
            a=a->next;
            continue;
        }
        else
        {
          if(b->data<a->data)
          {
            b=b->next;
            continue;
          }
          else{
            d=a->data;
            a=a->next;
            b=b->next;
         }
        }
       
      if(r.st==NULL)
      {
      r.st=c=createNode(d);
      }
      else
      {
        if(d!=c->data)
        {
        c->next=createNode(d);
        c=c->next;
        }
      }

    }
    return r;    
}
/*void main()
{
    MLIST p,q,r;
      init(&p);
      init(&q);
      init(&r);
      createList(&p);
      createList(&q);
      r=intersection(&p,&q);
      display(&p);
      display(&q);
      display(&r);
}*/

MLIST singleList(MLIST *p)
{
    MLIST r;
    init(&r);
    int d;
    NODE *a=p->st;
    NODE *c;
    sort(p);
    
    while (a)
    {
        if(a->data<a->data+1)
        {
            d=a->data;
            a=a->next;
        }
        else
        {
          if(a->data+1<a->data)
          {
            d=a->data;
            a=a->next;
          }
          else{
            d=a->data;
            a=a->next;
           
         }
        }
       
      /*if(r.st==NULL)
      {
      r.st=c=createNode(d);
      }
      else
      {
        if(d!=c->data)
        {
        c->next=createNode(d);
        c=c->next;
        }
      }*/

    }
    while (a!=NULL)
    {
        d=a->data;
        if(d!=c->data)
        {
        c->next=createNode(d);
        c=c->next;
        }
        a=a->next;

    }
    
    return r;    
}
void main()
{
    MLIST p,r;
      init(&p);
      
      init(&r);
      createList(&p);
      createList(&p);
      r=singleList(&p);
      display(&p);
      display(&r);
}