#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define loop(i, a) for (auto &i : a)

using namespace std;

typedef long int int32;
typedef pair<int32, int32> pii;

struct node {
    int32 a, b;
    node() {}
    node(int32 a, int32 b) : a(a), b(b) {}
};

int32 m, n, T;
int32 matchX[50505], matchY[50505], d[50505];
vector<node> adj;
queue<int32> q;

bool bfs(int32 k) {
    rep(u, 1, k) if (!matchX[u]) {
        d[u] = 0;
        q.push(u);
    }
    else d[u] = 1e9;
    d[0] = 1e9;
    while (!q.empty()) {
        int32 u = q.front();
        q.pop();
        if (d[u] < d[0]) {
            rep(v, adj[u].a, adj[u].b) if (d[matchY[v]] == 1e9) {
                d[matchY[v]] = d[u] + 1;
                q.push(matchY[v]);
            }
        }
    }
    return d[0] < 1e9;
}

bool dfs(int32 u, int32 k) {
    if (u != 0) {
        rep(v, adj[u].a, adj[u].b) {
            if (d[matchY[v]] == d[u] + 1 && dfs(matchY[v], k)) {
                matchX[u] = v;
                matchY[v] = u;
                return true;
            }
        }
        d[u] = 1e9;
        return false;
    }
    return true;
}

// 50%
bool check(int32 k) {
    int32 res = 0;
    memset(matchX, 0, sizeof matchX);
    memset(matchY, 0, sizeof matchY);
    while (bfs(k)) {
        rep(u, 1, k) if (!matchX[u] && dfs(u, k)) res++;
    }
    return res == k;
}

bool cmp(node A, node B) { return A.a < B.a; }

// 100%
bool check1(int32 k) {
    vector<node> B;
    rep(i, 1, k) B.push_back(adj[i]);
    sort(B.begin(), B.end(), cmp);
    priority_queue<int32, vector<int32>, greater<int32>> pq;
    int32 cur = 0;
    rep(i, 1, m) {
        while (cur < B.size() && B[cur].a <= i && i <= B[cur].b) pq.push(B[cur++].b);
        if (!pq.empty() && pq.top() < i)
            return false;
        if (!pq.empty())
            pq.pop();
    }
    return pq.empty();
}

int main() {
    // freopen("QUEUE.INP", "r", stdin);
    // freopen("QUEUE.OUT", "w", stdout);
    scanf("%ld", &T);
    while (T--) {
        scanf("%ld %ld", &m, &n);
        int32 ans = 0;
        adj.resize(n + 2);

        //
        rep(i, 1, n) {
            int32 a, b;
            scanf("%ld %ld", &a, &b);
            adj[i] = node(a, b);
        }
        int32 l = 0, r = n;
        int32 mid = l + r >> 1;
        while (l <= r) {
            if (check1(mid)) {
                ans = mid;
                l = mid + 1;
            } else
                r = mid - 1;
            mid = l + r >> 1;
        }
        printf("%ld\n", ans);
    }
    return 0;
}