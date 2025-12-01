#include<iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    Node(int val){
        data = val;
        next = NULL;
    }
    Node (){
        next = NULL;
    }
};
class List{
    public:
    Node *head;
    Node *tail;
    List(){
        head = tail =NULL;
    }
    void Inset_AT_End(int val){
        Node *newNode = new Node(val);
        if(head==NULL)  head = tail = newNode;
        else {
            tail->next = newNode;
            tail=newNode;
            tail->next = NULL;
        }
    }
    void print(){
        Node *iterator = head;
        while(iterator!=NULL){
            cout<<iterator->data<<"->";
            iterator=iterator->next;
        }
        cout<<"NULL"<<endl;
    }
    void reverse(Node *head1){
        if(head1 == NULL){
            return;
        }
        reverse(head1->next);
      cout<<head->data<<"->";
    }
    void reverse_iterator(){
        Node *temp1 = head->next;
        Node *temp2 = head;
        Node *prev = NULL;
        while(temp2!=NULL){
            if(temp2==head){
                temp2 ->next = NULL;
                tail = temp2;
                prev = temp2;
                temp2 = temp1;
                temp1 = temp1 -> next;
            }
            temp2 -> next = prev;
            prev = temp2 ;
            temp2 = temp1;
            if(temp1!=NULL) temp1 = temp1 -> next;
            head = prev;

        }

    }
};
int main(){
    List ll;
    ll.Inset_AT_End(1);
    ll.Inset_AT_End(2);
    ll.Inset_AT_End(3);
    ll.Inset_AT_End(4);
    ll.Inset_AT_End(5);
    ll.Inset_AT_End(6);
    ll.print();
    ll.reverse_iterator();
    ll.print();
}