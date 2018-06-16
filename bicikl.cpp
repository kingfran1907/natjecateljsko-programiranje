#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;

int n, k;
vector<int> graph1[maxn], graph2[maxn];
bool bio1[maxn], bio2[maxn];

void dfs1(int pos) {
    bio1[pos] = true;
    for (int i = 0; i < graph1[pos].size(); i++) {
        int tren = graph1[pos][i];
        if (!bio1[tren]) dfs1(tren);
    }
}

void dfs2(int pos) {
    bio2[pos] = true;
    for (int i = 0; i < graph2[pos].size(); i++) {
        int tren = graph2[pos][i];
        if (!bio2[tren]) dfs2(tren);
    }
}

int main() {
    memset(bio1, false, sizeof bio1);
    memset(bio2, false, sizeof bio2);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);

        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }

    dfs1(1);
    dfs2(1);
    int sol = 0;
    for (int i = 1; i <= n; i++)
        if (bio1[i] && bio2[i]) sol++;
    printf("%d", sol);
    return 0;
}
