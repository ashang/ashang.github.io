#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  long b, c, d = 0, e = 0, f = 100, i = 0, j, N;
  cout << "Please input the needed digits for Golden Ratio:\n";
  cin >> N;
  N = N * 3 / 2 + 6;
  long* a = new long[N + 1];
  while (i <= N) a[i++] = 1;
  for (; --i > 0;
       i == N - 6 ? printf("\r0.61") : printf("%02ld", e += (d += b / f) / f),
       e = d % f, d = b % f, i -= 2)
    for (j = i, b = 0; j; b = b / c * (j-- * 2 - 1))
      a[j] = (b += a[j] * f) % (c = j * 10);
  delete[] a;
  cin.ignore();
  cin.ignore();
  return 0;
}
