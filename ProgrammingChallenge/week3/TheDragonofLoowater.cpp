#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 20000

int main(){
    int n=1, m=1;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vector<int> d;
        vector<int> k;
        int tmpD, tmpK;
        for(int i = 0; i < n; i++){
            scanf("%d", &tmpD);
            d.push_back(tmpD);
        }
        for(int i = 0; i < m; i++){
            scanf("%d", &tmpK);
            k.push_back(tmpK);
        }
        
        sort(d.begin(), d.end());
        sort(k.begin(), k.end());

        int ans = 0;
        bool res = true;
        for(int i=0, j=0; i < n; ++i){
            while(j < m && d[i] > k[j]) ++j;
            if(j == m) {
                res = false;
                break;
            }
            else{
                ans += k[j++];
            }
        }

        if(res) cout << ans << endl;
        else cout << "Loowater is doomed!" << endl;
    }
    return 0;
}