# KMP算法

## 求Next数组

```c++
vector<int> Next;
void GetNext(string s){
    cout<<s<<endl;
    int n = s.length();
    Next.resize(n+1);
    for (int i  = 0,j=Next[0]=-1;i<n;Next[++i]=++j ){
        while (~j &&  s[j]!=s[i]) {
            j= Next[j];
        }
    }
    
}
```

## KMP

```c++
vector<int>  KMP(string text,string s){
    vector<int> ans;
    GetNext(s);
    int m = text.length(),n = s.length();
    for (int i = 0,j = 0;i<m;i++){
        while (j>0&&text[i]!=s[j]) j = Next[j];
        if(text[i]==s[j])++j;
        if(j==n) ans.push_back(i-n+1),j=Next[j]; 
    }
    return ans;
}
```

## 完整代码

```c++
#include <bits/stdc++.h>
using namespace std;

vector<int> Next;
void GetNext(string s){
    cout<<s<<endl;
    int n = s.length();
    Next.resize(n+1);
    for (int i  = 0,j=Next[0]=-1;i<n;Next[++i]=++j ){
        while (~j &&  s[j]!=s[i]) {
            j= Next[j];
        }
    }
    
}
vector<int>  KMP(string text,string s){
    vector<int> ans;
    GetNext(s);
    int m = text.length(),n = s.length();
    for (int i = 0,j = 0;i<m;i++){
        while (j>0&&text[i]!=s[j]) j = Next[j];
        if(text[i]==s[j])++j;
        if(j==n) ans.push_back(i-n+1),j=Next[j]; 
    }
    return ans;
}
int main(){
    string text = "bbbacbbbbabbab";
    string s = "bbbbab";
    cout<<KMP(text,s).size()<<endl;
    return 0;
}
```

