#include <cstdio>
using namespace std;

int n;
int a[10005];
int b[10005];

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int cnt = 0;

	for(int i=0; i<n; i++){ //非法 
		if(a[i]<0 || a[i]>3){
			goto L;
		}
	}
	if(a[n-1]==3 || a[0] == 3){ //非法 
		goto L;
	}
	
	if(a[0] == 0) b[0] = b[1] = 0;
	else if(a[0] == 2) b[0] = b[1] = 1; 
	
	if(a[0] == 1) goto B;
	
	b[2] = a[1] - a[0]; //0或2的情况 
	if(b[2] < 0 || b[2] > 1){
		goto L;
	}
	for(int i=3; i<n; i++){
		b[i] = a[i-1] - a[i-2] + b[i-3];
		if(b[i] < 0 || b[i] > 1){
			goto L;
		}
	}
	if(b[n-1] + b[n-2] != a[n-1]) //检查最后一个a 
		goto L;
	printf("1\n");
	return 0;	

B:	b[0] = 0; b[1] = 1; //01或10的情况 
	b[2] = a[1] - a[0];
	if(b[2] < 0 || b[2] > 1){
		goto L1;
	}
	for(int i=3; i<n; i++){
		b[i] = a[i-1] - a[i-2] + b[i-3];
		if(b[i] < 0 || b[i] > 1){
			goto L1;
		}
	}
	if(b[n-1] + b[n-2] != a[n-1])
		goto L1;
	cnt++;
		
L1:	b[0] = 1; b[1] = 0; //试探另一种 
	b[2] = a[1] - a[0];
	if(b[2] < 0 || b[2] > 1){
		goto L;
	}
	for(int i=3; i<n; i++){
		b[i] = a[i-1] - a[i-2] + b[i-3];
		if(b[i] < 0 || b[i] > 1){
			goto L;
		}
	}
	if(b[n-1] + b[n-2] != a[n-1])
		goto L;
	cnt++;
		
L:	printf("%d\n", cnt);
	return 0;

}
