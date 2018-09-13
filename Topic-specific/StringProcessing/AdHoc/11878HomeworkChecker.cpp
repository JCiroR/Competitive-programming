#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void) {
    int a, b, c, correct = 0;
    char result[10], op;
    while(scanf("%d%c%d=%s", &a, &op, &b, result) == 4) {
       if(result[0] == '?') continue;
       c = atoi(result);
       if(op == '+' && (a + b == c)) correct++; 
       else if(op == '-' && (a - b == c)) correct++; 
    }
    printf("%d\n", correct);
}