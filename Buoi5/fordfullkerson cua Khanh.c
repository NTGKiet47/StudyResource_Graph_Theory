#include <stdio.h>

#define MAXN 100
#define NO_EDGE 0
#define oo 999999

// Khai bao CTDL Queue
#define MAX_E 100
typedef int ElementType;
typedef struct{
	int front, rear;
	ElementType Data[MAX_E];
} Queue;

void make_null_Queue(Queue* Q){
	Q->front = 0;
	Q->rear = -1;
}

void enQueue(Queue* Q, ElementType x){
	Q->rear++;
	Q->Data[Q->rear] = x;
}

void deQueue(Queue* Q){
Q->front++;
}

ElementType front(Queue* Q){
	return Q->Data[Q->front];
}

int empty_Queue(Queue* Q){
	return (Q->rear < Q->front);
}


typedef struct {
	int C[MAXN][MAXN];
	int F[MAXN][MAXN];
	int n;
}Graph;

typedef struct {
	int dir;
	int p;
	int sigma;
}Label;

Label labels[MAXN];

void init_graph(Graph* G, int n){
	G->n = n;
	for(int u = 1; u <= G->n; u++)
		for(int v = 1; v <= G->n; v++)
			G->C[u][v] = 0;
}

void add_edge(Graph* G, int u, int v, int c){
	G->C[u][v] = c;
}

void init_flow(Graph* G){
	for(int u = 1; u <= G->n; u++)
	for(int v = 1; v <= G->n; v++)
	G->F[u][v] = 0;
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}
int FordFulkerson(Graph* G, int s, int t){
	// Khoi tao luon = 0
	init_flow(G);
	int max_flow = 0;
	// Lap
	Queue Q;
	do{
	// Buoc 1 - Xoa nhan va gan nhan dinh s
	//1.1 xoa tat ca cac nhan cu
	for(int u = 1; u <= G->n; u++)
		labels[u].dir = 0;
	//1.2 Gan nhan s: (+, s, oo)
	labels[s].dir += 1;
	labels[s].p = s;
	labels[s].sigma = oo;
	// Khoi tao Q rong va dua S vao Q
	make_null_Queue(&Q);
	enQueue(&Q, s);
	// Buoc 2 - Lap gan nhan cho cac dinh tim duong tang luong
	int found = 0;
	while(!empty_Queue(&Q)){
		//2.1 Lay 1 dinh trong Q ra, goi no la u
		int u = front(&Q); deQueue(&Q);
		//2.2 Xet ga nhan cho cac dinh ke voi u: cung thuan
		for(int v = 1; v <= G->n; v++){
			if(G->C[u][v] != NO_EDGE && labels[v].dir == 0 && G->F[u][v] < G->C[u][v]){
				labels[v].dir = +1;
				labels[v].p = u;
				labels[v].sigma = min(labels[u].sigma, G->C[u][v] - G->F[u][v]);
				
				enQueue(&Q, v);
			}
		}
		//2.3 Xet gan cac nhan cho cac dinh di den u: cung nghich
		for(int x = 1; x <= G->n; x++){
			if(G->C[x][u] != NO_EDGE && labels[x].dir == 0 && G->F[x][u] > 0){
				labels[x].dir = -1; // cung nghich
				labels[x].p = u;
				labels[x].sigma = min(labels[u].sigma, G->F[x][u]);
				enQueue(&Q, x);
			}
		}
		//2.4 Neu t duoc gan nhan -> Tim duoc duong tang luong
		if(labels[t].dir != 0){
			found = 1;
			break;
		}
	}
	if(found == 1){
		// Buoc 3 - Tang luong
		int sigma = labels[t].sigma;

	//3.1 cap nhat luong cua cac cung tren duong tang luong
		int u = t;
		while(u != s){
			int p = labels[u].p;
			if(labels[u].dir > 0)  // tang luong
			G->F[p][u] += sigma;
			else
			G->F[u][p] -= sigma;
			u = p;
		}
		max_flow += sigma;
	} else
		break;
	}while(1);
	return max_flow;
}

int main(){
	Graph G;
	int n, m, u, v, c;
	//freopen ("dtFord-fulkerson.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for(int e = 1; e <= m; e++){
		scanf("%d%d%d", &u, &v, &c);
	add_edge(&G, u, v, c);
}

	int max_flow = FordFulkerson(&G, 1, n);
	printf("Max flow: %d" , max_flow);
	printf("\nX0: ");
	for(u = 1; u <= G.n; u++)
		if(labels[u].dir != 0)
			printf("%d ", u);
	printf("\nY0: ");
	for(u = 1; u <= G.n; u++)
		if(labels[u].dir == 0)
			printf("%d ", u);
	return 0;
}
