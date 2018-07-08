#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;
const int lg = 30;

int n, m, k;
int niz[maxn];
int lca[lg + 10][maxn];

int main() {
    scanf("%d%d%d", &n, &k, &m); m--;
    for (int i = 0; i < n; i++)
        scanf("%d", niz+i);

    for (int i = 0; i < k; i++)
        scanf("%d", &lca[0][i + 1]);

    for (int i = 1; i < lg; i++)
        for (int j = 1; j <= k; j++)
            lca[i][j] = lca[i - 1][lca[i - 1][j]];

    for (int i = 0; i < n; i++) {
        int gdje = niz[i];
        for (int j = 0; j <= lg; j++)
            if (m & (1 << j)) gdje = lca[j][gdje];
        printf("%d ", gdje);
    }
    return 0;
}
