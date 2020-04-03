/*
///弗洛伊德
#include<bits/stdc++.h>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=105;
int mp[mx][mx];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        for(int i=1; i<=m; i++)
        {
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            mp[x][y]=min(v,mp[x][y]);
            mp[y][x]=mp[x][y];
        }
        for(int k=1; k<=n; k++)///必须放在最外层
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    printf("i=%d j=%d k=%d mp[i][k]=%d  mp[k][j]=%d  mp[i][j]=%d\n",i,j,k,mp[i][k],mp[k][j],mp[i][j]);
                    if(mp[i][k]+mp[k][j]<mp[i][j])
                        mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                printf("%d->%d=%d\n",i,j,mp[i][j]);
            }
        }
    }
}
///dij
#include<bits/stdc++.h>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=1005;
int mp[mx][mx],dis[mx],n,m;
bool vis[mx];
void dij()
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=mp[1][i];
        printf("%d\n",dis[i]);
        vis[i]=0;
    }
    vis[3]=1;
    for(int i=1;i<n;i++)
    {
        int minn=Inf,to=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]>dis[to]+mp[to][j])
            {
                 dis[j]=dis[to]+mp[to][j];
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        }
        for(int i=1;i<=m;i++)
        {
            int x,y,v;
            scanf("%d%d%d",&x,&y,&v);
            mp[x][y]=mp[y][x]=v;
        }
        dij();
        for(int i=1;i<=n;i++)
            printf("1->%d=%d\n",i,dis[i]);
    }
}
///bellmanfloyd
#include<bits/stdc++.h>
#define Inf 0x3f3f3f3f
const int mx=1005;
int mp[mx][mx],n,m,dis[mx];
struct node
{
    int x,y,v;
} a[mx];
bool bellmanfloyd()
{
    for(int i=1; i<=n; i++)
        dis[i]=Inf;
    dis[1]=0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=2*m; j++)
        {
            int x=a[j].x;
            int y=a[j].y;
            int v=a[j].v;
           // printf("x=%d  y=%d  v=%d\n",x,y,v);
            if(dis[x]+v<dis[y])
            {
                dis[y]=dis[x]+v;
                //printf("dis[%d]=%d  dis[%d]=%d\n",y,dis[y],x,dis[x]);
            }
        }
    }
    for(int j=1; j<=2*m; j++)
    {
        int x=a[j].x;
        int y=a[j].y;
        int v=a[j].v;
        if(dis[x]+v<dis[y])
        {
            //printf("dis[%d]=%d  v=%d  dis[%d]=%d\n",x,dis[x],v,y,dis[y]);
            return 0;
        }
    }
    return 1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=2*m; i+=2)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
            a[i+1].x=a[i].y;
            a[i+1].y=a[i].x;
            a[i+1].v=a[i].v;
        }
        bool f=bellmanfloyd();
        if(!f)
            printf("-1\n");
        else
        {
            for(int i=1; i<=n; i++)
                printf("1->%d=%d\n",i,dis[i]);
        }
    }
}
///  1F
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Inf 0x3f3f3f3f
using namespace std;
int n,m;
int dis[10010];
int mp[210][210];
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        }
        int a,b,x;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&x);
            mp[a][b]=min(mp[a][b],x);
            mp[b][a]=mp[a][b];
        }
        for(int k=0; k<n; k++)//i和j之间能否找到一个中专点来缩短i到j的权值
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(mp[i][k]+mp[k][j]<mp[i][j])
                        mp[i][j]=mp[i][k]+mp[k][j];
                }
            }
        }
        int s,t;
        scanf("%d %d",&s,&t);
        if(mp[s][t]<Inf)
            printf("%d\n",mp[s][t]);
        else
            printf("-1\n");
    }
    return 0;
}
/// 1k
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=1010;
int mp[mx][mx],dis[2010],vis[mx];
int n,m;
void dij()
{
     for(int i=1;i<=n;i++)
     {
        dis[i]=mp[1][i];
        vis[i]=0;
     }
     vis[1]=1;
     for(int i=1;i<n;i++)
     {
         int minn=Inf,to=-1;
         for(int j=1;j<=n;j++)
         {
             if(!vis[j]&&dis[j]<minn)
             {
                 minn=dis[j];
                 to=j;
             }
         }
         vis[to]=1;
         for(int i=1;i<=n;i++)
         {
             if(!vis[i]&&dis[i]>dis[to]+mp[to][i])
                dis[i]=dis[to]+mp[to][i];
         }
     }
}
int main()
{
    while(~scanf("%d %d",&m,&n))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
                }
        }
        int a,b,x;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&a,&b,&x);
            mp[a][b]=min(mp[a][b],x);
            mp[b][a]=mp[a][b];
        }
        dij();
        printf("%d\n",dis[n]);
    }
    return 0;
}
///M
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=10000;
int mp[mx][mx],dis[10010];
int n,w,m;
struct node
{
    int s,e,t;
} a[mx];
bool bellmanfloyd()
{
    for(int i=1; i<=n; i++)
        dis[i]=Inf;
    dis[1]=0;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=2*m+w; j++)
        {
            int s=a[j].s;
            int e=a[j].e;
            int t=a[j].t;
            if(dis[s]+t<dis[e])
                dis[e]=dis[s]+t;
        }
    }
    for(int i=1; i<=2*m+w; i++)
    {
        int s=a[i].s;
        int e=a[i].e;
        int t=a[i].t;
        if(dis[s]+t<dis[e])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int f;
    scanf("%d",&f);
    while(f--)
    {
        scanf("%d %d %d",&n,&m,&w);
        int cnt=1;
        int s,e,t;
        for(int i=1; i<=m; i++)
        {

            scanf("%d %d %d",&s,&e,&t);
            a[cnt].s=s;
            a[cnt].e=e;
            a[cnt].t=t;
            cnt++;
            a[cnt].s=e;
            a[cnt].e=s;
            a[cnt].t=t;
            cnt++;
        }
        for(int i=0; i<w; i++)
        {
            scanf("%d %d %d",&s,&e,&t);
            a[cnt].s=s;
            a[cnt].e=e;
            a[cnt].t=-t;
            cnt++;
        }
        bool ans=bellmanfloyd();
        if(!ans)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
///E
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=220;
int a[mx][mx];
int main()
{
    int n,r,w;
    string s,s1;
    int flag=1;
    while(~scanf("%d %d",&n,&r))
    {
        if(n==0&&r==0)
            break;
        if(flag>1)
            printf("\n");
        memset(a,0,sizeof(0));
        map<string,int> mp;
        //map<string,int> ::iterator it;
        int cnt=1;
        for(int i=1; i<=r; i++)
        {
            cin>>s>>s1>>w;
            if(!mp[s])
            {
                mp[s]=cnt;
                cnt++;
            }
            if(!mp[s1])
            {
                mp[s1]=cnt;
                cnt++;
            }
            a[mp[s]][mp[s1]]=w;
            a[mp[s1]][mp[s]]=w;
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                if(a[i][k])
                {
                    for(int j=1; j<=n; j++)
                    {
                        if(a[k][j])
                        {
                            if(a[i][j]<min(a[i][k],a[k][j]))
                            {
                                 a[i][j]=min(a[i][k],a[k][j]);
                            }

                        }
                    }
                }

            }
        }
        cin>>s>>s1;
        printf("Scenario #%d\n",flag);
        printf("%d tons\n",a[mp[s]][mp[s1]]);
        flag++;
    }
    return 0;
}
///N
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=1010;
int mp[mx][mx],dis[100010],vis[mx],disx[100010];
int ans;
int n,m,x;
void dij(int u)
{

    for(int i=1; i<=n; i++)
    {
        dis[i]=mp[u][i];
        vis[i]=0;
    }
    vis[u]=1;
    for(int i=1; i<n; i++)
    {
        int minn=Inf,to=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i]&&dis[i]>dis[to]+mp[to][i])
                dis[i]=dis[to]+mp[to][i];
        }
    }
}
int main()
{

    while(~scanf("%d%d%d",&n,&m,&x))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        }
        int a,b,t;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&a,&b,&t);
            mp[a][b]=min(mp[a][b],t);
        }
        dij(x);//求2到个点的最短路径
        for(int i=1;i<=n;i++)
        {
            disx[i]=dis[i];
        }
        int temp;
        for(int i=1;i<=n;i++)//倒置
        {
           for(int j=i+1;j<=n;j++)
           {
               int temp;
               temp=mp[i][j];
               mp[i][j]=mp[j][i];
               mp[j][i]=temp;
           }
        }
        dij(x);//实质是求各点到2的最短路径，如此实现了往返
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,disx[i]+dis[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
///J
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=35;
int n,m;
double val[mx][mx];
int main()
{
    string s,s1,s2;
    int flag=1;
    while(~scanf("%d",&n)&&n)
    {
        map<string,int> mp;
        memset(val,0,sizeof(val));
        int cnt=1;
        for(int i=1; i<=n; i++)
        {
            cin>>s;
            if(!mp[s])
            {
                mp[s]=cnt;
                cnt++;
            }
        }
        int a,b;
        double c;
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>c>>s2;
            val[mp[s1]][mp[s2]]=c;
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(val[i][k]*val[k][j]>val[i][j])
                        val[i][j]=val[i][k]*val[k][j];
                }
            }
        }
        if(val[1][1]>1.0)
        {
            //printf("%lf\n",val[1][1]);
             printf("Case %d: Yes\n",flag);
        }

        else
        {
            //printf("%lf\n",val[1][1]);
            printf("Case %d: No\n",flag);
        }
        flag++;
        mp.clear();
    }
    return 0;
}
///B
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=110;
int n,m;
int g[mx];
double mp[mx][mx],dis[mx];
int vis[mx];
void dij()
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=mp[n][i];
        vis[i]=0;
    }
    vis[n]=1;
    for(int i=1; i<n; i++)
    {
        double maxn=0;
        int to=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]>maxn)
            {
                maxn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[to]*mp[to][j]>dis[j])
            {
                dis[j]=dis[to]*mp[to][j];
            }
        }
    }
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {

        for(int i=1; i<n; i++)
        {
            scanf("%d",&g[i]);
        }
        memset(mp,0,sizeof(mp));
        int a,b;
        double c;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %lf",&a,&b,&c);
            mp[a][b]=max(mp[a][b],1.0-c);
            mp[b][a]=mp[a][b];///注意重边
        }
        dij();
        double ans=0;
        for(int i=1; i<n; i++)
        {
            ans+=1.0*g[i]*dis[i];
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
///G  ///to不能付初值（未弄清原因）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=110;
int mp[mx][mx],vis[mx],dis[mx];
int n,m;
void dij(int u)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=mp[u][i];
        vis[i]=0;
    }
    vis[u]=1;
    dis[u]=0;
    for(int i=1; i<=n; i++)
    {
        int minn=Inf,to;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[to]+mp[to][j]<dis[j])
                dis[j]=dis[to]+mp[to][j];
        }
    }
}
int main()
{
    int a,b;
    while(~scanf("%d",&n)&&n)
    {
        memset(mp,0,sizeof(mp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d %d",&a,&b);
                mp[i][a]=min(mp[i][a],b);
            }
        }
        int temp=Inf,pos=0;
        for(int i=1; i<=n; i++)
        {
            dij(i);
            int ans=0;
            for(int j=1; j<=n; j++)
            {
                if(j!=i)
                    ans=max(ans,dis[j]);
            }
            if(temp>ans)
            {
                temp=ans;
                pos=i;
            }
        }
        if(pos!=0)
            printf("%d %d\n",pos,temp);
        else
            printf("disjoint\n");
    }
    return 0;
}
///H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=110;
int mp[mx][mx],vis[mx],dis[110],n;
void dij(int u)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=mp[u][i];
        vis[i]=0;
    }
    vis[u]=1;
    for(int i=1; i<n; i++)
    {
        int minn=Inf,to=-1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int i=1; i<=n; i++)
        {
            if(!vis[i]&&dis[i]>dis[to]+mp[to][i])
                dis[i]=dis[to]+mp[to][i];
        }
    }
}
int main()
{

    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        int w;
        char s[mx];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                scanf("%s",s);
                if(s[0]!='x')
                {
                    sscanf(s,"%d",&w);///将字符串s转化为整型并复制给w
                    mp[i][j]=mp[j][i]=w;
                }
            }
        }
        dij(1);
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(ans<dis[i])
                ans=dis[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
///1D
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=1000010;
vector<pair<int,int> >a[mx];
int n,m;
queue<int> q;
int dis[mx],vis[mx],s[mx],e[mx],w[mx];
//int cnt[mx];///判断负权回路
void solve(int st)
{
    memset(vis,0,sizeof(vis));
    memset(dis,Inf,sizeof(vis));
    dis[st]=0;
    while(!q.empty())
        q.pop();
    q.push(st);
    vis[st]=1;
    “
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0; i<a[u].size(); i++)
        {
            int e=a[u][i].first;
            int w=a[u][i].second;
            if(dis[e]>dis[u]+w)
            {
                dis[e]=dis[u]+w;
                if(!vis[e])
                {
                    cnt[e]++;
                    //if(cnt[e]>=n)
                    // return false;///存在负权回路，否则返回ture   ps：讲函数定义为bool型
                    vis[e]=1;
                    q.push(e);
                }
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
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            a[i].clear();
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&s[i],&e[i],&w[i]);
            a[s[i]].push_back(make_pair(e[i],w[i]));
        }
        int ans=0;
        solve(1);
        for(int i=2; i<=n; i++)
            ans+=dis[i];
        for(int i=1; i<=n; i++)
        {
            a[i].clear();
        }
        for(int i=1; i<=m; i++)
            a[e[i]].push_back(make_pair(s[i],w[i]));
        solve(1);
        for(int i=2; i<=n; i++)
            ans+=dis[i];
        printf("%d\n",ans);
    }
    return 0;
}
///2G
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=105;
int mp[mx][mx];
int main()
{
    int n,a,b;
    while(~scanf("%d %d %d",&n,&a,&b))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j==i)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        }
        for(int i=1; i<=n; i++)
        {
            int m;
            scanf("%d",&m);
            for(int j=1; j<=m; j++)
            {
                int e;
                scanf("%d",&e);
                if(j==1)
                    mp[i][e]=0;
                else
                    mp[i][e]=1;
            }
        }
        int cnt=0;
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(mp[i][k]+mp[k][j]<mp[i][j])
                    {
                        mp[i][j]=mp[i][k]+mp[k][j];
                    }
                }
            }
        }
        if(mp[a][b]<Inf)
           printf("%d\n",mp[a][b]);
        else
            printf("-1\n");
    }
    return 0;
}
///2B
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=1010;
int mp[mx][mx],n,m,dis[mx],vis[mx];

void dij(int u)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=mp[u][i];
        vis[i]=0;
    }
    dis[u]=0;
    vis[u]=1;
    for(int i=1;i<n;i++)
    {
        int minn=-Inf,to;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]>minn)
            {
                minn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<dis[to]+mp[to][j])
                dis[j]=max(dis[j],min(dis[to],mp[to][j]));
        }
    }
}

int main()
{
    int t,s,e,w;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d %d",&s,&e,&w);
            mp[s][e]=mp[e][s]=w;
        }
        dij(1);
        printf("Scenario #%d:\n",i);
        printf("%d\n\n",dis[n]);
    }
    return 0;
}
/// 2A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=210;
double mp[mx][mx];
int n;
double dis[mx],x[mx],y[mx],vis[mx];

void dij(int u)
{
    for(int i=1; i<=n; i++)
    {
        dis[i]=mp[u][i];
        vis[i]=0;
    }
    vis[u]=1;
    dis[u]=0;
    for(int i=1; i<n; i++)
    {
        double minn=Inf;
        int to;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]<minn)
            {
                minn=dis[j];
                to=j;
            }
        }
        vis[to]=1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&dis[j]>max(dis[to],mp[to][j]))
            {
                dis[j]=max(dis[to],mp[to][j]);
            }
        }
    }
}

int main()
{

    int cnt=1;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j==i)
                    mp[i][j]=0;
                else
                    mp[i][j]=Inf;
            }
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
        }
        double a;
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                a=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                mp[i][j]=mp[j][i]=a;
            }
        }
        dij(1);
        printf("Scenario #%d\n",cnt);
        printf("Frog Distance = %.3lf\n\n",dis[2]);
        cnt++;
    }
    return 0;
}
/// E  用队列会超时  栈不会
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=150010;
int n,m,tol,hed[mx],dis[mx],vis[mx];
struct node
{
    int s,e,w,nex;
} T[mx];

void add(int s,int e, int w)
{
    T[tol].s=s;
    T[tol].e=e;
    T[tol].w=w;
    T[tol].nex=hed[s];
    hed[s]=tol++;
}

void spfa(int st)
{
    stack<int> q;
    while(!q.empty())
        q.pop();
    memset(vis,0,sizeof(vis));
    memset(dis,Inf,sizeof(dis));
    q.push(st);
    vis[st]=1;
    dis[st]=0;
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        vis[u]=0;
        for(int i=hed[u]; i!=-1; i=T[i].nex)
        {
            int e=T[i].e;
            int w=T[i].w;
            if(dis[e]>dis[u]+w)
            {
                dis[e]=dis[u]+w;
                if(!vis[e])
                {
                    vis[e]=1;
                    q.push(e);
                }
            }
        }
    }
}

int main()
{
    int s,e,w;
    while(~scanf("%d%d",&n,&m))
    {
        memset(hed,-1,sizeof(hed));
        tol=0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&s,&e,&w);
            add(s,e,w);
        }
        spfa(1);
        printf("%d\n",dis[n]);
    }
    return 0;
}
///2C
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#define Inf 0x3f3f3f3f
using namespace std;
const int mx=110;
int mp[mx][mx];
int n,m;
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        memset(mp,0,sizeof(mp));
        int a,b;
        for(int i=1; i<=m; i++)
        {
            scanf("%d %d",&a,&b);
            mp[a][b]=1;
        }
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    if(mp[i][k]&&mp[k][j])
                    {
                        mp[i][j]=1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    if(mp[i][j]||mp[j][i])
                        cnt++;
                }
            }
            if(cnt==n-1)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}*/
