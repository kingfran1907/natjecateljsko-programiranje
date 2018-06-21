#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;

int n, m;
bitset<maxn> niz[maxn];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        niz[a][b] = 1;
    }

    long long sol = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            bitset<maxn> tren = niz[i] & niz[j];
            long long ac = tren.count();
            sol += (long long)(ac * (ac - 1)) / 2;
        }
    }
    printf("%lld", sol);
    return 0;
}
