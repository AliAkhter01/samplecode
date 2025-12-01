#include<iostream>
using namespace std;
int Partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i = start-1;
    for(int j=start;j<=end;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=arr[end];
    arr[end]=temp;
    return i;
}
void QuickSort(int arr[],int start, int end){
    if(start>=end){
        return;
    }
    int pivot=Partition(arr,start,end);
    QuickSort(arr,start,pivot-1);
    QuickSort(arr,pivot+1,end);
}
int main(){
    int arr[]={100,23,22,11,32,1,2,6,5,4};
    QuickSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}