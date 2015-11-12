#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_N=505;
const int INF=30000;

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
    if(x==y) return;
    par[x]=y;
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

int T;
int s,n,m;
int x[MAX_N],y[MAX_N];

float dis(int x1,int y1,int x2,int y2)
{
    return sqrt((float)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

struct Edge
{
    int u,v;
    float w;
}e[MAX_N*MAX_N];
bool cmp(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

float kruscal()
{
    float ans=0;
    init();
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(!same(e[i].u,e[i].v))
        {
            unite(e[i].u,e[i].v);
            cnt++;
            if(cnt==n-s)
            {
                ans=e[i].w;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("2349.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&s,&n);
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
        printf("%.2f\n",kruscal());
    }
    return 0;
}
