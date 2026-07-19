#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;
void sortedArray() {
  int arr[] = {9, 3, 8, 7};
  cout << "Unsorted Array = {";
  bool flag = true;
  for (int x : arr) {
    if (!flag)
      cout << ",";
    cout << x;
    flag = false;
  }
  cout << "}" << endl;
  sort(begin(arr), end(arr));
  cout << "Sorted Array = {";
  flag = true;
  for (int x : arr) {
    if (!flag)
      cout << ",";
    cout << x;
    flag = false;
  }
  cout << "}" << endl;
}
int main() { sortedArray(); }
