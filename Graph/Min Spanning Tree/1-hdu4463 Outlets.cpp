#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_N=55;
const double INF=2000;

struct Point
{
    int x,y;
}a[MAX_N];

double dis(Point& p1, Point& p2)
{
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

int n;
int nike,apple;
double cost[MAX_N][MAX_N];//邻接矩阵（更适于稠密图）
double mincost[MAX_N];//集合到点i的最短距离
int used[MAX_N];

double prim()
{
    double res;
    for(int i=0;i<n;i++)
    {
        mincost[i]=INF;
        used[i]=0;
    }//将nike,apple两个点加入集合，并更新它们所到达的点的mincost
    mincost[nike]=mincost[apple]=0;
    used[nike]=used[apple]=1;
    res=cost[nike][apple];
    for(int i=0;i<n;i++)
    {
        mincost[i]=min(mincost[i],cost[nike][i]);
    }
    for(int i=0;i<n;i++)
    {
        mincost[i]=min(mincost[i],cost[i][apple]);
    }
    while(1)
    {
        int v=-1;
        for(int i=0;i<n;i++)//找到集合以外的mincost最小的点
        {
            if(!used[i]&&(v==-1||mincost[i]<mincost[v]))
                v=i;
        }
        if(v==-1) break;//不存在负权边
        used[v]=1;
        res+=mincost[v];//加入集合，更新它所到达的点
        for(int i=0;i<n;i++)
        {
            mincost[i]=min(mincost[i],cost[i][v]);
        }
    }
    return res;
}


int main()
{
    freopen("4463.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        scanf("%d%d",&nike,&apple);
        nike--;
        apple--;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i=0;i<n;i++)//求两点间距离，得到邻接矩阵
        {
            cost[i][i]=0;
            for(int j=i+1;j<n;j++)
                cost[i][j]=cost[j][i]=dis(a[i],a[j]);
        }
        printf("%.2lf\n",prim());
    }
    return 0;
}
