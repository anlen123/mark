---
title: dp学习
date: 2020-05-07 21:24:27
tags:
---
# **dp学习**

#### [64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)

```java

/*
求一个N*M 的数组,,从0,0走到最右下角的最短数值是多少
*/


package com.leecode;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[][] a = new int[100][100];
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int m = cin.nextInt();
        int[][] dp = new int[n+5][m+5];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = cin.nextInt();
            }
        }
        /**
         * 功能描述: 记忆化搜索
         * @param: [args]
         * @return: void
         * @author: anlen123
         * @date: 2020/4/24 - 15:33
         */
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < m; j++) {
//                dp[i][j] = -1;
//            }
//        }
//        int ret = dfs(n-1,m-1,a,dp);
//        System.out.println(ret);


        
        
        /**
         * 功能描述: 递归做法
         * @param: [args]
         * @return: void
         * @author: anlen123
         * @date: 2020/4/24 - 15:42
         */

        dp[0][0] = a[0][0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i-1][0]+a[i][0];
        }
        for (int i = 1; i < m; i++) {
            dp[0][i]=dp[0][i-1]+a[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = Math.min(dp[i-1][j],dp[i][j-1])+a[i][j];
            }
        }
        System.out.println(dp[n-1][m-1]);
    }
    
    
    /**
     * 功能描述: 记忆化搜索
     * @param: [x, y, a, dp]
     * @return: int
     * @author: anlen123
     * @date: 2020/4/24 - 15:42
     */

    public static int dfs(int x,int y,int[][] a,int[][] dp){
        if(x==0 && y==0) return a[0][0];
        if(x<0 || y< 0) return 99999999;
        if(dp[x][y]!=-1) return dp[x][y];
        return Math.min(dfs(x-1,y,a,dp),dfs(x,y-1,a,dp))+a[x][y];
    }

}


```

#### [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)

```java
/*

https://leetcode-cn.com/problems/maximum-subarray/
53. 最大子序和

给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

class Solution {
    public int maxSubArray(int[] nums) {
        int [] dp = new int[nums.length+1];

        dp[0] = nums[0];
        int ret = dp[0];
        for (int i = 1; i <nums.length; i++) {
            dp[i] = Math.max(nums[i],nums[i]+dp[i-1]);
            ret = Math.max(ret,dp[i]);
        }
        return ret;

    }
}
```

#### [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

```java
https://leetcode-cn.com/problems/house-robber/

/**
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    public int rob(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        if(nums.length==2){
            return Math.max(nums[0],nums[1]);
        }
        int [] dp = new int[nums.length+1];

        dp[0] = Math.max(nums[0],0);

        dp[1] = Math.max(nums[0],nums[1]);

        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[nums.length-1];
    }
}
```

#### [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)

```java
213. 打家劫舍 II
/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
    public int rob(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        return Math.max(DP(Arrays.copyOfRange(nums, 1, nums.length)),
                DP(Arrays.copyOfRange(nums, 0, nums.length-1)));
    }
    public int DP(int[] nums){
        if (nums == null || nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int[] dp = new int[nums.length + 1];

        dp[0] = Math.max(nums[0], 0);

        dp[1] = Math.max(nums[0], nums[1]);

        for (int i = 2; i < nums.length; i++) {
            dp[i] = Math.max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.length - 1];
    }
}    
```

#### [300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

```java
300. 最长上升子序列   //经典
/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

图片题解
https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
*/
    
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums==null || nums.length==0){
            return 0;
        }
        int[] dp = new int[nums.length + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i]=1;
        }
        int ret = 1;
        for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
            ret = Math.max(ret,dp[i]);
        }
        return ret;
    }
}
```

#### [62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)

```java
62. 不同路径
https://leetcode-cn.com/problems/unique-paths/

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

例如，上图是一个7 x 3 的网格。有多少可能的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

```

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/robot_maze.png)

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m+1][n+1];
        for (int i = 0; i < m + 1; i++) {
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[0][i]=0;
            dp[1][i]=1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
}
```

#### [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)

```java
/*
https://leetcode-cn.com/problems/longest-common-subsequence/
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

示例 1:

输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:

输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:

输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

|  {  dp[i-1][j-1]+1  ,             text1[i]==text[j];
|  {  max(dp[i-1][j],dp[i][j-1]) ,  other;


class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()+1][text2.length()+1];

        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if(text1.charAt(i-1)==text2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()][text2.length()];
    }
}
```

#### [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

```java
/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

 

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX  = amount+1;
        vector<int> dp(MAX,MAX);
        dp[0] = 0;
        for(int i = 1;i<=amount;i++){
            for(int j = 0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]==MAX){
            return -1;
        }
        else {
            return dp[amount];
        }
    }
};
```

----

----



####  [01背包](https://blog.csdn.net/achesong/article/details/88428895)

![](https://img-blog.csdnimg.cn/20190312205757755.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2FjaGVzb25n,size_16,color_FFFFFF,t_70)

```java
/*
有n件物品，每件物品的重量为w[i]，价值为c[i]。现有一个容量为V的背包，问如何选取物品放入背包，使得背包内物品的总价值最大。其中
每种物品都只有一件。
*/
package com.leecode;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Solution solution = new Solution();
        int N,V;
        N = cin.nextInt();
        V = cin.nextInt();
        int[] w = new int[10];
        int[] v = new int[10];
        for (int i = 1; i <= N; i++) {
            w[i] = cin.nextInt();
            v[i] = cin.nextInt();
        }
        int[][] dp = new int[N+1][V+1];
        dp[0][0] = 0;
        for (int i = 1; i <= N ; i++) {
            for (int j = 1; j <= V; j++) {
                if(w[i]>j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = Math.max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                }
            }
        }
        System.out.println(dp[N][V]);
    }
}




//一维优化
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Solution solution = new Solution();
        int N,V;
        N = cin.nextInt();
        V = cin.nextInt();
        int[] w = new int[10];
        int[] v = new int[10];
        for (int i = 1; i <= N; i++) {
            w[i] = cin.nextInt();
            v[i] = cin.nextInt();
        }
        int[] dp = new int[V+1];
        dp[0]=0;
        for (int i = 1; i <= N ; i++) {
            for (int j = V; j >=w[i]; j--) {
                dp[j] = Math.max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        System.out.println(dp[V]);
    }
}
    
```

