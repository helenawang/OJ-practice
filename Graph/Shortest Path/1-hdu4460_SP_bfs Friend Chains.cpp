#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;
const int MAX_N=1005;
const int INF=10005;
int n,m;
vector<int> G[MAX_N];//邻接矩阵
string name[MAX_N];
map<string,int> mapp;
int d[MAX_N][MAX_N];//d[i][j]--i到j的最短路长度
int vis[MAX_N];

void bfs(int st)
{
    memset(vis,0,sizeof(vis));
    d[st][st]=0;
    vis[st]=1;
    queue<int> que;
    que.push(st);
    while(!que.empty())
    {
        int cur=que.front();
        que.pop();
        for(int i=0;i<G[cur].size();i++)//扩展相连的下一层结点
        {
            int v=G[cur][i];
            if(!vis[v])
            {
                d[st][v]=d[st][cur]+1;
                vis[v]=1;
                que.push(v);
            }
        }
    }
}

int main()
{
    freopen("4660.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        mapp.clear();
        for(int i=0;i<n;i++) G[i].clear();
        for(int i=0;i<n;i++)
        {
            cin>>name[i];
            mapp[name[i]]=i;
        }
        scanf("%d",&m);
        while(m--)
        {
            string a,b;
            cin>>a>>b;
            int na=mapp[a];
            int nb=mapp[b];
            G[nb].push_back(na);
            G[na].push_back(nb);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                d[i][j]=INF;
            d[i][i]=0;
        }
        for(int i=0;i<n;i++) bfs(i);//对每个点求单源最短路
        int ans=0;
        for(int i=0;i<n;i++)//无向图，最短路对称。取最大值
            for(int j=i+1;j<n;j++)
                ans=max(ans,d[i][j]);
        if(ans==INF) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
