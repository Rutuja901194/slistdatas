#include<stdio.h>

int  main()
{
    int x[10],i,sv,l,r,mid;
    i=0;
    while (i<10)
    {
        printf("\n data: ");
        scanf("%d",&x[i]);
        if(i>0)
        {
            if(x[i]<x[i-1])
            {
                printf("\n Invalid: ");
                continue;
            }
        }
        i++;
    }
    printf("\n Enter Search Value : ");
    scanf("%d",&sv);
    l=0;r=9;
    do
    {
        mid=(l+r)/2;
        if(x[mid]==sv)
           break;
        if(sv<x[mid])
          r=mid-1;
        else
          l=mid+1;
    }while (l<=r);
    if(l<=r)
       printf("\n Found");
      else
      printf("\n Not Found");
      return 0; 
}