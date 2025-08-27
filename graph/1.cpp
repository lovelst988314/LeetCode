#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<vector<int>>& graph, int x, int n) {
    if(x == n) {
        result.push_back(path);
        return;
    }
    for(int i = 1; i < n+1; ++i) {
        if(graph[x][i] == 1) {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m;
    fin >> n >> m;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    while(m--) {
        int s, t;
        fin >> s >> t;
        graph[s][t] = 1;
    }// [s][t]=1 表示s->t可通  

    path.push_back(1);
    dfs(graph, 1, n);

    if(result.size() == 0) {
        fout << -1 << endl;
        return 0;
    }  

    for(int i = 0; i < result.size(); ++i) {
        for(int j = 0; j < result[i].size(); ++j) {
            fout << result[i][j];
            if(j != result[i].size()-1) fout << " ";
        }
        fout << endl;
    }

}