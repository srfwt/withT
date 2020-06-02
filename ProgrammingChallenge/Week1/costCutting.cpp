#include <iostream>
using namespace std;

int middle(int fir, int sec, int thi){
    if((fir >= sec && fir <= thi) || (fir <= sec && fir >= thi)){
        return fir;
    } else if((sec >= fir && sec <= thi) || (sec <= fir && sec >= thi)){
        return sec;
    } else {
        return thi;
    }

}
int main(){
    int n = 1;
    scanf("%d", &n);
    int dp[n][3], ans[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &dp[i][0]);
        scanf("%d", &dp[i][1]);
        scanf("%d", &dp[i][2]);
        ans[i] = middle(dp[i][0], dp[i][1], dp[i][2]);
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }
    return 0;
}