//classic 递归与回溯遍历图法
链接：https://www.nowcoder.com/questionTerminal/4b20ed271e864f06ab77a984e71c090f
来源：牛客网

#include <iostream>
#include <vector>
#include <limits.h>//用于限制内置变量类型如int，double，char的内存极限，如int不超过255等
 
using namespace std;
 
void dfs(int start, int index, int end);
 
int cmax, N, sp, M;
int costTimes, outBikes, inBikes;
int resultTimes = INT_MAX;
int resultOutBikes, resultInBikes;
vector<int> bikes, path, resultPath;
vector<vector<int> > times;
vector<bool> visited;
 
int main()
{
    ios::sync_with_stdio(false);
    // 输入数据
    cin >> cmax >> N >> sp >> M;
    bikes.resize(N+1, 0);
    visited.resize(N+1, false);
    times.resize(N+1, vector<int>(N+1, 0));
    for(int i=1; i<=N; i++) {
        cin >> bikes[i];
    }
    int m, n, dist;
    for(int i=0; i<M; i++) {
        cin >> m >> n >> dist;
        times[m][n] = dist;
        times[n][m] = dist;
    }
 
    // 深搜并输出结果
    dfs(0, 0, sp);
    cout << resultOutBikes << " 0";
    for(int i=1; i<resultPath.size(); i++) {
        cout << "->" << resultPath[i];
    }
    cout << " " << resultInBikes;
 
    return 0;
}
 
void dfs(int start, int index, int end)
{
    // 访问
    visited[index] = true;
    path.push_back(index);
    costTimes += times[start][index];
 
    // 处理
    if(index == end) {
        // 计算这条路上带去的车和带回的车
        inBikes = 0, outBikes = 0;
        for(int i=1; i<path.size(); i++) {
            if(bikes[path[i]] > cmax/2) {
                inBikes += bikes[path[i]] -cmax/2;
            } else {
                if((cmax/2 - bikes[path[i]]) < inBikes) {
                    inBikes -= (cmax/2 - bikes[path[i]]);
                } else {
                    outBikes += (cmax/2 - bikes[path[i]]) - inBikes;
                    inBikes = 0;
                }
            }
        }
        // 判断这条路是否更好
        if(costTimes != resultTimes) {
            if(costTimes < resultTimes) {
                resultTimes = costTimes;
                resultPath = path;
                resultOutBikes = outBikes;
                resultInBikes = inBikes;
            }
        } else if(outBikes != resultOutBikes) {
            if(outBikes < resultOutBikes) {
                resultPath = path;
                resultOutBikes = outBikes;
                resultInBikes = inBikes;
            }
        } else if(inBikes < resultInBikes) {
            resultPath = path;
            resultOutBikes = outBikes;
            resultInBikes = inBikes;
        }
    } else {
        // 递归
        for(int i=1; i<=N; i++) {
            if(times[index][i] != 0 && !visited[i]) {
                dfs(index, i, end);
            }
        }
    }
 
    // 回溯
    visited[index] = false;
    path.pop_back();
    costTimes -= times[start][index];
}