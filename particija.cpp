#include <bits/stdc++.h>

using namespace std;
const int loga = 20;
const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;

int n, k;
int niz[maxn];
int pref[maxn];
int rmq[loga + 10][maxn];

int query(int x, int y) {
    bool flag = x < 0;
    x = max(0, x);
    int kol = y - x + 1;

    int sol = 0x3f3f3f3f;
    if (flag) sol = 0;
    for (int i = 0; i <= loga; i++)
        if (kol & (1 << i)) sol = min(sol, rmq[i][x]), x += (1 << i);
    return sol;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", niz+i);

    if (k == 1) {
        int sol = 0;
        for (int i = 0; i < n; i++)
            sol += niz[i];
        printf("%d", sol);
        return 0;
    }

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + niz[i], rmq[0][i] = pref[i + 1];

    if (k == 2) {
        int sol = -inf;
        for (int i = 0; i < n - 1; i++)
            sol = max({sol, pref[i + 1], pref[n] - pref[i + 1]});
        printf("%d\n", sol);
        return 0;
    }

    for (int i = 1; i <= loga; i++)
        for (int j = 0; j < n; j++)
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);

    int sol = -0x3f3f3f3f, maxi = n - k + 1;
    for (int i = 0; i < n; i++)
        sol = max(sol, pref[i + 1] - query(i - maxi, i - 1));

    printf("%d", sol);
    return 0;
}
