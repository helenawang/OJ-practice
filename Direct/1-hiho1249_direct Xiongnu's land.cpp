#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_R = 1000005;
const int MAX_N = 10005;

int K;
int R, N;
struct Rec{
	int L, T;
	long long W, H; //注意类型！！
}rec[MAX_N];
int x[MAX_R];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&K);
	while(K--){
		scanf("%d",&R);
		scanf("%d",&N);
		memset(x,0,sizeof(x));
		long long sum = 0;
		for(int i=0; i<N; i++){
			scanf("%d%d%d%d",&rec[i].L,&rec[i].T,&rec[i].W,&rec[i].H);
			sum += rec[i].W*rec[i].H;
			for(int j=rec[i].L; j<rec[i].L+rec[i].W; j++)
				x[j] += rec[i].H;
		}
		long long wei = 0;
		int i;
		for(i=0; wei*2 < sum; i++)
			wei += x[i];
		while(x[i]==0 && i<R) i++;
		printf("%d\n",i);
	}
	return 0;
}
