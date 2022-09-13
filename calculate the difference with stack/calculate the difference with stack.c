#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50


typedef struct Node{
  
  int data;
  struct Node* next;
}NODE;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Push(NODE **top,int x)
{
	NODE* temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("stack overflow");
		return;
	}
	temp->data=x;
	temp->next=*top;
	*top=temp;
}

int Pop(NODE **top)
{
	char x;
	int y;
     NODE *temp,*temp1;
	if(isEmpty(*top))
	{
		printf("stack underflow");
		return;
	}
	x=(*top)->data;
	temp=*top;
	*top=(*top)->next;
	free(temp);
	return x;
}

int isEmpty(NODE *top)
{
	if((top)==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Peek(NODE *top)
{
	if (!isEmpty(top)) {
        return top->data;
    }
    else {
        printf("The stack is empty\n");
        return;
    }  
}



void InsertBeginning(int c[],int *i,int s)
{
	int n,k,m=0;
		int mode = 8-((*i)%8);
		
		for(k=0;k<mode;k++)
		{
			n=(*i);
			while(n!=-1)
	    	{
			c[n+1]=c[n];
			n--;  		
    		}
    		if(s==0)
			{
				c[m]=0;
			 } 
    		else
			{
			   c[m]=1;
			 }    		
			m++; 
    		(*i)++;
		}	
}


int main()
{
	int size=0,q,r=0;
	int c[MAX_SIZE];
	char a[MAX_SIZE];
	NODE* top = NULL;
	int number,sum=0;
	int rest;
	int s=0,i=0,n=0,m=0,p=0;
	printf("enter the number:");
	scanf("%d",&number);
	
	
	
	if(number<0)
	{
		number=0-number;
		s=1;
	}
	
	while(number!=0)
	{	
		rest=number%2;
		if(rest==1 && s==1 && n==0)
		{
			Push(&top,rest);
			n=1;
			number=number/2;
		}
		else if(s==1 && n==1)
		{
	    if(rest==0) rest=1;
		else rest=0;
		Push(&top,rest);
		number=number/2;
		}
		else
		{
		Push(&top,rest);
		number=number/2;	
		}	
	}
	
	while(top!=NULL)
	{
		c[i]=Pop(&top);
		i++;
	}
	
	
    
	while(i%8!=0)
	{
	InsertBeginning(c,&i,s);	
	}
	
	for (m = 0; m < i; m++)
	{
        p += sprintf (&a[p], "%d", c[m]);
    }
    
	for(n=0;n<i;n++)
	{
		printf("%c",a[n]);
	}
	
	printf("\n");
	
	for(n=0;n<i;n++)
	{
		if(isEmpty(top) || top->data==c[n])
		{
		Push(&top,c[n]);	
		}
		else
		{
		Pop(&top);	
		}
    }
    
    if(!isEmpty(top))
    {	
    	while(top!=NULL)
    	{
    	q=Pop(&top);
		r++;	
		}	
    	printf("The number %d is %d more than the number %d. Additional %d numbers %d are required",q,1-q,r,((i-r)/2)+r,1-q);
	}
      
     
     else if(isEmpty(top))
     {
     	printf("The number of 0's and 1's are equal");
	 }

                  
	return 0;
}
