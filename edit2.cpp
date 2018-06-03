#include <bits/stdc++.h>

using namespace std;

string a;
int dp[310][310];

int dis(int b) {
    for (int i = 0; i <= b; i++) {
        for (int j = b; j <= a.size(); j++) {
            int ac = j - b;
            if (min(i, ac) == 0) dp[i][ac] = max(i, ac);
            else if (a[i - 1] == a[j - 1]) dp[i][ac] = dp[i - 1][ac - 1];
            else dp[i][ac] = min({dp[i - 1][ac] + 1, dp[i][ac - 1] + 1});
        }
    }
    return dp[b][a.size() - b];
}

int main() {
    cin >> a;

    int sol = a.size();
    for (int i = 1; i < a.size(); i++)
        sol = min(sol, dis(i));

    //for (int i = 1; i < a.size(); i++) printf("%d -> %d\n", i, dis(i));
    printf("%d", sol);
    return 0;
}
