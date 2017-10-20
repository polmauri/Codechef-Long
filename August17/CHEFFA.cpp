// https://www.codechef.com/AUG17/problems/CHEFFA
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int current;
int dp[51][200][200];
int dpc[51][200][200];

int fun(int i, int d0, int d1, const vector<int>& a) {
  int& res = dp[i][100 + d0][100 + d1];
  int& cas = dpc[i][100 + d0][100 + d1];
  if (cas == current) {
    return res;
  }
  cas = current;
  int n = a.size();
  int x0 = (i < n ? a[i] : 0) + d0;
  int x1 = (i + 1 < n ? a[i + 1] : 0) + d1;
  if (i == n && x0 == 0 && x1 == 0) {
    return res = 1;
  }
  res = 0;
  for (int d = 0; d <= x0 && d <= x1; ++d) {
    res += fun(min(n, i + 1), d1 - d, d, a);
    res %= MOD;
  }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    ++current;
    cout << fun(0, 0, 0, a) << endl;
  }
}
