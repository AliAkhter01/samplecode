#include<iostream>
using namespace std;
class Heap{
    private:
    int *arr;
    int maxsize;
    int currsize;
    public:
    Heap(int s){
        maxsize =s;
        arr = new int[maxsize];
        currsize = 0;
    }
    Heap(){
        maxsize=100;
        arr = new int[maxsize];
        currsize=0;
    }
    void heapifyup(int index){
        int parent = (index-1)/ 2;
        if(index>0 && arr[index]>arr[parent]){
            swap(arr[index],arr[parent]);
            heapifyup(parent);
        }
        return;
    }
    void Insert(int value){
        if(currsize==maxsize)   {
            cout<<"Heap overflow"<<endl;
            return;
        }
        arr[currsize] = value;
        heapifyup(currsize);
        currsize++;

    }
    void heapifydown(int index){
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        if(left<currsize && arr[largest]<arr[left])  largest = left;
        if(right<currsize && arr[largest]<arr[right])    largest = right;
        if(largest!= index){
            swap(arr[largest],arr[index]);
            heapifydown(largest);
        }
    }
    void heapifydown(int n , int index){
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        if(left<n && arr[largest]<arr[left])  largest = left;
        if(right<n && arr[largest]<arr[right])    largest = right;
        if(largest!= index){
            swap(arr[largest],arr[index]);
            heapifydown(n,largest);
        }
    }
    void heapifydown(int array[],int n , int index){
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        if(left<n && array[largest]<array[left])  largest = left;
        if(right<n && array[largest]<array[right])    largest = right;
        if(largest!= index){
            swap(array[largest],array[index]);
            heapifydown(array,n,largest);
        }
    }
    void update_key(int index , int value){
        if(currsize==0){
            cout<<"Heap underflow"<<endl;
            return;
        }
        if(index<=currsize-1){
            if(value>arr[index]){
                arr[index] = value;
                heapifyup(index);
            }
            else  if(value<arr[index]){
                arr[index] = value;
                heapifydown(index);
            }
        }
    }
        bool max_heap(int array[],int index,int n){
            int left = 2*index +1 ;
            int right = 2*index +2;
            if(left>=n){
                return true;
            }
            if(left<n && array[left]>array[index])
                return false;
            
            if(right<n && array[right]>array[index])
                return false;
        
            return max_heap(array,left,n) && max_heap(array,right,n);
        }
        bool min_heap(int array[],int index , int n){
            int left = 2*index+1;
            int right = 2*index+2;
            if(left>=n){
                return true;
            }
            if(left<n && array[left]<array[index])  return false;
            if(right<n && array[right]<array[index])    return false;
            return min_heap(array,left,n) && min_heap(array,right,n);
        }
    void checkBinaryHeap(int array[] , int n){
       if(max_heap(array,0,n)){
        cout<<endl<<"Array is a max heap"<<endl;
        return ;
       }
       else if(min_heap(array,0,n)){
        cout<<endl<<"Array is a minheap"<<endl;
        return ;
       }
       else{
        cout<<endl<<"Array is not a Binary heap"<<endl;
        return ;
       }
    }
      void minheapifydown(int array[],int n , int index){
        int smallest = index;
        int left = 2*index +1;
        int right = 2*index +2;
        if(left<n && array[smallest]>array[left])  smallest = left;
        if(right<n && array[smallest]>array[right])    smallest = right;
        if(smallest!= index){
            swap(array[smallest],array[index]);
            minheapifydown(array,n,smallest);
        }
    }
   void Kth_Largest(int array[],int n,int k){
    int *arr = new int[k];
    for(int i=0;i<k;i++){
        arr[i]=array[i];
    }
    for(int i=k/2-1;i>=0;i--){
        minheapifydown(arr,k,i);
    }
    for(int i=k;i<n;i++){
        if(array[i]>arr[0]){
            arr[0]=array[i];
            minheapifydown(arr,k,0);
        }
    }
    cout<<endl<<"The Kth largest element is : "<<arr[0]<<endl;
    delete[] arr;
   }
    void delete_top(){
        if(currsize==0){
            cout<<"Heap underflow"<<endl;
            return;
        } 
        currsize--;
        arr[0] = arr[currsize];
        if(currsize>1){
            heapifydown(0);
        }
    }   
    void print(){
        if(currsize==0){
            cout<<"heap underflow"<<endl;
            return;
        }
        cout<<endl<<endl;
        for(int i=0;i<currsize;i++){
            cout<<arr[i]<<" ";
        }
    }
    
   void heapsort(){
    for(int i=currsize-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapifydown(i,0);
    }
   }
   void heapsort(int array[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapifydown(array,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(array[0],array[i]);
        heapifydown(array,i,0);
    }
   }
};
int main(){
    Heap h(10);
    h.Insert(4);
    h.Insert(3);
    h.Insert(10);
    h.print();
    // h.delete_top();
    // cout<<endl;
    // h.print();
    h.heapsort();
    h.print();
    int array[7] = {1,50,30,20,10,40,5};
    h.heapsort(array,7);
    cout<<endl<<endl;
    for(int i=0;i<7;i++){
        cout<<array[i]<<" ";
    }
}
