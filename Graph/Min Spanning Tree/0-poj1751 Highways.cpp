#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N=800;

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

double dis(int x1,int y1,int x2,int y2)
{
    return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int n,m,c;
int x[MAX_N],y[MAX_N];
struct Edge
{
    int u,v;
    double w;
}e[MAX_N*MAX_N];
bool cmp(const Edge e1,const Edge e2)
{
    return e1.w<e2.w;
}

int main()
{
    freopen("1751.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    m=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            e[m].u=i;
            e[m].v=j;
            e[m].w=dis(x[i],y[i],x[j],y[j]);
            m++;
        }
    sort(e,e+m,cmp);
    init();
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        unite(u,v);
    }
    for(int i=0;i<m;i++)
    {
        if(!same(e[i].u,e[i].v))
        {
            unite(e[i].u,e[i].v);
            printf("%d %d\n",e[i].u,e[i].v);
        }
    }
    return 0;
}
