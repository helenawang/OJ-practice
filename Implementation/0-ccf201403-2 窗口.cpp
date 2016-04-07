#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int x, y;

struct Point{
	int x, y;
	Point(){}
	Point(int xx, int yy):x(xx), y(yy){}
};

struct Window{
	int layer;
	int id;
	Point down, top;
	Window(){}
	Window(int l, int i, Point d, Point t):layer(l), id(i), down(d), top(t){}
	Window& operator=(Window w){
		layer = w.layer;
		id = w.id;
		down = w.down;
		top = w.top;
	}
	bool inside(Point p){
		if(p.x >= down.x && p.y >= down.y && p.x<=top.x && p.y<=top.y)
			return true;
		return false;
	}
}wins[12];

bool cmp(Window w1, Window w2){
	return w1.layer > w2.layer;
}

int main()
{
	freopen("201403-2.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		wins[i].id = i+1;
		wins[i].layer = n-i;
		wins[i].down = Point(x1, y1);
		wins[i].top = Point(x2, y2);
	}
	while(m--){
		scanf("%d%d", &x, &y);
		int flag = 0;
		for(int i=n-1; i>=0; i--){
			if(wins[i].inside(Point(x, y))){
				printf("%d\n", wins[i].id);
				flag = 1;
				wins[i].layer = 1; //top level
				for(int j=i+1; j<n; j++){ //i+1 attention
					wins[j].layer++;
				}
				sort(wins, wins+n, cmp);
				break;
			}		
		}
		if(flag==0) printf("IGNORED\n");
	}
	return 0;
}

