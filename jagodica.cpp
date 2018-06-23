#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;

int n, x, y;
pair<int, int> niz[maxn];
int loga[maxn], dp[maxn];
vector<int> saz;

void update(int x, int val) {
    for (x++; x < maxn; x += x & -x)
        loga[x] = max(loga[x], val);
}

int query(int x) {
    int sol = 0;
    for (x++; x > 0; x -= x & -x)
        sol = max(sol, loga[x]);
    return sol;
}

int main() {
    scanf("%d%d%d", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        niz[i] = make_pair(a, b);
    }
    niz[n] = make_pair(x, y), n++;
    sort(niz, niz+n);

    for (int i = 0; i < n; i++)
        saz.push_back(niz[i].second);
    sort(saz.begin(), saz.end());
    for (int i = 0; i < n; i++)
        niz[i].second = lower_bound(saz.begin(), saz.end(), niz[i].second) - saz.begin();
    y = lower_bound(saz.begin(), saz.end(), y) - saz.begin();

    for (int i = 0; i < n; i++) {
        dp[i] = query(niz[i].second) + 1;
        update(niz[i].second, dp[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (niz[i].first == x && niz[i].second == y) {
            printf("%d", dp[i] - 1);
            break;
        }
    }
    return 0;
}
