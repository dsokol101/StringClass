#include <iostream>
#include <vector>
/**
 * This program demonstrates the use of std::vector in C++. It shows how to create a vector, check its size and capacity, and access its elements using both the subscript operator and the at() method. The program also highlights the difference between these two methods of accessing vector elements, particularly in terms of bounds checking.
 *
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
void print_vec(vector<double> v);
void increment_vec(vector<double> &v);

void print_vecV2(const vector<double> &v)
{
   // this would cause an error:  increment_vec(v);
    for (double elt : v)
    {
        cout << elt << " ";
    }
    cout << endl;
}   
// pass by value, so we get a copy of the vector
void print_vec(vector<double> v)
{
    for (double elt : v)
    {
        cout << elt << " ";
    }
    cout << endl;
    v.clear(); // this does not affect the original vector in main() because we have a copy of the vector in this function
}
// pass by reference, so we get a reference to the original vector
void increment_vec(vector<double> &v)
{
    for (double &elt : v)
    {
        elt += 1.0; // this modifies the original vector in main() because we have a reference to the original vector
    }       
}

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
    v[0] = 1.1; // lvalue
    // with using square brackets, the programmer is responsible to make sure
    // index is in bounds, otherwise we have undefined behavior.
    // With at(), we get an exception if index is out of bounds.

    vector<double> v2{1.0, 2.0, 3.0}; // using initializer list constructor
    v = v2;
    cout << "\nv after assignment: ";
    // standard for loop
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    // change v and show that v2 is unchanged
    v[0] = 10.0;
    cout << "\nv after modifying v[0]: ";
    // range based for loop
    for (double elt : v)
    {
        cout << elt << " ";
    }
    cout << "\nv2 after modifying v: ";
    // using an iterator
    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << " ";
    }
    // comparing vectors using == and !=
    if (v == v2)
    {
        cout << "\nv and v2 are equal" << endl;
    }
    else
    {
        cout << "\nv and v2 are not equal" << endl;
    }   
    return 0;
}