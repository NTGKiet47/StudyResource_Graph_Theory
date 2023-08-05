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
//	g->edge[g->m].x = y;
//	g->edge[g->m].y = x;
//	g->edge[g->m].w = ts;
//	g->m++;
}
void bellman_ford(Graph g){
	int pi[MAX], p[MAX];
	int i, j, is_nega = 0;
	int start, end;
	for(i=1;i<=g.n;i++){
		pi[i] = INF;
	}
	pi[1] = 0;
	p[1] = 0;
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
	for(j=0;j<g.m;j++){
		int u = g.edge[j].x;
		int v = g.edge[j].y;
		int z = g.edge[j].w;
		if(pi[u] + z < pi[v]){
			pi[v] = pi[u] + z;
			is_nega = 1;
			// u di den v va hoan thanh 1 chu trinh nen
			start = v;
			end = u;
			break;
		}
	}
	printf("%d %d\n", start, end);
	i = end;
	printf("%d ", i);
	while(1){
		printf("%d ", p[i]);
		i = p[i];
		if(i==start)
			break;
	}
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
