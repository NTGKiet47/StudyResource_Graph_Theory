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
	int i;
	make_null_list(l1);
	for(i=1;i<=l2->num_list;i++){
		add_list(l1, ele_at_list(*l2, i));
	}
}
void hang_daBanh(Graph g){
	int i, j, k=1, n = g.num_graph;
	int rank[n+1], d[n+1];
	for(i=1;i<=n;i++){
		rank[i] = -1;
		d[i] = 0;
		for(j=1;j<=n;j++)
			if(g.ar_graph[j][i] == 1)
				d[i]++;
	}
	List s1, s2;
	make_null_list(&s1);
	for(i=1;i<=n;i++){
		if(d[i]==0)
			add_list(&s1, i);
	}
	while(s1.num_list > 0){
		make_null_list(&s2);
		for(i=1;i<=s1.num_list;i++){
			int u, v;
			u = ele_at_list(s1, i);
			if(rank[u]!=-1) continue;
			rank[u] = k;
			for(v=1;v<=g.num_graph;v++){
				if(g.ar_graph[u][v]==1)
					d[v]--;
				if(d[v]==0 && rank[v]==-1){
					add_list(&s2, v);
				}	
			}
		}
		copy_list(&s1, &s2);
		k++;
	}
	for(i=1;i<=n;i++){
		printf("%d ", rank[i]);
	}
}
int main(){
	Graph g;
	int n, i, j, u;
	scanf("%d", &n);
	init_graph(&g, n);
	int dur[MAX];
	for(i=1;i<=n;i++){
		scanf("%d", &dur[i]);
		while(1){
			scanf("%d", &u);
			if(u==0)
				break;
			add_edge(&g, i, u);
		}
	}
	
	return 0;
}
