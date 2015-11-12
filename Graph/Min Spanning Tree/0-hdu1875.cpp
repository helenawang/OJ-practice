#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N=105;

int par[MAX_N];
void init()
{
    memset(par,-1,sizeof(par));
}
int find(int x)
{
    if(par[x]==-1) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

int T;
int n,m;
int x[MAX_N],y[MAX_N];
double dis(int x1,int y1,int x2,int y2)
{
    return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct Edge
{
    int u,v;
    double w;
}e[MAX_N*MAX_N];

bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

double kruscal()
{
    double ans=0;
    init();
    for(int i=0;i<m;i++)
    {
        if(e[i].w<10) continue;
        if(e[i].w>1000) return -1;
        if(!same(e[i].u,e[i].v))
        {
            unite(e[i].u,e[i].v);
            ans+=e[i].w;
        }
    }
    return ans;
}

int main()
{
    freopen("1875.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        m=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                e[m].u=i;
                e[m].v=j;
                e[m].w=dis(x[i],y[i],x[j],y[j]);
                m++;
            }
        }
        sort(e,e+m,cmp);
        double ans=kruscal();
        if(ans==-1) printf("oh!\n");
        else printf("%.1lf\n",ans*100);
    }
    return 0;
}
