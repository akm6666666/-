#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//华为2023412
int n;
vector<vector<int>> node;
vector<int> dp;

int  dfs(int index){
     if(dp[index]!=INT_MIN) return dp[index];
    if(node[index][0]==-1)  return node[index][1];
    
    dp[index]=max(node[index][1],node[index][1]+dfs(node[index][0]));

    return dp[index];
}

int main(){
    
   cin>>n;
   node = vector<vector<int>>(n,vector<int>(2,INT_MIN));
   dp=vector<int>(n,INT_MIN);
   int i=n;
   while(i--){
     int  a,b,c;
     cin >> a>> b >> c;
     node[a][0]=b;
     node[a][1]=c;
   }

   for(int i=0;i<n;i++){
     dp[i]=dfs(i);
   }

   cout<<*max_element(dp.begin(),dp.end())<<endl;
   return 0;


}

/*
主办方设计了一个获取食物的游戏。游戏的地图由N个方格组成，每个方格上至多2个传送门，通过传送门可将参与者传送至指定的其它方格。同时，每个方格上标注了三个数字: 
(1) 第一个数字id:代表方格的编号，从0到N-1，每个方格各不相同

(2)第二个数字parent-id:代表从编号为parent-id的方格可以通过传送门传送到当前方格(-1则表示没有任何方格可以通过传送门传送到此方格，这样的方格在地图中有且仅有一个); 
(3)第不个数字value: 取值在[100，100]的整数值，正整数代表参与者得到相队取值单位的食物，负整数代表失去相应数值单位的食物(参与者可能存在临时持有食物为负数的情况)，0则代表无变化。
此外，地图设计时保证了参与者不可能到达相同的方格两次，并且至少有一个方格的value是正整数。 游戏开始后，参与者任意选择一个方格作为出发点，当遇到下列情况之一退出游戏: 
(1)参与者当前所处的方格无传送门: (2) 参与者在任意方格上丰动宣布退出游戏 请计算参与者退出游戏后，最多可以获得多少单位的食物 解答要求 
时间限制: C/C++ 1300ms.其他语言:2600ms内存限制: C/C++256MB其他语言:512MB 第一行:方块个数N (N<10000)

样例1输入:

7
0 1 8
1 -1 -2
2 1 9
4 0 -2
5 4 3
3 0 -3
6 2 -3
输出:

9
参与者从方格0出发，通过传送门到达方格4，再通过传送门到达方格5。一共获得8+(-2) +3=9个单位食物，得到食物展多: 或者参与者在游戏开始时处于方格2，直接主动宣布退出游戏，也可以获得9个单位食物。


样例2输入:

3
0 -1 3
1 0 1
2 0 2
输出:

5
解释:

参与者从方格0出发，通过传送门到达方格2，一共可以获得3+2=5个单位食物，此时得到食物最多


*/