///O
/*
START 1 2
1

END
START 0 5
1 2 2 3 3 4 4




END
START 0 10
1 9
2
3
4
5
6
7
8
9

END
ENDOFINPUT
Sample Output
YES 1
NO
YES 10

#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int M, N;
int door[20];
string sh;
char ch1[800];

int main() {
	while (cin >> sh) {
		if (sh == "ENDOFINPUT") {
			break;
		}
		cin >> M >> N;
		getchar();
		int cnt = 0;
		memset(door, 0, sizeof(door));
		for (int i = 0; i < N; i++) {
			gets_s(ch1);
			int len = strlen(ch1);
			for (int j = 0; j < len; j++) {
				if (ch1[j] != ' ') {
					int d = ch1[j] - '0';
					cnt++;
					door[i]++;
					door[d]++;
				}
			}
		}
		cin >> sh;
		int odd = 0, even = 0;
		for (int i = 0; i < N; i++) {
			if (door[i] & 1)odd++;
		}
		if ((odd == 0 && M == 0) || (odd == 2 && M != 0)) {
			cout << "YES " << cnt << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}*/
///L
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[1010];
int fa[27],degree[27],in[27],out[27],flag[27],S[27];
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
int mix(int x,int y)
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
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(flag,0,sizeof(flag));
        int n;
        scanf("%d",&n);
        for(int i=0; i<26; i++)
            fa[i]=i;
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            int len=strlen(s);
            x=s[0]-'a';
            y=s[len-1]-'a';
            mix(x,y);
            in[y]++;
            out[x]++;
            flag[y]=flag[x]=1;
        }
        int cnt=0;
        for(int i=0; i<26; i++)
        {
            if(flag[i]&&fa[i]==i)
                cnt++;
        }
        if(cnt>1)
        {
            printf("The door cannot be opened.\n");
        }
        else
        {
            int k=0;
            for(int i=0; i<26; i++)
            {
                if(flag[i]&&in[i]!=out[i])
                    S[k++]=i;
            }
            if(k==0)
            {
                printf("Ordering is possible.\n");

            }
            else if(k==2&&((in[S[1]]-out[S[1]]==1&&out[S[0]]-in[S[0]]==1)||(in[S[0]]-out[S[0]]==1&&out[S[1]]-in[S[1]]==1)))
            {
                printf("Ordering is possible.\n");
            }
            else
                printf("The door cannot be opened.\n");
        }

    }
    return 0;
}
///B
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int mapp[2000][2000],in[2000],ans[2000],vis[2000],k,n;
void dfs(int u)
{
    for(int i=1; i<=n; i++)
    {
        int v=mapp[u][i];
        if(v&&!vis[i])
        {
            // printf("sss");
            vis[i]=1;
            dfs(v);
            ans[k++]=i;
        }
    }

}
int main()
{
    int x,y,z;
    while(~scanf("%d %d",&x,&y))
    {
        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));
        memset(mapp,0,sizeof(mapp));
        k=0,n=0;
        if(x==0&&y==0)
            break;
        scanf("%d",&z);
        mapp[x][z]=y;
        mapp[y][z]=x;
        in[x]++;
        in[y]++;
        n=max(n,z);
        for(int i=1;; i++)
        {
            scanf("%d %d",&x,&y);
            if(x==0&&y==0)
                break;
            scanf("%d",&z);
            mapp[x][z]=y;
            mapp[y][z]=x;
            in[x]++;
            in[y]++;
            n=max(n,z);
        }
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(in[i]%2)
            {
                cnt++;
                if(cnt>0)
                    break;
            }
        }
        if(cnt>0)
            printf("Round trip does not exist.\n");
        else
        {

            dfs(1);
            for(int i=k-1; i>=0; i--)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
///A  一笔画问题
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int fa[100010],degree[100010],ans[100010];
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}
void mix(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
    {
        fa[xx]=yy;
    }
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        int a,b;
        memset(degree,0,sizeof(degree));
        memset(ans,0,sizeof(ans));
        for(int i=0; i<=n; i++)
            fa[i]=i;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            mix(a,b);
            degree[a]++;
            degree[b]++;
        }
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(degree[i]%2)
            {
                ans[Find(i)]++;
                flag++;
            }
        }
        flag/=2;
        for(int i=1; i<=n; i++)
        {
            if(fa[i]==i)
            {
                if(!ans[i]&&degree[i])//是欧拉回路且不是一个独立的点
                    flag++;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}
///C  二維數組會爆空間
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=10010;
int n,m;
struct node
{
    int to,flag;
}s,w;
vector<node >g[maxn];
void dfs(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].to;
        if(g[u][i].flag)
        {
            g[u][i].flag=0;
           // g[i][u].flag=0;
            dfs(v);
        }
    }
    printf("%d\n",u);
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        int a,b;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&a,&b);
            s.to=b;
            s.flag=1;
            w.to=a;
            w.flag=1;
            g[a].push_back(s);
            g[b].push_back(w);
        }
        dfs(1);
    }
    return 0;
}
///E
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
char s[1010][30];
char ans[1010][30];
int n;
int fa[27],in[27],out[27],flag[27],S[27],b[1010],K;
struct node
{
    char s[25];
    int x,y;
} e[1010];
int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
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
bool cmp(node n1,node n2)
{
    return strcmp(n1.s,n2.s)<0;
}
void dfs(int r)
{
    for(int i=0; i<n; i++)
    {
        if(!b[i]&&e[i].x==r)
        {
            b[i]=1;
            dfs(e[i].y);
            strcpy(ans[K++],e[i].s);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0; i<27; i++)
            fa[i]=i;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(flag,0,sizeof(flag));
        memset(b,0,sizeof(b));
        for(int i=0; i<n; i++)
        {
            scanf("%s",e[i].s);
            int len=strlen(e[i].s);
            e[i].x=e[i].s[0]-'a';
            e[i].y=e[i].s[len-1]-'a';
            in[e[i].y] ++;
            out[e[i].x] ++;
            mix(e[i].x,e[i].y);
            flag[e[i].x]=flag[e[i].y]=1;
        }
        sort(e,e+n,cmp);
        int cnt=0;
        for(int i=0; i<27; i++)
        {
            if(flag[i]&&fa[i]==i)
                cnt++;
        }
        if(cnt>1)
            printf("***\n");
        else
        {
            int n1=0,n2=0;
            int i,x=-1;
            for(i=0; i<27; i++)
            {
                if(flag[i]&&in[i]-out[i]==1)
                {
                    n1++;
                    if(n1>1)
                        break;
                }
                else if(flag[i]&&out[i]-in[i]==1)
                {
                    n2++;
                    x=i;
                    if(n2>1)
                        break;
                }
                else if(flag[i]&&abs(out[i]-in[i])>1)
                    break;
            }
            if(i<=26)
            {
                printf("***\n");
            }
            else
            {
                if(x==-1)
                {
                    for(int i=0; i<27; i++)
                    {
                        if(flag[i])
                        {
                            x=i;
                            break;
                        }
                    }
                }
                K=0;
                dfs(x);
                for(int i=K-1; i>=1; i--)
                    printf("%s.",ans[i]);
                printf("%s\n",ans[0]);
            }
        }
    }
    return 0;
}
///D
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int mx=500100;
int degree[mx],fa[mx],cur;
int cnt=1;
struct node
{
    int data[27];
    int num,id;
    void init()
    {
        for(int i=0; i<27; i++)
            data[i]=-1;
        num=0;
    }
} T[mx];

