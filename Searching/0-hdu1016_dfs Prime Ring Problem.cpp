#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX_N=25;
int n;
int vis[MAX_N];
int ans[MAX_N];
int cnt;

bool prime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

void dfs(int cur)
{
    if(cur==n)
    {
        if(!prime(ans[n-1]+1)) return ;
        for(int i=0;i<n-1;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n-1]);
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            if(!prime(i+ans[cur-1])) continue;
            vis[i]=1;
            ans[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    int ca=0;
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        ans[0]=1;
        vis[1]=1;
        printf("Case %d:\n",++ca);
        dfs(1);
        printf("\n");
    }
    return 0;
}
