#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <vector>

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define loop(i, a) for (auto &i : a)

using namespace std;

typedef long int int32;

int32 n, m, k, s, d[10101];
map<string, int32> name;
map<int32, string> trace;
bitset<10101> sp, visited, exist[10101];
queue<int32> q;
vector<int32> adj[10101];
vector<string> ans;

int main() {
    // freopen("SPECONE.INP", "r", stdin);
    // freopen("SPECONE.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(d, 0, sizeof d);
    cin >> n >> k >> s >> m;
    rep(i, 1, s) {
        string x;
        cin >> x;
        if (!name.count(x))
            name[x] = name.size() + 1, trace[name[x]] = x;
        sp.set(name[x]);
        q.push(name[x]);
        d[name[x]] = 1e9, visited[name[x]] = true;
    }
    rep(i, 1, m) {
        string u, v;
        cin >> u >> v;
        if (!name.count(u))
            name[u] = name.size() + 1, trace[name[u]] = u;
        if (!name.count(v))
            name[v] = name.size() + 1, trace[name[v]] = v;
        if (exist[name[u]][name[v]])
            continue;
        exist[name[u]][name[v]] = exist[name[v]][name[u]] = true;
        adj[name[u]].push_back(name[v]);
        adj[name[v]].push_back(name[u]);
    }
    // Solve
    while (!q.empty()) {
        int32 u = q.front();
        q.pop();
        loop(v, adj[u]) {
            d[v]++;
            if (d[v] >= k && !visited[v]) {
                q.push(v);
                sp.set(v);
                visited[v] = true;
            }
        }
    }
    cout << sp.count() << endl;
    rep(i, 1, n) if (sp[i]) ans.push_back(trace[i]);
    sort(ans.begin(), ans.end());
    loop(v, ans) cout << v << " ";
    return 0;
}