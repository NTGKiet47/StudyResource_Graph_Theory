#include<stdio.h>
#define MAX 100
typedef struct{
	int u, v, w;
}Edge;
typedef struct{
	Edge edges[MAX];
	int n, m;
}Graph;
void init_graph(Graph *g, int n){
	g->n = n;
	g->m = 0;
}
void add_edge(Graph *g, int x, int y, int z){
	g->edges[g->m].u = x;
	g->edges[g->m].v = y;
	g->edges[g->m].w = z;
	g->m++;
}
void swap_point(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap_edge(Edge *a, Edge *b){
	Edge tmp = *a;
	*a = *b;
	*b = tmp;
}
int par[MAX];
int find_root(int p){
	if(par[p] == p)
		return p;
	return find_root(par[p]);
}
void kruskal(Graph g){
	Graph t;
	init_graph(&t, g.n);
	int i, j, num_edge_onTree = 0, root_u, root_v, sum_w = 0;
	for(i=1;i<=g.n;i++)
		par[i] = i;
	for(i=0;i<g.m-1;i++){
		for(j=i+1;j<g.m;j++){
			if(g.edges[j].w < g.edges[i].w){
				swap_edge(&g.edges[j], &g.edges[i]);
			}else if(g.edges[j].w == g.edges[i].w){
				if(g.edges[j].u < g.edges[i].u){
					swap_edge(&g.edges[j], &g.edges[i]);
				}else if(g.edges[j].u == g.edges[i].u){
					if(g.edges[j].v < g.edges[i].v){
						swap_edge(&g.edges[j], &g.edges[i]);
					}
				}
			}
		}
	if(g.edges[i].u > g.edges[i].v)
		swap_point(&g.edges[i].u, &g.edges[i].v);
	}
	for(i=0;i<g.m;i++){
		int x, y ,z;
		x = g.edges[i].u;
		y = g.edges[i].v;
		z = g.edges[i].w;
		root_u = find_root(x);
		root_v = find_root(y);
		if(root_u != root_v){
			par[root_v] = root_u;
			sum_w += z;
			add_edge(&t, x, y, z);
			num_edge_onTree++;
			if(num_edge_onTree == t.n-1) 
				break;
		}
	}
	printf("%d\n", sum_w);
	for(i=0;i<t.m;i++){
		printf("%d %d %d\n", t.edges[i].u, t.edges[i].v, t.edges[i].w);
	}
}
int main(){
	
	int n, m,x,y,z;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y,&z);
		add_edge(&g, x, y, z);
	}
	kruskal(g);
	
	return 0;
}
