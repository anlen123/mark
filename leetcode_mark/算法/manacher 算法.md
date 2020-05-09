---
title: 堆排序
date: 2020-05-07 21:24:27
tags:
---
# manacher 算法



```c++
#include <bits/stdc++.h>
using namespace std;

string get_ss(string s){
    string ss = "$#";
    for(int i = 0;i<s.length();i++){
        ss+=s[i];
        ss+="#";
    }
    ss+="*";
    cout<<ss<<endl;
    return ss;
}
int manacher(string ss){
    int n = ss.length();
    int mx = 0;
    int id = 0;
    int MaxLeng = -1;
    vector<int> p(n,0);
    for(int i = 1;i<n-1;i++){
        if(mx>i){   
            p[i] = min(mx-i,p[id*2-i]);
        }
        else {
            p[i]=1;
        }

        while(ss[i+p[i]]==ss[i-p[i]]){
            p[i]++;
        }

        if(mx<p[i]+i){
            mx = p[i]+1;
            id = i;
        }
        MaxLeng= max(MaxLeng,p[i]-1);
    }
    return MaxLeng;
}

int main(){
    string s ;
    cin>>s;
    string ss = get_ss(s);
    cout<<manacher(ss)<<endl;
    return 0;
}
```

