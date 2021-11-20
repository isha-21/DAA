#include <iostream>
#include <algorithm>
using namespace std;

void Pair_search(int arr[], int n, int kth_elem)
{
    sort(arr, arr + n);
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
             if (arr[low] + arr[high] == kth_elem)
        {
            cout << "Pair found " <<endl;
            cout<<"Low = "<<low<< "   ELEM "<< arr[low] << endl;
            cout<<"   HIGH "<<high<<"   ELEM " << arr[high] << endl;
            return;
        }
        (arr[low] + arr[high] < kth_elem)? low++: high--;
    }
    cout << "Pair not found";
}

int main()
{
    int arr[] = { 4,6,70,80,8, 7, 2, 5, 3, 1 };
    int kth_elem;
    int k;
    cout<<"ENTER k index: ";
    cin >> k;
    kth_elem = arr[k];
    cout<<"KTH ELEM IS "<<arr[k]<<endl;
    int n = sizeof(arr)/sizeof(arr[0]);
    Pair_search(arr, n, kth_elem);
    return 0;
}
