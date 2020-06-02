#include <iostream>
using namespace std;
#define MAX_P 1000
int t;

int main(){
    scanf("%d", &t);
    while(t--){
        int W, p, p_n;
        scanf("%d", &W);
        scanf("%d", &p_n);
        int dp[MAX_P+1]={};
        dp[0] = 1;
        for(int i = 0; i < p_n; i++){
            scanf("%d", &p);
            for(int j = W-p; j >= 0; j--){
                if(dp[j] && !dp[j+p]) dp[j+p] = 1;
            }
        }
        if(dp[W] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}