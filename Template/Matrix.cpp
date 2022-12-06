#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1E9 + 7;

int sum(int a, int b) {
  a += b; 
  while (a >= MOD) a -= MOD; while (a < 0) a += MOD;
  return a;
}

void add(int &a, int b) {
  a += b; 
  while (a >= MOD) a -= MOD; while (a < 0) a += MOD;
}

struct Matrix {
  int n, m;
  vector<vector<int> > a;
  Matrix(int n, int m) : n(n), m(m), a(n) {
    for (int i = 0; i < n; i ++ ) a[i].resize(m);
  }
  void init() { // 初始化单位矩阵
    assert(n == m);
    for (int i = 0; i < n; i ++ ) a[i][i] = 1;
  }

  Matrix operator+ (const Matrix& B) const {
    assert(n == B.n && m == B.m);
    Matrix ret(n, m);
    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < m; j ++ ) {
        ret.a[i][j] = sum(a[i][j], B.a[i][j]);
      }
    }
    return ret;
  }

  Matrix operator- (const Matrix& B) const {
    assert(n == B.n && m == B.m);
    Matrix ret(n, m);
    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < m; j ++ ) {
        ret.a[i][j] = sum(a[i][j], -B.a[i][j]);
      }
    }
    return ret;
  }

  Matrix operator* (const Matrix& B) const {
    assert(m == B.n);
    Matrix ret(n, B.m);
    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < B.m; j ++ ) {
        for (int k = 0; k < m; k ++ ) {
          ret.a[i][j] = ((long long)ret.a[i][j] + ((long long)a[i][k] * B.a[k][j]) % MOD) % MOD;
        }
      }
    }
    return ret;
  }

  Matrix operator* (int B) const {
    Matrix ret(n, m);
    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < m; j ++ ) {
        ret.a[i][j] = (long long)a[i][j] * B % MOD;
      }
    }
    return ret;
  }

  Matrix operator^ (int k) const {
    assert(n == m);

    Matrix ret(n, n); ret.init();

    Matrix tmp(n, n);
    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < n; j ++ ) {
        tmp.a[i][j] = a[i][j];
      }
    }

    while (k) {
      if (k & 1) ret = ret * tmp;
      k >>= 1;
      tmp = tmp * tmp;
    }

    return ret;
  }
  
  Matrix& operator= (const Matrix& B) {
    a = B.a;
    n = B.n;
    m = B.m;
  }

  bool operator== (const Matrix& B) const {
    if (n != B.n || m != B.m) return false;

    for (int i = 0; i < n; i ++ ) {
      for (int j = 0; j < m; j ++ ) {
        if (a[i][j] != B.a[i][j]) return false;
      }
    }
    return true;
  }

};
