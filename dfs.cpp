#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dir[4][2] = {0,1 ,0,-1, 1,0, -1,0};


void dfs(const vector<vector<int>>& graph, vector<vector<bool>> &used,int i, int j) {
    queue<pair<int,int>> que;
    que.push({i,j});
    used[i][j] = true;
    while(!que.empty()) {
        pair<int,int> pr = que.front();
        que.pop();
        for(int i = 0; i < 4; i++) {
            int nextx = pr.first + dir[i][0];
            int nexty = pr.second + dir[i][1];
            if(nextx >= 0 && nextx < graph.size() && nexty >= 0 && nexty < graph[0].size()) {
                if(graph[nextx][nexty] ==  1 && used[nextx][nexty] == false) {
                    que.push({nextx,nexty});
                    used[nextx][nexty] = true;
                }
            }
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n,vector<int>(m,0));
    vector<vector<bool>> used(n,vector<bool>(m,false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] && !used[i][j]) {
                result++;
                used[i][j] = true;
                dfs(graph,used,i,j);
            }
        }
    }

    cout << result << endl;
}