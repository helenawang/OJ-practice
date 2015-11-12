#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N=205;
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

int n,m;
int x[MAX_N],y[MAX_N];
struct Edge
{
    int u,v;
    double w;
}e[MAX_N*MAX_N];
bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

double dis(int x1,int y1,int x2,int y2)
{
    return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double kruscal()
{
    double ans=0;
    init();
    for(int i=0;i<m;i++)
    {
        if(!same(e[i].u,e[i].v))
        {
            unite(e[i].u,e[i].v);
            if(same(0,1)) return e[i].w;
        }
    }
}

int main()
{
    freopen("2253.txt","r",stdin);
    int ca=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);
        m=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double temp=dis(x[i],y[i],x[j],y[j]);
                e[m].u=i;
                e[m].v=j;
                e[m].w=temp;
                m++;
            }
        }
        sort(e,e+m,cmp);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",ca++,kruscal());
    }
    return 0;
}


