#include <iostream>
#include "Header.h"

int main()
{
    my_deque<int> list;

    list.push_back(0);
    list.push_back(4);
    list.push_back(3);
    list.push_back(5);
    list.push_back(9);
 
   

    list.show_list();
    cout << list.size() << endl;
   
    list.push_front(228);

    list.show_list();
    cout << list.size() << endl;

  
}

