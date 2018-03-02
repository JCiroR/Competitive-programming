#include <set>
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

bool seen[61][61][61];

void clear(){
    for(int i = 0; i < 61; i++)
        for(int j = 0; j < 61; j++) 
            for(int k = 0; k < 61; k++)
                seen[i][j][k] = false;
}

int main(void) {
    set<int> pscores;
    for(int i = 0; i <= 20; i++) {
        pscores.insert(i);
        pscores.insert(i*2);
        pscores.insert(i*3);
    }
    pscores.insert(50);
    vector<int> scores(pscores.begin(), pscores.end());
    int target;
    while(cin >> target) {
        if(target <= 0) {
            cout << "END OF OUTPUT\n";
            break;
        }
        clear();
        int comb = 0, perm = 0;
        for(int i = 0; i < scores.size(); i++)
            for(int j = 0; j < scores.size(); j++)
                for(int k = 0; k < scores.size(); k++) {
                    if(scores[i] + scores[j] + scores[k] == target) {
                        perm++;
                        if(!seen[i][j][k]) {
                            seen[i][j][k] = seen[i][k][j] = true;
                            seen[k][i][j] = seen[k][j][i] = true;
                            seen[j][k][i] = seen[j][i][k] = true;
                            comb++;
                        }
                    }
                }
        if(comb == 0 && perm == 0) printf("THE SCORE OF %i CANNOT BE MADE WITH THREE DARTS.\n", target);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %i IS %i.\n", target, comb);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %i IS %i.\n", target, perm);
        }
        printf("**********************************************************************\n");
    } 
    return 0;
}