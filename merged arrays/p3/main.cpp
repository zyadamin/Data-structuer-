#include <iostream>
using namespace std;
void In_place merge(int A1[],int Size1,int A2[],int Size2){

  for(int i=0;i<Size2;i++){
  for(int j=0;j<Size1;j++){
        if(A1[j]>A2[i]){
swap(A1[j],A2[i]);
   }
  }
  }
  for(int i=0;i<Size1-1;i++){
  for(int j=0;j<Size1-1;j++){
        if(A1[j]>A1[j+1]){
    swap(A1[j],A1[j+1]);}

  }
  }
  for(int i=0;i<Size2-1;i++){
  for(int j=0;j<Size2-1;j++){
        if(A2[j]>A2[j+1]){
    swap(A2[j],A2[j+1]);}

  }
  }

cout<<"[1]"<<" ";
for(int i=0;i<Size1;i++){

    cout<<A1[i]<<" ";}

    cout<<endl;
cout<<"[2]"<<" ";

for(int i=0;i<Size2;i++){

cout<<A2[i]<<" ";}

}
int main()
{
int *A1,*A2;
int x1=0,x2=0;
cout<<"enter Size of A1=";
cin>>x1;
cout<<"enter Size of A2=";
cin>>x2;
A1=new int[x1];
A2=new int[x2];
cout<<"enter First array:"<<endl;
for(int i=0;i<x1;i++){
    cin>>A1[i];
}
cout<<"enter second array:"<<endl;
for(int i=0;i<x2;i++){
    cin>>A2[i];
}
cout<<"Sorted arrays is:"<<endl;
 In_place merge(A1,x1,A2,x2);


    return 0;
}
