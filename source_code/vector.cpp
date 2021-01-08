#include <cstdlib>

#include "vector.h"

template <typename T>
Vector<T>::~Vector()
{
  delete [] array;
} // ~Vector()


template <typename T>
int Vector<T>::getCount() const
{
  return count;
} // getCount()


template <typename T>
const T& Vector<T>::operator[] (int index) const
{
  return array[index]; 
} // operator[] 


template <typename T>
T& Vector<T>::operator[] (int index)
{
  return array[index];
} // operator[]


template <typename T> 
int Vector<T>::operator+= (const T& object)
{
  int pos = 0;

  for (pos = 0;
      pos < count && ! (object == array[pos]); pos++); 

  if (pos == count)
  {
    if (count == size)
    {
      T *temp = new T[size * 2];

      for (int i = 0; i < count; i++)
        temp[i] = array[i];

      delete [] array;
      array = temp;
      size *= 2;
    } // count == size

    for (pos = count - 1;
      pos >= 0 && object < array[pos]; pos--)
        array[pos + 1] = array[pos];
   
    array[++pos] = object;
    count++;

  } // if not found

  return pos;
   
} // operator+=
