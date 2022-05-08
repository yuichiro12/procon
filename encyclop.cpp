#include <bits/stdc++.h>
using namespace std;

void add_or_print(string str, int left, int right) {
  if (right == 0) {
    cout << str << endl;
  } else if (left > 0) {
    add_or_print(str + "(", left - 1, right);
    if (left < right) {
      add_or_print(str + ")", left, right - 1);
    }
  } else {
    add_or_print(str + ")", left, right - 1);
  }
}

int main() {
  int N;
  cin >> N;

  if (N % 2 == 0) {
    add_or_print("", N/2, N/2);
  }
}
