#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 2000

int main(){
    int n=1, m=1, D[MAX_N], K[MAX_N];;
    while(cin >> n >> m){

        if(n == 0 && m == 0) break;
        
        for(int i = 0; i < n; i++) scanf("%d", &D[i]);
        for(int i = 0; i < m; i++) scanf("%d", &K[i]);
        
        sort(D, D + n);
        sort(K, K + m);

        int ans = 0;
        bool res = true;

        for(int i = 0,j = 0; i < n && res; ++i){
            while(j < m && D[i] > K[j]) ++j;
            if(j == m) res = false;
            else ans += K[j++];
        }

        if(res) cout << ans << endl;
        else cout << "Loowater is doomed!" << endl;
    }
    return 0;
}