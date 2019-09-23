#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

vector<int> parentOf;
vector<int> maxDepth;

int findSet(int i) {
    return (i == parentOf[i])? i: (parentOf[i] = findSet(parentOf[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
        int p1 = findSet(i); int p2 = findSet(j);
        if(maxDepth[p1] > maxDepth[p2]) {
            parentOf[p2] = p1;
        } else {
            parentOf[p1] = p2;
            if(maxDepth[p1] == maxDepth[p2]) maxDepth[p2]++;
        }
    }
}

int main(void) {
    int tests, n;
    cin >> tests;
    getchar();
    while(tests--) {
        int yes = 0, no = 0;
        cin >> n; getchar();
        maxDepth = vector<int>(n, 0);
        parentOf = vector<int>(n, 0);
        for(int i = 0; i < n; i++)
            parentOf[i] = i;
        
        char flag = 'k';
        int c1, c2;
        while(flag != EOF && flag != '\n') {
            flag = getchar();
            switch(flag) {
                case 'c':
                    cin >> c1 >> c2;
                    getchar();
                    c1--; c2--;
                    unionSet(c1,c2);
                    
                    break;
                case 'q':
                    cin >> c1 >> c2;
                    getchar();
                    c1--; c2--;
                    if(isSameSet(c1, c2)) yes++;
                    else no++; 
            }
        }
        cout << yes << "," << no << "\n";
        if(tests != 0) cout << "\n";
    }
    return 0;
}