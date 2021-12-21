#include <bits/stdc++.h>
#define endtheline '\n'
using namespace std;

using abc = int;

const int N = 17, MAX_M = 6;
int n, m;
int ca[N];
int A[N][N];
int x[N];
int best = 1e9;
int load[MAX_M];
int temp1, temp2;

void init() {
    int temp = 0;
  for (int i = 0; i < MAX_M; i++) {
    load[i] = temp;
  }
}

void input() {
  cin >> temp1 >> temp2;
  n = temp1;
  m = temp2;
  for (int i = 0; i < n; i++) {
    cin >> ca[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
}

bool check(int k, int i) {
  // course k - period i
  for (int j = 0; j < k; j++) {
    if (A[k][j] == 1) {
      if (x[j] >= i)
        return 0;
    }
  }
  return 1;
}

void solve() {
  int cur_best = 0;
  for (int i = 0; i < m; i++) {
    // cout << "load " << i << " : " << load[i] << endl;
    if (cur_best < load[i])
      cur_best = load[i];
    // cout << "curBest: " << cur_best << endl;
  }
  if (cur_best < best)
    best = cur_best;
  // cout << best << endl;
  // for (int i = 0; i < n; i++) {
  //     cout << "Course " << i << " assigned to period " << x[i] << endl;
  // }
}

void TRY(int k) {
  for (int i = 0; i < m; i++) {
    if (check(k, i)) {
      x[k] = i;
      load[i] = ca[k] + load[i];
      if (k == n - 1) {
        solve();
      } else {
        TRY(k + 1);
      }
      load[i] -= ca[k]; 
    }
  }
}

int main() {
  init();
  input();
  TRY(0);
  cout << best;
  return 0;
}