#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_n 100
#define MAX_A 10000

int n, a[MAX_n], A;
bool dp[MAX_n][MAX_A];

int main(){
    scanf("%d", &n);
    scanf("%d" ,&A);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        cout << i << " = " << a[i] << endl;
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= A; j++){
            if(j >= a[i]) dp[i+1][j] = dp[i][j] || dp[i][j-a[i]];
            else dp[i+1][j] = dp[i][j];
        }
    }

    if(dp[n][A]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}