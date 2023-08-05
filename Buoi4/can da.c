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
	g->ar_graph[x][y] = 1;
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
	make_null_list(l1);
	int i;
	for(i=1;i<=l2->num_list;i++){
		add_list(l1, ele_at_list(*l2, i));
	}
}
void can_da(Graph g){
	int i, j, u, v, k, rank[MAX], d[MAX];
	for(i=1;i<=g.num_graph;i++){
		rank[i] = d[i] = 0;
		for(j=1;j<=g.num_graph;j++)
			if(g.ar_graph[j][i]==1)
				d[i]++;
	}
	List l1, l2, res;
	make_null_list(&l1);
	make_null_list(&res);
	for(i=1;i<=g.num_graph;i++){
		if(d[i]==0)
			add_list(&l1, i);
	}
	k = 1;
	while(l1.num_list > 0){
		make_null_list(&l2);
		for(i=1;i<=l1.num_list;i++){
			u = ele_at_list(l1, i);
			if(rank[u]!=0) continue;
			rank[u] = k++;
			add_list(&res, u);
			for(v=1;v<=g.num_graph;v++){
				if(g.ar_graph[u][v]==1){
					d[v]--;
				}
				if(d[v]==0 && rank[v]==0){
					add_list(&l2, v);
				}
			}
		}
		copy_list(&l1, &l2);
	}
	for(i=1;i<=res.num_list;i++)
		printf("%d\n", ele_at_list(res, i));
}

int main(){
	
	int n,m,x,y;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d", &x, &y);
		add_edge(&g, x, y);
	}
	can_da(g);
	
	return 0;
}
