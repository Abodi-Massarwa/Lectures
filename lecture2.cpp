#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

class Widget
{
    int* iptr;
    int x;
    //static int y=5; /// compile time error , static members must be initialized out of class

    static int y;
    /// static consts can be initialized in class !
    const static int khara=6; // good !
    // since they require allocation of memory independently from the class
    //const int z=5; // okay but bad style , we're used to define them in the init list
    const int z;
public:
    Widget(int x=3):x(4),z(5),iptr(new int(1337)){};
    //Widget();
    static int foo();

    //void k();




    ~Widget(){ delete iptr;
        std::cout<<"Widget instance destroyed \n";}
};
int Widget::y=5; // that is the right way to declare & define a static member !

//inline  -> .hpp
//outline -> .cpp

//Widget::Widget() {this->x=6;}
/*
 * //Widget::Widget() {this->x=6;}
 * multiple definition is considered as a Compilation time error
 *  its more than logical and fair enough
 *  since compiler needs to determine the definition that is gonna be impl'd in future
 *    https://ibb.co/L5MLJKz
 *
 */

/*
 * Linking time error is when suppose declared an outline member function and never provided a definition
 * it occurs only when someone calls that function in main()
 *https://ibb.co/8Xtc56v
 */

/*
 * Compiler's tasks :
 * NOTE: order doesn't matter:
 * 1) translate impl to binary/assembly
 * 2) validate legal coding (dividing by zero , providing impl when there is no decl in .hpp file  ......)
 *
 */
/*
 * NOTE : class isn't compiled only outline impl's are compiled
 * since they are compiled the compiler checks for the possibility of multiple definition ?
 */
/*
 *
 * compiler doesn't care about having an implementation
 * 1) if it already has in the block of declaration then let it be
 * 2) else assumes there is somewhere an implementation
 * 3) if there is no impl elsewhere then Linker drops the error
 */
/*compilation errors :
 * usually have file.cpp tag in them
 * and description of the exact line of the problem that caused the error
 *
 */
/*Linker errors :
 * usually have file.o / file.obj tag in them this means the file already passed compilation process
 * but fucked up at linking process
 *
 */
/*Runtime errors :
 * usually don't describe the file or the line of the problem since file is already compiled and linked and turned into a.out/ a.exe and all we have is a running process
 * for k*quantoms
 * most popular Runtime errors :
 * 1) core_dumped
 * 3) segsev (segmentation fault )
 * ..... etc
 *
 */

int Widget::foo()
{
    //return this->y; // bad style ! & doesn't compile ! static isn't dependant to an instance of this !
    return Widget::y; //GREAT !!
}


int main() {

   // Widget b;
//    Widget* a=new Widget();
//    free (a);
    //Widget* wp=&b;
    //delete(wp); //double deletions not always a good news since a is a stack variable
    /*
    wp=new Widget();
    delete wp;
     */

   // shared_ptr<Widget> wp1(new Widget); // auto destroyed doesn't require delete()
  //  auto_ptr<Widget> wp2(new Widget);
    //weak_ptr<Widget> wp3(new Widget());


/*
 * compiler cares more about : declaration > implementation (cares less)
 *
 *
 */
//Widget **widget_array= new Widget*[2];
//    for (int i = 0; i <2 ; ++i) {
//        widget_array[i]= new Widget;
//    }
//    for (int i = 0; i <2 ; ++i) {
//        delete widget_array[i];
//    }
//    delete []widget_array;
//
//shared_ptr<Widget> widget_array[2];
//shared_ptr<Widget>* widget_array;
//widget_array= new shared_ptr<Widget>[2];
//widget_array[0]=shared_ptr<Widget>(new Widget);
//widget_array[1]=shared_ptr<Widget>(new Widget);
//    delete [] widget_array;


    return 0;
}
