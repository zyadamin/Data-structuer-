#ifndef LINKEDLISTSTUDENT_H
#define LINKEDLISTSTUDENT_H
#include "linkedlistsubject.h"
#include <iostream>

using namespace std;


class linkedListStudent{

protected:
struct node{
 string name;
 string department ;
 int numberCourses ;

linkedListSubject courses ;
node* next;
};



node*head;
node *tail;

int length=0;

public:

    linkedList(){

    head=tail=nullptr;
    length=0;

    }

    void insert(){
        string name;string department ;int numberCourses;
cin>>name>>department>>numberCourses;
    node* newNode=new node;
    newNode->name=name;
    newNode->department=department;
    newNode->numberCourses=numberCourses;


    if(length==0){
        tail=head=newNode;
        newNode->next=nullptr;

    }else{
 newNode->next=nullptr;
  tail->next=newNode;
    tail=newNode;

    }

    for(int i=0;i<numberCourses;i++){
     string subjectName ;int total;char grade ;float point;
    cin>> subjectName >> total>> grade>> point;
newNode-> courses.insert ( subjectName , total, grade , point);

    }

    length++;


}

////////////
void deletet(string name){
if(length==0){cout<<"the position out of limit"<<endl;}

else{
node *c=new node;

if(name==head->name){
    node* cur = head;
    head=head->next;
    c=cur;
}

 else{
     node*p=head;
     node*cur=head->next;
     for(int i=0;i<size();i++){
        if(name==cur->name)
        {
           p->next=cur->next ;
         c=cur;
           break;
        }
        else{


            p=cur;
            cur=cur->next;
        }
     }
     }

for(int i=0;i<c->courses.size();i++){
c->courses.deletet();
}

delete c->courses.gethead();

delete c;

length--;

}
}

///////////////




void print(){
node * c=new node;
c=head;
for(int i=0;i<size();i++){

    cout<<c->name<<endl;
    cout<<c->department<<endl;
    cout<<c->numberCourses<<endl;
    cout<<"courses"<<endl;
    cout<<"------------------"<<endl;
  c->courses.print();
    c=c->next;

}
cout<<endl;




}
int size(){
return length; }



};

#endif // LINKEDLISTSTUDENT_H
