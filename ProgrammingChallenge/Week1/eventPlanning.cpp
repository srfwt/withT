#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isVacant(int N, int *v, int w){
    bool res = false;
    for(int i = 0; i < w; i++){
        if(v[i] >= N) res = true;
    }
    return res;
}
bool enoughMoney(int B, int r, int N){
    return B >= (r * N);
}


int main(){
    int N, B, H, W;
    while(cin >> N >> B >> H >> W){
        int r[H], v[H][W];
        vector<int> poss;
        int l;
        for(int i = 0; i < H; i++){
            cin >> l;
            r[i] = l;
            for(int j = 0; j < W; j++){
                cin >> l;
                v[i][j] = l;
            }
        }
        
        for(int i = 0; i < H; i++){
            int tmp[W];
            for(int j = 0; j < W; j++){
                tmp[j] = v[i][j];
            }
            if(isVacant(N, tmp, W) && enoughMoney(B, r[i], N)){
                poss.push_back(N*r[i]);
            }  
        }
        if(poss.empty()) cout << "stay home" << endl;
        else{
            int minPoss = *min_element(poss.begin(), poss.end());
            cout << minPoss << endl;
        }
    }
    return 0;
}