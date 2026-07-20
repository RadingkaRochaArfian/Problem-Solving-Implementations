#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
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
  sort(begin(arr), end(arr)); // implementation
  cout << "Sorted Array = {";
  flag = true;
  for (int x : arr) {
    if (!flag)
      cout << ",";
    cout << x;
    flag = false;
  }
  cout << "}" << endl << endl;
}
void sortedVector() {
  vector<int> v = {8, 7, 9, 10, 7, 11};
  cout << "Unsorted Vector = {";
  bool flag = true;
  for (const auto &x : v) {
    if (!flag)
      cout << ",";
    cout << x;
    flag = false;
  }
  cout << "}" << endl;
  sort(v.begin(), v.end()); // implementation
  cout << "Sorted Vector = {";
  flag = true;
  for (const auto &x : v) {
    if (!flag)
      cout << ",";
    cout << x;
    flag = false;
  }
  cout << "}" << endl << endl;
}
int main() {
  sortedArray();
  sortedVector();
}
