#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_n 100
#define MAX_A 10000

const int INF = 1<<29;
int n, A, a[MAX_n], dp[MAX_n][MAX_A];

int main(){
    scanf("%d", &n);
    scanf("%d", &A);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        cout << i << " = " << a[i] << endl;
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= A; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j >= a[i]) dp[i+1][j] = min(dp[i+1][j], dp[i][j-a[i]]+1);
        }
    }
    if(dp[n][A] < INF) cout << dp[n][A] << endl;
    else cout << -1 << endl;
    return 0;
}