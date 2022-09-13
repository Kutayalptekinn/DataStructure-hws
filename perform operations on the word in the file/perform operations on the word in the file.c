#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 10

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Node
    {
    char data[50];
    struct Node *left;
   	struct Node *right;
   	char *next[50];
   	int count;
}NODE;


void Inorder(NODE *root,int space)
{
	int i =0,j;
	int space1;
	if(root==NULL) return;
 
    space += COUNT;
    Inorder(root->right,space);
 
    printf("\n");
    for (i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", root->data);
    
    for(j=0;j<root->count;j++)
    {	
        space1=space;
        for (i = COUNT; i < space1; i++)
            printf(" ");
    	printf("%s\n",root->next[j]);
    	space1=space1/2;
	}
    
 
    Inorder(root->left,space);	
	


	
}
	
NODE* GetNewNode(char data[50],char isim[50])
{
	NODE* newNode=(NODE*)malloc(sizeof(NODE));
	strcpy(newNode->data,data);
	newNode->left=newNode->right=NULL;
	newNode->count=1;
	newNode->next[0]=(char*)malloc(strlen(isim)*sizeof(char));
	strcpy(newNode->next[0],isim);
	return newNode;
}

NODE *Insert(NODE *root,char data[50],char isim[50])
{
	
	 int i = 0,j=0;
	if((root)==NULL)
	{
		(root)=GetNewNode(data,isim);
	}
	
	else if(strcmp(data,(root)->data)<0)
	{
		(root)->left=Insert((root)->left,data,isim);
	}
	else if(strcmp(data,(root)->data)>0)
	{
		(root)->right=Insert((root)->right,data,isim);
	}
	else
	{
		
		for(j=0;j<root->count;j++)
		{
			if(strcmp(root->next[j],isim)==0)
    		{
    			printf("ekleyemezsiniz cunku ayni dosyada bu kelime geciyor");
    			return 0;
     		}
		}
		root->next[root->count]=(char*)malloc(strlen(isim)*sizeof(char));
		strcpy(root->next[root->count],isim);
		root->count++;
	}
	return root;
}

void KelimeleriListele(NODE* root)
{
		printf("root ilk sutun ve agac ok yonunde ilerliyor -------------> ---------> ---> -->");
        Inorder(root,0);
        printf("\n");
}
		
char DosyayaKelimeEkle(NODE **root)
{ int i,n;
	    
		FILE *fp,*fp2;
		char kelime[50];
		char isim[50],isim2[50];
			
		printf("dosya ismini .txt seklinde giriniz:\n");
		scanf("%s",isim);
		printf("kac kelime gireceginizi yaziniz:\n");
		scanf("%d",&n);
		fp = fopen(isim, "a");
		for(i=0;i<n;i++)
		{
		printf("dosyaya yazilacak kelimeyi giriniz:\n");
        scanf("%s",kelime);
        fprintf(fp,"%s ",kelime);
		}	
		fclose(fp);
   	    
    	fp = fopen(isim, "r");
    	while(fscanf(fp,"%s\n",&kelime)!=EOF)
    	{
    	(*root)=Insert(*root,kelime,isim);	
		}	
		KelimeleriListele(*root);
	
}



NODE* KelimeAra(NODE* root, char data[50])
{
	int i;
	if(root==NULL) printf("bulunamadi");
	else if(strcmp(root->data,data)==0)
	{
		printf("kelime bulundu-->\n");
		printf("%s\n",root->data);
		for(i=0;i<root->count;i++)
		{
			printf("%s ",root->next[i]);
		}
	}
	else if(strcmp(root->data,data)>=0) return KelimeAra(root->left,data);
	else
	{
		return KelimeAra(root->right,data);	
	 } 	
	 
}

NODE* FindMin(NODE* root)
{
	if(root && root->left)
	    return FindMin(root->left);
	else 
	    return root;
}

NODE* KelimeyiAgactanSil(NODE *root,char data[50])
{
	if((root)==NULL) return (root);
	else if(strcmp(data,(root)->data)<0) (root)->left=KelimeyiAgactanSil((root)->left,data);
	else if(strcmp(data,(root)->data)>0) (root)->right=KelimeyiAgactanSil((root)->right,data);
	else //found deleted number
	{
		// case1:no child
		if((root)->left==NULL && (root)->right==NULL)
		{
		NODE* temp=(root);
		(root)=NULL;
		free(temp);				
		}
		//case2: one child
		else if((root)->left==NULL)
		{
		NODE* temp=(root);
		(root)=(root)->right;
		free(temp);	
		}
		else if((root)->right==NULL)
	    {
		NODE* temp=(root);
		(root)=(root)->left;
		free(temp);		
		}
		//case3: 2 children
		else
		{
			NODE *temp=FindMin((root)->right);
			strcpy((root)->data,temp->data);
			(root)->right=KelimeyiAgactanSil((root)->right,temp->data);
		}
	}
	return (root);
}

NODE* DosyaSil(NODE* root,char data[50],int count)
{
	int i,j=0;
	NODE* temp;
	
	if((root)==NULL)
	{
		return;
	}
	for(i=0;i<(root)->count;i++)
	{
		if(strcmp((root)->next[i],data)==0)
		{
			if(root->count>1)
			{
				for(;i<(root->count-1);i++)
                {
                strcpy(root->next[i],root->next[i+1]);
                }
                root->count--;
			}
			else
			{
				root=KelimeyiAgactanSil(root,root->data);
			}
		}
	}
	DosyaSil((root)->left,data,count);
	DosyaSil((root)->right,data,count);
	
	return root;
}

int main(int argc, char *argv[])
{
	int m,i=1;
	NODE* root = NULL;
	char n[50];
	
	while(i)
	{
	    printf("Dosya Eklemek icin 1'i Dosya Silmek icin 2'yi Kelime aramak icin 3'u listelemek icin 4'u cikmak icin 5'i tuslayiniz:\n");
    	scanf("%d",&m);
       	if(m==1)
    	{
    		DosyayaKelimeEkle(&root);
    	}
    	else if(m==2)
    	{
    		printf("silinecek dosya ismini giriniz:\n");
    		scanf("%s",n);
    		root=DosyaSil(root,n,0);    		
		}
		else if(m==3)
    	{
    		printf("aranacak kelimeyi giriniz:\n");
    		scanf("%s",n);
    		KelimeAra(root,n);
    		printf("\n");
		}
		else if(m==4)
		{
	     KelimeleriListele(root);
		}
		else if(m==5)
		{
		printf("cikis yapiliyor...");
		i=0;	
		}
	}
	
	return 0;
}


