#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_n 100
#define MAX_M 10000
#define small -100000


int m, n, p[MAX_n], f[MAX_n], dp[MAX_n+1][MAX_M+1];

int solve(int i, int j){
    if(j > m && m < 1800) return small;
    if(j > m + 200) return small;
    if(i == n){
        if(j > m && j <= 2000) return small;
        else return 0;                
    }
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(solve(i+1, j), solve(i+1, j + p[i]) + f[i]);
}

int main(){
    while(cin >> m >> n){
        for(int i = 0; i < n; i++) scanf("%d %d", &p[i], &f[i]);
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << endl;
    }
}