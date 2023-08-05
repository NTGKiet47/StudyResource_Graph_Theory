#include<stdio.h>

#define MAX 100
#define INF 9999999
#define NO_EDGE 0
#define UNRANK -1
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
void tong_ngay(Graph g, int dur[]){
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
		printf("%d\n", k);
		k++;
	}
	int t[MAX];
	for(i=1;i<=g.num_graph;i++){
		if(rank[i]==1)
			t[i] = 0;
		else{
			t[i] = INF;
		}
	}
	for(i=1;i<=thu_tu.num_list;i++){
		u = ele_at_list(thu_tu, i);
		if(t[u] == 0) continue;
		for(j=1;j<i;j++){
			v = ele_at_list(thu_tu, j);
			if(g.ar_graph[v][u] == 1){
				if(t[u]==INF){
					t[u] = min(t[u], t[v]+dur[v]);
				}else{
					t[u] = max(t[u], t[v]+dur[v]);
				}
			}
		}
	}
	total_time = -1;
	for(i=1;i<=g.num_graph;i++)
		printf("%d rank = %d, t = %d\n", i, rank[i], t[i]);
	for(i=1;i<=g.num_graph;i++){
		if(rank[i] == k-1){
			if(dur[i]+t[i] > total_time)
				total_time = dur[i]+t[i];
		}
	}
	printf(".......... k = %d \n", k);
	
	printf("%d", total_time);
}

int main(){
	int n, m, x, y, i, dur[MAX];
	FILE *f = fopen("test.txt", "r");
	Graph g;
	fscanf(f, "%d", &n);
	init_graph(&g, n);
	for(i=1;i<=n;i++)
		fscanf(f, "%d", &dur[i]);
	fscanf(f,"%d", &m);
	while(m--){
		fscanf(f, "%d%d", &x, &y);
		add_edge(&g, x, y);
	}
	tong_ngay(g, dur);
	fclose(f);
	return 0;
}
