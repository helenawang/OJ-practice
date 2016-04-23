#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 22;

int n, m;
int G[MAX_N][MAX_N]; 
int dx[]={0, 0, 1,-1}, dy[]={1, -1, 0, 0};
int sx, sy, gx, gy;
int min_ans;


bool inside(int x, int y){
	if(x<0 || x>=n || y<0 || y>=m) return false;
	return true;
}

void dfs(int x, int y, int cnt){
	if(cnt > 10) return ;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!inside(x, y)) continue; //出界
		if(G[nx][ny] == 1) continue; //block
		else{
			while(inside(nx, ny) && G[nx][ny] != 1 && G[nx][ny] != 3){	
				nx += dx[i];
				ny += dy[i]; //沿此方向走到block为止
			}
			if(!inside(nx, ny)) continue; //此方向最终出界
			if(G[nx][ny] == 3){
				min_ans = cnt<min_ans ? cnt : min_ans;
				continue; //此方向中途命中
			} 

			G[nx][ny] = 0; //block消失
			nx -= dx[i];
			ny -= dy[i]; //抵达此方向最后一个合法位置，block的前一个
			//printf("%d %d\n", dx[i], dy[i]);
			dfs(nx, ny, cnt+1);
			nx += dx[i];
			ny += dy[i];
			G[nx][ny] = 1; //还原，回溯
		}
	}
	return ;
}

int main()
{
	freopen("3009.txt", "r", stdin);
	while(scanf("%d%d", &m, &n) != EOF){
		if(m==0 && n==0) break;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &G[i][j]);
				if(G[i][j] == 2){
					sx = i;
					sy = j;
				}else if(G[i][j] == 3){
					gx = i;
					gy = j;
				}
			}
		}
		
		min_ans = 29; //任意大于10的值
		dfs(sx, sy, 1); //投掷第一次
		if(min_ans > 10) min_ans = -1;
		printf("%d\n", min_ans);
	}
	return 0;
}


