#ifndef VECTOR_H
#define VECTOR_H

template <typename T>

class Vector
{

  T *array;
  int count;
  int size;

public:

  Vector(int sz): count(0), size(sz) {array = new T[size]; };
  ~Vector(); 
  int getCount() const; 
  const T& operator[] (int index) const;
  T& operator[] (int index); 
  int operator+= (const T& object); 

} ; // class Vector

#include "vector.cpp"

#endif // VECTOR_H 
