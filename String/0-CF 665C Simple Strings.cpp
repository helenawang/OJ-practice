#include <cstdio>
using namespace std;
const int MAX_N = 200005;
char s[MAX_N];

int main()
{
	scanf("%s", s);
	int cnt = 0;
	for(int i=1; s[i]!='\0'; i++){
		if(s[i] == s[i-1]){
			s[i] = s[i-1] + 1;
			if(s[i] > 'z') s[i] = 'a';
			if(s[i+1] != '\0' && s[i+1] == s[i]){
				s[i] += 1;
				if(s[i] > 'z') s[i] = 'a'; //注意这里要做出界处理
			}
			cnt++;
		}
	}
	printf("%s\n", s);
	return 0;
}