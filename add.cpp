
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp;

int func(vector<int>& weight, vector<int>& value, int capacity, int index){
    if(index == 0 || capacity == 0){
        return 0;
    }

    if(dp[index][capacity] != -1){
        return dp[index][capacity];
    }

    if(weight[index-1] <= capacity){
        int include = value[index-1] + func(weight, value, capacity - weight[index-1], index);
        int exclude = func(weight, value, capacity, index-1);

        dp[index][capacity] = max(include, exclude);
    }
    else{
        dp[index][capacity] = func(weight, value, capacity, index-1);
    }

    return dp[index][capacity];
}
int main() {
    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 20, 30};
    int capacity = 5;
    int n = weight.size();
    dp.assign(n + 1, vector<int>(capacity + 1, -1));

    cout << "Value: " << func(weight, value, capacity, n) << endl;
    return 0;
}