#include<iostream>
using namespace std;
class Node{
    public:
    string val;
    char key;
    Node *next;
    Node(){
        next=NULL;
    }
    Node(string val, char key){
        this->val=val;
        this->key=key;
        next = NULL;
    }
};
class HASHTABLE{
    private:
    Node **table;
    int tablesize;
    public:
    HASHTABLE(int size){
        this->tablesize=size;
        table = new Node*[tablesize];
        for(int i=0;i<tablesize;i++){
            table[i]=NULL;
        }
    }
    int hashfunction(char key){
        int keyt = key;
        return keyt%tablesize;
    }   
    void insert(string val, char key){
        int index = hashfunction(key);
        Node *newNode = new Node(val,key);
        if(table[index]==NULL){
            table[index]=newNode;
            return;
        }
        Node *temp = table[index];
        while(temp->next!=NULL){
            if(temp->key==key){
                temp->val=val;
                delete newNode;
                return;
            }
            temp=temp->next;
        }
        if(temp->key==key){
            temp->val=val;
            delete newNode;
            return;
        }
        temp->next=newNode;
    }
    string search(char key){
        int index = hashfunction(key);
        Node *iterator=table[index];
        while(iterator!=NULL){
            if(iterator->key == key){
                return iterator->val;
            }
            iterator=iterator->next;
        }
        return "";
    }
    void remove(char key){
        int index = hashfunction(key);
        if(table[index]==NULL){
            cout<<"Node D.N.E"<<endl;
            return;
        }
        if(table[index]->key==key){
            Node *temp = table[index];
            table[index]=table[index]->next;
            delete temp;
            return;
        }
        Node *iterator = table[index]->next;
        Node *prev = table[index];
        while(iterator!=NULL){
            if(iterator->key==key){
                prev->next=iterator->next;
                delete iterator;
                return;
            }
            prev = iterator;
            iterator=iterator->next;
        }
        cout<<"Value with given key D.N.E"<<endl;
    }
};
int main(){
    HASHTABLE h(3);
    pair<string,char> arr[10]={
        {"aaaa",'A'},
        {"bbbb",'B'},
        {"ccccc",'C'},
        {"zzzzz",'A'},
        {"ddddd",'D'},
        {"eeeee",'E'},
        {"fffff",'F'},
        {"ggggg",'G'},
        {"hhhhh",'H'},
        {"iiiii",'I'}};
        for(int i=0;i<10;i++){
            h.insert(arr[i].first,arr[i].second);
        }
         for(int i=0;i<10;i++){
           cout<<"{"<<arr[i].first<<" = "<< h.search(arr[i].second)<<"},"<<endl;
        }

    };