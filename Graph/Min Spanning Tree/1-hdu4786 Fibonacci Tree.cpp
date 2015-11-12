#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100005;
const int MAX_M=100005;
int T;
int n,m;
struct Edge
{
    int from,to,cost;
}edges[MAX_M];

bool cmp0(const Edge e1,const Edge e2)
{return e1.cost<e2.cost;}
bool cmp1(const Edge e1,const Edge e2)
{return e1.cost>e2.cost;}

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
    if(x==y) return;
    if(rankk[x]<rankk[y]) parent[x]=y;
    else
    {
        parent[y]=x;
        if(rankk[x]==rankk[y]) rankk[x]++;
    }
}
bool same(int x,int y)
{return find(x)==find(y);}

int kruscal()
{
    int ans=0;
    init(n);
    for(int i=0;i<m;i++)
    {
        if(!same(edges[i].from,edges[i].to))
        {
            unite(edges[i].from,edges[i].to);
            ans+=edges[i].cost;
        }
    }
    return ans;
}

int fib[25];
void init_fib()
{
    fib[0]=fib[1]=1;
    for(int i=2;fib[i-1]<MAX_M;i++)
        fib[i]=fib[i-1]+fib[i-2];
/*
    for(int i=0;fib[i]<MAX_M;i++)
        printf("%d %d\n",i,fib[i]);
    printf("\n");
*/
}

int main()
{
    init_fib();
    freopen("4786.txt","r",stdin);
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edges[i].from,&edges[i].to,&edges[i].cost);
        printf("Case #%d: ",ca);
        if(n==1||m==0||m<n-1)//所给边数<n-1一定不连通
        {
            printf("No\n");
            continue;
        }
        sort(edges,edges+m,cmp0);
        int left=kruscal();
        sort(edges,edges+m,cmp1);
        int right=kruscal();

        int flag=1;
        for(int i=2;i<=n;i++)//判是否为连通图（重边不影响求MST，但不能仅凭所给边数m判是否连通）
            if(!same(1,i)){flag=0; break;}
        if(!flag)
            {printf("No\n"); continue;}

        flag=0;
        for(int i=0;i<25;i++)//枚举100000以内的fibonacci数，有进入范围的即可
            if(left<=fib[i]&&fib[i]<=right)
                {flag=1;break;}
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
