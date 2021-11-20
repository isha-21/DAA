#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int kth_elem, int s)
{

    int low = 0, high = n - 1;
    int result = -1;
    while (low <= high)
    {
                int mid = (low + high)/2;

       if (kth_elem == arr[mid])
        {
            result = mid;
           if (s) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else if (kth_elem < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return result;
}

int main(void)
{int arr[] = { 2, 5, 5, 5, 6, 6, 7,8, 9, 9, 9};
    int kth_elem;
    int k;
    cout<<"ENTER index: ";
    cin >> k;
    kth_elem = arr[k];
    cout<<"KTH ELEM whose duplicates to be found "<<arr[k]<<endl;
    int n = sizeof(arr)/sizeof(arr[0]);

    int F = binarySearch(arr, n, kth_elem, 1);

    int L = binarySearch(arr, n, kth_elem, 0);

    int count = L - F + 1;

    if (F != -1) {
        cout<<"Element "<<  kth_elem<< " occurs "<< count<< " times in array "<<endl;
    }
    else {
        cout<<"Element not found";
    }

    return 0;
}
