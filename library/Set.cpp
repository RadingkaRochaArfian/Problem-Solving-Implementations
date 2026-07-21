// set is ordered of unique values
// to do function:
// find_if
// lower_bound
// begin
// rbegin
// rend
// empty
#include <iostream>
#include <set>
using namespace std;
void printSet(set<int> &st) {
  cout << "Current set values: {";
  bool flag = true;
  for (auto x : st) {
    if (!flag)
      cout << ",";
    cout << x;
    flag = false;
  }
  cout << "}" << endl;
}
void fFind(set<int> &st) {
  auto it = st.find(01);
  if (it != st.end()) {
    cout << "Deleting {1} on set..." << endl;
    st.erase(01);
  }
  printSet(st);
}
void fInsert(set<int> st) {
  cout << "Inserting {32} to set..." << endl;
  st.insert(32);
  printSet(st);
}
int main() {
  set<int> st = {80, 77, 01, 99};
  printSet(st);
  fFind(st);
  fInsert(st);
}
