///dij加优先队列
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=1e6+10;
priority_queue<pair<int,int> >q;
int tol,hed[mx],dis[mx];
int n,m,s[mx],e[mx],w[mx];
struct node
{
    int s,e,w,nex;
} T[mx];

void add_e(int s,int e,int w)
{
    T[tol].s=s;
    T[tol].e=e;
    T[tol].w=w;
    T[tol].nex=hed[s];
    hed[s]=tol++;
}

void dij_hed(int st)
{
    memset(dis,Inf,sizeof(dis));
    while(!q.empty())
        q.pop();
    dis[st]=0;
    q.push(make_pair(-dis[st],st));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(int i=hed[u]; i!=-1; i=T[i].nex)
        {
            int w=T[i].w;
            int e=T[i].e;
            if(dis[e]>dis[u]+w)
            {
                dis[e]=dis[u]+w;
                q.push(make_pair(-dis[e],e));
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(hed,-1,sizeof(hed));
        scanf("%d %d",&n,&m);
        tol=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&s[i],&e[i],&w[i]);
            add_e(s[i],e[i],w[i]);
        }
        long long ans=0;
        dij_hed(1);
        for(int i=2; i<=n; i++)
            ans+=dis[i];
        tol=0;
        memset(hed,-1,sizeof(hed));
        for(int i=1; i<=m; i++)
        {
            add_e(e[i],s[i],w[i]);
        }
        dij_hed(1);
        for(int i=2; i<=n; i++)
            ans+=dis[i];
        printf("%lld\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
int hed[maxn],dis[maxn];
int tol;
int ss[maxn],ee[maxn],tv[maxn];
bool vis[maxn];
struct node
{
    int s,e,val,nex;
}t[maxn];
void add(int s,int e,int val)
{
    t[tol].s=s;
    t[tol].e=e;
    t[tol].val=val;
    t[tol].nex=hed[s];
    hed[s]=tol++;
}

void spfa(int s)
{
    queue<int>q;
    while(!q.empty())
        q.pop();
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=hed[u];i!=-1;i=t[i].nex)
        {
            int e=t[i].e;
            if(dis[e]>dis[u]+t[i].val)
            {
                dis[e]=dis[u]+t[i].val;
                if(vis[e])
                    continue;
                vis[e]=1;
                q.push(e);
            }
        }
    }
}

int main()
{
    int T,m,n;
    scanf("%d",&T);
    while(T--)
    {
        tol=0;
        memset(hed,-1,sizeof(hed));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&ss[i],&ee[i],&tv[i]);
            add(ss[i],ee[i],tv[i]);
        }
        int sum=0;
        spfa(1);
        for(int i=2;i<=n;i++)
        sum+=dis[i];
        memset(hed,-1,sizeof(hed));
        tol=0;
        for(int i=0;i<m;i++)
            add(ee[i],ss[i],tv[i]);
        spfa(1);
        for(int i=2;i<=n;i++)
        {
            sum+=dis[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
int hed[maxn],s[maxn],e[maxn],w[maxn],dis[maxn];
int tol;
struct node
{
    int s,e,val,nex;
}t[maxn];

void spfa(int st)
{
    priority_queue<pair<int,int> >q;
    while(!q.empty())
        q.pop();
    memset(dis,inf,sizeof(dis));
    dis[st]=0;
    q.push(make_pair(-dis[st],st));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(int j=hed[u];j!=-1;j=t[j].nex)
        {
            int e=t[j].e;
            if(dis[e]>dis[u]+t[j].val)
            {
                dis[e]=dis[u]+t[j].val;
                q.push(make_pair(-dis[e],e));
            }
        }
    }
}

void add(int s,int e,int val)
{
    t[tol].s=s;
    t[tol].e=e;
    t[tol].val=val;
    t[tol].nex=hed[s];
    hed[s]=tol++;
}

int main()
{
    int n,m,T;
    scanf("%d",&T);
    while(T--)
    {
        tol=0;
        memset(hed,-1,sizeof(hed));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&s[i],&e[i],&w[i]);
            add(s[i],e[i],w[i]);
        }
        spfa(1);
        int sum=0;
        for(int i=2;i<=n;i++)
            sum+=dis[i];
        memset(hed,-1,sizeof(hed));
        tol=0;
        for(int i=0;i<m;i++)
            add(e[i],s[i],w[i]);
        spfa(1);
        for(int i=2;i<=n;i++)
            sum+=dis[i];
        printf("%d\n",sum);
    }
    return 0;
}



