#include <iostream>
#include <cstring>
using namespace std;
#define MAX_S 100000

int main(){
    int S, B;
    while(cin >> S >> B){
        if(S == 0 && B == 0) return 0;
        int alive[MAX_S];
        memset(alive, 1, sizeof(alive));
        for(int i = 0; i < B; i++){
            int L, R;
            cin >> L >> R;
            int ansL = L-1, ansR = R-1;
            memset(alive + L-1, 0, (R-L+1)*sizeof(int));
            while(alive[ansL] == 0){
                if(ansL==0){
                    ansL = -1;
                    break;
                }
                ansL--;
            }
            while(alive[ansR] == 0){
                if(ansR==S-1){
                    ansR = -1;
                    break;
                }
                ansR++;
            }

            if(ansL == -1) cout << "*";
            else cout << ansL+1;
            cout << " ";
            if(ansR == -1) cout << "*";
            else cout << ansR+1;
            cout << endl;
        }
        cout << "-" << endl;
    }
}