#include <iostream>

using namespace std;
#include "linkedlistsubject.h"
#include "linkedliststudent.h"

int main()
{
   linkedListStudent a;
   a.insert();
   a.insert();

   a.deletet("zyad");
   a.print();

/*
mm cs 1
data 88 a 2
zyad cs 1
data 88 a 2
*/


    return 0;
}
