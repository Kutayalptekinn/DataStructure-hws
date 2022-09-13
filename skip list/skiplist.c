#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "time.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct node
{
	int data;
	struct node* next;
	struct node* below;
}NODE;

 
NODE* SetsLevel(NODE *head,int *level);
void CreateList(NODE **head);
void PrintList(NODE **head,int level);
void Search(NODE *head,int level);
void insertNode(NODE *head,int level);
void DeleteNode(NODE *head,int level);

int main()
{
	int n;
	int level=1;
	NODE *heads,*heads1;
	NODE *head = NULL;

	CreateList(&head);
	srand(time(NULL));
	heads=SetsLevel(head,&level);
	PrintList(&heads,level);
    Search(heads,level);
  	PrintList(&heads,level);
	Search(heads,level);
	PrintList(&heads,level);
	insertNode(heads,level);
	PrintList(&heads,level);
	insertNode(heads,level);
	PrintList(&heads,level);
	DeleteNode(heads,level);
	PrintList(&heads,level);
	DeleteNode(heads,level);
	PrintList(&heads,level);

	
	
	
	
	
	
	
	
	return 0;
}

void CreateList(NODE **head)
{
	NODE *tmp;
	NODE *newNode;
	int i,n;
	

	
	newNode = (NODE*)malloc(sizeof(NODE));
	*head=newNode;
	printf("Listenin eleman sayisini giriniz.");
	scanf("%d",&n);
	printf("linkli liste elemanlarini sirali bir sekilde giriniz.\n");
	
	for(i=0;i<n;i++)
	{
		printf("linkli listenin %d. elemanini giriniz:",i+1);
		scanf("%d",&newNode->data);
		newNode->next = (NODE*)malloc(sizeof(NODE));
		if(i!=n-1)
		{
		newNode=newNode->next;	
		}
		
	}
	newNode->next=NULL;
}



NODE* SetsLevel(NODE *head,int *level)
{

	int flip;
	NODE *t;
	NODE *tmp2;
	NODE *tmp;
	NODE *heads=NULL;
	NODE *head2;
		
	tmp=head;
	
	
	
	for(t=tmp; t->next!=NULL; t=t->next)
	{	 
		flip=flipcoin();
		if(flip==1)
		{
			if(heads==NULL)
			{
			NODE *newNode1=(NODE*)malloc(sizeof(NODE));	
			heads=newNode1;
			newNode1->data=t->data;
			newNode1->below=t;
			newNode1->next=NULL;
			tmp2=newNode1;
        	heads->below=head;	
			}
			else
			{
			NODE *newNode2=(NODE*)malloc(sizeof(NODE));
			tmp2->next=newNode2;
			tmp2=newNode2;
			newNode2->data=t->data;
			newNode2->below=t;	
			newNode2->next=NULL;
			}
			
		}
	}
	if(heads!=NULL)
	{
		(*level)++;
		head=SetsLevel(heads,level);
	}
	return head;
	
}

int flipcoin()
{
    int i = rand() % 2;
        if (i == 0)
             return 0;
        else
             return 1;            
}


void PrintList(NODE **head, int level)
{
	NODE *tmp,*t;
	tmp=*head;
	printf("%d level:\n \n",level);
	while(level!=0)
	{
		t=tmp;
		while(t!=NULL)
    	{
			printf("%d\t",t->data);
			t=t->next;
        }
        tmp=tmp->below;
        printf("\n");	
    	level--;
    }
}

void Search(NODE *head,int level)
{
     	NODE *tmp,*t,*prev;
    	tmp=head;
    	
    	int m=1,val;
    	printf("aranacak elemani giriniz:");
    	scanf("%d",&val);
    	
    while(m==1)
    {
    	t=tmp;
    	while(tmp!=NULL && level!=0 && tmp->data<val)
		{
			prev=tmp;
			tmp=tmp->next;
		}
		if(level==0)
		{
			printf("eleman bulunamadi\n");
			m=0;
			return;
		}
		else if(tmp!=NULL && tmp->data==val && level!=0)
		{
			printf("bulundugu seviye: %d\n",level);
			printf("eleman bulundu\n");
			m=0;
			return;
		}
		else
		{
		tmp=t->below;	
		level--;	
		}	
		
	}
				
		
}


void insertNode(NODE *head,int level)
{
	    NODE *tmp,*prev,*t,*valNode,*hed;
    	tmp=head;
    	int m=1,val;
    	printf("eklenecek elemani giriniz:");
    	scanf("%d",&val);
    	
    while(m==1)
    {
    	t=tmp;
    	while(tmp!=NULL && level!=0 && tmp->data<=val)
		{	
		    prev=tmp;
			tmp=tmp->next;
		}
         if(level==1)
		{
			NODE *valNode=(NODE*)malloc(sizeof(NODE));
			valNode->next=prev->next;
			valNode->data=val;
            prev->next=valNode;
			m=0;
			printf("eleman eklendi\n");
			return;
		}

		tmp=t->below;	
		level--;	
	
	}
}

void DeleteNode(NODE *head,int level)
{
	NODE *tmp,*prev,*t,*valNode,*hed;
    	tmp=head;
    	int m=1,val;
    	printf("silinecek elemani giriniz:");
    	scanf("%d",&val);
    	
    while(m==1)
    {
    	t=tmp;
    	while(tmp!=NULL && level!=0 && tmp->data<val)
		{	
		    prev=tmp;
			tmp=tmp->next;
		}
         if(level==1)
		{
			if(t==tmp)
			{
				head=tmp->next;
				free(tmp);
				printf("eleman silindi\n");
			}
			else
			{
			prev->next=tmp->next;
			free(tmp);	
			printf("eleman silindi\n");
			}			
			m=0;
			return;
		}
		

		tmp=t->below;	
		level--;	
    }
}








