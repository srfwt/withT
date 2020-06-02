#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
#define MAX_C 20
#define MAX_K 20
#define MAX_M 200

int N, M, C, K, res;
int price[MAX_C][MAX_K];
int dp[MAX_M+1][MAX_K];

int shop(int m, int g){
    if(m > M) return -1;
    if(g == C) return m;
    if(dp[m][g] != -1) return dp[m][g];
    int i=0, tmp=-1;

    while(price[g][i] != 0){
        tmp = max(tmp, shop(m+price[g][i], g+1));
        i++;
    }
    return dp[m][g] = tmp;
}

int main(){
    scanf("%d", &N);
    while(N--){
        memset(price, 0, sizeof(price));
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &M, &C);
        for(int i = 0; i < C; i++){
            scanf("%d", &K);
            for(int j = 0; j < K; j++) scanf("%d", &price[i][j]);
        }

        if(shop(0 ,0) != -1) cout << dp[0][0] << endl;
        else cout << "no solution" << endl;
    }
    return 0;
}