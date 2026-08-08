#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    double x;
    scanf("%lf\n", &x);
    cout << 1 / x << endl;
  }
}
