#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_n 100
#define MAX_W 10000

int n, W, weight[MAX_n], value[MAX_n], dp[MAX_n+1][MAX_W+1]; 


int main(){
    scanf("%d", &n);
    scanf("%d", &W);
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
        cout << "w = "<< weight[i] << ", v = " << value[i] << endl;
    }

    for(int i = 0; i <= W; i++) dp[0][i] = 0;

    for(int i = 0; i < n; i++){
        for(int w = 0; w <= W; w++){
            if(w >= weight[i]) dp[i+1][w] = max(dp[i][w], dp[i][w-weight[i]]+ value[i]); 
            else dp[i+1][w] = dp[i][w];
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}