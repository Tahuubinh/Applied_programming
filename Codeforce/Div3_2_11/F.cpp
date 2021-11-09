#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, m;
int msum, mmin, mmax, nsum, nmin, nmax;
string s;

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> s;
        msum = mmin = mmax = 0;
        nsum = nmin = nmax = 0;
        int len = s.size();
        int i = 0;
        while (i < len){
            switch(s[i]){
                case 'L':
                    --msum;
                    if (msum < mmin){
                        if (mmax - msum >= m){
                            goto label;
                        }
                        mmin = msum;
                    }
                    ++i;
                    break;
                case 'R':
                    ++msum;
                    if (msum > mmax){
                        if (msum - mmin >= m){
                            goto label;
                        }
                        mmax = msum;
                    }
                    ++i;
                    break;
            }

            switch(s[i]){
                case 'U':
                    --nsum;
                    if (nsum < nmin){
                        if (nmax - nsum >= n){
                            goto label;
                        }
                        nmin = nsum;
                    }
                    ++i;
                    break;
                case 'D':
                    ++nsum;
                    if (nsum > nmax){
                        if (nsum - nmin >= n){
                            goto label;
                        }
                        nmax = nsum;
                    }
                    ++i;
                    break;
            }
        }
        label:
            cout << 1 - nmin << ' ' << 1 - mmin << endl;
    }

    
    return 0;
}
