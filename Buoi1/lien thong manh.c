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
	g->ar_graph[x][y] = 1;
}
int min(int a, int b){
	return a<b?a:b;
}
int on_stack[MAX];
int num[MAX];
int low[MAX];
int k = 1, count = 0;
void travel(Graph g, int p){
	num[p] = low[p] = k++;
	on_stack[p] = 1;
	int i;
	for(i=1;i<=g.n;i++){
		if(g.ar_graph[p][i]==1){
			if(num[i] == 0){
				travel(g, i);
				low[p] = min(low[i], low[p]);
			}else{
				if(on_stack[i]==1){
					low[p] = min(low[p], num[i]);
				}
			}
		}
	}
	if(num[p] == low[p])
		count++;
}
void is_connect(Graph g){
	int i, is_full_checked = 1;
	for(i=1;i<=g.n;i++){
		num[i] = low[i] = on_stack[i] = 0;
	}
	travel(g, 1);
	for(i=1;i<=g.n;i++){
		if(on_stack[i]==0){
			is_full_checked = 0;
			break;
		}
	}
	if(is_full_checked==0 || count>1){
		printf("unconnected");
	}else{
		printf("strong connected");
	}
}
int main(){
	
	int n, m ,x,y;
	scanf("%d%d", &n, &m);
	Graph g;
	init_graph(&g, n);
	while(m--){
		scanf("%d%d", &x, &y);
		add_edge(&g, x, y);
	}
	is_connect(g);	
	return 0;
}
