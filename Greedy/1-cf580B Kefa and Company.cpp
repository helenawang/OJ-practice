#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 100005;

int n, d;
int maxx = 0, minn = 1000000001;
struct Person
{
	int m, s;
}per[MAX_N];

bool cmp(Person p1, Person p2){
	if(p1.m == p2.m) return p1.s > p2.s; //m相等时，s大的优先 
	return p1.m < p2.m; //按m由小到大排 
}

bool out(int x){
	if(x <= maxx-d || x >= minn + d) return true;
	minn = x < minn ? x : minn;
	maxx = x > maxx ? x : maxx;
	return false;
}

int dif(int x, int y){
	int z = x - y;
	return z>=0 ? z : -z;
}

int main()
{
	//freopen("1005.txt", "r", stdin);
	scanf("%d%d", &n, &d);
	for(int i=0; i<n; i++)
		scanf("%d%d", &per[i].m, &per[i].s);
	if(n==1) printf("%d\n", per[0].s);
	else{
		sort(per, per+n, cmp);
//		for(int i=0; i<n; i++)
//			printf("%d %d\n",  per[i].m, per[i].s);
		long long max_sum = 0;
		long long cur_sum = 0;
		int start = 0;  
		for(int i=0; i<n; i++){
			while(start < i && per[i].m - per[start].m >= d){
				cur_sum -= per[start].s;
				start++;
			} //不满足时，定位新起点 ，最多追上i 
			cur_sum += per[i].s;
			max_sum = cur_sum > max_sum ? cur_sum : max_sum; 
		}
		
		printf("%I64d\n", max_sum);
	}
	
	return 0;
}
