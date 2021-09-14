#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define loop(i, a) for (auto &i : a)

using namespace std;

typedef long int int32;

struct TYPE {
    int32 i, j, t1, t2;  // t1 chieu rong, t2 chieu dai
    TYPE() {}
    TYPE(int32 i, int32 j, int32 t1, int32 t2) : i(i), j(j), t1(t1), t2(t2) {}
};

int32 const movex[] = { 0, -1, 0, 1 };
int32 const movey[] = { -1, 0, 1, 0 };

int32 m, n, k, sd[5];
int32 S[1010][1010], F[1010][1010];
bool grid[1010][1010], visited[1010][1010][5][5];

int32 getS(int32 x, int32 y, int32 u, int32 v) {
    return S[u][v] - S[u][y - 1] - S[x - 1][v] + S[x - 1][y - 1];
}

bool check(int32 i, int32 j, int32 t1, int32 t2) {
    if (i < 1 || i > m)
        return false;
    if (j < 1 || j > n)
        return false;
    if (i + sd[t1] - 1 < 1 || i + sd[t1] - 1 > m)
        return false;
    if (j + sd[t2] - 1 < 1 || j + sd[t2] - 1 > n)
        return false;
    if (visited[i][j][t1][t2])
        return false;
    return getS(i, j, i + sd[t1] - 1, j + sd[t2] - 1) == 0;
}

void BFS() {
    queue<TYPE> q;
    q.push(TYPE(1, 1, 0, 1));
    memset(visited, false, sizeof visited);
    while (!q.empty()) {
        TYPE top = q.front();
        q.pop();
        // Tinh tien
        rep(i, 0, 3) {
            int32 u = top.i + movex[i], v = top.j + movey[i];
            if (!check(u, v, top.t1, top.t2))
                continue;
            q.push(TYPE(u, v, top.t1, top.t2));
            visited[u][v][top.t1][top.t2] = true;
        }
        // Lat khoi hop
        int32 t3 = 3 - top.t1 - top.t2;
        // Lat len
        if (check(top.i - sd[t3], top.j, t3, top.t2)) {
            q.push(TYPE(top.i - sd[t3], top.j, t3, top.t2));
            visited[top.i - sd[t3]][top.j][t3][top.t2] = true;
        }
        // Lat xuong
        if (check(top.i + sd[top.t1], top.j, t3, top.t2)) {
            q.push(TYPE(top.i + sd[top.t1], top.j, t3, top.t2));
            visited[top.i + sd[top.t1]][top.j][t3][top.t2] = true;
        }
        // Lat phai
        if (check(top.i, top.j + sd[top.t2], top.t1, t3)) {
            q.push(TYPE(top.i, top.j + sd[top.t2], top.t1, t3));
            visited[top.i][top.j + sd[top.t2]][top.t1][t3] = true;
        }
        // Lat trai
        if (check(top.i, top.j - sd[t3], top.t1, t3)) {
            q.push(TYPE(top.i, top.j - sd[t3], top.t1, t3));
            visited[top.i][top.j - sd[t3]][top.t1][t3] = true;
        }
    }
}

void addRect(int32 x, int32 y, int32 u, int32 v) {
    F[x][y]++, F[u + 1][v + 1]++;
    F[x][v + 1]--, F[u + 1][y]--;
}

int main() {
    // freopen("BLGAME.INP", "r", stdin);
    // freopen("BLGAME.OUT", "w", stdout);
    memset(grid, false, sizeof grid);
    rep(i, 0, 2) scanf("%ld", sd + i);
    scanf("%ld %ld %ld", &m, &n, &k);
    rep(i, 1, k) {
        int32 x, y;
        scanf("%ld %ld", &x, &y);
        grid[x][y] = true;
    }
    // Solve
    int32 res = 0;
    memset(S, 0, sizeof S);
    memset(F, 0, sizeof F);
    rep(i, 1, m) rep(j, 1, n) S[i][j] = S[i - 1][j] + S[i][j - 1] + (grid[i][j]) - S[i - 1][j - 1];
    BFS();
    rep(i, 1, m) rep(j, 1, n) {
        rep(t1, 0, 2) rep(t2, 0, 2) {
            if (t1 == t2)
                continue;
            if (!visited[i][j][t1][t2])
                continue;
            addRect(i, j, i + sd[t1] - 1, j + sd[t2] - 1);
            // printf("%ld %ld %ld %ld\n", i, j, t1, t2);
        }
    }
    rep(i, 1, m) rep(j, 1, n) {
        F[i][j] += F[i - 1][j] + F[i][j - 1] - F[i - 1][j - 1];
        if (F[i][j] != 0)
            res++;
    }
    printf("%ld", res);
    return 0;
}