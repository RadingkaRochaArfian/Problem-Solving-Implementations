#include <iostream>
#include <iterator>
#include <numeric>
using namespace std;
int main() {
  int arrInt[] = {5, 4, 3, 2, 9, 8};
  double arrDouble[] = {3.33, 44, 33, 99.00, 33, 88};
  int lenArrInt = size(arrInt);
  int lenArrDouble = size(arrDouble);
  int sumInt = accumulate(arrInt, arrInt + lenArrInt, 0);
  double sumDouble = accumulate(arrDouble, arrDouble + lenArrDouble, 0.0);
  cout << "Sum int: " << sumInt << endl;
  cout << "Sum double: " << sumDouble << endl;
}
