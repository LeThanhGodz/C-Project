#define Tourist "ROBOT"
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORs(i, a, b) for (int i = a; i < b; i++)
#define _FOR(i, a, b) for (int i = a; i >= b; i--)
#define _FORs(i, a, b) for (int i = a; i > b; i--)
using namespace std;
const int maxn = 1e3;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int base = 31;
const int UP = 1e8;
typedef pair<ll, ll> pi;
typedef pair<pi, pi> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<pi> vpi;
typedef vector<vpi> vpii;
int n, x, y, s, top, top1;
int idx, idy;
int dx[5] = { 0, -1, 0, 1 };
int dy[5] = { -1, 0, 1, 0 };
int check[maxn + 5][maxn + 5][5];
char a[maxn + 5][maxn + 5];
pi P[maxn * maxn + 5], D[maxn * maxn + 5];
map<pi, pi> Map;
void init() {
    freopen(Tourist ".inp", "r", stdin);
    freopen(Tourist ".out", "w", stdout);
}
void Time_Decreasing() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void enter() {
    cin >> n >> x >> y >> s;
    FOR(i, 1, n) {
        FOR(j, 1, n) {
            char c;
            cin >> c;
            a[j][i] = c;
        }
    }
}
void solve() {
    if (x < 1 || y < 1 || x > n || (y > n && y - n > s)) {
        cout << x << ' ' << y - s;
        return;
    }
    ll X = x, Y = min(y, n), direction = 0;
    if (y > n) {
        s = s - (y - n);
        if (a[X][Y] == '#') {
            s++;
            y++;
            cout << X + dx[1] * s << ' ' << Y + 1 + dy[1] * s;
            return;
        }
    }
    while (true) {
        if (s == 0) {
            cout << X << ' ' << Y;
            return;
        }
        if (X < 1 || Y < 1 || X > n || Y > n) {
            cout << X + dx[direction] * s << ' ' << Y + dy[direction] * s;
            return;
        }
        //         cout << X << ' ' << Y << ' ' << direction << ' ' << check[X][Y][direction] <<'\n';
        if (check[X][Y][direction])
            break;
        //         cout << X << Y << direction << '\n';
        check[X][Y][direction] = 1;
        P[top] = { X, Y };
        top++;
        FOR(i, direction, direction + 3) {
            int tmpdirection = i % 4;
            ll tmpx = X + dx[tmpdirection];
            ll tmpy = Y + dy[tmpdirection];
            if (a[tmpx][tmpy] != '#') {
                s--;
                direction = tmpdirection;
                Map[{ tmpx, tmpy }] = { X, Y };
                X = tmpx;
                Y = tmpy;
                break;
            }
        }
    }
    s++;
    //    cout << s << '\n';
    top = top - 1;
    int mark = 0;
    FORs(i, 0, top) {
        if (P[i].fi == Map[{ X, Y }].fi && P[i].se == Map[{ X, Y }].se) {
            mark = 1;
        }
        if (mark) {
            D[top1] = { P[i].fi, P[i].se };
            top1++;
        }
    }
    cout << D[s % top1].fi << ' ' << D[s % top1].se;
}
int main() {
    Time_Decreasing();
    enter();
    solve();
}