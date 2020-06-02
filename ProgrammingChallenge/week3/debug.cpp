#include <iostream>
using namespace std;
int S, N, d;
int main(){
    scanf("%d", &S);
    while(S--){
        scanf("%d", &d);
        scanf("%d", &N);
        int max = 0, ansX, ansY;
        int **killed = new int*[1025];
        for(int i = 0; i < 1025; i++){
            killed[i] = new int[1025]; 
        }
        cout << d << " " << N << endl;
        for(int i = 0; i < N; i++){
            int x, y, size;
            scanf("%d %d %d", &x, &y, &size);
            cout << x << " " << y << " " << size << endl;
        }
    }
    return 0;
}