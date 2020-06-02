#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_s 20000

int b, s;

int main(){
    scanf("%d", &b);
    int counter = 1;
    while(b--){
        int S[MAX_s], ST[MAX_s+1];
        scanf("%d", &s);
        for(int i = 0; i < s-1; i++){
            scanf("%d", &S[i]);
        }
        int maxSum=0, ptrR=0, ptrL=0;
        ST[0] = 0;
        for(int i = 1; i < s+1 ;i++) ST[i] = ST[i-1] + S[i-1];

        for(int i=1; i < s+1; i++){
            for(int j=1; j < s+1; j++){
                if(ST[j]-ST[i-1] >= maxSum){
                    if(ST[j]<0&&ST[i-1]<0) break;
                    maxSum = ST[j] - ST[i-1];
                    ptrR = i;
                    ptrL = j+1;
                }
            }
        }
        if(maxSum <= 0) cout << "Route " << counter << " has no nice parts" << endl;
        else cout << "The nicest part of route " << counter <<  " is between stops " << ptrR <<  " and " << ptrL << endl;
        counter++;
    }
    return 0;
}