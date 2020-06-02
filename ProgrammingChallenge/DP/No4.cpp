#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_n 100
#define MAX_A 10000

const int MOD = 1000000009;

int n, a[MAX_n], A, dp[MAX_n+1][MAX_A+1];
int main(){
    scanf("%d", &n);
    scanf("%A", &A);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= A; j++){
            (dp[i+1][j] += dp[i][j]) %= MOD;
            if(j >= a[i]) (dp[i+1][j] += dp[i][j-a[i]]) %= MOD;
        }
    }
    cout << dp[n][A] << endl;
    return 0;
}