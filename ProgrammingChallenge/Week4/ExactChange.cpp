#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_n 100
#define MAX_price 10000

const int INF = 1 << 29;
int T, N, n, t, total, ans;

int coins[MAX_n], dp[MAX_price + 1];

int main(){
    scanf("%d", &T);
    while(T--){
        memset(coins, 0, sizeof(coins));
        memset(dp, 0, sizeof(dp));
        scanf("%d", &N);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &coins[i]);
        }
       
       dp[0] = 1, total = 0;
       for(int i = 0; i < n; i++){
           total += coins[i];
           if(total > MAX_price) total = MAX_price-1;
           for(int j = total; j >= coins[i]; j--){
               if(dp[j] == 0 || dp[j] > dp[j-coins[i]] + 1){
                   if(dp[j-coins[i]]){
                       dp[j] = dp[j-coins[i]] + 1;
                   }
               }
           }
       }
       while(dp[N] == 0) N++;
       cout << N << " " << dp[N]-1 << endl;
    }
    return 0;
}