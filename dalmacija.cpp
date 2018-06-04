#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5+10;

struct {
    int mx[maxn], cnt;
    void update(int x) {
        for (x = max(0, x), x++; x < maxn; x += x & -x)
            mx[x]++;
    }

    int query(int x) {
        if (x == -1) return 0;
        int sol = 0;
        for (x++; x > 0; x -= x & -x)
            sol += mx[x];
        return sol;
    }
} loga1, loga2;

int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        loga1.update(a + b);
        loga2.update(a - b);
    }

    int sol = 0;
    for (int i = 0; i < maxn - 10; i++) {
        int ac = n - loga1.query(i - 1) - (n - loga2.query(i));
        sol = max(sol, ac);
        //printf("%d %d\n", i, ac);
    }
    printf("%d", sol);
    return 0;
}
