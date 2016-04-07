#include <cstdio>
using namespace std;

long long a,b;

int main()
{
	while(scanf("%llX%llX",&a,&b)!=EOF){
		long long int c = a+b;
		int f = 0; //正数为1，负数为0
		if(c<0){
			c = ~c + 1;
			f = 1;
		}
		if(f) printf("-%llX\n",c);
		else printf("%llX\n",c);
	}
	return 0;
}
