#include <cstdio>
using namespace std;

int n;
int A[505][505];

int main()
{
	freopen("201412-2.txt", "r", stdin);
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &A[i][j]);
	int r = 0, c = 0;
	printf("%d ", A[r][c]);
	while(0<=r<n && 0<=c<n){
		c++; //右行 
		if(c>n-1){ //改下行 
			c--;
			r++;
		}
		if(r>n-1) break;
		while(0 <= r && r<n && 0<=c && c<n){
			printf("%d ", A[r][c]);
			c--;
			r++;
		}
		c++;
		r--;
		
		r++;
		if(r>n-1){
			r--;
			c++;
		}
		if(c>n-1) break;
		while(0 <= r && r<n && 0<=c && c<n){	
			printf("%d ", A[r][c]);
			r--;
			c++;
		}
		r++;
		c--;
	}
	return 0;
}
