#include<stdio.h>
#define MAX 100
typedef struct{
	int f[MAX][MAX], c[MAX][MAX], n;
}Graph;
void init_flow(Graph *g){
	int i, j;
	for(i=1;i<=g->n;i++){
		for(j=1;j<=g->n;j++){
			g->f[i][j] = 0;
		}
	}
}

typedef struct{
	int nhan, pre, sigma;
}Label;
Label labels[MAX];

typedef struct{
	int ar_queue[MAX];
	int f, r;
}Queue;
void makenullQueue(Queue *q){
	q->f = 0;
	q->r = -1;
}
void enqueue(Queue *q, int x){
	q->ar_queue[q->r] = ele;
}
int dequeue(Queue *q){
	int tmp = q->ar_queue[q->f++];
	return tmp;
}
int empty_queue(Queue q){
	return q.f > q.r;
}
int ford_fullkerson(Graph *g, int s, int t){
	init_flow(&g);
	Queue q;
	int i, j;
	do{
		for(i=1;i<=g.n;i++)
			labels[i].nhan = 0; // = 0 la chua co nhan
		labels	
	}
}
