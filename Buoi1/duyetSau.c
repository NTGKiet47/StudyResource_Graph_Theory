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
typedef struct{
	int ar_stack[MAX];
	int num_stack;
}Stack;
void make_null_stack(Stack *s){
	s->num_stack = 0;
}
void add_stack(Stack *s, int ele){
	s->ar_stack[s->num_stack] = ele;
	s->num_stack++;
}
int top(Stack s){
	return s.ar_stack[s.num_stack-1];
}
void pop(Stack *s){
	s->num_stack--;
}
int empty_stack(Stack s){
	return s.num_stack==0;
}
void deaph_first_search(Graph g){
	int mark[MAX], pre[MAX];
	int i, u ,v;
	for(i=1;i<=g.n;i++){
		mark[i] = 0;
		pre[i] = -1;
	}
	Stack s;
	make_null_stack(&s);
	add_stack(&s, 1);
	pre[1] = 0;
	while(!empty_stack(s)){
		u = top(s);
		pop(&s);
		if(mark[u]==1) continue;
		mark[u] = 1;
		for(v=1;v<=g.n;v++){
			if(g.ar_graph[u][v]==1){
				if(mark[v]==0){
					add_stack(&s, v);
					pre[v] = u;
				}
			}
		}
		if(empty_stack(s)){
			for(i=1;i<=g.n;i++){
				if(mark[i]==0){
					add_stack(&s, i);
					pre[i] = 0;
					break;
				}
			}
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
	deaph_first_search(g);
	return 0;
}
