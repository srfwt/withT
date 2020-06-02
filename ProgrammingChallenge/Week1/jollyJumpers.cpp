#include <iostream>
#include <climits>
#include <string>
using namespace std;

#define MAX 3000
int a, b, tmp = INT_MAX;
bool ans = true;

void strToArr(string s, int *a){
    int sz = sizeof(s), k = 0;
    for(int i = 0; i < sz; i++){
        if((s[i] >= '0') && (s[i] <= '9')) {
            a[k] = s[i] - '0'; 
            k++;
        }
    }
}

void solve(int prev_a){
    int a_val = abs(a-b);
    if(a_val > tmp) {
        ans = false;
    }
    tmp = a_val;
    cout << ans << endl;
    int b_val = abs(b - prev_a);
    if(b_val > tmp) {
        ans = false;
    }
    tmp = b_val;
    cout << ans << endl;
}

int main(){
    string s;
    int *a;
    while(getline(cin, s)){
        strToArr(s, a);
        for(int i = 0; i < sizeof(a); i++){
            cout << a[i] << endl;
        }
    }

    return 0;
}