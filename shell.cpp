#include <iostream>
#include <fstream>

using namespace std;

int main() {

	int N;

	ifstream fin("shell.in");

	fin >> N;
	int operations[3][N], maxpoints = 0;

	for(int i = 0; i < N; i++) {
		fin >> operations[0][i] >> operations[1][i] >> operations[2][i];
	}

	for(int i = 0; i < 3; i++) {
		int S[3] = {0};
		S[i] = 1;

		int temppoints = 0;




		for(int e = 0; e < N; e++) {
			int a = S[operations[0][e]-1];
			S[operations[0][e]-1] = S[operations[1][e]-1];
			S[operations[1][e]-1] = a;


			if(S[operations[2][e]-1] == 1) {
				temppoints++;
			}
		}

		maxpoints = max(maxpoints, temppoints);
			
	}
	

	ofstream out("shell.out");
	out << maxpoints << "\n";
	return 0;
}

	
