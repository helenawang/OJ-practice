#include <cstdio>
using namespace std;

int T;
__int64 N;
int k;

int main()
{
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%I64d %d", &N, &k);
		printf("Case #%d:\n", ca);
		int even = 0;
		if(!(N&1)){ //偶数归为等同的奇数处理
			even = 1;
			N = N>0 ? N-1 : N+1;
		} 
		__int64 bits = ((__int64)1 << k) - 1 + N;
		bits >>= 1;
		__int64 cur = 1;
		for(int i=0; i<k-1; i++){
			printf("%I64d %c\n", cur, (bits&1) ? '+' : '-');
			bits >>= 1;	
			cur <<= 1;
		}
		printf("%I64d %c\n", even ? ((__int64)1 << (k-1))+1 : (__int64)1 << (k-1), 
			(bits&1) ? '+' : '-');
	}
	return 0;
}
