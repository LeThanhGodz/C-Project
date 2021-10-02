#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n, sc, sr, ec, er, tim, used[1005][1005][4], cnt;
string a[1005];
bool b[1005][1005];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };
typedef pair<int, int> ii;
ii trace[4000005];
void DFS(int r, int c, int dir, int t) {
    if (t == 0) {
        cout << c << " " << r;
        return;
    }
    if (c < 1 || c > n || r < 1 || r > n) {
        int u = r + dr[dir - 1] * t;
        int v = c + dc[dir - 1] * t;
        cout << v << " " << u;
        return;
    }
    if (used[r][c][dir] == 0) {
        cnt++;
        used[r][c][dir] = cnt;
        trace[cnt].fi = r;
        trace[cnt].se = c;
        int ndir = dir, u, v;
        while (true) {
            u = r + dr[ndir - 1];
            v = c + dc[ndir - 1];
            if (b[u][v] == 0) {
                DFS(u, v, ndir, t - 1);
                break;
            } else {
                if (ndir < 4)
                    ndir++;
                else
                    ndir = 1;
            }
        }
    } else {
        int len = cnt - used[r][c][dir] + 1;
        int delta = len - ((t + 1) % len);
        int o = cnt - delta;
        cout << trace[o].se << " " << trace[o].fi;
        return;
    }
}
int main() {
    /*freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> sc >> sr >> tim;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#')
                b[i][j] = 1;
        }
    }
    if (sc >= 1 && sc <= n && sr >= 1 && sr <= n) {
        bool che = 0;
        for (int i = 0; i < 4; i++) {
            int u = sr + dr[i];
            int v = sc + dc[i];
            if (b[u][v] == 0)
                che = 1;
        }
        if (che == 0) {
            cout << sc << " " << sr;
            return 0;
        }
        DFS(sr, sc, 1, tim);
    } else {
        bool checker = 0;
        if (sr >= n && sc >= 1 && sc <= n) {
            if (sr - n - 1 < tim) {
                checker = 1;
                tim -= (sr - n - 1);
                sr = n + 1;
            }
        }
        if (checker == 1) {
            if (b[n][sc] == 0) {
                tim--;
                DFS(n, sc, 1, tim);
            } else {
                sc -= tim;
                cout << sc << " " << sr;
            }
        } else {
            sr -= tim;
            cout << sc << " " << sr;
        }
    }
}
//Nhưng nó có cái hay của nó