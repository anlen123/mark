# [1366. 通过投票对团队排名](https://leetcode-cn.com/problems/rank-teams-by-votes/)

现在有一个特殊的排名系统，依据参赛团队在投票人心中的次序进行排名，每个投票者都需要按从高到低的顺序对参与排名的所有团队进行排位。

排名规则如下：

参赛团队的排名次序依照其所获「排位第一」的票的多少决定。如果存在多个团队并列的情况，将继续考虑其「排位第二」的票的数量。以此类推，直到不再存在并列的情况。
如果在考虑完所有投票情况后仍然出现并列现象，则根据团队字母的字母顺序进行排名。
给你一个字符串数组 votes 代表全体投票者给出的排位情况，请你根据上述排名规则对所有参赛团队进行排名。

请你返回能表示按排名系统 排序后 的所有团队排名的字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rank-teams-by-votes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



```python
int cnt[30][30];
bool cmp(char a,char b){
    a-='A';
    b-='A';
    for (int i = 0;i<26;i++){
        if(cnt[a][i]>cnt[b][i]) return true;
        if(cnt[a][i]<cnt[b][i])return false;
    }
    return a<b;
}
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        memset(cnt,0,sizeof cnt);
        int len = votes[0].length();
        for (int i = 0;i<n;i++){
            for (int j = 0;j<len;j++){
                cnt[votes[i][j]-'A'][j]++;
            }
        }
        string s=votes[0];
        sort(s.begin(),s.end(),cmp);
        return s;
    }
};
```

