#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=30;
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
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return ;
    if(rankk[x]<=rankk[y]) parent[x]=y;
    else
    {
        parent[y]=x;
        rankk[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}

int n,e;
int ans;
struct Edge
{
    int from,to,cost;
}edges[MAX_N*MAX_N];

bool cmp(const Edge &e1,const Edge &e2)
{
    return e1.cost<e2.cost;
}

int main()
{
    freopen("1251.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        e=0;
        for(int i=1;i<=n-1;i++)
        {
            char s[2];
            scanf("%s",s);
            int k;
            scanf("%d",&k);
            while(k--)
            {
                char ad[2];
                scanf("%s",ad);
                edges[e].from=i;
                edges[e].to=ad[0]-'A'+1;
                scanf("%d",&edges[e].cost);
                e++;
            }
        }
        sort(edges,edges+e,cmp);
        ans=0;
        init(n);
        for(int i=0;i<e;i++)
        {
            if(!same(edges[i].from,edges[i].to))
            {
                ans+=edges[i].cost;
                unite(edges[i].from,edges[i].to);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
