#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int res[52][52];
vector<int> adj[52];
bool visited[52];

void conn(int a, int b, int c)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
    res[a][b] += c;
}

int dfs(int x, int cap = 1001)
{
    visited[x] = true;
    if (x == 51){
        return cap;
    }
    int cur;
    for (int i = 0; i < adj[x].size(); i++){
        if (!visited[adj[x][i]] && res[x][adj[x][i]] > 0){
            cur = dfs(adj[x][i], min(cap, res[x][adj[x][i]]));
            if (cur > 0){
                res[x][adj[x][i]] -= cur;
                res[adj[x][i]][x] += cur;
                return cur;
            }
        }
    }
    return 0;
}

int maxFlow()
{
    int flow = 0;
    while (true){
        for (int i = 0; i < 52; i++){
            visited[i] = false;
        }
        int cur = dfs(26);
        if (cur == 0){
            break;
        }
        flow += cur;
    }
    return flow;
}

int main()
{
    //freopen("MTOTALF.in", "r", stdin);
    int N;
    cin >> N;
    char a, b;
    int F;
    for (int i = 0; i < N; i++){
        cin >> a >> b >> F;
        conn((a >= 'a' && a <= 'z') ? a - 'a' : a - 'A' + 26, (b >= 'a' && b <= 'z') ? b - 'a' : b - 'A' + 26, F);
    }
    cout << maxFlow();
}
