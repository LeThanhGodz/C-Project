#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define loop(i, a) for (auto &i : a)

using namespace std;

typedef long int int32;
typedef long long int64;

struct node {
    int32 x, y;
    node(int32 x, int32 y) : x(x), y(y) {}
    node() {}
    bool operator<(node A) {
        if (this->x == A.x)
            return this->y < A.y;
        return this->x < A.x;
    }
};

struct square {
    int32 x, y, u, v;
    square() {}
    square(int32 x, int32 y, int32 u, int32 v) : x(x), y(y), u(u), v(v) {}
};

int32 n, k, r, p;
vector<square> sq;
int64 grid[550][550], S[550][550];
vector<node> bonus[101010];

int64 getS(int32 x, int32 y, int32 u, int32 v) {
    if (x > u || y > v)
        return 0LL;
    return S[u][v] - S[u][y - 1] - S[x - 1][v] + S[x - 1][y - 1];
}

void subtask1() {
    bool check[55][55];
    int64 ans = -1e17;
    rep(i, 1, k) {
        int64 tmp = 0;
        memset(check, false, sizeof check);
        loop(it, bonus[i]) {
            rep(x, it.x, it.x + r - 1) {
                rep(y, it.y, it.y + r - 1) if (!check[x][y]) {
                    tmp += grid[x][y];
                    check[x][y] = true;
                }
            }
        }
        ans = max(tmp, ans);
    }
    printf("%lld", ans);
}

square smallSquare(square x, square y) {
    square res;
    res.x = max(x.x, y.x);
    res.y = max(x.y, y.y);
    res.u = min(x.u, y.u);
    res.v = min(x.v, y.v);
    return res;
}

// Ham tinh phan giao nhau cua cac hinh trong cont
int64 getArea(vector<square> cont) {
    square res = cont[0];
    rep(i, 1, cont.size() - 1) res = smallSquare(res, cont[i]);
    return getS(res.x, res.y, res.u, res.v);
}

int64 calS() {
    int64 res = 0;
    vector<square> cont;
    // Lan luot tinh area cua 1 o, 2 o giao nhau, 3 ..., 4...
    rep(k, 1, (1 << p) - 1) {
        // Tinh area cac hv duoc chon
        cont.clear();
        rep(i, 0, p - 1) if (k >> i & 1) cont.push_back(sq[i + 1]);
        int64 tmp = getArea(cont);
        int biton = __builtin_popcount(k);
        if (biton & 1)
            res += tmp;
        else
            res -= tmp;
    }
    return res;
}

void subtask2() {
    int64 ans = -1e17;
    rep(i, 1, k) sort(bonus[i].begin(), bonus[i].end());
    rep(i, 1, k) {
        int32 x, y, u, v;
        x = bonus[i][0].x, y = bonus[i][0].y;
        u = bonus[i][1].x, v = bonus[i][1].y;
        int64 tmp = getS(x, y, x + r - 1, y + r - 1) + getS(u, v, u + r - 1, v + r - 1);
        // cout << tmp << " | ";
        if (x + r - 1 >= u) {
            if (y <= v && v <= y + r - 1) {
                // cout << "DEG";
                if (u + r - 1 <= x && v + r - 1 <= y + r - 1) {
                    tmp -= getS(u, v, u + r - 1, v + r - 1);
                } else if (u + r - 1 > x && v + r - 1 > y + r - 1) {
                    tmp -= getS(u, v, (x + r - 1) - u, (y + r - 1) - v);
                } else if (u + r - 1 > x) {
                    tmp -= getS(u, v, (x + r - 1) - u, v + r - 1);
                } else
                    tmp -= getS(u, v, u + r - 1, (y + r - 1) - v);
            } else if (v <= y && v + r - 1 >= y) {
                // cout << "DEG2";
                if (u + r - 1 >= x + r - 1) {
                    tmp -= getS(u, y, x + r - 1, v + r - 1);
                } else
                    tmp -= getS(u, y, u + r - 1, v + r - 1);
            }
        }
        // cout << tmp << endl;
        ans = max(ans, tmp);
    }
    printf("%lld", ans);
}

void fulltask() {
    sq.assign(p + 3, square());
    int64 ans = 0;
    rep(i, 1, k) {
        int j = 1;
        loop(it, bonus[i]) sq[j] = square(it.x, it.y, it.x + r - 1, it.y + r - 1), j++;
        ans = max(ans, calS());
    }
    printf("%lld", ans);
}

int main() {
    // freopen("input.INP", "r", stdin);
    // freopen("BONUS.INP", "r", stdin);
    // freopen("BONUS.OUT", "w", stdout);
    scanf("%ld %ld %ld %ld", &n, &k, &r, &p);
    rep(i, 1, n) rep(j, 1, n) scanf("%lld", &grid[i][j]);
    rep(i, 1, k) {
        rep(j, 1, p) {
            int32 x, y;
            scanf("%ld %ld", &x, &y);
            bonus[i].push_back(node(x, y));
        }
    }
    // Init
    memset(S, 0, sizeof S);
    rep(i, 1, n) { rep(j, 1, n) S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + grid[i][j]; }
    // Solve
    if (n <= 50 && k <= 50)
        subtask1();
    else
        fulltask();
    return 0;
}