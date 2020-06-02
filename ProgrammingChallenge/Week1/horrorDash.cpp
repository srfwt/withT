#include <iostream>
using namespace std;

int T, N;
int main(){
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int c, cMAX = 1;
        scanf("%d", &N);
        for(int j = 0; j < N; j++){
            scanf("%d", &c);
            if(c > cMAX) cMAX = c;
        }
        cout << "Case " << i+1 << ": " << cMAX << endl;
    }
    return 0;
}