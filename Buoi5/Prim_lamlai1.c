#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef struct{
	int ar[MAX][MAX];
	int num_point;
}Graph;
void init_graph(Graph *g, int n){
	g->num_point = n;
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar[i][j] = 0;
}
void add_edge(Graph *g, int x, int y, int z){
	g->ar[x][y] = g->ar[y][x] = z;
}
typedef struct{
	int ar[MAX];
	int num_list;
}List;
void make_null_list(List *l){
	l->num_list = 0;
}
void add_list(List *l, int ele){
	l->ar[l->num_list] = ele;
	l->num_list++;
}
int ele_at_list(List l, int pos){
	return l.ar[pos-1];
}
int closet_point(int p, List s, Graph g){
	int min_dis = INF;
	int min_point = -1;
	int i;
	for(i=1; i<=s.num_list; i++){
		int v = ele_at_list(s, i);
		if(g.ar[p][v]!=0 && min_dis > g.ar[p][v]){
			min_dis = g.ar[p][v];
			min_point = v;
		}
	}
	return min_point;
}
void prim(Graph g){
	Graph t;
	init_graph(&t, g.num_point);
	int i, j, u, v, mark[MAX], sum = 0;
	for(i=1;i<=g.num_point;i++)
		mark[i] = 0;
	List l;
	make_null_list(&l);
	add_list(&l, 1);
	mark[1] = 1;
	for(i=1;i<g.num_point;i++){
		int min_dis = INF;
		int min_u = -1, min_v = -1;
		for(u=1;u<=g.num_point;u++){
			if(mark[u]==0){
				v = closet_point(u, l, g);
				if(v!=-1 && g.ar[u][v] < min_dis){
					min_dis = g.ar[u][v];
					min_u = u;
					min_v = v;
				}
			}
		}
		add_list(&l, min_u);
		mark[min_u] = 1;
		add_edge(&t, min_u, min_v, min_dis);
		sum+=min_dis;
	}
	printf("%d\n", sum);
	for(i=1;i<=t.num_point;i++){
		for(j=i+1;j<=t.num_point;j++){
			if(t.ar[i][j]!=0){
				if(i<=j)
					printf("%d %d %d\n", i, j, t.ar[i][j]);
				else
					printf("%d %d %d\n", j, i, t.ar[i][j]);
			}
		}
	}
}
int main(){
	int n,m,x,y,z;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		add_edge(&g, x, y, z);
	}
	prim(g);
	return 0;
}
