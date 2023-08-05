#include<stdio.h>

#define MAX 100
#define INF 9999999
#define NO_EDGE 0
#define UNRANK -1

/*
7
8 0
17 4 1 0
15 6 2 7 5 4 0
14 0
7 0
18 4 5 0
1 6 2 0
*/
typedef struct{
	int ar_graph[MAX][MAX];
	int num_graph;
}Graph;
void init_graph(Graph *g, int n){
	g->num_graph = n;
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j] = NO_EDGE;
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
// ham nay sap xep cac cong viec theo thu hang (Thu tu TOPO)
void quanLy_duAn(Graph g, int dur[]){
	int deg_in[MAX], deg_out[MAX], rank[MAX];
	int i, j, u, v, k=1, num = g.num_graph, total_time;
	for(i=1;i<=num;i++){
		rank[i] = UNRANK;
		deg_in[i] = deg_out[i] = 0;
		for(j=1;j<=num;j++){
			if(g.ar_graph[j][i]==1)
				deg_in[i]++;
			if(g.ar_graph[i][j]==1)
				deg_out[i]++;
		}
	}
	List l1, l2, thu_tu;
	make_null_list(&l1);
	make_null_list(&thu_tu);
	for(i=1;i<=num;i++)
		if(deg_in[i]==0)
			add_list(&l1, i);
	while(l1.num_list > 0){
		make_null_list(&l2);
		for(i=1;i<=l1.num_list;i++){
			u = ele_at_list(l1, i);
			if(rank[u]!=UNRANK) continue;
			rank[u] = k;
			add_list(&thu_tu, u);
			for(v=1;v<=g.num_graph;v++){
				if(g.ar_graph[u][v]==1)
					deg_in[v]--;
				if(deg_in[v]==0 && rank[v]==UNRANK)
					add_list(&l2, v);
			}
		}
		copy_list(&l1, &l2);
		k++;
	}
	int t[MAX], T[MAX];
	for(i=1;i<=g.num_graph;i++){
		if(rank[i]==1)
			t[i] = 0;
		else{
			t[i] = INF;
		}
		T[i] = -1;
	}
	for(i=1;i<=thu_tu.num_list;i++){
		u = ele_at_list(thu_tu, i);
		if(t[u] == 0) continue;
		for(v=1;v<=g.num_graph;v++){
			if(g.ar_graph[v][u] == 1){
				if(t[u]==INF){
					t[u] = min(t[u], t[v]+dur[v]);
				}else{
					t[u] = max(t[u], t[v]+dur[v]);
				}
			}
		}
	}
	for(i=1;i<=thu_tu.num_list;i++)
		if(rank[i] == k-1){
			total_time = t[i];
			T[i] = total_time;			
		}
	for(i=thu_tu.num_list;i>=1;i--){
		u = ele_at_list(thu_tu, i);
		if(T[u] == total_time) continue;
		for(j=thu_tu.num_list;j>i;j--){
			v = ele_at_list(thu_tu, j);
			if(g.ar_graph[u][v]==1){
				if(T[u]==-1){
					T[u] = max(T[u], T[v]-dur[u]);
				}else{
					T[u] = min(T[u], T[v]-dur[u]);
				}
			}
		}
	}
//	for(i=1;i<=g.num_graph;i++)
//		printf("%d rank = %d\n", i, rank[i]);
	for(i=1;i<=g.num_graph;i++)
		printf("%d %d\n", t[i], T[i]);
}
int main(){
	int n, i, j, dur[MAX];
	scanf("%d", &n);
	Graph g;
	init_graph(&g, n);
	for(i=1;i<=n;i++){
		scanf("%d", &dur[i]);
		while(1){
			scanf("%d", &j);
			if(j==0)
				break;
			add_edge(&g, j, i);
		}
	}
	quanLy_duAn(g, dur);
	return 0;
}
