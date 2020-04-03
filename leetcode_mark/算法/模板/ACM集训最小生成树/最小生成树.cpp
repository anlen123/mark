///L


Sample Input
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0
Sample Output
3
5


        
  
Huge input, scanf is recommended.


/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tu[110][110];
const int maxn=1<<30;
int n,m,vis[110],cnt[110],ans;
int prim()
{
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        cnt[i]=tu[1][i];
    }
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        int pos=-1,Min=maxn;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j]&&cnt[j]<Min)
            {
                Min=cnt[j];
                pos=j;
            }
        }
        if(pos==-1)
            return -1;
        ans+=Min;
        vis[pos]=1;
        for(int i=1; i<=n; i++)
        {

            if(!vis[i]&&tu[pos][i]<cnt[i])
                cnt[i]=tu[pos][i];
        }
    }
    return ans;
}
int main()
{
    for(int i=1; i<=110; i++)
        for(int j=1; j<=110; j++)
            tu[i][j]=maxn;
    while(~scanf("%d",&n)&&n)
    {
        int a,b,k;
        ans=0;
        for(int i=1; i<=n*(n-1)/2; i++)
        {
            scanf("%d %d %d",&a,&b,&k);
            tu[a][b]=k;
            tu[b][a]=k;
        }
        printf("%d\n",prim());
    }
    return 0;
}
///I


