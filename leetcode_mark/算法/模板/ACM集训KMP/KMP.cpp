/*///A

Sample Input
2
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 1 3
13 5
1 2 1 2 3 1 2 3 1 3 2 1 2
1 2 3 2 1
Sample Output
6
-1


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1000100],b[10100],Next[10100];
int n,m;
int getnext(int m)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<=m)
    {
        if(j==-1||b[i]==b[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP(int n,int m)
{
    int j=0,i=0;
    while(i<n)
    {
        if(j==-1||a[i]==b[j])
        {
            i++,j++;
        }
        else
            j=Next[j];
        if(j==m)
            return i-j+1;
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        getnext(m);
        int ans=KMP(n,m);
        printf("%d\n",ans);
    }
    return 0;
}
///C
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[300],str1[300];
int Next[300],cnt;
void getnext(int l2)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<l2)
    {
        if(j==-1||str1[i]==str1[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP(int L1,int L2)
{
    int j=0,i=0;
    while(i<=L1)
    {
        if(j==-1||str[i]==str1[j])
            i++,j++;
        else
            j=Next[j];
        if(j==L2)
        {
            cnt++;
            j=0;
        }
        if(i==L1)
            return cnt;
    }
}
int main()
{
    while(~scanf("%s",str))
    {
        cnt=0;
        if(!strcmp(str,"#"))
            break;
        scanf("%s",str1);
        int l1=strlen(str);
        int l2=strlen(str1);
        getnext(l2);
        int ans=KMP(l1,l2);
        printf("%d\n",ans);
    }
    return 0;
}
///B


Sample Input
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
Sample Output
1
3
0


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char w[10010],T[1000100];
int Next[10010],cnt;
void getnext(int l1)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<=l1)
    {
        if(j==-1||w[i]==w[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP(int l1,int l2)
{
    int j=0,i=0;
    while(i<l2)
    {
        if(j==-1||w[j]==T[i])
            i++,j++;
        else
            j=Next[j];
        if(j==l1)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%s%s",w,T);
        int l1=strlen(w);
        int l2=strlen(T);
        getnext(l1);
        int ans=KMP(l1,l2);
        printf("%d\n",ans);
    }
    return 0;
}
///D


Sample Input
3
aaa
12
aabaabaabaab
0
Sample Output
Test case #1
2 2
3 3

Test case #2
2 2
6 2
9 3
12 4


#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000100];
int Next[1000100],vis[1000100],len,n;
//循环节长度(i - 1) - ( next[i] - 1 ) = i - next[i];
void getnext(int len)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<=len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int main()
{
    int k=1;
    while(~scanf("%d",&n)&&n!=0)
    {
        scanf("%s",str);
        len=strlen(str);
        getnext(len);
        printf("Test case #%d\n",k++);
        for(int i=1; i<=len; i++)
        {
            if(i%(i-Next[i])==0&&Next[i]!=0)
            {
                printf("%d %d\n",i,i/(i-Next[i]));
            }
        }
        printf("\n");
    }
    return 0;
}
///F;

Sample Input
abcd
aaaa
ababab
.
Sample Output
1
4
3


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[1000100];
int Next[1000100],len;
void getnext(int len)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int main()
{
    while(~scanf("%s",str)&&str[0]!='.')
    {
        len=strlen(str);
        getnext(len);
        int ans=1;
        if(len%(len-Next[len])==0&&Next[len]!=0)
            ans=len/(len-Next[len]);
        printf("%d\n",ans);
    }
    return 0;
}
///I;

Sample Input
clinton
homer
riemann
marjorie
Sample Output
0
rie 3

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[50010],s2[50010];
int Next[50010],cnt;
void getnext(int len1)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<=len1)
    {
        if(j==-1||s1[i]==s1[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP(int len1,int len2)
{
    int i=0,j=0;
    while(i<len2)
    {
        if(j==-1||s1[j]==s2[i])
        {
            i++,j++;
        }
        else
        {
            j=Next[j];
        }
    }
    return j;

}
int main()
{
    int ans;
    while(~scanf("%s %s",s1,s2))
    {
        cnt=0;
        int len1=strlen(s1);
        int len2=strlen(s2);
        getnext(len1);
        ans=KMP(len1,len2);
        if(ans==0)
            printf("%d\n",ans);
        else
        {
            printf("%s %d\n",s2+len2-ans,ans);
        }
    }
    return 0;
}
///R
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[1000100];
int Next[1000100];
int a[1000100],k,t;
void getnext(int len)
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int main()
{

    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int k=1;
        scanf("%s",str);
        int len=strlen(str);
        getnext(len);
        a[0]=len;
        int temp=Next[len];
        while(temp)
        {
            a[k++]=len-temp;
            temp=Next[temp];
        }
        printf("Case #%d: %d\n",i,k);
        for(int i=1;i<k;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[0]);
    }
    return 0;
}
///E


Sample Input
abc
aaabcbc
b
bbb
abc
ab
Sample Output
a
ab


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[5000010],s2[5000010];
char ans[5000010];
int Next[5000010],pos[5000010],cnt;
void getnext(int len1)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<len1)
    {
        if(j==-1||s1[i]==s1[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
void KMP(int len1,int len2)
{
    int j=0,i=0;
    cnt=0;
    while(i<len2)
    {
        ans[cnt]=s2[i];
        if(j==-1||s1[j]==s2[i])
        {
            i++,j++,cnt++,
            pos[cnt]=j;
        }
        else
            j=Next[j];
        if(j==len1)
        {
            cnt-=len1;
            j=pos[cnt];
        }
    }
    if(cnt==0)
        printf("\n");
    else
    {
        for(int i=0; i<cnt; i++)
            printf("%c",ans[i]);
        printf("\n");
    }
}
int main()
{
    while(~scanf("%s %s",s1,s2))
    {
        int len1=strlen(s1);
        int len2=strlen(s2);
        getnext(len1);
        KMP(len1,len2);
    }
    return 0;
}
///G
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[400010];
int Next[400010];
void getnext(int len)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
    for(int i=0;i<=len;i++)
        printf("%d ",Next[i]);
    printf("\n");
}
int main()
{
    while(~scanf("%s",str))
    {
        int len=strlen(str);
        getnext(len);
    }
    return 0;
}

///J
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
char str[200010];
int Next[200010],dp[200010];
void getnext(int len)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<=len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d",&n);
        scanf("%s",str);
        int len=strlen(str);
        getnext(len);
        dp[0]=0;
        for(int i=1;i<=len;i++)
        {
            dp[i]=dp[Next[i]]+1;
            sum+=dp[i];
        }
        printf("%d\n",sum%10007);
    }
    return 0;
}
///G
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
char str[400010];
int Next[400010];
int a[400010];
void getnext(int len)
{
    int j=-1,i=0;
    Next[0]=-1;
    while(i<=len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
    //for(int i=1;i<=len;i++)
      //  printf("%d ",Next[i]);
}
int main()
{
    while(~scanf("%s",str))
    {
        int k=1;
        int len=strlen(str);
        getnext(len);
        int temp=len;
        a[0]=len;
        while(Next[temp])
        {
            a[k++]=Next[temp];
            temp=Next[temp];
        }
        for(int i=k-1;i>=1;i--)
            printf("%d ",a[i]);
        printf("%d\n",a[0]);
    }
    return 0;
}
///L

Sample Input
2
3
ABCD
BCDFF
BRCD
2
rose
orchid
Sample Output
2
2


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    int t,n,flag;
    scanf("%d",&t);
    char str[110][110],s1[110],s2[110];
    while(t--)
    {
        int n,pos=0,maxn=0;
        scanf("%d",&n);
        int minn=1000;
        for(int i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            int len=strlen(str[i]);
            if(len<minn)
            {
                minn=len;
                pos=i;
            }
        }
        for(int i=0; i<minn; i++)
        {
            for(int j=i; j<minn; j++)
            {
                flag=1;
                for(int k=i; k<=j; k++)
                {
                    s1[k-i]=s2[j-k]=str[pos][k];
                }
                s1[j-i+1] = s2[j-i+1] = '\0';
                printf("%s %s\n",s1,s2);
                int len1=strlen(s1);
                for(int l=0; l<n; l++)
                {
                    //printf("ssss");
                    if(!strstr(str[l],s1)&&!strstr(str[l],s2))
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    maxn=max(maxn,len1);
                }
            }
        }
        printf("%d\n",maxn);
    }
    return 0;
}
///H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    char str[15][65],s1[65],s2[65];
    int t,n,flag,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        memset(s2,'\0',sizeof(s2));
        for(int i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            // int len1=strlen(str[i]);
            //printf("%d\n",len1);
        }
        for(int i=0; i<=60; i++)
        {
            for(int j=i; j<=60; j++)
            {
                flag=1;
                for(int k=i; k<=j; k++)
                {
                    s1[k-i]=str[0][k];
                }
                s1[j-i+1]='\0';
                int len=strlen(s1);
                for(int l=0; l<n; l++)
                {
                    if(!strstr(str[l],s1))
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    if(len>ans)
                    {
                        ans=len;
                        strcpy(s2,s1);
                    }
                    if(len==ans)
                    {
                        if(strcmp(s1,s2)<0)///s1比s2字典序大
                            strcpy(s2,s1);
                    }
                }
            }
        }
        if(ans<3)
            printf("no significant commonalities\n");
        else
            printf("%s\n",s2);
    }
    return 0;
}*/
///M
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    int n,ans;
    int len,flag;
    char str[4010][210],s1[210],s2[210];
    while(~scanf("%d",&n)&&n!=0)
    {
        memset(s2,'\0',sizeof(s2));
        for(int i=0; i<n; i++)
        {
            scanf("%s",str[i]);
            len=strlen(str[0]);

        }
        ans=0;
        for(int i=0; i<=len; i++)
        {
            for(int j=i; j<=len; j++)
            {
                flag=1;
                for(int k=i; k<=j; k++)
                {
                    s1[k-i]=str[0][k];
                }
                s1[j-i+1]='\0';
                int len1=strlen(s1);
                for(int l=0; l<n; l++)
                {
                    if(!strstr(str[l],s1))
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    if(len1>ans)
                    {
                        ans=len1;
                        strcpy(s2,s1);
                    }
                    if(len1==ans)
                    {
                        if(strcmp(s1,s2)<0)
                            strcpy(s2,s1);
                    }
                }
            }
        }
        if(!ans)
            printf("IDENTITY LOST\n");
        else
            printf("%s\n",s2);
    }
    return 0;
}
