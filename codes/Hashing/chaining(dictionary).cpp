#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    string value;
    Node *next;
    Node(int key, string value){
        this->value=value;
        this->key = key;
        next=NULL;
    }
    Node(){
        next = NULL;
    }
};
class Dictionary{
    private:
    Node **table;
    int size;
    public:
    Dictionary(int s){
        size = s;
        table = new Node*[size];
        for(int i=0;i<size;i++){
            table[i]=NULL;
        }
    }
    int HashFunction(int key){
        return key%size;
    }
    void AddRecord(string value){
         int sum = 0;
        for(int i=0;i<value.length();i++){
            sum+=value[i];
        }
        int index = HashFunction(sum);
        Node *newNode = new Node(sum,value);
        if(table[index]==NULL){
            table[index]=newNode;
            return;
        }
        Node *temp = table[index];
        while(temp->next!=NULL){
            if(temp->key==sum){
                temp->value=value;
                delete newNode;
                return;
            }
            temp=temp->next;
        }
        if(temp->key==sum){
            temp->value=value;
            delete newNode;
            return;
        }
        temp->next=newNode;
    }
    string Word_Searh(string value){
        int sum =0;
        for(int i=0;i<value.length();i++){
            sum+=value[i];  
        }
        int index = HashFunction(sum);
        if(table[index]==NULL){
            return "";
        }
        Node *temp = table[index];
        while(temp!=NULL){
            if(temp->key==sum){
                return temp->value;
            }
            temp=temp->next;
        }
        return "";
    }
    void Print_Dictionary(){
        for(int i=0;i<size;i++){
            if(table[i]!=NULL){
                Node *temp=table[i];
                while(temp!=NULL){
                    cout<<"Index "<<i<<": ("<<temp->key<<", "<<temp->value<<")"<<endl;
                    temp=temp->next;
                }
            }
        }
    }
};
int main(){
    Dictionary d(100);
    d.AddRecord("FASTNU");
    d.AddRecord("CS");
    string value = d.Word_Searh("FASTNU");
    if(value=="")   cout<<"Not found"<<endl;
    else cout<<value<<endl;
    value= d.Word_Searh("ALI");
      if(value=="")   cout<<"Not found"<<endl;
    else cout<<value<<endl;
    d.Print_Dictionary();
}