Sample Input
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100
Sample Output
3
?


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[110];
struct node
{
    int l,r,v;
} tu[10100];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m)&&n)
    {
        int cnt=0;
        for(int i=1; i<=110; i++)
            fa[i]=i;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d%d",&tu[i].l,&tu[i].r,&tu[i].v);
        }
        sort(tu,tu+n,cmp);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(mix(tu[i].l,tu[i].r))
            {
                ans+=tu[i].v;
            }
        }
        for(int i=1; i<=m; i++)
        {
            if(fa[i]==i)
                cnt++;
        }
        if(cnt>1)
            printf("?\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
///H

Sample Input
1 0

2 3
1 2 37
2 1 17
1 2 68

3 7
1 2 19
2 3 11
3 1 7
1 3 5
2 3 89
3 1 91
1 2 32

5 7
1 2 5
2 3 7
2 4 8
4 5 11
3 5 10
1 5 6
4 2 12

0
Sample Output
0
17
16
26


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[100010];
struct node
{
    int l,r,v;
} tu[100010];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n,m;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        for(int i=0; i<=n; i++)
            fa[i]=i;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&tu[i].l,&tu[i].r,&tu[i].v);
        }
        sort(tu,tu+m,cmp);
        int ans=0,num=0;
        for(int i=0; i<m; i++)
        {
            if(mix(tu[i].l,tu[i].r))
            {
                ans+=tu[i].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
///F J

Sample Input
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0
Sample Output
216
30


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int fa[100100];
struct node
{
    int l,r,v;
} tu[100100];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0; i<=n; i++)
            fa[i]=i;
        char ch[5];
        int k,sum=0;;
        for(int i=0; i<n-1; i++)
        {
            scanf("%s %d",ch,&k);
            int pos=sum;
            sum+=k;
            int x=ch[0]-'A'+1;
            for(int i=pos; i<sum; i++)
            {
                scanf("%s %d",ch,&tu[i].v);
                int y=ch[0]-'A'+1;
                tu[i].l=x;
                tu[i].r=y;
            }
        }
        sort(tu,tu+sum,cmp);
        int ans=0;
        for(int i=0; i<sum; i++)
        {
            if(mix(tu[i].l,tu[i].r))
            {
                ans+=tu[i].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
///G
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110];
int fa[1100];
struct node
{
    int l,r,v;
} tu[100100];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0;
        for(int i=0;i<=n;i++)
            fa[i]=i;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                if(i!=j)
                {
                    tu[cnt].l=i;
                    tu[cnt].r=j;
                    tu[cnt].v=a[i][j];
                    cnt++;
                }
            }
        }
        sort(tu,tu+cnt,cmp);
        int ans=0;
        for(int i=0; i<cnt; i++)
        {
            if(mix(tu[i].l,tu[i].r))
            {
                ans+=tu[i].v;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110];
int fa[1100],flag;
struct node
{
    int l,r,v;
} tu[100100];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        flag=1;
        return true;
    }
    return false;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int cnt=0;
        for(int i=0; i<=n; i++)
            fa[i]=i;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                if(i!=j)
                {
                    tu[cnt].l=i;
                    tu[cnt].r=j;
                    tu[cnt].v=a[i][j];
                    cnt++;
                }
            }
        }
        sort(tu,tu+cnt,cmp);
        int q,b,c;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&b,&c);
            mix(b,c);
        }
        int ans=0;
        for(int i=0; i<cnt; i++)
        {
            flag=0;
            mix(tu[i].l,tu[i].r);
            if(flag)
                ans+=tu[i].v;
        }
        printf("%d\n",ans);
    }
    return 0;
}
///K
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int fa[10100];
struct node
{
    int from,to;
    double dis;
} a[10100],b[10100];
double cmp(node a,node b)
{
    return a.dis<b.dis;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int x,y;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a[i].from,&a[i].to);
        }
        for(int i=0; i<=n; i++)
            fa[i]=i;
        int k=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                b[k].from=i;
                b[k].to=j;
                b[k].dis=sqrt((a[i].from-a[j].from)*(a[i].from-a[j].from)+(a[i].to-a[j].to)*(a[i].to-a[j].to));
                k++;
            }
        }
        sort(b,b+k,cmp);
        double ans=0.0;
        int sum=0;
        for(int i=0; i<k; i++)
        {
            if(b[i].dis>=10&&b[i].dis<=1000&&mix(b[i].from,b[i].to))
            {
                sum++;
                ans+=b[i].dis;
            }
            if(sum==n-1)
                break;
        }
        if(sum==n-1)
            printf("%.1lf\n",ans*100);
        else
            printf("oh!\n");
    }
    return 0;
}
///A
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int flag,fa[550];
struct node
{
    int from,to;
    double dis;
} a[500100];
struct node1
{
    double x,y;
} b[550];
double cmp(node a,node b)
{
    return a.dis<b.dis;
}
double cmp2 (int a,int b)
{
    return a<b;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    double d[511];
    while(t--)
    {
        int s,p;
        scanf("%d %d",&s,&p);
        for (int i=1; i<=p; i++)
            fa[i]=i;
        for(int i=1; i<=p; i++)
        {
            scanf("%lf %lf",&b[i].x,&b[i].y);
        }
        int k=0;
        for(int i=1; i<p; i++)
        {
            for(int j=i+1; j<=p; j++)
            {
                a[k].from=i;
                a[k].to=j;
                a[k].dis=sqrt((b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y));
                k++;
            }
        }
        sort(a,a+k,cmp);
        int t=0;
        for (int i=0; i<k; i++)
        {
            if(mix(a[i].from,a[i].to))
            {
                d[t]=a[i].dis;
                t++;
            }
        }
        sort(d,d+t,cmp2);
        printf ("%.2lf\n",d[p-1-s]);
    }
    return 0;
}
///B
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int flag,fa[550];
struct node
{
    int from,to;
    double dis;
} a[50010];
struct node1
{
    double x,y,z;
    double r;
} b[550];
double cmp(node a,node b)
{
    return a.dis<b.dis;
}
double cmp2 (int a,int b)
{
    return a<b;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0; i<=n; i++)
            fa[i]=i;
        for(int i=1; i<=n; i++)
            scanf("%lf %lf %lf %lf",&b[i].x,&b[i].y,&b[i].z,&b[i].r);
        int k=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                a[k].from=i;
                a[k].to=j;
                a[k].dis=sqrt((b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y)+(b[i].z-b[j].z)*(b[i].z-b[j].z))-b[i].r-b[j].r;
                k++;
            }
        }
        sort(a,a+k,cmp);
        double ans=0.0;
        for (int i=0; i<k; i++)
        {
            if(mix(a[i].from,a[i].to))
            {
                if(a[i].dis>0.0)
                    ans+=a[i].dis;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
///D
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int fa[21000];
struct node
{
    int from,to;
    char s[10];
    int val;
} b[2000100];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n;
    //char s[2010][10];
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1; i<=n; i++)
            scanf("%s",&b[i].s);
        for(int i=0; i<=n; i++)
            fa[i]=i;
        int num=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                int cnt=0;
                for(int k=0; k<7; k++)
                {
                    if(b[i].s[k]!=b[j].s[k])
                    {
                        cnt++;
                    }
                }
                b[num].from=i;
                b[num].to=j;
                b[num].val=cnt;
                num++;
            }
        }
        sort(b,b+num,cmp);
        int ans=0;
        for(int i=0; i<num; i++)
        {
            if(mix(b[i].from,b[i].to))
            {
                ans+=b[i].val;
            }
        }
        printf("The highest possible quality is 1/%d.\n",ans);
    }
    return 0;
}
///E
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int fa[1000];
struct node
{
    int x,y;
    int from,to;
    double dis;
}a[1001000];
double cmp(node a,node b)
{
    return a.dis<b.dis;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        for(int i=1;i<=n;i++)
            fa[i]=i;
        scanf("%d",&m);
        int b,c;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&b,&c);
            mix(b,c);
        }
        int k=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                a[k].from=i;
                a[k].to=j;
                a[k].dis=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
                k++;
            }
        }
        sort(a,a+k,cmp);
        for(int i=0;i<k;i++)
        {
            if(mix(a[i].from,a[i].to))
            {
                printf("%d %d\n",a[i].from,a[i].to);
            }
        }
    }
    return 0;
}
///N
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int fa[500];
struct node
{
    int x,y;
    int w;
} a[5100];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int Find(int x)
{
    if(fa[x]!=x)
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x),yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
            fa[i]=i;
        for(int i=0; i<m; i++)
            scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
        sort(a,a+m,cmp);
        int ans=0;
        for(int i=0; i<m; i++)
        {
            if(mix(a[i].x,a[i].y))
            {
                ans+=a[i].w;
            }
        }
        int flag=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<=n; j++)
                fa[j]=j;
            int sum=0,cnt=0;
            for(int k=0; k<m; k++)
            {
                if(k!=i)
                {
                    if(mix(a[k].x,a[k].y))
                        sum+=a[k].w;
                    cnt++;
                }
            }
            if(cnt==n-1&&sum==ans)
                flag++;
            if(flag==2)
                break;
        }

        printf("\n");
        if(flag<2)
            printf("%d\n",ans);
        else
            printf("Not Unique!\n");
    }
    return 0;
}*/
///M
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
char a[60][60];
int m,n,cont;
int sign[60][60],vis[60][60];
int fx[4]= {0,0,1,-1};
int fy[4]= {1,-1,0,0};
int fa[250000];
struct node
{
    int x,y,val;
} s,w;
struct node1
{
    int x,y,step;
} e[250000];
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
bool mix(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
        return true;
    }
    return false;
}
void bfs(int x,int y,int from)
{
    memset(vis,0,sizeof(vis));
    queue<node> q;
    s.x=x;
    s.y=y;
    s.val=0;
    vis[x][y]=1;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            w.x=s.x+fx[i];
            w.y=s.y+fy[i];
            w.val=s.val+1;
            if(w.x>=0&&w.x<n&&w.y>=0&&w.y<m&&vis[w.x][w.y]==0&&sign[w.x][w.y]!=-1)
            {
                vis[w.x][w.y]=1;
                q.push(w);
                if(sign[w.x][w.y]>0)
                {
                    e[cont].x=from;
                    e[cont].y=sign[w.x][w.y];
                    e[cont++].step=w.val;
                }
            }
        }
    }
}

int cmp(node1 a,node1 b)
{
    return a.step<b.step;
}

char ch[100];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        gets(ch);
        for(int i=0; i<n; i++)
            gets(a[i]);
        cont=0;
        int flag=1;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(a[i][j]=='#')
                    sign[i][j]=-1;
                if(a[i][j]==' ')
                    sign[i][j]=0;
                if(a[i][j]=='S'||a[i][j]=='A')
                {
                    sign[i][j]=flag;
                    flag++;
                }

            }
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                if(sign[i][j]>0)
                    bfs(i,j,sign[i][j]);
            }
        int ans=0;
        sort(e,e+cont,cmp);
        for(int i=1; i<=flag; i++)
        {
            fa[i]=i;
        }
        for(int i=0; i<cont; i++)
        {
            if(mix(e[i].x,e[i].y))
            {
                ans+=e[i].step;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
