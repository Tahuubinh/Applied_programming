#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define pii pair<int, int>
using ll = long long;
using ull = unsigned long long;
int t;

int n, k;
int a[101];
int cnteq[101];

// int findMinRec(int i, int sumCalculated,
//                int sumTotal)
// {
//     // If we have reached last element.  Sum of one
//     // subset is sumCalculated, sum of other subset is
//     // sumTotal-sumCalculated.  Return absolute difference
//     // of two sums.
//     if (i == 0)
//         return abs((sumTotal - sumCalculated)
//                    - sumCalculated);
 
//     // For every item arr[i], we have two choices
//     // (1) We do not include it first set
//     // (2) We include it in first set
//     // We return minimum of two choices
//     return min(
//         findMinRec(i - 1, sumCalculated + cnteq[i],
//                    sumTotal),
//         findMinRec(i - 1, sumCalculated, sumTotal));
// }

int findMin(int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += cnteq[i];
 
    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];
 
    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
 
    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];
 
            // If i'th element is included
            if (cnteq[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - cnteq[i - 1]];
        }
    }
 
    // Initialize difference of two sums.
    int diff = INT_MAX;
 
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--){
        memset(cnteq, 0, sizeof cnteq);
        cin >> n >> k;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int ans = 0;
        int start = n + 1 - k - k;
        for (int i = 1; i < start; ++i){
            ans += a[i];
        }
        int cnt = 0;
        // if (start <= 0){
        //     ++start;
        // }
        a[start - 1] = a[start];
        for (int i = start; i <= n; ++i){
            if (a[i] != a[i - 1]){
                ++cnt;
                // cnteq[cnt].first = 0;
                // cnteq[cnt].second = a[i];
            }
            ++cnteq[cnt];
        }
    //     for (int i = cnt - 1; i > start; --i){
    //         cnteq[i] = abs(cnteq[i] - cnteq[i + 1]);
    //     }
    //     if (cnteq[start] >= cnteq[start + 1]){
    //         ans += (cnteq[start] - cnteq[start + 1]) / 2 +
    //                 (cnteq[start] - cnteq[start + 1]) % 2 * a[start];
    //     } else {
    //         if ((cnteq[start] + cnteq[start - 1]) & 1){
    //             ans += a[start] + (cnteq[start + 1] - cnteq[start])/2;
    //         }
    //         else {
    //             ans += (cnteq[start + 1] - cnteq[start])/2;
    //         }
    //     }
    //     cout << ans << endl;
        int totalsum = 0;
        // for (int i = 1; i<=cnt; ++i){
        //     totalsum += cnteq[i];
        // }
        totalsum = accumulate(cnteq, cnteq + cnt, totalsum);
        // cout << "totalsum: " << totalsum;
        // cout << "cnt: " << cnt << endl;
        // cout << "ans: " << ans << endl;
        ans += findMin(cnt + 1) / 2;
        cout << ans << endl;
    }
    

    
    return 0;
}
