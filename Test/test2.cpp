#include <iostream>
#include <limits.h>
using namespace std;

int n, k;

// tong cost, best cost(ca^.n), current path, best path
int fk = 0, foptimum = 2147483647;
int x[1003];

int c[1003][1003];

int check[1003];

int minc = 1000001;

// tham khach hang id la phai cho khach toi dich id+n luon de co slot cho khach
// khac do taxi chi co 1 slot
bool visited[1001];

void Try(int id) {
  if (id == n + 1) {
    foptimum = min(foptimum, fk + c[x[id - 1] + n][0]);
  } else {
    if (fk + minc * (2 * n + 2 - (id - 1) * 2 - 1) < foptimum) {
      for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
          x[id] = i;
          if (id == 1)
            fk += (c[x[id - 1]][i] + c[i][i + n]);
          else
            fk += (c[x[id - 1] + n][i] + c[i][i + n]);
          visited[i] = 1;
          Try(id + 1);
          if (id == 1)
            fk -= (c[x[id - 1]][i] + c[i][i + n]);
          else
            fk -= (c[x[id - 1] + n][i] + c[i][i + n]);
          visited[i] = 0;
        }
      }
    }
  }
}

int main() {
  cin >> n;
  long input;

  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= 2 * n; j++) {
      cin >> input;
      c[i][j] = input;
      if (input && input < minc)
        minc = input;
    }
  }

  Try(1);
  cout << foptimum;

  return 0;
}