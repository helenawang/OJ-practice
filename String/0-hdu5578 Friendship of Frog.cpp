#include <cstdio>
using namespace std;
const int MAX_N = 1000;
const int INF = 10000;
int T;
int n;
char frogs[MAX_N];
int ans;

int main()
{
	freopen("in", "r", stdin);
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		scanf("%s", frogs);
		ans = INF;
		for(int j=0; frogs[j]!='\0'; j++){
			for(int k=j+1; frogs[k]!='\0'; k++){
				if(frogs[j] == frogs[k]){
					ans = k-j < ans ? k-j : ans;
					break;
				}
			}
		}
		if(ans == INF) ans = -1;
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}