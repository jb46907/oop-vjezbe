#include <cstddef>
#include <iostream>
struct MyVector
{
    int* arr;
    int size = 0;
    int capacity = 0;

    // member functions
    void vector_new();
    void vector_delete();
    void vector_push_back(int n);/* adds a new element at the end of the vector */
    void vector_pop_back();/* removes the last element in the vector */
    int& vector_front();/* returns a reference to the first element in the vector*/
    int& vector_back(); /* returns a reference to the last element in the vector */
    int vector_size(); /* returns the number of the elements in the vector */

    void print_vector();
};
