#include<stdio.h>
#define MAX 100

typedef struct{
	int ar_graph[MAX][MAX];
	int n;
}Graph;
void init_graph(Graph *g, int n){
	g->n = n;
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j]=0;
}
void add_edge(Graph *g, int x, int y){
	g->ar_graph[x][y] = g->ar_graph[y][x] = 1;
}
int mark[MAX];
int pre[MAX];
void travel(Graph g, int p){
	if(mark[p]==1)
		return;
	mark[p] = 1;
	int i;
	for(i=1;i<=g.n;i++){
		if(g.ar_graph[p][i]==1){
			if(mark[i]==0){
				pre[i] = p;
				travel(g, i);
			}
		}
	}
}
void dfs_recursion(Graph g){
	int i;
	for(i=1;i<=g.n;i++){
		mark[i] = 0;
		pre[i] = -1;
	}
	pre[1] = 0;
	travel(g, 1);
	for(i=1;i<=g.n;i++){
		if(mark[i]==0){
			pre[i] = 0;
			travel(g, i);
			break;
		}
	}
	for(i=1;i<=g.n;i++)
		printf("%d %d\n", i, pre[i]);
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
	dfs_recursion(g);
	return 0;
}
