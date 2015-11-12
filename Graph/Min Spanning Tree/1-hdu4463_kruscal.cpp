#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_N=55;

int parent[MAX_N];
int rankk[MAX_N];
void init(int N)
{
    for(int i=0;i<=N;i++)
    {
        parent[i]=i;
        rankk[i]=0;
    }
}
int find(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    if(rankk[x]<rankk[y]) parent[x]=y;
    else
    {
        parent[y]=x;
        if(rankk[x]==rankk[y]) rankk[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

struct Point
{
    int x,y;
}a[MAX_N];

double dis(Point& p1, Point& p2)
{
    return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct Edge
{
    int from,to;
    double cost;
}edges[MAX_N*MAX_N];

bool cmp(Edge e1,Edge e2)
{
    return e1.cost<e2.cost;
}

int n,m;
int nike,apple;
double dis_na;

double kruscal()
{
    double ans=0;
    init(n);
    unite(nike,apple);
    ans+=dis_na;
    for(int i=0;i<m;i++)
    {
        if(!same(edges[i].from,edges[i].to))
        {
            ans+=edges[i].cost;
            unite(edges[i].from,edges[i].to);
        }
    }
    return ans;
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
        m=0;
        for(int i=0;i<n;i++)//求两点间距离，得到所有边
        {
            for(int j=i+1;j<n;j++)
            {
                double temp=dis(a[i],a[j]);
                edges[m].from=i;
                edges[m].to=j;
                edges[m].cost=temp;
                m++;
                if((i==nike&&j==apple)||(i==apple&&j==nike)) dis_na=temp;
            }
        }
        sort(edges,edges+m,cmp);
        printf("%.2lf\n",kruscal());
    }
    return 0;
}

