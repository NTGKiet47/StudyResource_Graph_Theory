#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef struct{
	int x, y, w;
}Edge;
typedef struct{
	Edge edge[MAX];
	int n, m;
}Graph;
void init_graph(Graph *g, int n){
	g->n = n;
	g->m = 0;
}
void add_edge(Graph *g, int x, int y, int ts){
	g->edge[g->m].x = x;
	g->edge[g->m].y = y;
	g->edge[g->m].w = ts;
	g->m++;
}
void bellman_ford(Graph g){
	int pi[MAX], p[MAX];
	int i, j, negative = 0;
	for(i=1;i<=g.n;i++){
		pi[i] = INF;
	}
	pi[1] = 0;
	for(i=1;i<=g.n;i++){
		for(j=0;j<g.m;j++){
			int u = g.edge[j].x;
			int v = g.edge[j].y;
			int z = g.edge[j].w;
			if(pi[u] + z < pi[v]){
				pi[v] = pi[u] + z;
				p[v] = u;
			}
		}
	}
	for(i=1;i<=g.n;i++){
		printf("dinh %d: pi:%3d  p:%3d\n", i,pi[i],p[i]);
	}
	for(i=0;i<g.m;i++){
		int u = g.edge[i].x;
		int v = g.edge[i].y;
		int z = g.edge[i].w;
		if(pi[u] + z < pi[v]){
			negative = 1;
			break;
		}
	}
//	if(negative == 1)
//		printf("negative cycle");
//	else
//		printf("ok");
//	
}
int main(){
	
	int n, m ,x,y,w;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &w);
		add_edge(&g, x, y, w);
	}
	bellman_ford(g);
	return 0;
}
