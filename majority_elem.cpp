
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int majority_ele(vector<int> const &nums)
{
        unordered_map<int, int> map;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        map[nums[i]]++;
    }

      for (auto pair: map)
    {
        if (pair.second > n/2) {
            return pair.first;
        }
    }
    return -1;
}

int main()
{
    vector<int> input = { 4, 8, 2, 2, 2, 7, 2, 3, 2, 1, 2 };

    int result = majority_ele(input);
    if (result != -1) {
        cout << "The required majority element is " << result;
    }
    else {
        cout << "The majority element doesn't exist";
    }

    return 0;
}
