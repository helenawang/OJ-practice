#include <cstdio>
#include <cmath>
using namespace std;

int T;
int ex, ey;

int main()
{
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++){
		scanf("%d%d", &ex, &ey);
		int cnt = 1;
		int flag = 1;
		while(flag){
			if(ex == ey) break;
			flag = 0;
			if(ex > ey){
				int x;
				for(int i=ex - ey; i >= sqrt(ex - ey); i--){
					if(ey % i == 0){ //枚举gcd(x, ey)
						if(ex % (1 + ey / i) == 0){
							x = ex / (1 + ey / i);
							if(x % i == 0){
								flag = 1;
								//printf("%d can be divided by %d\n", x, i);
								break;
							}
						}else if(ex % (1 + i) == 0){
							x = ex / (1 + i);
							if(x % i == 0){
								flag = 1;
								//printf("%d can be divided by %d\n", x, i);
								break;
							}
						}
					}
				}
				if(flag){
					ex = x;
					//printf("(%d, %d)\n", ex, ey);
					cnt++;
				}else break;
			}else{
				int y;
				for(int i=ey - ex; i >= (ey - ex)>>1; i--){
					if(ex % i == 0){ //枚举gcd(ex, y)
						if(ey % (1 + ex / i) == 0){
							y = ey / (1 + ex / i);
							if(y % i == 0){
								//printf("%d can be divided by %d\n", y, i);
								flag = 1;
								break;
							}
						}else if(ey % (1 + i) == 0){
							y = ey / (1 + i);
							if(y % i == 0){
								//printf("%d can be divided by %d\n", y, i);
								flag = 1;
								break;
							}
						}
					}
				}
				if(flag){
					ey = y;
					//printf("(%d, %d)\n", ex, ey);
					cnt++;
				}else break;
			}
		}
		printf("Case #%d: %d\n", ca, cnt);
	}
	return 0;
}