#include<bits/stdc++.h>
int GCD(int a,int b)
{
    return a%b?GCD(b,a%b):b;
}
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int x = GCD(n,m);
    cout<<x<<endl;
    return 0;
}