#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
void accumulateVector() {
  vector<int> vInt;
  for (int i = 1; i < 10; i += 2) {
    vInt.push_back(i);
  }
  cout << "Sum of {";
  for (int i = 0; i < vInt.size(); i++) {
    cout << vInt[i];
    if (i < vInt.size() - 1) {
      cout << ",";
    }
  }
  int sum = accumulate(vInt.begin(), vInt.end(), 0);
  cout << "} = " << sum << endl;
}
int main() { accumulateVector(); }
