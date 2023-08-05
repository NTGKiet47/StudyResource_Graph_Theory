#include<stdio.h>
#define INF 9999999
void find_way(int a[][100], int n, int m){
	int ts[100][100];
	int i, j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			ts[i][j] = 0;
	ts[1][1] = a[1][1];
	int left, up;
	i=1;j=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			left = up = INF;
			if(i==1 && j==1) continue;
			if(i==1)
				left = ts[i][j-1] + a[i][j];
			if(j==1)
				up = ts[i-1][j] + a[i][j];
			if(i>1 && j>1){
				left = ts[i][j-1] + a[i][j];
				up = ts[i-1][j] + a[i][j];
			}
			ts[i][j] += (left<up?left:up);
		}
	}
	printf("%d", ts[n][m]);
}
int main(){
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	int a[100][100];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d", &a[i][j]);
	find_way(a, n, m);	
	return 0;
}
