#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
template<class T>
class Binary_tree{

struct node{

T item;
node * right;
node* left;

};


int hightHElper(node * nodee){

if(nodee==nullptr){return -1;}

int right=hightHElper(nodee->right);

int left=hightHElper(nodee->left);


if(left>=right){return left+1;}
else{return right+1;}
}


void flip2(node*cur){
node*c=cur;
c=cur->left;
cur->left=cur->right;
cur->right=c;
if(cur->left!=nullptr){
flip2(cur->left);}
if(cur->right!=nullptr){
flip2(cur->right);
}
}

void sum(node*cur,vector<int>v,long long & summ){
        v.push_back(cur->item);
if(cur->left!=nullptr&&cur->right!=nullptr){
sum(cur->left,v,summ);
sum(cur->right,v,summ);
}
else if(cur->left!=nullptr&&cur->right==nullptr){
sum(cur->left,v,summ);
}
else if(cur->left==nullptr&&cur->right!=nullptr){
sum(cur->right,v,summ);
}
else if(cur->left==nullptr&&cur->right==nullptr){

   long long w=1;
   long long y=0;

   for(int i=v.size()-1;i>=0;i--){
    y+=v[i]*w;
    w=w*10;

   }
summ+=y;
}
}

node* root;
int length;

public:

Binary_tree(){

length=0;
root=nullptr;
}

node* getRoot(){

return root;
}

int size(){
return length;
}

void insert(T item){
 node* newNode = new node();
 newNode->item=item;

if(length==0){
root=newNode;
}

else{

node* cur= new node();
cur=root;

while(true){

if(cur->item<item){

if(cur->right==nullptr){
cur->right=newNode;
break;
}
cur=cur->right;
}

else{

if(cur->left==nullptr){
cur->left=newNode;
break;
}
cur=cur->left;
}
}

newNode->left=newNode->right=nullptr;
}


length++;
}



void delete1(T item){

node* cur=new node();
node* pre=new node();
cur=root;

while(cur->left!=nullptr||cur->right!=nullptr){

if(cur->item==item){break;}

else if(cur->item<item){
pre=cur;
cur=cur->right;
}
else{
pre = cur;
cur=cur->left;
}

}

if(cur->left==nullptr&&cur->right==nullptr){

if(pre->item<item){
pre->right=nullptr;
}
else{pre->left=nullptr;}
delete cur;
length--;
}

else if(cur->left!=nullptr&&cur->right==nullptr){
if(pre->item<item){pre->right=cur->left;}
else{pre->left=cur->left;}
delete cur;
length--;
}

else if(cur->right!=nullptr&&cur->left==nullptr){
if(pre->item<item){pre->right=cur->right;}
else{pre->left=cur->right;}
delete cur;
length--;
}


else if(cur->left!=nullptr&&cur->right!=nullptr){

node* now=new node();
now=cur->left;

while(now->right!=nullptr){
now=now->right;
}

int value=now->item;
delete1(now->item);
cur->item=value;

}


}


void printPreorder(node* p){

if(p !=nullptr){
cout<<p->item<<" ";
printPreorder(p->left);
printPreorder(p->right);
}

}


void printInorder(node* p){

if(p !=nullptr){
printInorder(p->left);
cout<<p->item<<" ";
printInorder(p->right);
}

}

void printPostorder(node* p){

if(p !=nullptr){
printPostorder(p->left);
printPostorder(p->right);
cout<<p->item<<" ";
}

}


void flip(){
node*cur=root;
flip2(cur);
}



void largestValues(){

int max1=-1;

queue<node*>q;
vector<node*>x;
x.push_back(root);

for(int j=0;j<hight()+1;j++){

while(!q.empty()){
x.push_back(q.front());
q.pop();
}

for(int i=0;i<x.size();i++){

if(x[i]->left!=nullptr){q.push(x[i]->left);}

if(x[i]->right!=nullptr){q.push(x[i]->right);}

if( max1 < x[i]->item){ max1= x[i]->item;}

}


x.clear();
cout<<max1<<" ";
max1=-1;
}
cout<<endl;
}


void BranchesSum(){
node*cur=root;
vector<int>v;
long long summ=0;

sum(cur,v,summ);
cout<<summ<<endl;
}



int hight(){

if(root==nullptr){return -1;}

else{return hightHElper(root);}

}

};



int main()
{
Binary_tree<int> x1;

x1.insert(10);
x1.insert(5);
x1.insert(14);
x1.insert(1);
x1.insert(7);
x1.insert(12);
x1.insert(16);
x1.insert(13);
x1.insert(20);
x1.insert(25);


cout<<"Preorder"<<endl;
x1.printPreorder(x1.getRoot());
cout<<endl;cout<<endl;

cout<<"Inorder"<<endl;
x1.printInorder(x1.getRoot());
cout<<endl;cout<<endl;

cout<<"Postorder"<<endl;
x1.printPostorder(x1.getRoot());
cout<<endl;cout<<endl;


cout<<"flip"<<endl;
x1.flip();
x1.printPreorder(x1.getRoot());
cout<<endl;cout<<endl;


cout<<"largestValues"<<endl;
x1.largestValues();
cout<<endl;cout<<endl;

cout<<"BranchesSum"<<endl;
x1.BranchesSum();
cout<<endl;cout<<endl;



    return 0;

}
