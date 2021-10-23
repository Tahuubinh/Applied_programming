#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <time.h>

using namespace std;

#define MAX 1000006

long long i;
int n, m, temp;
int a[10005];

void ans() {
  for (int i = 1; i <= m; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> temp;
    a[i] = temp;
    continue;
  }
  if (a[m] != n) {
    ++a[m];
    ans();
  } else {
    long long index = m;
    while (a[index] - a[index - 1] == 1) {
      --index;
    }
    index = index - 1;
    if (!index) {
      cout << -1;
    } 
    if (index){
      ++a[index];
      for (i = index + 1; i <= m; i++) {
        a[i] = a[index] - index + i;
      }
      ans();
    }
  }
  return 0;
}