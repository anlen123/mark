朋友圈 
输入样例:
7 4
3 1 2 3
2 1 4
3 5 6 7
1 6
输出样例:
4
作者: DS课程组
单位: 浙江大学
时间限制: 400 ms
内存限制: 64 MB

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ll long long
#define chushihua(x,y) memset(x,y,sizeof x)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const ll MAXX = 1000000 + 10;
const double PI = 3.14159265358979323846;
const ll mod = 1000000007;
int fa[100100], sum[100100];
int find(int x)
{
	if (x == fa[x])
		return x;
	else
		fa[x] = find(fa[x]);
	return fa[x];
}
void mix(int x, int y)
{
	int a = find(y);
	fa[a] = find(x);
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			int x;
			scanf("%d", &x);
			int y;
			scanf("%d", &y);
			for (int i = 1; i <= x - 1; i++) {
				int p;
				scanf("%d", &p);
				mix(y, p);
			}
		}
		for (int i = 1; i <= n; i++) {
			find(i);
		}
		for (int i = 1; i <= n; i++) {
			sum[fa[i]]++;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, sum[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
/*
///POJ 1182
#include <stdio.h>
#include <stdlib.h>
int N,K,D;
int fa[50020],r[50020];
int flag,count;
//这些权值具有一定属性，即可将他们与父节点的关系，
//变化为与所在树的根结点关系。
void init()
{
    int i;
    for(i=0; i<=N; i++)
    {
        fa[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(x!=fa[x])
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
        r[x]=(r[x]+r[t])%3;
        //printf("r[x]=%d x=%d\n",r[x],x);
    }
    return fa[x];
}
void mix(int d,int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        fa[yy]=xx;
        r[yy]=(r[x]-r[y]-(d-1)+3)%3;
         //printf("r[yy]=%d yy=%d\n",r[yy],yy);
    }
    if(xx==yy)
    {
        if(d==1&&r[x]!=r[y])
            count++;
        if(d==2&&r[x]==r[y]||d==2&&r[x]!=(r[y]+1)%3)
            count++;
    }
}
int main()
{
    scanf("%d%d",&N,&K);
    int x,y,i;
    count=0;
    init();
    while(K--)
    {
        scanf("%d %d %d",&D,&x,&y);
        if(x>N||y>N)
            count++;
        else if(x==y&&D==2)
            count++;
        else
        {
            mix(D,x,y);

        }
    }
    printf("%d\n",count);
    return 0;
}
///POJ 1611
#include <cstdio>
#include <iostream>
using namespace std;
int n,m,fa[30010],k,a[30010];
void init()
{
    for(int i=0; i<=n; i++)
        fa[i]=i;
}
int Find(int x)
{
    if(x!=fa[x])
    {
        int t=fa[x];
        fa[x]=Find(t);
    }
    return fa[x];
}
void mix(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
    {
        fa[yy]=xx;
    }
}
int main()
{
    int sum;
    while(~scanf("%d %d",&n,&m))
    {
        init();
        sum=0;
        if(n==0&&m==0)
            break;
        while(m--)
        {
            scanf("%d",&k);
            for(int i=0; i<k; i++)
                scanf("%d",&a[i]);
            for(int i=0; i<k-1; i++)
                mix(a[i],a[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            if(Find(i)==Find(0))
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
///POJ 1703
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fa[100100],enemy[100100];
int find(int x)
{
    if(x==fa[x])
        return x;
    else
        fa[x] = find(fa[x]);
    return fa[x];
}
void mix(int x,int y)
{
     int a=find(y);
     fa[a] = find(x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,a,b,N,M;
        char ch;
        memset(enemy,0,sizeof(enemy));
        scanf("%d %d",&N,&M);
        for(i=0;i<=N;i++)
            fa[i]=i;
        for(i=0; i<M; i++)
        {
            getchar();
            scanf("%c%d%d",&ch,&a,&b);
            if(ch=='D')
            {
                if(enemy[a])
                    mix(enemy[a],b);
                if(enemy[b])
                    mix(enemy[b],a);
                enemy[a]=b;
                enemy[b]=a;
            }
            else
            {
                if(find(a)==find(enemy[b]))
                    printf("In different gangs.\n");
                else if(find(a)==find(b))
                    printf("In the same gang.\n");
                else
                    printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
///POJ 1988
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int fa[30010],dis[30010],r[30010];
void init()
{
    for(int i=0; i<=30010; i++)
    {
        fa[i]=i;
        r[i]=1;
        dis[i]=0;
    }
}
int Find(int x)
{
    if(x!=fa[x])
    {
        int t=fa[x];
        fa[x]=Find(t);
        dis[x]+=dis[t];
    }
    return fa[x];
}
void mix(int a,int b)
{
    int xx=Find(a);
    int yy=Find(b);
    if(xx!=yy)
    {
        fa[yy]=xx;
        dis[yy]=r[xx];
        r[xx]+=r[yy];
    }
}
int main()
{
    int p,a,b;
    scanf("%d",&p);
    char ch;
    init();
    getchar();
    while(p--)
    {
        scanf("%c",&ch);
        if(ch=='M')
        {
            scanf("%d %d",&a,&b);
            mix(a,b);
            //printf("r[a]=%d r[b]=%d dis[a]=%d dis[b]=%d ",r[a],r[b],dis[a],dis[b]);
        }
        else if(ch=='C')
        {
            scanf("%d",&a);
            int ans=Find(a);
            printf("%d\n", r[ans]-dis[a]-1);
        }
        getchar();
    }
    return 0;
}
///HDU 2181
#include <stdio.h>
#include <stdlib.h>
int m;
int map[25][3];
int vis[25];
int ans[25];
int count=1;
void dfs(int m,int n,int M)
{
    int i;
    vis[m]=1;
    ans[n]=m;
    for(i=0; i<3; i++)
    {
        int temp=map[m][i];
        if(!vis[temp])
            dfs(temp,n+1,M);
        if(temp==M&&n==19)
        {
            printf("%d:  ",count++);
            for(i=0; i<=n; i++)
                printf("%d ",ans[i]);
            printf("%d\n",M);
        }
    }
    vis[m]=0;
}
int main()
{
    int i;
    for(i=1; i<=20; i++)
        scanf("%d %d %d",&map[i][0],&map[i][1],&map[i][2]);
        while(~scanf("%d",&m)&&m)
        {
            memset(vis,0,sizeof(vis));
            dfs(m,0,m);
        }
    return 0;
}
///POJ 2492
#include<stdio.h>
#include <stdlib.h>
int n,m;
int fa[1000010],r[1000010];
int flag;
void init()
{
    int i;
    for(i=0; i<=n; i++)
    {
        fa[i]=i;
        r[i]=0;
    }
}
int Find(int x)
{
    if(x!=fa[x])//x!=fa[x]说明x之前有过交配对象
    {
        int t=fa[x];
        fa[x]=Find(fa[x]);//找到之前跟x交配的是谁
        r[x]=(r[x]+r[t])%2;//x的权值加上之前与x交配的对象的权值在除以属性的种类
    }
    return fa[x];//返回之前和x交配的是谁
}
void mix(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx==yy)//xx==yy说明x和y曾经和同一个人交配过
    {
        if(r[x]==r[y])
            flag=1;//30-34行说明x和y是同类
    }
    else
    {
        fa[yy]=xx;//x和y交配；
        r[yy]=(r[x]+r[y]+1)%2;//更新其中一个的权值，权值不同表示属性不同
    }
}

int main()
{
    int i,t,a,b,count=1;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d %d",&n,&m);
        init();
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            if(!flag)
                mix(a,b);
        }
        printf("Scenario #%d:\n",count++);
        if(flag)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        printf("\n");
    }
    return 0;
}
///POJ 2542
#include <stdio.h>
#include <math.h>
int N,M;
int fa[50010];
void init()
{
    int i;
    for(i=0; i<=N; i++)
    {
        fa[i]=i;
    }
}
int find(int x)
{
    if(x!=fa[x])
    {
        return fa[x]=find(fa[x]);
    }
    return fa[x];
}
void mix(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
        fa[xx]=yy;
}
int main()
{
    int a,b,count=0;
    while(~scanf("%d %d",&N,&M)&&N&&M)
    {

        count++;
        int i,sum=0;
        init();
        for(i=0; i<M; i++)
        {
            scanf("%d %d",&a,&b);
            mix(a,b);
        }
        for(i=1; i<=N; i++)
        {
            if(fa[i]==i)
                sum++;
        }
        printf("Case %d: %d\n",count,sum);
    }
    return 0;
}
///POJ 2236
#include <stdio.h>
#include <stdlib.h>

int fa[1010],  dis[1010][2];
int vis[1010];

int find(int x)
{
    if(x!=fa[x])
        fa[x]=find(fa[x]);
    return fa[x];
}
void mix(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
    }
}
int main()
{
    int n,d,p,q,i;
    double s[1010];
    char ch;
    scanf("%d%d",&n,&d);
    memset(vis,0,sizeof(vis));
    for(i=1; i<=n; i++)
        fa[i]=i;
    for(i=1; i<=n; i++)
        scanf("%d %d", &dis[i][0],&dis[i][1]);
    getchar();
    while(~scanf("%c",&ch))
    {
        if(ch == 'O')
        {
            scanf("%d",&p);
            vis[p]=1;
            for(i=1; i<=n; i++)
            {
                if(i == p);
                else
                {
                    if(vis[i])
                    {
                        int s = (dis[i][0]-dis[p][0])*(dis[i][0]-dis[p][0])+(dis[i][1]-dis[p][1])*(dis[i][1]-dis[p][1]);
                        if(s <= d * d)
                            mix(p,i);
                    }
                }
            }
        }
        if(ch == 'S')
        {
            scanf("%d %d",&p,&q);
            if(find(p)==find(q)&&vis[p]&&vis[q])
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
        getchar();
    }
    return 0;
}
///CF 659E
#include <stdio.h>
#include <stdlib.h>
int fa[100010];
int cicle[100010];
int n,m;
void init()
{
    int i;
    for(i=0; i<=n; i++)
    {
        fa[i]=i;
    }
}
int find(int x)
{
    if(x!=fa[x])
    {
        int t=fa[x];
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void mix(int a,int b)
{
    int xx=find(a);
    int yy=find(b);
    if(xx!=yy)
    {
        fa[xx]=yy;
        if(cicle[xx])
            cicle[yy]=1;
    }
    if(xx==yy)
    {
        cicle[xx]=1;
    }
}
int main()
{
    int i,a,b,count=0;
    memset(cicle, 0, sizeof(cicle));
    scanf("%d%d",&n,&m);
    init();
    for(i=0; i<m; i++)
    {
        scanf("%d %d",&a,&b);
        mix(a,b);
    }
    for (i=1; i<=n; i++)
    {
        if (fa[i]==i&&!cicle[i])
            count++;
    }
    printf("%d\n",count);
    return 0;
}
