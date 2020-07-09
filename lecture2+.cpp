//
// Created by abdms on 07/07/2020.
//
class A{}; //~~ class A{}; //empty
class B;
void foo();
/// hide function
class uncopyable
{
public:
    uncopyable();

private:
    uncopyable(uncopyable&){}
   uncopyable& operator=(const uncopyable&){}
};
class Widget: public uncopyable
{
public:
    Widget(){}
};
class Widget1
{
public:
    Widget1(){}

private:
    Widget1(Widget1& ){}
    Widget1& operator=(const Widget1&){}
};
class Widget2
{
public:
    Widget2(){}
    Widget2(Widget2& )=delete ;
    Widget2& operator=(const Widget2&)=delete ;
};
class Widget3: public uncopyable
{
public:
    Widget3(){}
    Widget3(Widget3& other){}
    Widget3& operator=(const Widget3&){}
};

//void shit(const int& a){return;}


int main(){
   // A b(); //simulates an empty class
    //foo(); // linkage error
    /*
    Widget a; // created
    Widget b;
    a=b; //compilation error
     */
    /*
    Widget1 a;
    Widget1 b;
    a=b;
     */


    /*
    Widget2 a;
    Widget2 b;
    a=b;
     */

    /*
    1)private decl
    2) inhrt
    3) =delete
*/

    // lets try to make it give us a linkage error ! /// success
/*
   Widget3 a;
   Widget3 b;
   a=b;
*/
//int x=5;
//shit(x);
//shit(1337); // 1337 -> const int


    return 0;

};
