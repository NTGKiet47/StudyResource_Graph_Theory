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
int white = 0, black = 1, gray = 2;
int color[MAX];
int cycle = 0;
void travel(Graph g, int p, int par){
	color[p] = gray;
	int i;
	for(i=1;i<=g.n;i++){
		if(g.ar_graph[p][i]==1){
			if(i==par) continue;
			if(color[i]==white){
				travel(g, i, p);
			}
			if(color[i]==gray){
				cycle = 1;
				return;
			}
		}
	}
	color[p] = black;
}
void is_cycle(Graph g){
	int i;
	for(i=1;i<=g.n;i++){
		color[i] = white;
	}
	travel(g, i, -1);
	for(i=1;i<=g.n;i++)
		if(color[i]==white)
			travel(g, i, -1);
	if(cycle == 1)
		printf("YES");
	else
		printf("NO");
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
	is_cycle(g);
	return 0;
}
