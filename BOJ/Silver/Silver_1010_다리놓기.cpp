#include <iostream>
#include <vector>
using namespace std;

int memo[30][30] = { 0, };  // 메모이제이션

int combination(int n, int r)
{
    if (memo[n][r]) return memo[n][r];
    if (r == 0 || n == r) return 1;
    else {
        memo[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
        return memo[n][r];
    }
}

int main(void)
{
    int n;
    vector<pair<int, int>> v;

    cin >> n;
    for (auto i = 0; i < n; i++) {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        v.push_back(temp);
    }

    for (auto i : v) {
        cout << combination(i.second, i.first) << endl;
    }
    return 0;
}