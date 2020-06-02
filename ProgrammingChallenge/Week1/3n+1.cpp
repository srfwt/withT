#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
int i, j;
map<int, int> dp;

int timesThreePlusOne(int n){
    if(dp.count(n) == 1) return dp[n];
    else {
        if(n % 2 != 0) dp[n] = 1 + timesThreePlusOne(3*n + 1);
        else dp[n] =  1 + timesThreePlusOne(n/2);
    }
    return dp[n];
}

int main(){
    int i, j;
    dp[1] = 1;
    while(cin >> i >> j){
        int tmp, res = 1;
        for(int n = min(i, j); n <= max(i, j); n++){
            tmp = timesThreePlusOne(n);
            if(tmp > res) res = tmp;
        }
        cout << i << " " << j << " " << res << endl;
    }
    return 0;
}