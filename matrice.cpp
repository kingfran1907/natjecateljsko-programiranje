#include <bits/stdc++.h>

using namespace std;
const int maxn = 410;
const int inf = 0x3f3f3f3f;

int n;
int niz[maxn][maxn];
int sol[maxn][maxn];
int pref[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &niz[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pref[i][j + 1] = pref[i][j] + niz[i][j], sol[i][j] = -inf;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tren = 0, mini = 0, best = -inf;
            for (int k = 0; k < n; k++) {
                tren += pref[k][j + 1] - pref[k][i];
                best = max(best, tren - mini);
                sol[k + 1][j + 1] = max(best, sol[k + 1][j + 1]);
                //if (i == 0 && j == 1) printf("%d\n", best);
                mini = min(mini, tren);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sol[i][j] = max({sol[i][j], sol[i][j - 1], sol[i - 1][j]});

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", sol[i + 1][j + 1]);
        printf("\n");
    }
    return 0;
}
