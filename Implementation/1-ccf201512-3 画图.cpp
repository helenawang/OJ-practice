#include <cstdio>
#include <cstring>
using namespace std;

int m, n, q;
char A[105][105];
int x1, y1, x2, y2;
int x, y;
char c;
int dx[]={0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
int visited[105][105];

void dfs(int xx, int yy){
	A[xx][yy] = c;
	visited[xx][yy] = 1;
	for(int i=0; i<4; i++){
		int nx = xx + dx[i];
		int ny = yy + dy[i];
		if(nx<0 || nx>n || ny<0 || ny>m) continue;
		if(A[nx][ny]=='|' || A[nx][ny]=='-' || A[nx][ny] == '+') continue;
		if(visited[nx][ny]) continue;
		dfs(nx, ny);
	}
	return ;
}

int main()
{
	freopen("201512-3.txt","r",stdin);
	for(int i=0; i<105; i++)
		for(int j=0; j<105; j++)
			A[i][j] = '.';
	scanf("%d%d%d",&n, &m, &q); //n行m列 
	while(q--){
		int comm;
		scanf("%d",&comm);
		switch(comm){
			case 0:
				scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
				
				if(x1 == x2){
					if(y1 < y2){
						for(int i=y1; i<=y2; i++){
							if(A[x1][i] == '-' || A[x1][i] == '+') //注意这里 
								A[x1][i] = '+';
							else A[x1][i] = '|';
						}
					}else{
						for(int i=y2; i<=y1; i++){
							if(A[x1][i] == '-' || A[x1][i] == '+')
								A[x1][i] = '+';
							else A[x1][i] = '|';
						}
					}
				}else if(y1 == y2){
					if(x1 < x2){
						for(int i=x1; i<=x2; i++){
							if(A[i][y1] == '|' || A[i][y1] == '+')
								A[i][y1] = '+';
							else A[i][y1] = '-';
						}	
					}else{
						for(int i=x2; i<=x1; i++){
							if(A[i][y1] == '|' || A[i][y1] == '+')
								A[i][y1] = '+';
							else A[i][y1] = '-';
						}
					}
				}
				break;
			case 1:
				scanf("%d%d %c",&x, &y, &c);
				memset(visited,0,sizeof(visited));
				//printf("%d %d %c\n",x, y, c);
				dfs(x, y);
				break;
		}
		}
	for(int i=m-1; i>=0; i--){
		for(int j=0; j<n; j++){
			printf("%c",A[j][i]);
		}
		printf("\n");
	}
	return 0;
}
