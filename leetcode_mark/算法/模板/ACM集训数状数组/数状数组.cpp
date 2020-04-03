///H
/*
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[200010];
int b[200010];
int lb(int x)
{
    return x&-x;
}
void add(int k,int d,int n)
{
    b[k]+=d;
    while(k+lb(k)<=n)
    {
        b[k+=lb(k)]+=d;
    }
}
int sum(int k)
{
    int value=b[k];
    while(k > lb(k))
    {
        k-=lb(k);
        value+=b[k];
    }
    return value;
}

int main()
{
    int n,x,y,cnt=1;
    char s[5];
    while(~scanf("%d",&n)&&n)
    {
        memset(b,0,sizeof(b));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            add(i,a[i],n);
        }
        if(cnt>1)
            printf("\n");
        printf("Case %d:\n",cnt);
        while(~scanf("%s",s)&&strcmp(s,"END"))
        {
            scanf("%d %d",&x,&y);
            if(s[0]=='S')
            {
                add(x,y-a[x],n);
                a[x]=y;
            }
            else
            {
                printf("%d\n",sum(y)-sum(x-1));
            }
        }
        //printf("\n");
        cnt++;
    }
    return 0;
}
///J
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long ans;
int n;
int a[500010],c[500010];
struct node
{
    int num;
    int pos;
}s[500010];
bool cmp(node x,node y)
{
    return x.num<y.num;
}
int lb(int x)
{
    return x&-x;
}
void updata(int x)
{
    while(x<=n)
    {
        c[x]+=1;
        x+=lb(x);
    }
}
int getsum(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=c[x];
        x-=lb(x);
    }
    return sum;
}
int main()
{

    while(~scanf("%d",&n)&&n)
    {
        for(int i=1; i<=n; i++)
        {
             scanf("%d", &s[i].num);
             s[i].pos=i;
        }
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n;i++)
            c[i]=0;
        for(int i=1;i<=n;i++)
        {
            a[s[i].pos]=i;
        }
        ans=0;
        for(int i=1;i<=n;i++)
        {
            updata(a[i]);
            ans+=i-getsum(a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
///M
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c[15010];
int ans[15010];
int n;
int lb(int x)
{
    return x&-x;
}
void updata(int k)
{
    c[k]+=1;
    while(k+lb(k)<=32002)
    {
        c[k+=lb(k)]+=1;
    }
}
int getsum(int k)
{
    int value=c[k];
    while(k > lb(k))
    {
        k-=lb(k);
        value+=c[k];
    }
    return value;
}
int main()
{
    int x,y;
    while(~scanf("%d",&n))
    {
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&x,&y);
            int sum=getsum(x+1);
            ans[sum]++;
            //printf("%d\n",getsum(x));
            updata(x+1);
            //printf("x=%d c[x]=%d\n",x,c[x]);
        }
        for(int i=0; i<n; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
///I
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn=1000100;
int c[maxn],p[maxn];
int lb(int x)
{
    return x&-x;
}
void updata(int k,int d)
{
    c[k]+=d;
    while(k+lb(k)<maxn)
    {
        c[k+=lb(k)]+=d;
    }
}
int getsum(int k)
{
    int value=c[k];
    while(k>lb(k))
    {
        k-=lb(k);
        value+=c[k];
    }
    return value;
}
int main()
{
    int t,n,m,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        memset(c,0,sizeof(c));
        memset(p,0,sizeof(p));
        for(int i=1; i<=n; i++)
        {
            p[i]=n-i+1;
            updata(i,1);
        }
        int temp=n;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&a);
            if(i<m)
                printf("%d ",n-getsum(p[a]));
            else
                printf("%d\n",n-getsum(p[a]));
            updata(p[a],-1);
            temp++;
            p[a]=temp;
            updata(p[a],1);
        }
    }
    return 0;
}
///L
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn=100100;
int MAX,temp;
int c[maxn];
int ans[maxn];
struct node
{
    int s,t,id;
} num[maxn];
bool cmp(node a,node b)
{
    if(a.s!=b.s)
        return a.s<b.s;
    else
        return a.t>b.t;
}

int lb(int x)
{
    return x&(-x);
}

void updata(int x)
{
    c[x]+=1;
    while(x+lb(x)<=MAX)
    {
        x+=lb(x);
        c[x]+=1;
    }
}
int sum(int x)
{
    int value=c[x];
    while(x>lb(x))
    {
        x-=lb(x);
        value+=c[x];
    }
    return value;
}

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        memset(c,0,sizeof(c));
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&num[i].s,&num[i].t);
            num[i].s++;
            num[i].t++;
            num[i].id=i;
            MAX=max(MAX,num[i].t);
        }
        stable_sort(num+1,num+1+n,cmp);
        ans[num[1].id]=0;
        updata(num[1].t);
        temp=num[1].t;
        for(int i=2; i<=n; i++)
        {
            if(num[i].s==num[i-1].s && num[i].t == num[i-1].t)
                ans[num[i].id]=ans[num[i-1].id];
            else
                ans[num[i].id]=sum(temp)-sum(num[i].t-1);
            //printf("sum(N)=%d sum(num[i].t-1)=%d\n",sum(temp),sum(num[i].t-1));
            updata(num[i].t);
            temp= max(temp,num[i].t);
        }
        for(int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}*/
///N
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int maxn=1e5+10;
vector<vector<int> > a(maxn);
int n,m,lef[maxn],rig[maxn],c[maxn],cnt,s[maxn];
int lb(int x)
{
    return x&(-x);
}
void updata(int x,int d)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=lb(x);
    }
}
int sum(int x)
{
    int value=0;
    while(x>0)
    {
        value+=c[x];
        x-=lb(x);
    }
    return value;
}
void dfs(int x)
{
    lef[x]=cnt;
    for(int i=0; i<a[x].size(); i++)
    {
        cnt++;
        dfs(a[x][i]);
    }
    rig[x]=cnt;
}
int main()
{
    int x,y;
    char str[5];
    while(~scanf("%d",&n))
    {
        memset(lef,0,sizeof(lef));
        memset(rig,0,sizeof(rig));
        memset(s,0,sizeof(s));
        memset(c,0,sizeof(c));
        for(int i=0; i<=n; i++)
            a[i].clear();
        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
        }
        cnt=1;
        dfs(1);
        for(int i=1; i<=n; i++)
        {
            s[i] = 1;
            updata(i,1);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s%d",str,&x);
            if(str[0]=='Q')
            {
                printf("%d\n",sum(rig[x])-sum(lef[x]-1));
            }
            else
            {
                if(s[x])
                    updata(lef[x],-1);
                else
                    updata(lef[x],1);
                s[x]=!s[x];
            }
        }
    }
    return 0;
}
