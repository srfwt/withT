#include <cstdio>
#include <iostream>
using namespace std;

int g[3][3];
void f(){
	int modulo_2[3][3];

	modulo_2[0][0] = (g[0][1] + g[1][0]) % 2;
	modulo_2[0][1] = (g[0][0] + g[0][2] + g[1][1]) % 2;
	modulo_2[0][2] = (g[0][1] + g[1][2]) % 2;
	modulo_2[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
	modulo_2[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
	modulo_2[1][2] = (g[0][2] + g[1][1] + g[2][2]) % 2;
	modulo_2[2][0] = (g[1][0] + g[2][1]) %2;
	modulo_2[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
	modulo_2[2][2] = (g[2][1] + g[1][2]) % 2;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++) g[i][j] = modulo_2[i][j];
	}
}

bool isEmpty(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(g[i][j] != 0) return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			for(int m = 0; m < 3; m++) scanf("%1d", &g[j][m]);
		}
		
		int ans = -1;
		while(!isEmpty()){
			f();
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}