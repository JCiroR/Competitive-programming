#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int k, p;
    cin >> k >> p;
    
    long long sum = 0;
    string numb, aux; 
    for(int i = 1; i <= k; i++) {
        numb = aux = to_string(i);
        reverse(aux.begin(), aux.end());
        numb += aux;
        sum = ((sum % p) + (stoll(numb) % p)) % p;    
    }
    cout << sum << endl;
}
