#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char getChar(int x,int y);
void printMatris(int **visited,int **matris,int n,int m,int *puan);
void createRandomApples(int **matris,int **visited,int n,int m);
int main()
{
	FILE *fptr;
	char c,pre;
	int **matris;
	fptr=fopen("maze.txt","r");
	int i=0,m,n,j=0,startx,starty,endx,endy,x,y,hlpr=1,puan=0;
	int row,col;
	int **visited;
	
	printf("labirentin satir ve sutun sayisini giriniz:\n");
	scanf("%d %d",&n,&m);
	matris = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<m;i++){
		matris[i] = (int*)calloc(m,sizeof(int));
	}
	visited = (int**)malloc(sizeof(int*)*n);
	for(i=0;i<m;i++){
		visited[i] = (int*)calloc(m,sizeof(int));
	}
	visited[0][0]=0;
	i=0;
	
	
	while ((c = getc(fptr))!= EOF)	
	{
		
		if((char)c=='-' || (char)c=='|'|| (char)c=='+')
		{
			matris[i][j]=0;
			j++;
		}
		else if(c=='\n')
		{
			i++;
			
			if(hlpr){
				m=j;
				hlpr=0;	
			}
			j=0;
		}
	
		else if(c==' ')
		{
		  	matris[i][j]=1;
		  	j++;
		}
		else if(c=='b')
		{
			startx=j;
			starty=i;
			matris[i][j]=1;
			j++;
		}
		else if(c=='c')
		{
			endx=j;
			endy=i;
			matris[i][j]=1;
			j++;
		}
	}
	n=i;
    createRandomApples(matris,visited,n,m);
	recursiveSolve(startx,starty,endx,endy,matris,visited,&puan,n,m);

	
	
	
	
	
	
	return 0;
}





int recursiveSolve(int x, int y,int endX,int endY,int **matris,int **visited,int *puan,int n,int m) {
    if (x == endX && y == endY){
    	printf("\n\ncikis bulundu!!");
    	return 1;
	}
    
   usleep(699999);
    
    visited[y][x]=1;
    system("cls");
	printMatris(visited,matris,n,m,puan);
     if(x+1<m && visited[y][x+1]!=1 && matris[y][x+1])
     {
     	if(visited[y][x+1]==2){
     		(*puan)+=10;	
		 }
     	if(recursiveSolve(x+1,y,endX,endY,matris,visited,puan,n,m)){
     		return 1;
		 }
	 }
	 else if(!matris[y][x+1] && !matris[y+1][x] && !matris[y-1][x]) {
	 	(*puan)-=5;
	 }
	 
	 
	 
	  if(x-1>0 && visited[y][x-1]!=1 && matris[y][x-1])
     {
     	if(visited[y][x-1]==2){
     		(*puan)+=10;	
		 }
     	if(recursiveSolve(x-1,y,endX,endY,matris,visited,puan,n,m)){
		 	return 1;
		 }
     	
	 }
	 else if(!matris[y][x-1] && !matris[y+1][x] && !matris[y-1][x])
	 {
	 	(*puan)-=5;
	  } 
	 
	if(y+1<n && visited[y+1][x]!=1 && matris[y+1][x])
     {
     	if(visited[y+1][x]==2){
     		(*puan)+=10;	
		 }
     	if(recursiveSolve(x,y+1,endX,endY,matris,visited,puan,n,m)){
     		return 1;
		 }
	 }
	 else if(!matris[y+1][x] && !matris[y][x+1] && !matris[y][x-1])
	 {
	 	(*puan)-=5;
	  } 
	 
	 if(y-1>0 && visited[y-1][x]!=1 && matris[y-1][x])
     {
     	if(visited[y-1][x]==2){
     		(*puan)+=10;	
		 }
     	if(recursiveSolve(x,y-1,endX,endY,matris,visited,puan,n,m)){
     		return 1;
		 }
	 }
	 else if(!matris[y-1][x]&& !matris[y][x-1]&& !matris[y][x+1])
	 {
	 	(*puan)-=5;
	  } 
	 visited[y][x]=0;
     
    return 0;
}

void printMatris(int **visited,int **matris,int n,int m,int *puan)
{
	int i,j;
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(matris[i][j]){
				if(visited[i][j]==1){
					printf("*");
				}
				else if(visited[i][j]==2){
					printf("%c",248);
				}

				else{
					printf(" ");
				}
			}
			else{
				char a=getChar(j,i);
				printf("%c",a);
			}
			
		}
		printf("\n");
	}
	
	printf("\n");
	printf("toplam puanim:%d	",*puan);
}

char getChar(int x,int y)
{
	if(x%2==0 && y%2==0)
	{
		return '+';
	}
	else if(x%2==1 && y%2==0)
	{
		return '-';
	}
    else if(x%2==0 && y%2==1)
    {
    	return '|';
	}
	
	
}

void createRandomApples(int **matris,int **visited,int n,int m)
{
	int i,j,k=0,apple;
	printf("eklenecek elma sayisini giriniz:\n");
	scanf("%d",&apple);
	
	while(k<apple){
		i=rand()%n;
		j=rand()%m;
		if(matris[i][j]==1)
		{
			visited[i][j]=2;
			matris[i][j]=248;
			k++;
		}
	}
}


