#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l,int r,int &compare,int &swaps)
{srand(time(0));
int pivot=rand()%(r-l+1)+l;
int i=l-1,j=l;
swap(arr[pivot],arr[r]);
swaps++;
pivot=arr[r];
while(j<=r)
    {
    compare++;
    if(arr[j]<=pivot)
    {
        swaps++;
        i++;
    swap(arr[i],arr[j]);
    }
    j++;
    }
return i;
}

void QuickSort(int arr[],int l,int r,int &compare,int &swaps)
{int p;
if(l<r){
p=partition(arr, l, r, compare, swaps);
QuickSort(arr, l, p-1, compare, swaps);
QuickSort(arr,p+1,r,compare,swaps);
}
}

int  main() {
     int t;
 cout<<" NO OF TEST CASES:";
    cin>>t;

while(t--){
int n,compare=0,swaps=0;
cout<<" NO OF ELEMENTS IN TEST CASE "<<t<<endl;
cin>>n;
int arr[n];
cout<<"Enter Array : "<<endl;
for(int i=0;i<n;i++)
    cin>>arr[i];
QuickSort(arr,0,n-1,compare,swaps);
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<"\n Comparisons = "<<compare;
cout<<"\nSwaps="<<swaps<<endl;
}
return 0;
}
