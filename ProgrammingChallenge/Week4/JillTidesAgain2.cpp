#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_s 20000

int b, s;

int main(){
    scanf("%d", &b);
    int counter = 1;
    while(b--){
        int S[MAX_s];
        scanf("%d", &s);
        for(int i = 0; i < s-1; i++){
            scanf("%d", &S[i]);
        }
        int sum=0, ans=0, currPtr, srt=0, end=0, tmpsrt=0;
        for(int i = 0; i < s-1; i++){
            sum += S[i];
            if(sum > ans){
                ans = sum;
                srt = tmpsrt;
                end = i;
            }else if(sum == ans){
                if(i-tmpsrt > end-srt){
                    ans = sum;
                    srt = tmpsrt;
                    end = i;
                }
            }

            if(sum < 0) {
                sum = 0;
                tmpsrt = i+1;
            }
        }

        if(ans <= 0) cout << "Route " << counter << " has no nice parts" << endl;
        else cout << "The nicest part of route " << counter <<  " is between stops " << srt+1 <<  " and " << end+2 << endl;
        counter++;
    }
    return 0;
}