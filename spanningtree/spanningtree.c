#include <stdio.h>

#define MAX 30

typedef struct edge {
  int u, v, w;
} EDGE;

typedef struct edgeTree {
  EDGE data[MAX];
  int n;
} EDGETREE;

EDGETREE edgeTree;

int Graph[MAX][MAX], n;
EDGETREE spanlist;
void applyUnion();
void kruskalAlgo();
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() {
  int  i, j,belongs[MAX], cno1, cno2;

  sort();

  	for (i = 0; i <= edgeTree.n; i++)
        belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < edgeTree.n; i++)
   {
    cno1 = belongs[edgeTree.data[i].u];
    cno2 = belongs[edgeTree.data[i].v];

    if (cno1 != cno2)
	{
        spanlist.data[spanlist.n] = edgeTree.data[i];
        spanlist.n = spanlist.n + 1;
        applyUnion(belongs, cno1, cno2);
    }
  }
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 1; i <= edgeTree.n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

void sort() {
  int i, j;
  EDGE temp;

  for (i = 1; i < edgeTree.n; i++)
    for (j = 0; j < edgeTree.n - 1; j++)
      if (edgeTree.data[j].w > edgeTree.data[j + 1].w) {
        temp = edgeTree.data[j];
        edgeTree.data[j] = edgeTree.data[j + 1];
        edgeTree.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main() {
  int i, j,u,v,w, total_cost;

	edgeTree.n=7;
	edgeTree.data[0].w=1; edgeTree.data[0].u=5; edgeTree.data[0].v=7;
	edgeTree.data[1].w=2; edgeTree.data[1].u=1; edgeTree.data[1].v=2;
	edgeTree.data[2].w=3; edgeTree.data[2].u=2; edgeTree.data[2].v=3;
	edgeTree.data[3].w=5; edgeTree.data[3].u=4; edgeTree.data[3].v=5;
	edgeTree.data[4].w=6; edgeTree.data[4].u=2; edgeTree.data[4].v=6;
	edgeTree.data[5].w=6; edgeTree.data[5].u=6; edgeTree.data[5].v=7;
	edgeTree.data[6].w=12; edgeTree.data[6].u=7; edgeTree.data[6].v=8;
	
	while(1)
	{
	printf("\n");
	printf("dugumleri giriniz\n");
	scanf("%d\n",&u);
	scanf("%d",&v);
	printf("kenar degerini giriniz\n");
	scanf("%d",&w);
	
	edgeTree.n++;
	edgeTree.data[edgeTree.n-1].u=u;
	edgeTree.data[edgeTree.n-1].v=v;
	edgeTree.data[edgeTree.n-1].w=w;
    kruskalAlgo();
    print();
	}
	

  
  return 0;
  
}
