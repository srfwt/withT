#include <iostream>
#include <cstring>
using namespace std;
#define MAX_S 100000

int L[MAX_S], R[MAX_S];
int main(){
    int S, B;
    while(cin >> S >> B){
        if(S == 0 && B == 0) return 0;
        for(int i = 0; i < S+1; i++){
            L[i] = i-1;
            R[i] = i+1;
        }
        for(int i = 0; i < B; i++){
            int l, r;
            cin >> l >> r;
            if(L[l] < 1) cout << "*";
            else cout << L[l];
            cout << " ";
            if(R[r] > S) cout << "*";
            else cout << R[r];
            cout << endl;

            L[R[r]] = L[l];
            R[L[l]] = R[r];
        }
        cout << "-" << endl;
    }
    return 0;
}