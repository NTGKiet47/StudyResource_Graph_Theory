#include<stdio.h>

#define MAX 100

typedef struct{
	int ar_graph[MAX][MAX];
	int num_graph;
}Graph;
void init_graph(Graph *g, int n){
	g->num_graph = n;
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j] = 0;
}
void add_edge(Graph *g, int x, int y){
	g->ar_graph[y][x] == 1;
}
typedef struct{
	int ar_list[MAX];
	int num_list;
}List;
void make_null_list(List *l){
	l->num_list = 0;
}
void add_list(List *l, int ele){
	l->ar_list[l->num_list] = ele;
	l->num_list++;
}
int ele_at_list(List l, int pos){
	return l.ar_list[pos-1];
}
void copy_list(List *l1, List *l2){
	int i;
	make_null_list(l1);
	for(i=1;i<=l2->num_list;i++){
		add_list(l1, ele_at_list(*l2, i));
	}
}
void chia_keo(Graph g){
	int i, j, u, v, rank[MAX], d[MAX], k=1;
	for(i=1;i<=g.num_graph;i++){
		rank[i] = d[i] = 0;
		for(j=1;j<=g.num_graph;j++)
			if(g.ar_graph[j][i]==1)
				d[i]++;
	}
	List l1, l2;
	make_null_list(&l1);
	for(i=1;i<=n;i++){
		if(d[i]==0)
			add_list(&l1, i);
	}
	while(s1.num_list > 0){
		make_null_list(&l2);
		for(i=1;i<=l1.num_list;i++){
			int u, v;
			u = ele_at_list(l1, i);
			if(rank[u]!=-1) continue;
			rank[u] = k;
			for(v=1;v<=g.num_graph;v++){
				if(g.ar_graph[u][v] != 0)
					d[v] -= g.ar_graph[u][v];
				if(d[v]==0 && rank[v]==-1){
					add_list(&l2, v);
				}	
			}
		}
		copy_list(&l1, &l2);
		k++;
	}
	for(i=1;i<=n;i++){
		printf("%d\n", rank[i]);
	}
}

int main(){
	Graph g;
	int n, m;
	scanf("%d%d", &n, &m);
	init_graph(&g, n);
	while(m--){
		int x, y;
		scanf("%d%d", &x, &y);
		add_edge(&g, x, y);
	}
	
	return 0;
}
