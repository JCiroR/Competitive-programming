#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
vector<int> nums;

void gen(int left) {
    if(s.size() > 9) return;
    if(left == 0) {
        string temp = s;        
        reverse(temp.begin(), temp.end());
        nums.push_back(stoi(temp));
        return;
    }
    for(int i = min(9, left); i >= 0; i--) {
        if(left - i >= 0) {
            s.push_back((char)(i + '0'));
            gen(left - i);
            s.pop_back();
        }
    }   
}

int main(void) {
    nums.reserve(10000);
    gen(10);
    sort(nums.begin(), nums.end());
    int k;
    cin >> k;
    cout << nums[k - 1] << endl;
}