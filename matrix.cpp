#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct matrix {
  vector<vector<T>> m;

  // constructor
  matrix():m(vector<vector<T>>()){}
  matrix(int r,int c):m(vector<vector<T>>(r,vector<T>(c))){}
  matrix(int r,int c, T d):m(vector<vector<T>>(r,vector<T>(c,d))){}
  // index
  vector<T> operator[](const int i) const {return m[i];} //読み取り
  vector<T>& operator[](const int i){return m[i];} //書き込み

  // row, columns
  int nrow = (int)(m.size());
  int ncol = (int)(m[0].size());
  vector<T> row(int i) {return m[i];}
  vector<T> col(int j) {
    vector<T> c(ncol);
    for (int i = 0; i < ncol; i++) {
      c[i] = m[i][j];
    }
    return c;
  }

  matrix& operator=(const matrix& a) {return *a;}
  matrix& operator+=(const matrix& a) {
    assert(ncol == a.ncol && nrow == a.nrow);
    for (int i = 0; i < nrow; i++) {
      for (int j = 0; j < ncol; j++) {
        m[i][j] += a[i][j];
      }
    }
    return *this;
  }
  matrix& operator-=(const matrix& a) {
    assert(ncol == a.ncol && nrow == a.nrow);
    for (int i = 0; i < nrow; i++) {
      for (int j = 0; j < ncol; j++) {
        m[i][j] -= a[i][j];
      }
    }
    return *this;
  }
  matrix& operator*=(const matrix& a) {
    assert(ncol == a.nrow);
    matrix<T> m2(nrow, a.ncol, 0);
    for (int i = 0; i < nrow; i++) {
      for (int k = 0; k < a.ncol; k++) {
        for (int j = 0; j < ncol; j++) {
          m2[i][k] += m[i][j] * a[j][k];
        }
      }
    }
    for (int i = 0; i < nrow; i++) {
      m[i].resize(a.ncol, 0);
      for (int k = 0; k < a.ncol; k++) {
        m[i][k] = m2[i][k];
      }
      ncol = a.ncol;
    }
    return *this;
  }
  matrix operator+(const matrix& a) const {return matrix(*this) += a;}
  matrix operator-(const matrix& a) const {return matrix(*this) -= a;}
  matrix operator*(const matrix& a) const {return matrix(*this) *= a;}
  // scalar
  matrix& operator*=(const T& a) {
    for (int i = 0; i < nrow; i++) {
      for (int j = 0; j < ncol; j++) {
        m[i][j] *= a;
      }
    }
    return *this;
  }
  matrix operator*(const T& a) const {return matrix(*this) *= a;}
  // compare
  bool operator==(const matrix& a) {
    assert(ncol == a.ncol && nrow == a.nrow);
    bool flg = true;
    for (int i = 0; i < nrow; i++) {
      if (m[i] != a[i]) flg = false;
    }
    return flg;
  }
  bool operator!=(const matrix& a) {return !(matrix(*this) == a);}

  void print() {
    for (int i = 0; i < nrow; i++) {
      for (int j = 0; j < ncol; j++) {
        if(j != 0) cout << " ";
        cout << m[i][j];
        if(j == ncol-1) cout << endl;
      }
    }
    return;
  }
};


int main() {
  double nrow, ncol, n2row, n2col;
  cin >> nrow >> ncol;
  cin >> n2row >> n2col;
  matrix<double> m1(nrow, ncol);
  matrix<double> m2(n2row, n2col);
  for (int i = 0; i < nrow; i++) {
    for (int j = 0; j < ncol; j++) {
      cin >> m1[i][j];
    }
  }
  for (int i = 0; i < n2row; i++) {
    for (int j = 0; j < n2col; j++) {
      cin >> m2[i][j];
    }
  }
  matrix<double> m = m1 * m2;
  m.print();
  assert(m1 == m1);
  assert(m1 != m1 * 2);
}
