#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;

int n, m;
int pc[20][20];
int bio[1 << 17];
set< pair<int, int> > s;

int flip(int x, int index) {
    return x ^ (1 << index);
}

int main() {
    memset(pc, inf, sizeof pc);
    memset(bio, inf, sizeof bio);
    scanf("%d%d", &n, &m);

    int tren = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        sum += c;
        pc[a - 1][b - 1] = min(c, pc[a - 1][b - 1]), pc[b - 1][a - 1] = min(c, pc[b - 1][a - 1]);
        tren = flip(tren, a - 1), tren = flip(tren, b - 1);
    }

    s.insert(make_pair(sum, tren));
    bio[tren] = sum;
    //printf("%d\n", sum);
    while (!s.empty()) {
        int dis = s.begin()->first;
        int node = s.begin()->second;
        s.erase(s.begin());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || pc[i][j] == inf) continue;
                int tren = node;
                tren = flip(tren, i), tren = flip(tren, j);
                if (bio[tren] > dis + pc[i][j]) {
                    s.erase(make_pair(bio[tren], tren));
                    bio[tren] = dis + pc[i][j];
                    s.insert(make_pair(bio[tren], tren));
                }
            }
        }
    }

    printf("%d", bio[0]);
    return 0;
}
