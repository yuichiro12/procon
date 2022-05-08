#include <bits/stdc++.h>
using namespace std;

bool is_splittable_into_weighted_pieces(vector<int> &A, int L, int pieces, int weight) {
  int current = 0;
  int prev_end = 0;
  for (int p = 0; p < pieces; p++) {
    for (int i = current; i < A.size(); i++) {
      if (L - A.at(i) < weight) {
        return false;
      } else if (A.at(i) - prev_end >= weight) {
        if (p == pieces - 1) {
          return L - A.at(i) >= weight;
        }
        current =  i + 1;
        prev_end = A.at(i);
        break;
      }
    }
  }
  return false;
}

int binary_search(vector<int> &A, int L, int K) {
  int left = -1;
  int right = L + 1;
  while (right - left > 1) {
    int mid = left + (right - left)/2;
    if (is_splittable_into_weighted_pieces(A, L, K, mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

int main() {
  int N, L;
  int K;
  cin >> N >> L >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  cout << binary_search(A, L, K) << endl;
}
