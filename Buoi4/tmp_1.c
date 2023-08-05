#include<stdio.h>
#define MAX 100
#define INF 9999999
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
int min(int a, int b){
	return a<b?a:b;
}
int max(int a, int b){
	return a>b?a:b;
}
void print_list(List l){
	int i;
	for(i=1;i<=l.num_list;i++)
		printf("%d, ", ele_at_list(l, i));
}
void rank_job(Graph g, int dur[]){
	int deg_in[MAX], deg_out[MAX], rank[MAX];
	int i,j,u,v,k=1, max_rank;
	for(i=1;i<=g.num_graph;i++){
		deg_in[i] = deg_out[i] = rank[i] = 0;
		for(j=1;j<=g.num_graph;j++){
			if(g.ar_graph[j][i]!=0)
				deg_in[i]++;
			if(g.ar_graph[i][j]!=0)
				deg_out[i]--;
		}
	}
	List l1, l2, topo_sort;
	make_null_list(&l1);
	make_null_list(&topo_sort);
	for(i=1;i<=g.num_graph;i++)
		if(deg_in[i]==0)
			add_list(&l1, i);
	while(l1.num_list > 0){
		make_null_list(&l2);
		for(i=1;i<=l1.num_list;i++){
			u = ele_at_list(l1, i);
			if(rank[u] != 0) continue;
			rank[u] = k;
			max_rank = k;
			add_list(&topo_sort, u);
			for(v=1;v<=g.num_graph;v++){
				if(g.ar_graph[u][v]!=0){
					deg_in[v]--;
				}
				if(deg_in[v]==0 && rank[v]==0)
					add_list(&l2, v);
			}
		}
		k++;
		copy_list(&l1, &l2);
	}
	int t[MAX], T[MAX], tong_thgian = 0;
	for(i=1;i<=g.num_graph;i++){
		if(rank[i]==1)
			t[i] = 0;
		else
			t[i] = INF;
		T[i] = -1;
	}
	for(i=1;i<=topo_sort.num_list;i++){
		u = ele_at_list(topo_sort, i);
		if(t[u]==0) continue;
		for(v=1;v<=g.num_graph;v++){
			if(g.ar_graph[v][u]!=0){
				if(t[u]==INF)
					t[u] = min(t[u], t[v]+dur[v]);
				else
					t[u] = max(t[u], t[v]+dur[v]);
			}
		}
	}
	int max_t = -1;
	for(i=topo_sort.num_list;i>=1;i--){
		u = ele_at_list(topo_sort, i);
		if(rank[u]==max_rank){
			if(max_t < t[u])
				max_t = t[u] + dur[u];
		}
	}
	printf("%d", max_t);
}
int main(){
	int n, m, x, y, i, dur[MAX];
	Graph g;
	FILE *f = fopen("test.txt", "r");
	if(f!=NULL) {
		while(!feof(f)){
			fscanf(f, "%d", &n);
			init_graph(&g, n);
			for(i=1;i<=n;i++)
				fscanf(f, "%d", &dur[i]);
			fscanf(f, "%d", &m);
			while(m--){
				fscanf(f, "%d%d", &x, &y);
				add_edge(&g, x, y);
			}			
		}
	}
	rank_job(g, dur);
	return 0;
}
