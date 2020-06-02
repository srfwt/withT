#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int dp[5][8];
    int i = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    dp[0][1] = 2;
    cout << dp[0][0].size() << endl;
    return 0;
}