#include <cstdio>
#include <cstring>
using namespace std;
const int MAX_N=1005;
int n,m;
int cnt;
int vis[MAX_N];
int ans[MAX_N];
int flag;

void dfs(int cur)
{
    if(flag) return ;
    if(cur==n)
    {
        cnt++;
        if(cnt==m)
        {
            flag=1;
            for(int i=0;i<n-1;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[n-1]);
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        flag=0;
        dfs(0);
    }
    return 0;
}
