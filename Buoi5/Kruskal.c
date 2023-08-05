#include<stdio.h>
#define MAX 100

int par[MAX];

typedef struct{
	int u,v,w;
}Edge;
typedef struct{
	Edge edges[MAX];
	int num_point, num_edge;
}Graph;
void init_graph(Graph *g, int n){
	g->num_edge = 0;
	g->num_point = n;
}
void add_edge(Graph *g, int x, int y, int z){
	g->edges[g->num_edge].u = x;
	g->edges[g->num_edge].v = y;
	g->edges[g->num_edge].w = z;
	g->num_edge++;
}
int find_root(int p){
	if(par[p] == p)
		return p;
	return find_root(par[p]);
}
void swap_edge(Edge *e1, Edge *e2){
	Edge tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
Graph kruskal(Graph g, int *sum){
	Graph t;
	init_graph(&t, g.num_point);
	int i, j;
	for(i=0; i<g.num_edge-1; i++){
		for(j=i+1; j<g.num_edge; j++){
			if(g.edges[j].w < g.edges[i].w){
				swap_edge(&g.edges[j], &g.edges[i]);
			}else if(g.edges[j].w == g.edges[i].w){
				if(g.edges[j].u < g.edges[i].u)
					swap_edge(&g.edges[j], &g.edges[i]);
				else if(g.edges[j].u == g.edges[i].u)
					if(g.edges[j].v < g.edges[i].v)
						swap_edge(&g.edges[j], &g.edges[i]);
			}
		}
		if(g.edges[i].u > g.edges[i].v){
			swap(&g.edges[i].u, &g.edges[i].v);
		}
	}
	for(i=1;i<=g.num_point;i++){
		par[i] = i;
	}
	int num_point_treeT = 0;
	for(i=0; i<g.num_edge; i++){
		int u, v, w, root_u, root_v;
		u = g.edges[i].u;
		v = g.edges[i].v;
		w = g.edges[i].w;
		root_u = find_root(u);
		root_v = find_root(v);
		if(root_u != root_v){
			par[root_v] = root_u;
			add_edge(&t, u, v, w);
			*sum += w;
			num_point_treeT++;
			if(num_point_treeT == t.num_point-1)
				return t;
		}
	}
	return t;
}
int main(){
	int n,m,x,y,z,i;
	Graph g;
	scanf("%d%d", &n, &m);
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		add_edge(&g, x, y ,z);
	}
	int sum_edge = 0;
	Graph t = kruskal(g, &sum_edge);
	printf("%d\n", sum_edge);
	for(i=0; i<t.num_edge; i++){
		printf("%d %d %d\n", t.edges[i].u, t.edges[i].v, t.edges[i].w);
	}
	return 0;
}
