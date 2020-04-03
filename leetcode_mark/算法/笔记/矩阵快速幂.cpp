  #include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXX = 1000000 + 10;
const ll MOD  = 32767;
const double PI = 3.14159265358979323846;
ll oula(ll n)
{
    ll i, rea = n;
    for (i = 2; i*i <= n; i++)
    {
        if (n%i == 0)
        {
            rea = rea - rea / i;
            while (n%i == 0)
                n /= i;
        }
    }
    if (n > 1)
        rea = rea - rea / n;
    return rea;
}
struct node
{
    ll a[2][2];
} X, res, ans;

ll ksc(ll a,ll b,ll mod)
{
    ll ans = 0;
    while (b)
    {
        if (b&1)
            ans = (ans %mod + a % mod )%mod;
        a = a%mod  + a %mod;
        b >>=1;
    }
    return ans;
}

node cheng(node x, node y)
{
    node S;
    memset(S.a, 0, sizeof(S.a));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                S.a[i][j] +=ksc(x.a[i][k],y.a[k][j],MOD);
                S.a[i][j]  = (S.a[i][j]+MOD)%MOD;
            }
        }
    }
    return  S;
}

void ksm(ll  n)
{
    while (n)
    {
        if (n & 1)
            ans = cheng(ans, X);
        X = cheng(X, X);
        n >>= 1;
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {

        ll  n;
        ans.a[0][0] = 1;//单位矩阵
        ans.a[0][1] = 0;
        ans.a[1][0] = 1;
        ans.a[1][1] = 0;
        X.a[0][0] = 2;
        X.a[0][1] = 1;
        X.a[1][0] = 1;
        X.a[1][1] = 0;
        cin>>n;
        if (n==1)
        {
            cout<<1<<endl;
            continue;
        }
        ksm(n-2);
        node S;  
        S.a[0][0]=2;   前两项
        S.a[1][0]=1;
        S= cheng(ans,S);
        ll xx =  S.a[0][0];
        cout <<xx<< endl;
    }
    return 0;
}
