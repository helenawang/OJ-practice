#include <cstdio>
using namespace std;
const int MAX_N = 100005;
typedef long long ll;

int T;
char frogs[MAX_N];
ll sum;
ll a, b, c; //相邻三个串的长度
ll max_add;

ll abs(ll x){
	return x>=0 ? x: -x;
}

int main()
{
	freopen("2015-sh-k.txt", "r", stdin);
	scanf("%d", &T);
	for(int ca=1; ca<=T; ca++){
		scanf("%s", frogs);
		int length = 0;
		for(int i=0; frogs[i]!='\0'; i++) length++;
		sum = 0;
		max_add = 0;
		a = 1;
		while(frogs[a] == frogs[a-1]) a++; //第一串的长度, a结束时为b串首字符
		sum += a*a;
		if(frogs[a] != '\0') b = 1;
		else b = 0;
		for(int i=a; i<length; i++){
			if(frogs[i+1] != frogs[i]){ //向前看一个字符,不同则b串已结束
				if(b > 1){// 合并a,b
					sum += b*b;
					ll addition = 2*abs(a - b) + 2;//增量
					max_add = addition > max_add ? addition : max_add;
					a = b; //a,b串顺次向前
					b = 1; 
				}else if(b == 1){ //b==1, 合并a,b,c
					sum += b*b;
					//printf("addb %d to sum\n", b);
					i++; //i指向"c串"首字符
					if(frogs[i] == '\0'){
						c = 0;
					}else{
						c = 1;
						while(frogs[i+1] == frogs[i]){
							i++;
							c++;
						} //i指向"d串"首字符
					}
					sum += c*c; //未来的a
					//printf("addc %d to sum\n", c);
					ll addition = 2*(a*c + a + c); //增量
					max_add = addition > max_add ? addition : max_add;
					a = c;
					if(i<length) b = 1;//新的"b串"即为d串, 新的"a串"即为c串
				}		
			}else{
				b++;
			}
		}
		//printf("%d\n", sum);
		printf("Case #%d: %lld\n", ca, max_add + sum);
	}
	return 0;
}
