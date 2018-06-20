#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> niz[300010];

int bio[100010];

bool bfs(vector< vector<int> > &node, int tren) {
    queue<int> q;
    bio[tren] = 0;
    q.push(tren);

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int i = 0; i < node[a].size(); i++) {
            const int c = node[a][i];
            if (bio[c] == -1) {
                bio[c] = !(bool)bio[a];
                q.push(c);
            } else if (bio[c] == bio[a]) return false;
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d", &niz[i].first, &niz[i].second);

    int lo = 1;
    int hi = m;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        //printf("%d %d -> %d\n", lo, hi, mid);
        memset(bio, -1, sizeof bio);
        vector< vector<int> > node(100010);

        for (int i = 0; i < mid; i++) {
            const int tx = niz[i].first, ty = niz[i].second;
            node[tx].push_back(ty);
            node[ty].push_back(tx);
        }

        bool valid = true;
        for (int i = 0; i < n; i++) if (bio[i] == -1 && !node[i].empty()) {
            if (!bfs(node, i)) {
                valid = false;
                break;
            }
        }

        if (valid) lo = mid+1;
        else hi = mid;
    }
    printf("%d", lo);
    return 0;
}
