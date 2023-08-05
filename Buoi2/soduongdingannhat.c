#include<stdio.h>
#define MAX 100
#define INF 9999999
typedef struct{
	int ar_graph[MAX][MAX];
	int n;
}Graph;
void init_graph(Graph *g, int n){
	int i, j;
	g->n = n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g->ar_graph[i][j] = -1;
}
void add_edge(Graph *g, int x, int y, int w){
	g->ar_graph[x][y] = w;
	g->ar_graph[y][x] = w;
}
void moore_dijktra(Graph g){
	int pi[MAX], mark[MAX], cnt[MAX];
	int i, j, k, min_pi = INF;
	for(i=1;i<=g.n;i++){
		pi[i] = INF;
		mark[i] = 0;
		cnt[i] = 0;
	}
	pi[1] = 0;
	cnt[1] = 1;
	for(i=1;i<=g.n;i++){
		min_pi = INF;
		for(j=1;j<=g.n;j++){
			if(pi[j] < min_pi && mark[j]==0){
				min_pi = pi[j];
				k = j;
			}
		}
		mark[k] = 1;
		for(j=1;j<=g.n;j++){
			if(g.ar_graph[k][j]!=-1 && mark[j]==0){
				if(g.ar_graph[k][j] + pi[k] < pi[j]){
					pi[j] = g.ar_graph[k][j] + pi[k];
					cnt[i] = cnt[k];
				}else if(g.ar_graph[k][j] + pi[k] == pi[j]){
					cnt[i] += cnt[k];
				}
			}
		}
	}
	if(pi[g.n]==INF)
		printf("-1 0");
	else
		printf("%d %d", pi[g.n], cnt[g.n]);
}
int main(){
	int n, m ,x,y,w;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d%d", &x, &y, &w);
		add_edge(&g, x, y, w);
	}
	moore_dijktra(g);	
	return 0;
}
