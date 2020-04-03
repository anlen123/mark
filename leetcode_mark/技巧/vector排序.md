# 单个vector
```c++
bool cmp(int  a,int b){
    return a > b;
}
vector<int> ans;
sort(ans.begin(),ans.end(),cmp);


```
# 居然还可以在后面直接写

```c++
vector<int> ans;
ans.push_back(10);    
ans.push_back(100);
ans.push_back(1);
sort(ans.begin(),ans.end(),[](int a,int b){
    return a>b;
});
/*
执行完成，耗时：0 ms
100
10
1
*/
```



# map的value值排序

```c++
// map 内部是红黑树，key值已经是排好序的了
map<char,int> mp;
map<char,int> ::iterator it;
mp['A']=1;
mp['B']=-1;

//首先用vector把map的key和value取出来
vector<pair> ans;
for (it=mp.begin(),it!=end();it++){
    ans.push_back(*it);
}
vector<int> ans;
bool cmp(const pair<char,int> a,const pair<char,int> b){
    return a.second < b.second;
}
sort(ans.begin(),ans.end(),cmp);

// 去出vector的key和value
for (int i= ;i< ans.size();i++){
    cout<<ans[i].first;
    cout<<ans[i].second;

}


```

