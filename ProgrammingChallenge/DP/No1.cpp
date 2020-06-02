#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 10000

int N, a[MAX_N], dp[MAX_N+1];
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        dp[i+1] = max(dp[i], dp[i] + a[i]);
    }

    cout << dp[N] << endl;
    return 0;
}