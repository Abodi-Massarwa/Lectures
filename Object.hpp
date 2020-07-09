//
// Created by Abodi Msarwi on 09/07/2020.
//

#ifndef EXAMS_OBJECT_HPP
#define EXAMS_OBJECT_HPP


#include <string>
#include <iostream>
using namespace std;
class Object {
int* arr;
string word;
size_t id;
size_t size;
public:
    static int counter;
    Object(int size=10):size(size),arr(new int[size]),word("abodi"),id(counter++){}
    void resize()
    {
        int old_size=size;
        size+=10;
        int* arr_new= new int[size];
        for (int i = 0; i <old_size ; ++i)
        {
            arr_new[i]=this->arr[i];
        }
        delete[] this->arr;
        this->arr= arr_new;

    }
    int& operator[](size_t x){return this->arr[x];}
    ~Object(){delete []arr; cout<<"\nobject: "<<id<< "has been deleted\n";}

};


#endif //EXAMS_OBJECT_HPP
