#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;
map<char, int> rewardMap;

int main(){
    int n, k, m, val;
    char chr;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        double totalReward=0;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            cin >> chr >> val;
            rewardMap.insert(make_pair(chr, val));
        }
        scanf("%d", &m);
        cin.ignore();
        
        for(int j = 0; j < m; j++){
            string s;
            getline(cin, s);
            for(int k = 0; k < s.size(); k++){
                decltype(rewardMap)::iterator it = rewardMap.find(s[k]);
                if(it != rewardMap.end()) totalReward += it->second;
            }
        }
        totalReward /= 100;
        cout << fixed << setprecision(2) << totalReward << "$" << endl;
        rewardMap.clear();
    }
    return 0;
}