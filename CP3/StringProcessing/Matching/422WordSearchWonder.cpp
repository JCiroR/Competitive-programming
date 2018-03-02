/*
    Yo solo queria resolver sopas de letras :'v
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int,int> ii;

const int MAXN = 110;
char M[MAXN][MAXN];
int l;
string word;

const int UL = 1, U = 2, UR = 3, R = 4, DR = 5, D = 6, DL = 7, L = 8;

pair<int,int> findWord(int dir, int row, int col, int cC) {
    const ii def = make_pair(-1, -1);
    if(word[cC] != M[row][col]) return def;
    else if(word.size() == cC + 1)
        return make_pair(row, col);
    ii answ = def;
    switch(dir) {
        case 0:
            if(row < l - 1 && M[row+1][col] == word[cC+1]) {
                answ = findWord(D, row +  1, col, cC+1);
                if(answ.first != -1) return answ;
            }
            if(row > 0 && M[row-1][col] == word[cC + 1]) {
                answ = findWord(U, row - 1, col, cC+1);
                if(answ.first != -1) return answ;
            }
            if(col < l - 1 && M[row][col+1] == word[cC+1]) {
                answ = findWord(R, row, col+1, cC+1);
                if(answ.first != -1) return answ;
            }
            if(col > 0 && M[row][col-1] == word[cC+1]) {
                answ = findWord(L, row, col-1, cC+1);
                if(answ.first != -1) return answ;
            }
            if(col < l-1 && row < l-1 && M[row+1][col+1] == word[cC+1]) {
                answ = findWord(DR,row+1,col+1,cC+1);
                if(answ.first != -1) return answ;
            }
            if(col < l-1 && row > 0 && M[row-1][col+1] == word[cC+1]) {
                answ = findWord(UR, row-1, col+1, cC+1);
                if(answ.first != -1) return answ; 
            }
            if(col > 0 && row > 0 && M[row-1][col-1] == word[cC+1]) {
                answ = findWord(UL, row-1, col-1, cC+1);
                if(answ.first != -1) return answ;
            }
            if(col > 0 && row < l-1 && M[row+1][col-1] == word[cC+1]) {
                answ = findWord(DL, row+1, col-1, cC+1);
                if(answ.first != -1) return answ;
            }
            return def;
            break;
        case UL:
            if(col > 0 && row > 0 && M[row-1][col-1] == word[cC+1]) 
                return findWord(UL, row-1, col-1, cC+1);
            else return def;
            break;
        case U:
            if(row > 0 && M[row-1][col] == word[cC+1])
                return findWord(U, row-1, col, cC+1);
            else return def;
            break;
        case UR:
            if(row > 0 && col < l-1 && M[row-1][col+1] == word[cC+1])
                return findWord(UR, row-1, col+1, cC+1);
            else return def;
            break;
        case R:
            if(col < l-1 && M[row][col+1] == word[cC+1])
                return findWord(R, row, col+1, cC+1);
            else return def;
            break;
        case DR:
            if(col < l-1 && row < l-1 && M[row+1][col+1] == word[cC+1])
                return findWord(DR, row+1,col+1, cC+1);
            else return def;
            break;
        case D:
            if(row < l-1 && M[row+1][col] == word[cC+1])
                return findWord(D, row+1, col, cC+1);
            else return def;
            break;
        case DL:
            if(col > 0 && row < l-1 && M[row+1][col-1] == word[cC+1])
                return findWord(DL, row+1, col-1, cC+1);
            else return def;
            break;
        case L:
            if(col > 0 && M[row][col-1] == word[cC+1])
                return findWord(L, row, col-1, cC+1);
            else return def;
            break;
    }
    return def;
}

int main(void) {
    cin >> l;
    for(int i = 0; i < l; i++)
        scanf("%s\n", &M[i][0]);
    while(cin >> word && word[0] != '0') {
        ii to = make_pair(-1, -1), from;
        for(int i = 0; i < l; i++) {
            if(to.first != -1) break;
            for(int j = 0; j < l; j++) {
                to = findWord(0, i, j, 0);
                if(to.first != -1) {
                    from = make_pair(i, j);
                    break;
                }
            }
        }
        if(to.first == -1) printf("Not found\n");
        else {
            printf("%d,%d %d,%d\n", from.first + 1, from.second+1, to.first+1, to.second+1);
        }
    }
}