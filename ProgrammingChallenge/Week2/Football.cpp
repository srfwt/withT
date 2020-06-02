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
        pts = gms = won = tie = lost = glS = glA = 0;
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

int strcmp_ignorecase(const char* a, const char* b){
    while(tolower(*a) == tolower(*b)){
        if(*a == '\0'){
            return 0;
        }
        ++a;
        ++b;
    }
    return tolower(*a) - tolower(*b);
}

bool cmp(Team a, Team b){
    if(a.pts != b.pts) return a.pts > b.pts;
    if(a.won != b.won) return a.won > b.won;
    if((a.glS-a.glA) != (b.glS-b.glA)) return (a.glS-a.glA) > (b.glS - b.glA);
    if(a.glS != b.glS) return a.glS > b.glS;
    if(a.gms != b.gms) return a.gms < b.gms;
    else{
        int lexio = strcmp_ignorecase(a.name, b.name);
        if(lexio < 0) return true;
        else return false;
    }

}

int N, T, G;

int main(){
    cin >> N;
    (void) getchar();
    while(N--){
        vector<Team> v;
        string tournament;
        getline(cin, tournament);
        cin >> T;
        (void)getchar();
        for(int i = 0; i < T; i++){
            string tmpName;
            Team tmp;
            tmp.init();
            getline(cin, tmpName);
            for(int j = 0; j < tmpName.size()+1; j++){
               tmp.name[j] = tmpName[j];
            }
            v.push_back(tmp);
        }

        cin >> G;
        (void)getchar();

        for(int i = 0; i < G; i++){
            string tmpGame, A, B;
            int Agl=0, Bgl=0;
            getline(cin, tmpGame);
            int k;
            for(k=0; tmpGame[k] != '#'; k++) A.push_back(tmpGame[k]);
            for(k++; tmpGame[k] != '@'; k++) Agl = Agl*10 + tmpGame[k] - '0';
            for(k++; tmpGame[k] != '#'; k++) Bgl = Bgl*10 + tmpGame[k] - '0';
            for(k++; tmpGame[k] != '\0'; k++) B.push_back(tmpGame[k]);
        
            for(int j = 0; j < T; j++){
                string vName = v[j].name;
                if(vName == A){
                    v[j].rec(Agl, Bgl);
                }
                if(vName == B){
                    v[j].rec(Bgl, Agl);
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        cout << tournament << endl;
        for(int i = 0; i < T; i++){
            cout << i+1 << ") " << v[i].name << " " << v[i].pts << "p, ";
            cout << v[i].gms << "g (" << v[i].won << "-" << v[i].tie << "-" << v[i].lost;
            cout << "), " << v[i].glS - v[i].glA << "gd (" << v[i].glS << "-" << v[i].glA << ")" << endl;
        }
        if(N!=0) cout << endl;
    }
    return 0;
}