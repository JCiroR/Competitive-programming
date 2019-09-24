#include <bits/stdc++.h>
using namespace std;

double maxE[13], minE[13];
int times[13] = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
double probs[13];

void loadProbs() {
    for(int i = 0; i <= 12; i++) {
        probs[i] = (double)times[i]/36.0;
    }
}

int map_mask(int mask, int subset, int set_size) {
    int j = 0;
    for(int i = 0; i < set_size; i++) {
        while(!(mask & (1 << j))) j++;
        if(!(subset & (1 << i)))
            mask &= ~(1 << j);
        j++;
    }
    return mask;
}

int getSum(int mask, int maskSize) {
    int sum = 0;
    for(int i = 0; i < maskSize; i++)
        if(mask & (1 << i))
            sum += i;
    return sum;
}

double concat_values(int values) {
    if(values == 0) return 0;
    string s = "";
    for(int i = 1; i <= 9; i++) {
        if(values & (1 << i)) s.push_back('0' + i);
    }
    return (double) stoi(s, nullptr, 10);
}

double move(int values) {
    int set_size = __builtin_popcount(values);
    for(int i = 2; i <= 12; i++)
        maxE[i] = -1;
    int setAux = (1 << set_size) - 1;
    while(setAux >= 0) {
        int mask = map_mask(values, setAux, set_size);
        int sum = getSum(mask, 10);
        if(sum >= 2 && sum <= 12) {
            int nextMask = values ^ mask;
            maxE[sum] = max(maxE[sum], move(nextMask));
        }
        setAux--;
    }
    double expValue = 0;
    double score = concat_values(values);
    for(int i = 2; i <= 12; i++) {
        if(maxE[i] == -1) expValue += probs[i] * score;
        else expValue += (maxE[i] * probs[i]);
    }
    return expValue;
}

double first_move(int values, int first_sum) {
    int set_size = __builtin_popcount(values);
    for(int i = 2; i <= 12; i++)
        maxE[i] = -1;

    int setAux = (1 << set_size) - 1;
    while(setAux > 0) {
        int mask = map_mask(values, setAux, set_size);
        int sum = getSum(mask, 10);
        if(sum == first_sum) {
            int nextMask = values ^ mask;
            maxE[sum] = max(maxE[sum], move(nextMask));
        }
        setAux--;
    }
   if(maxE[first_sum] != -1) return maxE[first_sum];
   else return concat_values(values);
}

int main() {
    loadProbs();
    int values = stoi("1000011110",nullptr,2);
    cout << first_move(values, 4) << endl;
}