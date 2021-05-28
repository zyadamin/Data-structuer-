#include <iostream>
#include<stack>

using namespace std;

bool check(char open,char close){//check if there two paired bracket or not

    if(open=='('&&close==')'){return true;}

    else if(open=='{'&&close=='}'){return true;}

    else if(open=='['&&close==']'){return true;}

return false;
}

bool Balanced_String(string exp){

stack<char>s;//store brackets

for(int i=0;i<exp.size();i++){

    if (exp[i]== '(' || exp[i]=='['|| exp[i]=='{'){
         s.push(exp[i]);
    }
  else if (exp[i]==')'||exp[i]==']'||exp[i]=='}'){

    if(s.empty()==true||check(s.top(),exp[i])==false){

            return false;
    }

    else{s.pop();}
    }

 }

 if(s.empty()==true){
     return true;
 }

 else{return false;}


}





int main()
{
    string exp;
    cout<<"enter your expression :"<<endl;
    cin>>exp;
    if(Balanced_String(exp)){
        cout<<"balance"<<endl;
    }
    else{
       cout<<"Not balance"<<endl;

    }
    return 0;
}
