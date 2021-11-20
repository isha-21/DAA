#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[],int l,int r,int &compare,int &shifts)
{int i,j,tmp;
for(i=l+1;i<=r;i++)
    {tmp=arr[i];
    j=i-1;
    while(j>=0){
        compare++;
        if(arr[j]<tmp)
            break;
        arr[j+1]=arr[j];
        shifts++;
        j--;
        }
    arr[++j]=tmp;
    }
}

int main(){
    int t;
    cout<<" NO OF TEST CASES:";
    cin>>t;
    while(t--){
int n,compare=0,shifts=0;
cout<<" NO OF ELEMENTS IN TEST CASE "<<t<<endl;
cin>>n;
int arr[n];
cout<<"Enter Array : "<<endl;
for(int i=0;i<n;i++)
    cin>>arr[i];
InsertionSort(arr,0,n-1,compare,shifts);
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";
cout<<"\n  Comparisons="<<compare<<endl;
cout<<"Shifts="<<shifts<<endl;
}
return 0;
}
