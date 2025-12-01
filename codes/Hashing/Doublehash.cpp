#include<iostream>
using namespace std;
#define size 101
class Node{
    public:
 string name;
 int roll;
 bool occupied;
 Node(){
    occupied=false;
 }   
 Node(int r, string n){
    roll = r;
    name = n;
    occupied= true;
 }
};
class StudentHash{
    private:
    Node *Table[size];
    protected:
    int hash1(int key){
        return key%size;
    }
    int hash2(int key){
        int r = 97;
        return r - (key%r);
    }
    public:
    StudentHash(){
        for(int i=0;i<size;i++){
            Table[i]=NULL;
        }
    }
    void Insert_Record(int roll, string name){
        int h1 = hash1(roll);
        int h2 = hash2(roll);
        int index;
        int i=0;
        Node *newNode = new Node(roll,name);
        while(i<size){
            index = (h1 + i*h2 )%size;
            if(Table[index]==NULL){
                Table[index]=newNode;
                return;
            }
            if(Table[index]!=NULL && Table[index]->occupied==false){
                Table[index]->roll=roll;
                Table[index]->name=name;
                Table[index]->occupied=true;
                delete newNode;
                return;
            }
            i++;
        }
    }
    void Search_record(int roll){
        int h1  = hash1(roll);
        int h2 = hash2(roll);
        int index;
        int i=0;
        while(i<size){
            index = (h1 + h2*i)%size;
            if(Table[index]==NULL)  break;
            if(Table[index]!=NULL && Table[index]->occupied==true && Table[index]->roll==roll){
                cout<<"Student's name: "<<Table[index]->name<<endl;
                return;
            }
            i++;
        }
        cout<<"No record found"<<endl;
    }
    void delete_record(int roll){
        int h1 = hash1(roll);
        int h2 = hash2(roll);
        int index;
        int i=0;
        while(i<size){
            index = (h1 + i*h2)%size;
            if(Table[index]!=NULL && Table[index]->occupied==true && Table[index]->roll==roll){
                Table[index]->occupied=false;
                return;
            }
            i++;
        }
        cout<<"Student not found to delete"<<endl;
    }
};
int main(){
    StudentHash h1;
    
}