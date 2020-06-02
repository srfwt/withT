#include <iostream>
using namespace std;

int N;
int main(){
    scanf("%d", &N);
    while(N--){
        int A, B, C, x, y, z;
        bool found = false;
        scanf("%d %d %d", &A, &B, &C);
        for(x = -100; x <= 100; x++){
            if(found) break;
            for(y = -100; y <= 100; y++){
                if(found) break;
                for(z = -100; z <= 100; z++){
                    if(found) break;
                    if(y != x && z != x && z != y &&
                    x + y + z == A && x*y*z == B &&
                    x*x + y*y + z*z == C){
                        cout << x << " " << y << " " << z << endl;
                        found = true;
                    }
                    if(x == 100 && y == 100 && z == 100) cout << "No solution." << endl;
                }
            }
        }
    }
}