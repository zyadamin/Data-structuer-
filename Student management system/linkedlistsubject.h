#ifndef LINKEDLISTSUBJECT_H
#define LINKEDLISTSUBJECT_H

#include <iostream>

using namespace std;
class linkedListSubject{

private:

public:
struct node{
string subjectName ;
int total;
 char grade ;
 float point;

node* next;
};

node* head;
node* tail;
int length=0;
public:

    linkedList(){

    head=tail=nullptr;
    length=0;
    }


  void insert(string subjectName ,int total,char grade ,float point){
    node* newNode=new node;
    newNode->subjectName=subjectName;
    newNode->total=total;
    newNode->grade  =grade ;
      newNode->point=point;

    if(length==0){
        tail=head=newNode;
        newNode->next=nullptr;
}
    else{
  newNode->next=nullptr;
  tail->next=newNode;
    tail=newNode;}
    length++;


}




void deletet(){
if(length==0){cout<<"the position out of limit"<<endl;}

else{

node* a=head;
node * c= new node();

for(int i=0;i<length;i++){
    c=a;
    a=a->next;
}

//a->next=c->next;
tail=c;
delete a;
length--;
}
}


node *gethead(){
return head;
}

 void print(){
node *c=new node;
c=head;
for(int i=0;i<size();i++){

    cout<<c->subjectName<<endl;
    cout<<c->total<<endl;
    cout<<c->grade<<endl;
     cout<<c->point<<endl;
    c=c->next;

}


}

int size(){
return length; }



};






#endif // LINKEDLISTSUBJECT_H
