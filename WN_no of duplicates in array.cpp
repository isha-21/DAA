// C++ program to count occurrences of an element
#include<bits/stdc++.h>

using namespace std;

// Returns number of times x occurs in arr[0..n-1]

int count(int arr[], int n, int k)
{

    int x = 0;

    for (int i=0; i<n; i++)

        if (k == arr[i])

          x++;

    return k;
}

// Driver code

int main()
{

    int arr[] = {4, 5, 5, 5, 4, 6, 1, 1 ,8 ,8 };

    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 5;

    cout << count(arr, n, k);

    return 0;
}

