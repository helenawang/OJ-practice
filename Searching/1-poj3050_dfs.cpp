#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;

int G[5][5];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
set<int> dif;

bool inside(int x, int y){
	if(x<0 || x>=5 || y<0 || y>=5) return false;
	return true;
}

void dfs(int x, int y, int step, int sum){
	if(step==6){
		dif.insert(sum);
		return ;
	}
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!inside(nx, ny)) continue;
		dfs(nx, ny, step+1, sum*10 + G[nx][ny]); //用形参传递当前路径，免去回溯 
	}
}


int main()
{
	freopen("3050.txt", "r", stdin);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
			scanf("%d", &G[i][j]);
	}
	
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			dfs(i, j, 1, G[i][j]);
		}
	}
	printf("%d\n", dif.size());
	// for(set<string>::iterator iter = dif.begin(); iter != dif.end(); iter++){
	// 	printf("%s\n", iter->c_str());
	// }
	return 0;
}
