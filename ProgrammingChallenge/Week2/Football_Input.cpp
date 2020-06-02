#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Team{
    int pts, gms, won, tie, lost, glS, glA;
    char name[31];

    void init(){
        pts = gms = won = tie = lost = 0;
        glS = glA = 0; 
    }

    void rec(int a, int b){
        glS += a;
        glA += b;
        gms++;
        if(a > b){
            pts += 3;
            won++;
        }else if(b > a){
            lost++;
        }else{
            pts++;
            tie++;
        }
    }
};



int N, T, G;

int main(){
    cin >> N;
    (void)getchar();
    while(N--){
        vector<Team> v;
        string tournament;
        getline(cin, tournament);
        cout << tournament << endl;
        cin >> T;
        (void)getchar();
        cout << T << endl;
        for(int i = 0; i < T; i++){
            string tmpName;
            getline(cin, tmpName);
            v[i].init();
            for(int j = 0; j < tmpName.size(); j++){
               v[i].name[j] = tmpName[j];
            }
        }

        cin >> G;
        (void)getchar();

        for(int i = 0; i < G; i++){
            string tmpGame, A, B;
            int Agl=0, Bgl=0,k;
            getline(cin, tmpGame);
            for(k=0; tmpGame[k] != '#'; k++) A[k] = tmpGame[k];
            for(k++; tmpGame[k] != '@'; k++) Agl = Agl*10 + tmpGame[k] - '0';
            for(k++; tmpGame[k] != '#'; k++) Bgl = Bgl*10 + tmpGame[k] - '0';
            int m = 0;
            for(k++; tmpGame[k] != '\0'; k++) B[m++] = tmpGame[k];
            for(int j = 0; j < T; j++){
                string vName;
                int n;
                for(n = 0; v[j].name[n] != '\0'; n++) vName[n] = v[j].name[n];
                vName[n] = '\0';
                if(vName == A){
                    v[j].rec(Agl, Bgl);
                }
                if(vName == B){
                    v[j].rec(Bgl, Agl);
                }
            }
        }
    }
    return 0;
}