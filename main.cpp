#include "Entity/Entity.hpp"
#include "List/List.hpp"
#include <list>
#include <iostream>
#include <cmath>
#include <list>

bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};


int main() {
  //  {
  //    ft::list<Entity> abc2;
  //    Entity *entity = new Entity(1);
  //
  //    abc2.push_front(*entity);
  //    abc2.push_front(Entity(2));
  //    abc2.push_front(Entity(3));
  //    abc2.push_front(Entity(4));
  //    abc2.push_front(Entity(5));
  //
  //    ft::list<Entity>::iterator first = abc2.begin();
  //    ft::list<Entity>::iterator last = abc2.end();
  //    for (int i = 0; i < 8; i++) {
  //      std::cout << *last << std::endl;
  //      --last;
  //    }
  //  }
  //  {
  //    std::cout << "\nstd:\n" << std::endl;
  //
  //    std::list<Entity> abc2;
  //    Entity *entity = new Entity(1);
  //    abc2.push_front(*entity);
  //    abc2.push_front(Entity(2));
  //    abc2.push_front(Entity(3));
  //    abc2.push_front(Entity(4));
  //    abc2.push_front(Entity(5));
  //    delete entity;
  //    std::list<Entity>::iterator first = abc2.begin();
  //    std::list<Entity>::iterator last = abc2.end();
  //    for (int i = 0; i < 8; i++) {
  //      std::cout << *last << std::endl;
  //      --last;
  //    }
  //  }
  //
  //  {
  //    ft::list<int> first(3, 100);  // three ints with a value of 100
  //    ft::list<int> second(5, 200); // five ints with a value of 200
  //
  //    first.swap(second);
  //
  //    std::cout << "first contains:";
  //    for (ft::list<int>::iterator it = first.begin(); it != first.end();
  //    it++)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //    std::cout << "second contains:";
  //    for (ft::list<int>::iterator it = second.begin(); it != second.end();
  //    it++)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //  }
  //  {
  //    std::list<int> first(3, 100);  // three ints with a value of 100
  //    std::list<int> second(5, 200); // five ints with a value of 200
  //
  //    first.swap(second);
  //
  //    std::cout << "first contains:";
  //    for (std::list<int>::iterator it = first.begin(); it != first.end();
  //    it++)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //    std::cout << "second contains:";
  //    for (std::list<int>::iterator it = second.begin(); it != second.end();
  //    it++)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //  }
  //  {
  //    ft::list<int> mylist;
  //
  //    // set some initial content:
  //    for (int i=1; i<10; ++i) mylist.push_back(i);
  //
  //    mylist.resize(5);
  //    mylist.resize(7,100);
  //    mylist.resize(12);
  //
  //    std::cout << "mylist contains:";
  //    for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //
  //    std::cout << '\n';
  //  }
  //  {
  //    std::list<int> mylist;
  //
  //    // set some initial content:
  //    for (int i=1; i<10; ++i) mylist.push_back(i);
  //
  //    mylist.resize(5);
  //    mylist.resize(7,100);
  //    mylist.resize(12);
  //
  //    std::cout << "mylist contains:";
  //    for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //
  //    std::cout << '\n';
  //
  //  }
  //  {
  //    ft::list<int> mylist;
  //    ft::list<int>::iterator it;
  //
  //    mylist.push_back (100);
  //    mylist.push_back (200);
  //    mylist.push_back (300);
  //
  //    std::cout << "mylist contains:";
  //    for (it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //    mylist.clear();
  //    mylist.push_back (1101);
  //    mylist.push_back (2202);
  //
  //    std::cout << "mylist contains:";
  //    for (it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //  }
  //  {
  //    std::list<int> mylist;
  //    std::list<int>::iterator it;
  //
  //    mylist.push_back (100);
  //    mylist.push_back (200);
  //    mylist.push_back (300);
  //
  //    std::cout << "mylist contains:";
  //    for (it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //    mylist.clear();
  //    mylist.push_back (1101);
  //    mylist.push_back (2202);
  //
  //    std::cout << "mylist contains:";
  //    for (it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //  }
  //  {
  //    ft::list<int> mylist1, mylist2;
  //    ft::list<int>::iterator it;
  //
  //    // set some initial values:
  //    for (int i=1; i<=4; ++i)
  //      mylist1.push_back(i);      // mylist1: 1 2 3 4
  //
  //    for (int i=1; i<=3; ++i)
  //      mylist2.push_back(i*10);   // mylist2: 10 20 30
  //
  //    it = mylist1.begin();
  //    ++it;                         // points to 2
  //
  //    mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
  //    // mylist2 (empty)
  //    // "it" still points to 2 (the 5th element)
  //
  //    mylist2.splice (mylist2.begin(),mylist1, it);
  //    // mylist1: 1 10 20 30 3 4
  //    // mylist2: 2
  //    // "it" is now invalid.
  //    it = mylist1.begin();
  //    std::advance(it,3);           // "it" points now to 30
  //
  //    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
  //    // mylist1: 30 3 4 1 10 20
  //
  //    std::cout << "mylist1 contains:";
  //    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //    std::cout << "mylist2 contains:";
  //    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //  }
  //  {
  //    std::list<int> mylist1, mylist2;
  //    std::list<int>::iterator it;
  //
  //    // set some initial values:
  //    for (int i=1; i<=4; ++i)
  //      mylist1.push_back(i);      // mylist1: 1 2 3 4
  //
  //    for (int i=1; i<=3; ++i)
  //      mylist2.push_back(i*10);   // mylist2: 10 20 30
  //
  //    it = mylist1.begin();
  //    ++it;                         // points to 2
  //
  //    mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
  //    // mylist2 (empty)
  //    // "it" still points to 2 (the 5th element)
  //
  //    mylist2.splice (mylist2.begin(),mylist1, it);
  //    // mylist1: 1 10 20 30 3 4
  //    // mylist2: 2
  //    // "it" is now invalid.
  //    it = mylist1.begin();
  //    std::advance(it,3);           // "it" points now to 30
  //
  //    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
  //    // mylist1: 30 3 4 1 10 20
  //
  //    std::cout << "mylist1 contains:";
  //    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //    std::cout << "mylist2 contains:";
  //    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //
  //  }
  //  {
  //    int myints[]= {17,89,7,14};
  //    ft::list<int> mylist;
  //
  //    mylist.push_front(myints[0]);
  //    mylist.push_front(myints[1]);
  //    mylist.push_front(myints[2]);
  //    mylist.push_front(myints[3]);
  //
  //    mylist.remove(14);
  //    mylist.remove(7);
  //
  //    std::cout << "mylist contains:";
  //    for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //  }
  //  {
  //    int myints[]= {17,89,7,14};
  //    std::list<int> mylist;
  //
  //    mylist.push_front(myints[0]);
  //    mylist.push_front(myints[1]);
  //    mylist.push_front(myints[2]);
  //    mylist.push_front(myints[3]);
  //
  //    mylist.remove(14);
  //    mylist.remove(7);
  //
  //    std::cout << "mylist contains:";
  //    for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
  //      std::cout << ' ' << *it;
  //    std::cout << '\n';
  //  }
//  {
//    ft::list<int> mylist;
//
//    for (int i = 1; i < 10; ++i)
//      mylist.push_back(i);
//
//    mylist.reverse();
//
//    std::cout << "mylist contains:";
//    for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//      std::cout << ' ' << *it;
//
//    std::cout << '\n';
//  }
//  {
//    std::list<int> mylist;
//
//    for (int i = 1; i < 10; ++i)
//      mylist.push_back(i);
//
//    mylist.reverse();
//
//    std::cout << "mylist contains:";
//    for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//      std::cout << ' ' << *it;
//
//    std::cout << '\n';
//  }
//  {
//    ft::list<int> first;
//    ft::list<int> second;
//
//    first.assign (7,100);                      // 7 ints with value 100
//
//    second.assign (first.begin(),first.end()); // a copy of first
//
//    int myints[]={1776,7,4};
//    first.assign(myints,myints+3);            // assigning from array
//
//    std::cout << "Size of first: " << int (first.size()) << '\n';
//    std::cout << "Size of second: " << int (second.size()) << '\n';
//  }
//  {
//    std::list<int> first;
//    std::list<int> second;
//
//    first.assign (7,100);                      // 7 ints with value 100
//
//    second.assign (first.begin(),first.end()); // a copy of first
//
//    int myints[]={1776,7,4};
//    first.assign (myints,myints+3);            // assigning from array
//
//    std::cout << "Size of first: " << int (first.size()) << '\n';
//    std::cout << "Size of second: " << int (second.size()) << '\n';
//    return 0;
//  }
//  {
//    ft::list<int> mylist1, mylist2;
//    ft::list<int>::iterator it;
//
//    // set some initial values:
//    for (int i=1; i<=4; ++i)
//      mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//    for (int i=1; i<=3; ++i)
//      mylist2.push_back(i*10);   // mylist2: 10 20 30
//
//    it = mylist1.begin();
//    ++it;                         // points to 2
//
//    mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
//    // mylist2 (empty)
//    // "it" still points to 2 (the 5th element)
//
//    mylist2.splice (mylist2.begin(),mylist1, it);
//    // mylist1: 1 10 20 30 3 4
//    // mylist2: 2
//    // "it" is now invalid.
//    it = mylist1.begin();
//    std::advance(it,3);           // "it" points now to 30
//
//    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//    // mylist1: 30 3 4 1 10 20
//
//    std::cout << "mylist1 contains:";
//    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    std::cout << "mylist2 contains:";
//    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//  }
//  {
//    std::list<int> mylist1, mylist2;
//    std::list<int>::iterator it;
//
//    // set some initial values:
//    for (int i=1; i<=4; ++i)
//      mylist1.push_back(i);      // mylist1: 1 2 3 4
//
//    for (int i=1; i<=3; ++i)
//      mylist2.push_back(i*10);   // mylist2: 10 20 30
//
//    it = mylist1.begin();
//    ++it;                         // points to 2
//
//    mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
//    // mylist2 (empty)
//    // "it" still points to 2 (the 5th element)
//
//    mylist2.splice (mylist2.begin(),mylist1, it);
//    // mylist1: 1 10 20 30 3 4
//    // mylist2: 2
//    // "it" is now invalid.
//    it = mylist1.begin();
//    std::advance(it,3);           // "it" points now to 30
//
//    mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
//    // mylist1: 30 3 4 1 10 20
//
//    std::cout << "mylist1 contains:";
//    for (it=mylist1.begin(); it!=mylist1.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    std::cout << "mylist2 contains:";
//    for (it=mylist2.begin(); it!=mylist2.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    return 0;
//  }
//  {
//    std::list<std::string> mylist;
//    std::list<std::string>::iterator it;
//    mylist.push_back ("two");
//    mylist.push_back ("one");
//    std::cout << "mylist contains:";
//    for (it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//    mylist.sort();
//
//    std::cout << "mylist contains:";
//    for (it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    mylist.sort(compare_nocase);
//
//    std::cout << "mylist contains:";
//    for (it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//  }
//  std::cout << '\n';
//
//  {
//    ft::list<std::string> mylist;
//    ft::list<std::string>::iterator it;
//    mylist.push_back ("two");
//    mylist.push_back ("one");
//    std::cout << "mylist contains:";
//    for (it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//    mylist.sort();
//
//    std::cout << "mylist contains:";
//    for (it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    mylist.sort(compare_nocase);
//
//    std::cout << "mylist contains:";
//    for (it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//  }
//  {
//    int myints[]= {15,36,7,17,20,39,4,1};
//    std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
//
//    mylist.remove_if (single_digit);           // 15 36 17 20 39
//
//   mylist.remove_if (is_odd());               // 36 20
//
//    std::cout << "mylist contains:";
//    for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//  }
//  {
//    int myints[]= {15,36,7,17,20,39,4,1};
//    ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
//
//    mylist.remove_if (single_digit);           // 15 36 17 20 39
//
//    mylist.remove_if (is_odd());               // 36 20
//
//    std::cout << "mylist contains:";
//    for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//  }
  {
    double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                         12.77, 73.35, 72.25, 15.3,  72.25 };
    std::list<double> mylist (mydoubles,mydoubles+10);

    mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
    // 15.3,  72.25, 72.25, 73.0,  73.35

    mylist.unique();           //  2.72,  3.14, 12.15, 12.77
    // 15.3,  72.25, 73.0,  73.35

    mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
    // 15.3,  72.25, 73.0

    mylist.unique (is_near());           //  2.72, 12.15, 72.25

    std::cout << "mylist contains:";
    for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
//  {
//    double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
//                         12.77, 73.35, 72.25, 15.3,  72.25 };
//    std::list<double> mylist (mydoubles,mydoubles+10);
//
//    mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
//    // 15.3,  72.25, 72.25, 73.0,  73.35
//
//    mylist.unique();           //  2.72,  3.14, 12.15, 12.77
//    // 15.3,  72.25, 73.0,  73.35
//
//    mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
//    // 15.3,  72.25, 73.0
//
//    mylist.unique (is_near());           //  2.72, 12.15, 72.25
//
//    std::cout << "mylist contains:";
//    for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
//      std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    return 0;
//  }
  return 0;
}

