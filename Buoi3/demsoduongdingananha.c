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
void add_edge(Graph *g, int x, int y, int w){
	g->ar_graph[x][y] = w;
	g->ar_graph[y][x] = w;
}
void moore_dijktra(Graph g){
	int pi[MAX], cnt[MAX], mark[MAX];
	int i, j, k, min = INF;
	for(i=1;i<=g.num_graph;i++){
		pi[i] = INF;
		mark[i] = cnt[i] = 0;
	}
	pi[1] = 0;
	for(i=1;i<g.num_graph;i++){
		min = INF;
		for(j=1;j<=g.num_graph;j++){
			if(pi[j] < min && mark[j] == 0){
				min = pi[j];
				k = j;
			}
		}
		mark[k] = 1;
		cnt[k] = 1;
		for(j=1;j<=g.num_graph;j++){
			if(g.ar_graph[k][j]!=0 && mark[j]==0){
				if(pi[j] > g.ar_graph[k][j] + pi[k]){
					pi[j] = g.ar_graph[k][j] + pi[k];
					cnt[j] += 1;
				}else if(pi[j] == g.ar_graph[k][j] + pi[k]){
					pi[j] = g.ar_graph[k][j] + pi[k];
					cnt[j] += cnt[k];
				}
			}
		}
	}
	if(pi[g.num_graph]==INF)
		printf("-1 0");
	else
		printf("%d %d", pi[g.num_graph], cnt[g.num_graph]);
}
int main(){
	Graph g;
	int n, m;
	scanf("%d%d", &n, &m);
	init_graph(&g, n);
	while(m--){
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add_edge(&g, x, y, w);
	}
	moore_dijktra(g);
	return 0;
}
