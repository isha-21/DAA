#include<bits/stdc++.h>
using namespace std;

int MergeSort(int[],int,int,int&);
int Merge(int[],int,int,int,int&);

int MergeSort(int arr[],int l,int r,int &compare)
{
    int inversion=0,mid;
    if(l<r){
    mid=l+(r-l)/2;
    inversion=MergeSort(arr,l,mid,compare);
    inversion+=MergeSort(arr,mid+1,r,compare);
    inversion+=Merge(arr,l,mid,r,compare);
    }
return inversion;
}

int Merge(int arr[],int l,int mid,int r,int &compare){
    int n1=mid-l+1,n2=r-mid,inversion=0;
int L[n1];
int R[n2];
int i=l,j=mid+1,k=0;
while(i<=mid)
L[k++]=arr[i++];
k=0;
while(j<=r)
    R[k++]=arr[j++];
i=0,j=0,k=l;
while(i<n1&&j<n2){
compare++;
if(L[i]<=R[j])
    arr[k++]=L[i++];
    else{
    arr[k++]=R[j++];

    inversion+=n1-i;
    }
}
while(i<n1)
    arr[k++]=L[i++];
while(j<n2)
    arr[k++]=R[j++];
return inversion;
}
int main(){
    int t;
 cout<<" NO OF TEST CASES:";
    cin>>t;
while(t--){
int n,compare=0,inversion;
cout<<" NO OF ELEMENTS IN TEST CASE "<<t<<endl;
cin>>n;
int arr[n];
cout<<"Enter Array : "<<endl;
for(int i=0;i<n;i++)
    cin>>arr[i];
inversion=MergeSort(arr,0,n-1,compare);
for(int i=0;i<n;i++)
cout<<arr[i]<<"  ";
cout<<"\n Comparisons="<<compare;
cout<<"\n Inversions="<<inversion<<endl;
}
return 0;
}


