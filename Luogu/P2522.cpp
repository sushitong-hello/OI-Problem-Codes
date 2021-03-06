/**************************************************************
 * Problem: Luogu P2522
 * Author: Rqy
 * Date: 2017 Dec 23
 * Algorithm: 莫比乌斯反演
**************************************************************/
#include <algorithm>
#include <cstdio>
typedef long long LL;
const int N = 50050;
int mu[N];
int n, a, b, c, d, k;
LL solve(int a, int b) {
  a /= k;
  b /= k;
  LL ans = 0;
  for (int i = 1, last; i <= a && i <= b; i = last + 1) {
    last = std::min(a / (a / i), b / (b / i));
    ans += (LL)(a / i) * (b / i) * (mu[last] - mu[i - 1]);
  }
  return ans;
}
int main() {
  mu[1] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = i * 2; j < N; j += i)
      mu[j] -= mu[i];
  for (int i = 2; i < N; ++i) mu[i] += mu[i - 1];
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    printf("%lld\n", solve(b, d) - solve(a - 1, d) - solve(b, c - 1) + solve(a - 1, c - 1));
  }
  return 0;
}
