#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef struct{
	int ar_graph[MAX][MAX];
	int num_point;
}Graph;
void init_graph(Graph *g, int n){
	g->num_point = n;
	int i, j;
	for(i=1;i<=n; i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j] = 0;
}
void add_edge(Graph *g, int x, int y, int w){
	g->ar_graph[x][y] = w;
	g->ar_graph[y][x] = w;
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

int distance_from(int p, List s, Graph g){
	int min_dis = INF;
	int min_v = -1;
	int i;
	for(i=1;i<=s.num_list;i++){
		int v = ele_at_list(s, i);
		if(g.ar_graph[p][v] != 0 && min_dis > g.ar_graph[p][v]){
			min_dis = g.ar_graph[p][v];
			min_v = v;
		}
	}
	return min_v;
}
int prim(Graph g, Graph *t){
	int sum = 0;
	int i, u, v, mark[MAX];
	for(i=1; i<=g.num_point; i++){
		mark[i] = 0;
	}
	List l;
	make_null_list(&l);
	add_list(&l, 1);
	mark[1] = 1;
	for(i=1;i<g.num_point;i++){
		int min_dis = INF, min_u = -1, min_v = -1;
		for(u=1;u<=g.num_point;u++){
			// chua co trong list
			if(mark[u]==0){
				// tim dinh gan dinh u nhat
				v = distance_from(u, l, g);
				if(v!=-1 && g.ar_graph[u][v] < min_dis){
					min_dis = g.ar_graph[u][v];
					min_u = u;
					min_v = v;
				}
			}
		}
		add_list(&l, min_u);
		mark[min_u] = 1;
		add_edge(t, min_u, min_v, min_dis);
		sum += min_dis;
	}
	return sum;
}
int main(){
	Graph g;
	int n,m,x,y,z;
	scanf("%d%d", &n, &m);
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		add_edge(&g, x, y, z);
	}
	Graph t;
	init_graph(&t, n);
	int sum = prim(g, &t);
	printf("%d\n", sum);
	int i, j;
	for(i=1; i<=t.num_point;i++){
		for(j=i+1; j<=t.num_point;j++){
			if(t.ar_graph[i][j]!=0)
				if(i<=j)
					printf("%d %d %d\n", i, j, t.ar_graph[i][j]);
				else
					printf("%d %d %d\n", j, i, t.ar_graph[i][j]);
		}
	}
	return 0;
}
