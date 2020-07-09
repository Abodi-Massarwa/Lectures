//
// Created by abdms on 07/07/2020.
//

#include <iostream>
using namespace std;
//void foo(int& i)
//{
//
//}
//void foo(const int& i)
//{
//
//}
//
//int main()
//{
//    // normal number not allocated in stack or heap is considered to be const -rvalue
//
//    foo(7);
//    int x=7;
//    foo(x);
///*
// * Summary:
// *
// * L-value : is a value that is allocated by variable in memory(stack/heap) : ex: int x=7; foo(x);
// * R-value : is a "temp" value not assigned to any kind of secture in memory ex: foo(7);
// *
// * DONE !
// *
// *
// */
//}
class A
{
public :

    A(){}
    void foo()const///void foo(const A * const)
    {
        A* temp_ptr=const_cast<A*const>(this);
        temp_ptr->foo();


    }
    void foo()// void foo( A * const)
    {
    std::cout<<"successfully hacked you motherfucker";
    }

};
ostream& operator <<(ostream& out,A& a)
{
    out<<"oday\n";
    return out;
}
//int& f(int& x){return ++x;}
int main()
{
    A a1;
    A a2;
   // a1.foo();
    cout<<a1;
//    int var=5;
//     const int* x=&var;
//    int* y= const_cast<int*>(x);
//    *y=1337;
//    std::cout<<*x;




//const A a;
//a.foo();
}
/*
 * every object can access a const member function since it upper-casts the non consts to const in the worst case scenario
 * unlike the non const member function they only accept non-const objects !!
 */