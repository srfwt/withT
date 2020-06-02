#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct team{
	string name;
	int goalScore;
	int goalAgainst;
	int win, tie, loss;
};
bool cmp(struct team A, struct team B){
	int PA, PB;
	PA = A.win * 3 + A.tie;
	PB = B.win * 3 + B.tie;
	if (PA > PB)	return true;
	if (PB > PA)	return false;
	if (A.win > B.win)	return true;
	if (A.win < B.win)	return false;
	if (A.goalScore - A.goalAgainst>B.goalScore - B.goalAgainst)	return true;
	if (A.goalScore - A.goalAgainst<B.goalScore - B.goalAgainst)	return false;
	if (A.goalScore > B.goalScore)	return true;
	if (A.goalScore < B.goalScore)	return false;
	PA = A.win + A.tie + A.loss;
	PB = B.win + B.tie + B.loss;
	if (PA > PB)	return false;
	if (PA < PB)	return true;
	for (int i = 0;; i++){ // ignore case
		char a = A.name[i];
		char b = B.name[i];
		if (a >= 'A'&&a <= 'Z')	a += 32;
		if (b >= 'A'&&b <= 'Z')	b += 32;
		if (a == '\0')	return true;
		if (b == '\0')	return false;
		if (a > b)	return false;
		if (a < b)	return true;
	}
}
int main(){
	int t;
	cin >> t;
	(void)getchar();
	while (t--){
		struct team T[30];
		string tournamentName;
		getline(cin, tournamentName);
		int n, g;
		cin >> n;
		(void)getchar();
		for (int i = 0; i < n; i++){
			getline(cin, T[i].name);
			T[i].goalAgainst = 0;
			T[i].goalScore = 0;
			T[i].loss = T[i].tie = T[i].win = 0;
		}
		cin >> g;
		(void)getchar();
		for (int j = 0; j < g; j++){
			int a, AS = 0, BS = 0;
			string R, A, B;
			getline(cin, R);
			for (a = 0; R[a] != '#'; a++)	A.push_back(R[a]);
			for (a++; R[a] != '@'; a++)	AS = AS * 10 + R[a] - '0';
			for (a++; R[a] != '#'; a++)	BS = BS * 10 + R[a] - '0';
			for (a++; R[a] != '\0'; a++)	B.push_back(R[a]);
			for (int k = 0; k < n; k++){
				if (T[k].name == A){
					T[k].goalScore += AS;
					T[k].goalAgainst += BS;
					if (AS > BS)	T[k].win++;
					if (AS == BS)	T[k].tie++;
					if (AS < BS)	T[k].loss++;
				}
				if (T[k].name == B){
					T[k].goalScore += BS;
					T[k].goalAgainst += AS;
					if (AS < BS)	T[k].win++;
					if (AS == BS)	T[k].tie++;
					if (AS > BS)	T[k].loss++;
				}
			}
		}
		sort(T, T + n, cmp);
		cout << tournamentName << endl;
		for (int i = 0; i < n; i++){
			cout << i + 1 << ") " << T[i].name << " " << T[i].win * 3 + T[i].tie << "p, ";
			cout << T[i].win + T[i].loss + T[i].tie << "g (" << T[i].win << "-" << T[i].tie << "-" << T[i].loss << "), ";
			cout << T[i].goalScore - T[i].goalAgainst << "gd (" << T[i].goalScore << "-" << T[i].goalAgainst << ")" << endl;
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}