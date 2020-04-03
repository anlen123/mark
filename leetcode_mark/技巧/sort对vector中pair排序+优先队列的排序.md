# sort对vector中pair排序+优先队列的排序

```c++
//对vector中的 pair排序
 
vector<pair<int,char>>V;
bool cmp(const pair<int,char> a, const pair<int ,char> b) 
{
    return a.first<b.first;            /// first 小的在前
}
 
sort(V.begin(),V.end(),cmp);
```

```c
// priority_queue 普通优先队列( 如 int 队列)
 
priority_queue<int,vector<int>,greater<int> > //greater 小的先弹出，less 为大的先弹出
priority_queue<int>                          //默认，大的先弹出
```

```c++
// 优先队列中使用 pair , 自定义排序
 
#define pii pair<int,int>
 
struct cmp
{
    bool operator() (const pii p1,const pii p2)
    {
        return p1.first > p2.first;         // first 小的先弹出
    }
};
 
priority_queue<pii,vector<pii>,cmp> Q;
```

