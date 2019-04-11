#ifndef DYNAMICBAG_H
#define DYNAMICBAG_H

#include <cstdlib>
#include <algorithm>
#include <iostream>

class dynamicBag
{
public:
    typedef std::size_t size_type;

    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty dynamicBag
    dynamicBag();

    // copy constructor  (NEW! Before we used the built-in one)
    // pre: none
    // post: creates a new dynamicBag which is a copy of the given one
    dynamicBag(const dynamicBag &);

    // constructor that creates a dynamicBag out of an array of integers
    // pre: size must match the size of the array
    // post: creates a new dynamicBag which is a copy of the array passed in
    dynamicBag(int a[], int sz);


    // pre: none    (NEW!  Our first destructor)
    // post: destroys this dynamicBag; needed because we are using
    //       dynamically allocated memory
    ~dynamicBag();

    // CONSTANT MEMBERS
    // pre: none
    // post: returns the number of elements in this dynamicBag
    size_type size() const;

    // pre: none
    // post: returns the number of times entry appears in this dynamicBag
    size_type count(int entry) const;

    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    int operator [](size_type pos) const;

    // MUTATING MEMBERS

    // pre: none
    // post: adds a copy of target to this dynamicBag
    void insert(int target);

    // pre: none
    // post: if new_capacity is at most the capacity of this dynamicBag,
    // then do nothing; otherwise, expand the capacity of this dynamicBag
    // to new_capacity
    void reserve(size_type new_capacity);

    // pre: none
    // post: adds to this dynamicBag a copy of each element of b
    //returns the modified object
    dynamicBag operator += (const dynamicBag & b);

    // pre: none
    // post: if target appears in this dynamicBag, remove one copy and
    //       return true; else return false

    bool erase_one(int target);

    // pre: none
    // post: removes every copy of target in this dynamicBag and
    //       returns the number of elements removed
    size_type erase(int target);

    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
   //returns the modified object
    dynamicBag operator =(const dynamicBag &b);

    void insertAt(int item, size_type index);

private:
    int *data_;
    size_type capacity_;
    size_type used_;

    // INVARIANTS:
    //   data_ points a dynamically allocated array of size capacity_
    //   data_[0], data_[1], ..., data_[used_-1] store the elements
    //   of this dynamicBag
    //   we don't care about data_[used_], ..., data_[capacity_]


};

// pre: none
// post: returns the sum of a and b
dynamicBag operator +(const dynamicBag & a, const dynamicBag & b);
// pre: none
// post: prints out all of the elements of b in order.
std::ostream& operator <<(std::ostream&  out, const dynamicBag& b);

#endif // DYNAMICBAG_H
