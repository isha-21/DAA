/*Program to count pairs with difference k*/
#include<iostream>

using namespace std;

int Pair_search(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k )
                  count++;
    }
    return count;
}
int main()
{
    int arr[] =  {25, 6, 8 , 35, 5, 3, 10, 7, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"ENTER k value ";
    cin >> k;
    cout << "Count of pairs with given diff as k "<< Pair_search(arr, n, k);
    return 0;
}

