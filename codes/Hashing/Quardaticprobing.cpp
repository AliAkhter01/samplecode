#include<iostream>
using namespace std;
#define size 15
class Node{
    public:
    string name;
    int roll;
    bool occupied;
    Node (){
        occupied = false;
    }
    Node(int r, string n){
        name = n;
        roll = r;
        occupied= true;
    }

};
class StudentHashTable{
    private:
    Node *Table[size];
    public:
    StudentHashTable(){
        for(int i=0;i<size;i++){
            Table[i]=NULL;
        }
    }
    int HashFunction(int key){
        return key%size;
        }
    void Insert_Record(int roll, string name){
        int hash = HashFunction(roll);
        int index;
        Node *newNode = new Node(roll, name);
        int i =0;
        while(i<size){
            index = (hash + i*i)%size;
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
    void SearchRecord(int roll){
        int hash = HashFunction(roll);
        int index;
        int i=0;
            while(i<size){
                index = (hash+i*i)%size;
                if(Table[index]!=NULL && Table[index]->occupied==true && Table[index]->roll==roll){
                   cout<<"Student's name= "<<Table[index]->name<<endl;
                   return;
                }
                i++;
            }
            cout<<"No record Found"<<endl;
            return;
        }
    void delete_record(int roll){
        int hash = HashFunction(roll);
        int index;
        int i=0;
        while(i<size){
            index = (hash+i*i)%size;
            if(Table[index]!=NULL && Table[index]->occupied==true && Table[index]->roll==roll){
                Table[index]->occupied=false;
                cout<<"Record deleted"<<endl;
                return;
            }
            i++;
        }
        cout<<"Record doesn't exist"<<endl;
    }
        
};
int main(){
    StudentHashTable h;
    h.Insert_Record(10,"Ali");
    h.Insert_Record(12,"Rehan");
    h.Insert_Record(13,"Umer");
    h.Insert_Record(14,"Burney");
    h.SearchRecord(12);
    h.SearchRecord(10);
    h.SearchRecord(16);
    h.delete_record(14);
    h.SearchRecord(14);
}