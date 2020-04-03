题意：q次查询，给出a,b，求最多的可能组数使得 x*y<a*b

思路：组数与sqrt(a*b)有关，然后根据关系来计算，可以当一个结论记住

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
	int n;
	cin >> n;
	ll a, b, pr;
	ll ans;
	for(int i = 1;i <= n; i++)
	{
		cin >> a >> b;
		pr = a * b;
		ll t = sqrt(pr);
		if(t * (t + 1) < pr)
			ans = t * 2 - 1;
		else if(t * t == pr)
		{
			if(a == b)
				ans = (t - 1) * 2;
			else
				ans = (t - 1) * 2 - 1;
		}
		else
			ans = (t - 1) * 2;
		cout << ans << endl;
	}
	return 0;
}
