#include <bits/stdc++.h>

using namespace std;
const int maxn = 50010;

int n;
pair<int, int> niz[maxn];
vector< pair<int, int> > sol;

void rek(int l, int r) {
    //printf("debug: %d %d\n", l, r);
    if (r - l <= 0) return;
    int mid = (l + r) / 2;

    set<int> s;
    for (int i = l; i <= r; i++)
        if (niz[i].first != niz[mid].first) s.insert(niz[i].second);

    for (auto iter = s.begin(); iter != s.end(); iter++)
        sol.push_back(make_pair(niz[mid].first, *iter));

    int i;
    for (i = mid; i >= l; i--)
        if (niz[i].first != niz[mid].first) break;
    rek(l, i);

    for (i = mid; i <= r; i++)
        if (niz[i].first != niz[mid].first) break;
    rek(i, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &niz[i].first, &niz[i].second);
    sort(niz, niz+n);
    rek(0, n - 1);
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d\n", sol[i].first, sol[i].second);
    return 0;
}
