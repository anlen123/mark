---
title: 快速幂
date: 2020-05-07 21:24:27
tags:
---

```c
ll quick_pow(ll a, ll b, ll mod) {
	ll ans = 1;
	while (b)
	{
		if (b & 1) ans = (ans*a) % mod;
		a = (a*a) % mod;
		b >>= 1;
	}
	return ans;
}
```