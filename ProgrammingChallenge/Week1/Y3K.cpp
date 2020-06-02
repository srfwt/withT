#include <iostream>
using namespace std;

int g_x, g_d, g_m, g_y;

void solve(int x, int d, int m, int y){
    d += x;
    int ex_d = 0;
    if(d > 31){
        ex_d = d / 31;
        d %= 31;
    }

    m += ex_d;
    int ex_m = 0;
    if(m > 12){
        ex_m = m / 12;
        m %= 12;
    }

    y += ex_m;
    g_d = d;
    g_m = m;
    g_y = y;
}

int main(){
    
    while(cin >> g_x >> g_d >> g_m >> g_y){
        if(g_x == 0 && g_d == 0 && g_m == 0 && g_y == 0) return 0;
        solve(g_x, g_d, g_m, g_y);
        cout << g_d << " " << g_m << " " << g_y;
    }
    
    return 0;
}