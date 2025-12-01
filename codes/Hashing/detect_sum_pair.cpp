#include<iostream>
using namespace std;
class Node{
    public:
    int sum;
    pair<int,int> value;
    Node *next;
    Node(int s, int a , int b){
        sum =s;
        value.first=a;
        value.second=b;
    }
    Node(){
        next=NULL;
    }
};
    class   HASH{
        private:
        Node **table;
        int size;
        public:
        HASH(int size){
            this->size=size;
            table=new Node*[size];
            for(int i=0;i<size;i++){
                table[i]=NULL;
            }
        }
    int HashFunction(int key){
        return key%size;
    }
    bool Insert(int a,int b){
        int sum=a+b;
        int index = HashFunction(sum);
        Node *newNode = new Node(sum,a,b);
        if(table[index]==NULL){
            table[index]=newNode;
            return false;
        }
        Node *temp = table[index];
        while(temp->next!=NULL){
            if(temp->sum == sum && temp->value.first != a && temp->value.first != b &&  temp->value.second != a && temp->value.second != b){
                cout<<"("<<temp->value.first<<","<<temp->value.second<<") and ("<<a<<","<<b<<")"<<endl;
                delete newNode;
                return true;
            }
            temp=temp->next;
        }
         if(temp->sum == sum && temp->value.first != a && temp->value.first != b &&  temp->value.second != a && temp->value.second != b){
                cout<<"("<<temp->value.first<<","<<temp->value.second<<") and ("<<a<<","<<b<<")"<<endl;
                delete newNode;
                return true;
        }
        temp->next=newNode;
        return false;
    }
    bool PrintSameSumPair(int *arr,int size){
        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                if(Insert(arr[i],arr[j]))  return true;
            }
        }
        return false;
    }
};
int main(){
    HASH h1(101);
    int arr1[]={3, 4, 7, 1, 2, 9, 8};
    if(!h1.PrintSameSumPair(arr1,7)) cout<<"No Pair found"<<endl;
    HASH h2(101);
    int arr2[]={3, 4, 7, 1, 12, 9};
     if(!h2.PrintSameSumPair(arr2,6)) cout<<"No Pair found"<<endl;
     HASH h3(101);
    int arr3[]={65, 30, 7, 90, 1, 9, 8};
    if(!h3.PrintSameSumPair(arr3,7)) cout<<"No Pair found"<<endl;
}