#include<stdio.h>
#define MAX 100

typedef struct{
	int ar_graph[MAX][MAX];
	int n;
}Graph;
void init_graph(Graph *g, int n){
	g->n = n;
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j]=0;
}
void add_edge(Graph *g, int x, int y){
	g->ar_graph[x][y] = g->ar_graph[y][x] = 1;
}
typedef struct{
	int ar_queue[MAX];
	int front, rear;
}Queue;
void make_null_queue(Queue *q){
	q->front = 0;
	q->rear = -1;
}
void add_queue(Queue *q, int ele){
	q->rear++;
	q->ar_queue[q->rear] = ele;
}
int top(Queue q){
	return q.ar_queue[q.front];
}
void pop(Queue *q){
	q->front++;
}
int empty_queue(Queue q){
	return q.front>q.rear;
}
void breath_first_search(Graph g){
	int mark[MAX], pre[MAX];
	int i, j, u, v;
	for(i=1;i<=g.n;i++){
		mark[i] = 0;
		pre[i] = -1;
	}
	Queue q;
	make_null_queue(&q);
	// bat dau tu dinh 1
	add_queue(&q, 1);
	pre[1] = 0;
	while(!empty_queue(q)){
		u = top(q);
		pop(&q);
		if(mark[u]==1)
		 	continue;
		mark[u] = 1;
		for(v=1;v<=g.n;v++){
			if(g.ar_graph[u][v] == 1){
				if(mark[v]==0){
					add_queue(&q, v);
					if(pre[v]==-1)
						pre[v] = u;
				}
			}
		}
		if(empty_queue(q)){
			for(i=1;i<=g.n;i++){
				if(mark[i] == 0){
					pre[i] = 0;
					add_queue(&q, i);
					break;
				}
			}		
		}
	}
	for(i=1;i<=g.n;i++)
		printf("%d %d\n", i, pre[i]);
}
int main(){
	Graph g;
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	init_graph(&g, n);
	while(m--){
		scanf("%d%d", &x, &y);
		add_edge(&g, x, y);
	}
	breath_first_search(g);
	return 0;
}
