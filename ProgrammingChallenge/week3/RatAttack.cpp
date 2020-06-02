#include <iostream>
#include <cstring>
using namespace std;

int S, N, d;

int main(){
    scanf("%d", &S);
    while(S--){
        int max = 0, ansX, ansY;
        int **killed = (int**) malloc(sizeof(int*) *1025);
        for(int i = 0; i < 1025; i++) killed[i] = (int*) malloc(sizeof(int) * 1025);
        for(int i = 0; i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                killed[i][j] = 0;
            }
        }
        scanf("%d", &d);
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            int x, y, size;
            scanf("%d %d %d", &x, &y, &size);
            
            for(int m = -d; m <= d; m++){
                for(int n = -d; n <= d; n++){
                    if(x+m < 0 || y+n < 0 || x+m > 1024 || y+n > 1024) continue;
                    killed[x+m][y+n] += size;
                }
            }
        }
        for(int x = 0; x < 1025; x++){
            for(int y = 0; y < 1025; y++){
                int tmp = killed[x][y];
                if(tmp > max){
                    max = tmp;
                    ansX = x;
                    ansY = y;
                }
            }
        }
        cout << ansX << " " << ansY << " " << max << endl;
    }
    return 0;
}