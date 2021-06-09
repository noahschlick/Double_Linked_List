//
//  main.cpp
//  Proj1_DS
//
//  Created by Noah Schlickeisen on 2/16/21.
//
//

#include <iostream>
#include "linkedlist.h"
#include <cstdlib>
#include <assert.h>
using namespace std;

int main()
{
    // insert code here...
    LinkedList<int> ll;
    
    for (int i = 0; i < 10; i++)
    {
        ll.insert(i);
    }
    
    cout << "length: " << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "rm 5 " << ll.remove(5) << endl;
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "rm 0 " << ll.remove(0) << endl;
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "rm 9 " << ll.remove(9) << endl;
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    for (int i = 0; i < 10; i++)
    {
        cout << "rm " << i << " " << ll.remove(i) << endl;
        ll.print_forwards();
        ll.print_backwards();
    }
    
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    for (int i = 9; i >= 0; i--)
    {
        ll.insert(i);
    }
    
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "add -1 " << endl;
    ll.insert(-1);
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "add 100 " << endl;
    ll.insert(100);
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "add 4 " << endl;
    ll.insert(4);
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    
    cout << "rm 4 " << ll.remove(4) << endl;
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "rm 4 " << ll.remove(4) << endl;
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    
    cout << "rm 4 " << ll.remove(4) << endl;
    cout << ll.length() << endl;
    ll.print_forwards();
    ll.print_backwards();
    cout << "last elem "<< ll.getLast() <<endl;
    
    LinkedList<double> *pll = new LinkedList<double>;
    
    for (int i = 0; i < 10000; i++)
    {
        pll->insert(i*17.4);
    }
    delete pll;
    pll = NULL;
    
    return 0;
}
