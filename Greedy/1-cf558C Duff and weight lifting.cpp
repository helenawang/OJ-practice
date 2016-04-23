#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;

int n;
int w[MAX_N];

struct cmp{
	bool operator()(const ll&a, const ll&b){
		return a>b;
	}	
};
priority_queue<ll, vector<ll>, cmp > que;

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &w[i]);
		que.push(w[i]);
	}
	int cnt = 0;
	while(que.size() >= 2){
		int a = que.top();
		que.pop();
		int b = que.top();
		que.pop();
		//printf("%d %d\n", a, b);
		if(a==b) que.push(a+1);
		else{
			cnt++;
			que.push(b);
		}
	}
	if(que.size() == 1) cnt++;
	printf("%d\n", cnt);
	return 0;
}
