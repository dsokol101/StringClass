# C++ `string` and `vector` Examples

This repository contains two example programs demonstrating the use of the C++ Standard Library classes `string` and `vector`.

## `string` Example

The string program demonstrates:

- Different ways to construct and initialize a `string`
- The default constructor and empty strings
- Finding the length of a string with `length()`
- Accessing and modifying individual characters using `[]`
- Concatenating strings with `+` and `+=`
- Assigning one string to another with `=`
- Comparing strings using `==`, `!=`, `<`, `>`, `<=`, and `>=`

### C++ vs. Java

Unlike Java, C++ allows the usual comparison operators to be used with strings:

```cpp
if (s1 == s2)
```

instead of Java's `s1.equals(s2)`.

Similarly, strings can be ordered using operators such as `<` rather than Java's `compareTo()`.

---

## `vector` Example

A `vector` is a container that stores a sequence of elements and can grow dynamically.

The vector program demonstrates:

- Default construction of an empty `vector`
- `size()` and `capacity()`
- Adding elements with `push_back()`
- Accessing elements with `[]` and `at()`
- The difference between unchecked `[]` access and bounds-checked `at()`
- Assigning one vector to another with `=`
- Comparing vectors with `==` and `!=`
- Iterating through a vector using:
  - a traditional `for` loop
  - a range-based `for` loop
  - an iterator
- Passing a vector by value
- Passing a vector by reference

### Pass by Value vs. Pass by Reference

Passing a vector **by value** makes a copy:

```cpp
void print_vec(vector<double> v);
```

Changes to `v` inside the function do not affect the original vector.

Passing a vector **by reference** avoids making a copy and allows the function to modify the original vector:

```cpp
void increment_vec(vector<double>& v);
```

If a function should avoid copying the vector but should **not** modify it, use a `const` reference:

```cpp
void print_vec(const vector<double>& v);
```