int CreatTire(char *s,int len)
{
    int p=0;
    for(int i=0; i<len; i++)
    {
        int x=s[i]-'a';
        if(T[p].data[x]==-1)
        {
            T[cur].init();
            T[p].data[x]=cur++;
        }
        p=T[p].data[x];
    }
    if(T[p].num==1)
        return T[p].id;
    else
    {
        T[p].num=1;
        T[p].id=cnt++;
    }
    return T[p].id;
}

int Find(int x)
{
    if(x!=fa[x])
        fa[x]=Find(fa[x]);
    return fa[x];
}

void Mix(int x,int y)
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
    char s1[15],s2[15];
    memset(degree,0,sizeof(degree));
    for(int i=0; i<mx; i++)
        fa[i]=i;
    T[0].init();
    cur=1;
    while(~scanf("%s %s",s1,s2))
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        int a=CreatTire(s1,len1);
        int b=CreatTire(s2,len2);
        degree[a]++;
        degree[b]++;//度
        Mix(a,b);
    }
    int cot=0,cot1=0;
    for(int i=1; i<cnt; i++)
    {
        if(degree[i]%2)
            cot++;
        if(fa[i]==i)
            cot1++;
    }
    if(cot>2||cot1>1)
        printf("Impossible\n");
    else
        printf("Possible\n");
    return 0;
}
///G
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m,pic[1100][1100],d[1100],road[1500],now;
void dfs(int x)
{
    for(int i=1;i<=500;i++)
        if(pic[x][i])
        {
            pic[x][i]--;             //注意可能有重边
            pic[i][x]--;
            dfs(i);
        }
    road[++now]=x;             //记录路径
}
int main()
{
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        pic[x][y]++;
        pic[y][x]++;
        d[x]++;
        d[y]++;
    }
    int st=1;                          //如果无度为1的点，则从任意点开始搜，即寻找欧拉回路
    for(int i=1;i<=500;i++)            //如果有度为1的点，则从该点开始搜，即寻找欧拉路
        if(d[i]%2)
        {
            st=i;
            break;
        }
    dfs(st);
    for(int i=now;i>=1;i--)
    {
        cout<<road[i]<<endl;
    }
    return 0;
}

9
1 2
2 3
3 4
4 2
4 5
2 5
5 6
5 7
4 6*/
