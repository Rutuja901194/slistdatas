//double linked list

#include<stdio.h>
#include<string.h>

typedef struct node
{
    struct node*prev;
    int data;
    struct node *next;
}NODE;

typedef struct dlist
{
    NODE *st; //points to first node
    NODE *ed; //points to last node
}DLIST;

void init(DLIST *t)
{
    t->st=NULL;
    t->ed=NULL;
}

//fun to create a node

NODE *createNode(int d)
{
    NODE *a;
    a=(NODE*)malloc(sizeof(NODE));
    a->data=d;
    a->prev=a->next=NULL;
    return a;
}

//display
void dispSE(DLIST *t)
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
}

//display list ed->st

void dispES(DLIST *t)
{
    NODE *a=t->ed;
     if(t->ed==NULL)
        printf("\n Empty list");
    else
        {
            printf("\n Data");
            while(a!=NULL)
            {
                printf("%4d",a->data);
                 a=a->prev;
            }
        }
}

//fun add new node at end

void addEnd(DLIST*t,int d)
{
    NODE *a=createNode(d);
    NODE *b;
    if(t->st==NULL)
        t->st=a;
    else
    {
        b=t->ed;
        b->next=a;
        a->prev=b;
    }
    t->ed=a;
}

//fun to add new node at begin

void addBeg(DLIST*t,int d)
{
    NODE *a=createNode(d);
    NODE *b;
    if(t->ed==NULL)
        t->ed=a;
    else
    {
        b=t->st;
        a->next=b;
        b->prev=a;
    }
    t->st=a;
}

/*void main()
{
    DLIST p;
    init(&p);
    addEnd(&p,10);
    addEnd(&p,20);
    addEnd(&p,30);
    dispSE(&p);
    addBeg(&p,40);
    dispSE(&p);
    dispES(&p);
}*/

//function to delete 1st node on list 1)empty 2) 1 node in the list
 //delete 1st node
 void delFirst(DLIST *t)
 {
  NODE *a=t->st,*b;
  if(t->st==NULL)
    return;
   if(t->st==t->ed)//only 1 node
   {
    t->st=t->ed=NULL;
   } 
   else
   {
     b=a->next;
     b->prev=NULL;
     t->st=b;
   }
   free(a);
 }
 /*void main()
{
    DLIST p;
    init(&p);
    addEnd(&p,10);
    addEnd(&p,20);
    addEnd(&p,30);
    dispSE(&p);
    addBeg(&p,40);
    dispSE(&p);
    delFirst(&p);
    dispES(&p);

}*/

//function to delete last digit
void delLast(DLIST *t)
 {
  NODE *a=t->ed,*b;
  if(t->st==NULL)
    return;
   if(t->st==t->ed)//only 1 node
   {
    t->st=t->ed=NULL;
   } 
   else
   {
     b=a->prev;
     b->next=NULL;
     t->ed=b;
   }
   free(a);
 }

/*void main()
{
    DLIST p;
    init(&p);
    addEnd(&p,10);
    addEnd(&p,20);
    addEnd(&p,30);
    dispSE(&p);
    addBeg(&p,40);
    dispSE(&p);
    delFirst(&p);
    delLast(&p);
    dispES(&p);

}*/

//functio to delete ith node from list

void deliNode(DLIST *t,int pos)
{
  NODE *a=t->st,*b,*c;
  int i=1;
  if(t->st==NULL||pos<1)
    return;
  if(pos==1)
      delFirst(t);
  else
  {
    while(i<pos && a!=NULL)
    {
      b=a;
      a=a->next;
      i++;
    }
   
  if(a==NULL)//no such Node
   return ;
  if(a->next==NULL)
  {
    delLast(t);
    return ;
  }
  c=a->next;
  b->next=c;
  c->prev=b;
  free(a);
  }
}
 /*void main()
{
    DLIST p;
    init(&p);
    addEnd(&p,10);
    addEnd(&p,20);
    addEnd(&p,30);
    dispSE(&p);
    addBeg(&p,40);
    addBeg(&p,50);
    dispSE(&p);
    delFirst(&p);
    delLast(&p);
    deliNode(&p,3);
    dispSE(&p);
}*/

//fn to insert after
void insertA(DLIST *t,int pos,int d)
{
	int i=1;
	NODE *a=t->st,*b,*c;
	if(t->st==NULL||pos<1)//empty list
	return;
		while(i<=pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(pos>i)//NO SUCH NODE EXIST
		return;
		if(a==NULL)
		addEnd(t,d);
		else 
		{
		c=createNode(d);
		b->next=c;
		c->prev=b;
		c->next=a;
		a->prev=c;
	}
}

//fn to insert before
void insertB(DLIST *t,int pos,int d)
{
	int i=1;
	NODE *a=t->st,*b,*c;
	if(t->st==NULL||pos<1)//empty list
	return;
	if(pos==1)
	addBeg(t,d);
	else
	{
		while(i<pos&&a!=NULL)
		{
			b=a;
			a=a->next;
			i++;
		}
		if(a==NULL)
		return;
		c=createNode(d);
		b->next=c;
		c->prev=b;
		c->next=a;
		a->prev=c;
	}
}

int main()
{
	DLIST p,t;
	init(&p);
	addBeg(&p,10);
	addEnd(&p,20);
	addEnd(&p,30);
	addEnd(&p,40);
	dispSE(&p);
	insertB(&p,3,25);
	dispSE(&p);
	insertA(&p,4,35);
	dispSE(&p);
	return 0;	
}

