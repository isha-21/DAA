#include<iostream>
using namespace std;
void kth_largest(int arr[], int size, int k)
{
  int a;

  for(int i=0;i<k;i++)
   {

     for(int j=0;j<size-1;j++)
        {
          if(arr[j] > arr[j+1])
          {
            a = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = a;
          }
        }
   }

   cout<<"K-th largest element of array is : "<< arr[size-k]<<endl;
}
void kth_smallest(int arr[], int size, int k)
{
  int a;

  for(int i=0;i<k;i++)
   {

     for(int j=0;j<size-1;j++)
        {
          if(arr[j] < arr[j+1])
          {
            a = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = a;
          }
        }
   }

   cout<<"K-th Smallest element of array is : "<< arr[size-k]<<endl;
}
int main()
{
     int size=10;
     int arr[]={7,9,45,5, 8, 12, 20, 35, 4, 50};
     int k = 4;
kth_largest(arr, size,k);
kth_smallest(arr, size,k);
     return 0;
}
