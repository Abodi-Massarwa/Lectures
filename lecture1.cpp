//
// Created by abdms on 07/07/2020.
//
/*
 * in this file we summarize how compiler works with functions
 *
 *
 *
 */

int foo(int x=5)
{
    return 0;
}

/*
 * this foo is the same as foo() & foo(x)
 */
template <class T>
void temp(T a)
{
    return;
}
template <> void temp<char>(char a)
{
    return;
}
/*
 * templates aren't compiled till someone calls them !
 * but the specialization is dealt with same as a normal function (it compiles although it's called or not)
 */

/*
 *
 * compiler
 * 1) searches for functions with the same name
 * 2) filters out according to number of arguments
 * 3) filters out according to the type of args
 * and that's how compiler knows what function we are trying to call
 *
 */
int main()
{
    foo();
    foo(5);
    temp(5); //comiled once called
    temp('a');//compiled even without calling it in main !

}