#include<stdio.h>
#define MAX 100
typedef struct{
	int ar_graph[MAX][MAX];
	int n;
}Graph;
void init_graph(Graph *g, int n){
	int i, j;
	g->n = n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j] = 0;
}
void add_edge(Graph *g, int x, int y){
	g->ar_graph[x][y] = g->ar_graph[y][x] = 1;
}
int side[MAX];
int is_devide = 1;
void travel(Graph g, int p, int s){
	if(side[p]==(-1)*s){
		is_devide = 0;
		return;
	}else{
		if(side[p] == 0){
			side[p] = s;
			int i;
			for(i=1;i<=g.n;i++){
				if(g.ar_graph[p][i]==1)
					travel(g, i, (-1)*s);
			}
		}
	}
}
void devide_graph(Graph g){
	int i;
	for(i=1;i<=g.n;i++)
		side[i] = 0;
	travel(g, 1, 1);
	for(i=1;i<=g.n;i++){
		if(side[i]==0)	
			travel(g, i, 1);
	}
	if(is_devide==0)	
		printf("IMPOSSIBLE");
	else{
		for(i=1;i<=g.n;i++){
			if(side[i]==side[1])
				printf("%d ", i);
		}printf("\n");
		for(i=1;i<=g.n;i++)
			if(side[i]!=side[1])
				printf("%d ", i);
	}
}
int main(){
	int n, m , x, y;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d", &x, &y);
		add_edge(&g, x, y);
	}
	devide_graph(g);
	return 0;
}
