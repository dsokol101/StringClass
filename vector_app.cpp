#include <iostream>
#include <vector>
/**
 * This program demonstrates the use of std::vector in C++. It shows how to create a vector, check its size and capacity, and access its elements using both the subscript operator and the at() method. The program also highlights the difference between these two methods of accessing vector elements, particularly in terms of bounds checking.
 *
 * todo:
 * 1. show operator = (assignment operator)
 * 2. show operator == and operator !=
 * 3. show passing a vector as a parameter to a function
 * 4. show returning a vector from a function
 * 5. show iterating over a vector using a range-based for loop
 * 6. show iterating over a vector using an iterator
 * 7. show how to use the vector constructor that takes an initializer list
 * 8. show how to use the vector constructor that takes a size and a default value
 */
using namespace std;

int main()
{
    vector<double> v; // default constructed (on the stack)
    cout << "size of v before doing anything: " << v.size() << endl;
    cout << "capacity of default constructed vector: " << v.capacity() << endl;

    v.push_back(3.14);
    cout << "size of v after push_back: " << v.size() << endl;
    // can use [] on a vector
    cout << "v[0] = " << v[0] << endl;
    try
    {
        cout << "v[1] = " << v.at(1) << endl; // out of bounds access, but no error
    }
    catch (const out_of_range &e)
    {
    }
    v[0] = 1.1;
    // with using square brackets, the programmer is responsible to make sure
    // index is in bounds, otherwise we have undefined behavior.
    // With at(), we get an exception if index is out of bounds.

    vector<double> v2{1.0, 2.0, 3.0}; // using initializer list constructor
    v = v2;
    cout << "v after assignment: ";
    // standard for loop
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }   
    // change v and show that v2 is unchanged
    // range based for loop
    for (double elt: v)
    {
        cout << elt << " ";
    }   
    // using an iterator
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }   
    return 0;
}