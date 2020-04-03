///HDU 2084
/*#include <iostream>
#include <cstdio>
using namespace std;
int a[10000][10000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
                scanf("%d",&a[i][j]);
        }
        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=i; j++)
                a[i][j]=max(a[i+1][j]+a[i][j],a[i+1][j+1]+a[i][j]);
        }
        printf("%d\n",a[1][1]);
    }
    return 0;
}
/// HDU 1003
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int t,n;
    int a[100010];
    int ans=-9999999;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&n);
        int ans=-9999999;
        int sum=0,s=1,e=1,pos=1,s1=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            if(sum>=0)
            {
                sum+=a[i];
            }
            else
            {
                sum=a[i];
                s1=i;
            }
            if(sum>ans)
            {
                ans=sum;
                s=s1;
                e=i;
            }
        }
        printf("Case %d:\n",i);
        printf("%d %d %d\n",ans,s,e);
        if(t-i)
            printf("\n");

    }
    return 0;
}
///HDU 1579
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long dp[25][25][25];
int maxn= -1*1e9;
void init()
{
    for(int i=0; i<=20; i++)
        for(int j=0; j<=20; j++)
            for(int k=0; k<=20; k++)
                dp[i][j][k]=maxn;
}
long long Find(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
    return 1;
    else if(a>20||b>20||c>20)
    {
        if(dp[20][20][20]==maxn)
            dp[20][20][20]=Find(20,20,20);
        return dp[20][20][20];
    }
    else if(a<b&&b<c)
    {
        if(dp[a][b][c]==maxn)
            dp[a][b][c]=Find(a,b,c-1)+Find(a,b-1,c-1)-Find(a,b-1,c);
        return dp[a][b][c];
    }
    else
    {
        if(dp[a][b][c]==maxn)
            dp[a][b][c]=Find(a-1,b,c)+Find(a-1,b-1,c)+Find(a-1,b,c-1)-Find(a-1,b-1,c-1);
        return dp[a][b][c];
    }
}
int main()
{
    int a,b,c;
    init();
    while(~scanf("%d %d %d",&a,&b,&c))
    {
        if(a==-1&&b==-1&&c==-1)
            break;
        if(a<=0||b<=0||c<=0)
            printf("w(%d, %d, %d) = 1\n",a,b,c);
        else if(a>20||b>20||c>20)
            printf("w(%d, %d, %d) = %lld\n",a,b,c,Find(20,20,20));
        else
            printf("w(%d, %d, %d) = %lld\n",a,b,c,Find(a,b,c));
    }
    return 0;
}
///51Nod 1118
#include <iostream>
#include <cstdio>
using namespace std;
int dp[1005][1005];
void init(int m,int n)
{
    for(int i=2;i<=m;i++)
        dp[i][1]=1;
    for(int i=2;i<=n;i++)
        dp[1][i]=1;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        init(m,n);
        dp[1][1]=0;
        dp[1][2]=1;
        dp[2][1]=1;
        for(int i=2;i<=m;i++)
            for(int j=2;j<=n;j++)
              dp[i][j]=(dp[i][j-1]+dp[i-1][j])%1000000007;
        printf("%d\n",dp[m][n]);
    }
    return 0;
}
///HDU 2602
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1100],v[1100],dp[1100][1100];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,V;
        scanf("%d %d",&n,&V);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int j=1; j<=n; j++)
            scanf("%d",&v[j]);
        for(int j=0; j<=V; j++)
            dp[0][j]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=V; j++)
            {
                 if(j<v[i])
                    dp[i][j]=dp[i-1][j];
                 else
                 {
                     dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+a[i]);
                     //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
                 }

            }
        }
        printf("%d\n",dp[n][V]);
    }
    return 0;
}
///POJ 2081
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[500100];
int vis[10000000];
int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        memset(vis,0,sizeof(vis));
        a[0]=0;
        if(k==-1)
            break;
        for(int i=1; i<=k; i++)
        {
            if(a[i-1]-i>0&&!vis[a[i-1]-i])
                a[i]=a[i-1]-i;
            else
                a[i]=a[i-1]+i;
            vis[a[i]]=i;
        }
        printf("%d\n",a[k]);
    }
    return 0;
}
///POJ 1953
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    long long a[100000];
    a[0]=0,a[1]=2,a[2]=3;
    for(int i=3;i<=45;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&n);
        printf("Scenario #%d:\n",i);
        printf("%lld\n",a[n]);
        if(t-i)
            printf("\n");
    }
    return 0;
}
///HDU 1114
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[510],v[510],dp[510][10010];
int V1,V2,V,n;
int main()
{
    int t;
    scanf("%d",&t);
    dp[0][0]=0;
    for(int i=1; i<510; i++)
        dp[i][0]=0;
    for(int i=1; i<10010; i++)
        dp[0][i]=1e9;
    while(t--)
    {
        scanf("%d %d",&V1,&V2);
        V=V2-V1;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a[i],&v[i]);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=V; j++)
            {
                if(j<v[i])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],dp[i][j-v[i]]+a[i]);
            }
        }
        if(dp[n][V]==1e9)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n][V]);
    }
    return 0;
}
///POJ 3356
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int a,b;
    char str1[1010],str2[1010];
    int dp[2][1010];
    while(~scanf("%d%s%d%s",&a,str1+1,&b,str2+1))
    {
        int len1=strlen(str1+1);
        int len2=strlen(str2+1);
        int temp=len1>len2?len1:len2;
        memset(dp,0,sizeof(dp));
        int e=0;
        for(int i=1; i<=len1; i++)
        {
            e=1-e;
            for(int j=0; j<=len2; j++)
            {
                if(str1[i]==str2[j])
                    dp[e][j]=dp[1-e][j-1]+1;
                else
                    dp[e][j]=max(dp[e][j-1],dp[1-e][j]);
            }
        }
        printf("%d\n",temp-dp[e][len2]);
    }
    return 0;
}
///POJ 1887
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int Search(int *b,int len,int w)
{
    int left=0,right=len-1;
    int mid;
    while(left<=right)
    {
        mid = left + (right-left)/2;
        if (b[mid] > w)
            right = mid - 1;
        else if (b[mid] < w)
            left = mid + 1;
        else
            return mid;
    }
    return left;
}
int a[50000],dp[50000],cnt=0,n;
int main()
{
    while(~scanf("%d",&a[0])&&a[0]!=-1)
    {
        for(int i=1;; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==-1)
            {
                n=i;
                cnt++;
                break;
            }
        }
        int len=1,pos=0;
        dp[0]=a[n-1];
        for(int i=n-1; i>=0; i--)
        {
            if(a[i]>dp[len-1])
            {
                dp[len]=a[i];
                len++;
            }
            else
            {
                pos=Search(dp,len,a[i]);
                dp[pos]=a[i];
            }
        }
        printf("Test #%d:\n",cnt);
        printf("  maximum possible interceptions: %d\n",len);
        printf("\n");
    }
    return 0;
}
///POJ 1088
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
///dp保存自身的状态，也方便计算下一个的状态
using namespace std;
int mapp[500][500];
int dp[500][500];
int r,c;
int xx[4]= {-1,0,0,1};
int yy[4]= {0,-1,1,0};
int check(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c)
        return 1;
    return 0;
}
int dfs(int x, int y)
{
    if(dp[x][y])
        return dp[x][y];
    int hi=1;
    for(int i=0; i<4; i++)
    {
        int X=x+xx[i];
        int Y=y+yy[i];
        if(check(X,Y)&&mapp[x][y]>mapp[X][Y])
        {
            hi=max(dfs(X,Y)+1,hi);
        }
    }
    dp[x][y]=hi;
    return hi;
}
int main()
{
    while(~scanf("%d%d",&r,&c))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=r; i++)
            for(int j=1; j<=c; j++)
                scanf("%d",&mapp[i][j]);
        int ans=0,h=0;
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                h=dfs(i,j);
                ans=max(h,ans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
///POJ 1157
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int F,V;
    int a[110][110],dp[110][110];
    while(~scanf("%d%d",&F,&V))
    {
        for(int i=1; i<=F; i++)
            for(int j=1; j<=V; j++)
                scanf("%d",&a[i][j]);
        for(int i=1; i<=V; i++)
            dp[0][i]=0;
        for(int j=1; j<=F; j++)
            dp[j][j]=dp[j-1][j-1]+a[j][j];
        for(int i=1; i<=F; i++)
        {
            for(int j=i+1; j<=V; j++)
            {
                dp[i][j]+=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
            }
        }
        printf("%d\n",dp[F][V]);
    }
    return 0;
}*/
///POJ 2533
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
///最长递增子序列
/*int main()
{
    int dp[11000],n;
    int a[11000];
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            dp[i]=1;
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int j=2; j<=n; j++)
        {
            for(int i=1; i<j; i++)
            {
                if(a[j]>a[i]&&dp[j]<dp[i]+1)
                {
                    dp[j]=dp[i]+1;
                }
            }
        }
        int maxx=dp[1];
        for(int i=1; i<=n; i++)
            if(dp[i]>maxx)
                maxx=dp[i];
        printf("%d\n",maxx);
    }
    return 0;
}*/
int main()
{
    int dp[11000],n;
    int a[11000];
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j]&&dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
}*/
/*
int main()
{
    int dp[11000],n;
    int a[11000];
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        int len=1,pos=0;
        dp[0]=a[1];
        for(int i=2;i<=n;i++)
        {
            if(a[i]>dp[len-1])
            {
                dp[len]=a[i];
                len++;
            }
            else
            {
                pos=lower_bound(dp,dp+len,a[i])-dp;
                dp[pos]=a[i];
            }
        }
        printf("%d\n",len);
    }
}/*
///POJ 1631
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t,n;
    int a[40100],dp[40100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        dp[0]=a[1];
        int len=1,pos=0;
        for(int i=1; i<=n; i++)
        {
            if(a[i]>dp[len-1])
            {
                dp[len]=a[i];
                len++;
            }
            else
            {
                pos=lower_bound(dp,dp+len,a[i])-dp;
                dp[pos]=a[i];
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
///POJ 1458
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str1[1100],str2[1100];
int dp[1200][1200];
int main()
{
    int len1,len2;
    while(~scanf("%s %s",str1+1,str2+1))
    {
        for(int i=0;i<=1200;i++)
        {
            dp[i][0]=dp[0][i]=0;
        }
        len1=strlen(str1+1);
        len2=strlen(str2+1);
        for(int i=1;i<=len1;i++)
            for(int j=1;j<=len2;j++)
        {
            if(str1[i]==str2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
///POJ 1159
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[2][5010];
int main()
{
    int n,k;
    char str[5010];
    char str1[5010];
    while(~scanf("%d",&n))
    {
        k=1;
        scanf("%s",str+1);
        int len=strlen(str+1);
        for(int i=len; i>=1; i--)
            str1[k++]=str[i];
        memset(dp,0,sizeof(dp));
        int e=0;
        for(int i=1; i<=len; i++)
        {
            e=1-e;
            for(int j=0; j<=len; j++)
            {
                if(str[i]==str1[j])
                    dp[e][j]=dp[1-e][j-1]+1;
                else
                    dp[e][j]=max(dp[e][j-1],dp[1-e][j]);
            }
        }
        printf("%d\n",n-dp[e][len]);
    }
    return 0;
}
///HDU 2571
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int minn=-1e9;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    int dp[22][1005];
    int a[22][1005];
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&a[i][j]);
        }
        for(int i=0; i<=n; i++)
            dp[i][0]=minn;
        for(int j=0; j<=m; j++)
            dp[0][j]=minn;
        dp[0][1]=dp[1][0]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                for(int k = 2; k<=m; k++)
                {
                    if(j%k==0)
                        dp[i][j] = max(dp[i][j],dp[i][j/k]);
                }
                dp[i][j]+=a[i][j];
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
///HDU 1257
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int dp[11000],n;
    int a[11000];
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            dp[i]=1;
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        for(int j=2; j<=n; j++)
        {
            for(int i=1; i<j; i++)
            {
                if(a[j]>a[i]&&dp[j]<dp[i]+1)
                {
                    dp[j]=dp[i]+1;
                }
            }
        }
        int maxx=0;
        for(int i=1; i<=n; i++)
            if(dp[i]>maxx)
                maxx=dp[i];
        printf("%d\n",maxx);
    }

    return 0;
}
///HDU 1423
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define maxn 510
using namespace std;

int a[maxn],b[maxn],dp[maxn][maxn];
int main()
{
    int t;
    int n,m,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(a[i]!=b[j])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    for(int k=0; k<j; k++)
                    {
                        if(a[i]>b[k])
                        {
                             dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
                        }
                    }
                }
            }
        }
        ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                //printf("%d ",dp[i][j]);
                ans=max(ans,dp[i][j]);
            }
            //printf("\n");
        }
        printf("%d\n",ans);
        if(t)
            printf("\n");

    }
    return 0;
}
///HDU 1087
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n,maxn;
    int a[1100],dp[1100];
    while(~scanf("%d",&n))
    {
        maxn=0;
        memset(dp,0,sizeof(dp));
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        dp[1]=a[1];
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                if(a[i]>a[j])
                {
                    dp[i]=max(dp[i],dp[j]+a[i]);
                }
            }
            dp[i]=max(dp[i],a[i]);
        }
        for (int i=1; i<=n; i++)
        {
            //printf("%d ",dp[i]);
            maxn=max(maxn,dp[i]);
        }
        printf ("%d\n",maxn);
    }
    return 0;
}
///HDU 1025
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
///F
int arr[500010],dp[500010];
int main()
{
    int n,a,b,k,cnt=0,countt;
    while(~scanf("%d",&n))
    {
        k=0;
        countt=0;
        cnt++;
        map<int,int> mp;
        map<int,int> ::iterator it;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a,&b);
            mp[a]=b;
        }
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            arr[k++]=it->second;
            countt++;
        }
        dp[0]=arr[0];
        int len=1,pos=0;
        for(int i=1; i<countt; i++)
        {
            if(arr[i]>dp[len-1])
            {
                dp[len]=arr[i];
                len++;
            }
            else
            {
                pos=lower_bound(dp,dp+len,arr[i])-dp;
                dp[pos]=arr[i];
            }
        }
        printf("Case %d:\n",cnt);
        if(len==1)
        {
            printf("My king, at most %d road can be built.\n\n",len);
        }
        else
        {
            printf("My king, at most %d roads can be built.\n\n",len);
        }
        mp.clear();
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
///F
int arr[500010],dp[500010];
int main()
{
    int n,a,b,cnt=0;
    while(~scanf("%d",&n))
    {
        cnt++;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d",&a,&b);
            arr[a]=b;
        }
        dp[0]=arr[1];
        int len=1,pos=0;
        for(int i=1; i<=n; i++)
        {
            if(arr[i]>dp[len-1])
            {
                dp[len]=arr[i];
                len++;
            }
            else
            {
                pos=lower_bound(dp,dp+len,arr[i])-dp;
                dp[pos]=arr[i];
            }
        }
        printf("Case %d:\n",cnt);
        if(len==1)
        {
            printf("My king, at most %d road can be built.\n\n",len);
        }
        else
        {
            printf("My king, at most %d roads can be built.\n\n",len);
        }

    }
    return 0;
}
///HDU 1207
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int a[100];
int main()
{
    int cnt=2,sum=2,t=2;
    a[1]=1;
    while(t<=64)
    {
        for(int i=1;i<=cnt;i++)
        {
            a[t]=a[t-1]+sum;
            t++;
            if(t>64)
                break;
        }
        cnt++;
        sum*=2;
    }
        int n;
    while(~scanf("%d",&n))
    {
       printf("%d\n",a[n]);
    }
    return 0;
}
///CF 546D
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int a[5000010],temp,sum[5000010];
void xianxingshai()
{
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));
    sum[1] = 0;
    a[0]=a[1]=1;
    for(int i=2; i<=5000010; i++)
    {
        if(a[i]==0)
        {
            for(int j=i; j<=5000010; j+=i)
            {
                temp=j;
                while(temp%i==0)
                {
                    sum[j]++;
                    temp/=i;
                }
                a[j]=1;

            }
        }
    }
    for (int i=2; i<=5000010; i++)
    {
        sum[i]+=sum[i-1];
    }
}
int main()
{
    int t,a,b;
    while(~scanf("%d",&t))
    {
        xianxingshai();
        for(int i=1; i<=t; i++)
        {
            scanf("%d %d",&a,&b);
            printf("%d\n",sum[a]-sum[b]);
        }
    }
    return 0;
}
*/
