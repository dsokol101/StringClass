#include <string>
#include <iostream>
using namespace std;

int main() {
    // 3 equivalent ways to initialize a string
    string s1 = "Hello, ";
    string s2("World!");
    string s3{"good bye."};
    // default constructor creates an empty string
    string s4{};
    string s5;

    cout << "s1: " << s1 << endl;
    cout << "length of s4: " << s4.length() << endl;
    cout << "s5: " << s5 << endl;
    cout << "length of s5: " << s5.length() << endl;


    // let's take a look at some operators that we can use on strings
    cout << "0th char in s1: " << s1[0] << endl;
    s1[0] = 'h'; // you can modify a string using the [] operator

    cout << s1 + s2 << endl; // you can concatenate strings using the + operator
    s1 += s2; // you can also concatenate using the += operator

    // assignment operator
    s3 = s1;
    // comparison operators
    // in Java we use .equals() to compare strings, but in C++ we can use == and !=
    if (s1 == s3) { 
        cout << "s1 and s3 are equal" << endl;
    } else {
        cout << "s1 and s3 are not equal" << endl;
    }   
    // in Java, we have to use compareTo() to order strings, but in C++ we can use <, >, <=, >=
    if (s1 < s2) { 
        cout << s1 << " is less than " << s2 << endl;
    }
    
    return 0;
}