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
using namespace std;
const int MAXX = 100000 + 10;
const double PI = 3.14159265358979323846;
const ll mod = 1000000007;
int main() {
	int n, m;
	while (~scanf("%d%d",&n,&m)) {
		int sum = abs(n - m);
		int ans = min(n, m);
		int kk = sum * (1 + sqrt(5)) / 2;
		if (ans ==kk) {
			printf("Lao Wang\n");
		}
		else {
			printf("Xiao Ren\n");
		}
	}

}