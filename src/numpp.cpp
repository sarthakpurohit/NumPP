#include <iostream>
#include <typeinfo>
#include <map>

#include "numpp.hpp"

using namespace std;

template <class T>
int numpp<T>::shape_match(vector<int> dim) {
  
  if(this->dim.size() == dim.size()) {
    for(int i=0; i<this->dim.size(); i++)

      if(this->dim[i] != dim[i])
        return 0;
    return 1;
  }

  return 0;
}

template <class T>
numpp<T>::numpp(vector<int> dim) {
  this->dim = dim;
  this->ndim = 1;
  for(int i=0; i<this->dim.size(); i++)
    this->ndim *= this->dim[i];
  try {
    T *a = new T[this->ndim];
    delete[] a;
  } catch(bad_alloc&) {
    cerr<<"\033[1;31m Error\033[0m: Memory out of bounds!";
  }
}

template <class T>
void numpp<T>::shape() {
  cout<<"{ ";
  for(int i=0; i<this->dim.size()-1; i++)
    cout<<this->dim[i]<<", ";
  cout<<this->dim[this->dim.size() - 1]<<" }";
}

template <class T>
void numpp<T>::reshape(vector<int> new_dim) {
  this->ndim = 1;
  int new_ndim = 1;
  for(int i=0; i<this->dim.size(); i++)
    this->ndim *= this->dim[i];
  for(int i=0; i<new_dim.size(); i++)
    new_ndim *= new_dim[i];

  if(this->ndim == new_ndim) {
    cout<<"New dimensions: ";
    cout<<"{ ";
    for(int i=0; i<new_dim.size()-1; i++)
      cout<<new_dim[i]<<", ";
    cout<<new_dim[new_dim.size() - 1]<<" }";
  } else
    cerr<<"\033[1;31m Error\033[0m: Invalid dimensions!";
}

template <class T>
void numpp<T>::push_vec(vector<int> dim, vector<T> data)
 {
  if(shape_match(dim))
    this->data = data;
  else
    cerr<<"\033[1;31m Error\033[0m: Dimension doesn't match declared numpp dimension!";
}
 
template <class T>
 void numpp<T>::search(T a, char* ch)
 {
   if (ch=="Linear")
 {
   int count=0;
   for(int i=0;i<ndim;i++)
   {
     if(a==data[i])
       count++;
   }

     if(count==0)
     cout<<"Status not found";
     else
     {
       cout<<"Status found "<<"Occurence "<<count;
     }
   }
   else if(ch=="Binary")
   { 
       int i, j; 
    T temp; 
    for (i = 0; i < ndim-1; i++)  
    {     
    for (j = 0; j < ndim-i-1; j++)  
    {
        if (data[j] > data[j+1]) 
        {
          temp=data[j];
          data[j]=data[j+1];
          data[j+1]=temp;
        }
    }
    }
      int count=0;
     int start, end, middle;
     start=0;
     end=ndim-1;
     for(int i=0;i<ndim;i++)
{
  middle=(start+end)/2;
  if(a==data[middle])
  {
  count++;
  }
  else if(a>data[middle])
start=middle+1;
else 
end=middle-1;  
}
if(count>0)
cout<<"Status found ";
else
{
  cout<<"Status Not found";
}

   }
 }
 template <class T>
 void numpp<T>::sort(char* ch)
 {
   if(ch=="Bubble")
{  
    int i, j; 
    T temp; 
    for (i = 0; i < ndim-1; i++)  
    {     
    for (j = 0; j < ndim-i-1; j++)  
    {
        if (data[j] > data[j+1]) 
        {
          temp=data[j];
          data[j]=data[j+1];
          data[j+1]=temp;
        }
    }
    }
   
}
else if(ch=="Insertion")
{
  int i, j;  
  T key;
    for (i = 1; i < ndim; i++) 
    {  
        key = data[i];  
        j = i - 1;  
        while (j >= 0 && data[j] > key) 
        {  
            data[j + 1] = data[j];  
            j = j - 1;  
        }  
        data[j + 1] = key;  
    }
      
}
else if(ch=="Selection")
{
   int i, j, min_idx;
   T temp;  
  
    for (i = 0; i < ndim-1; i++)  
    {  
       
        min_idx = i;  
        for (j = i+1; j < ndim; j++)  
        if (data[j] < data[min_idx])  
            min_idx = j;  
        temp=data[min_idx];
        data[min_idx]=data[i];
        data[i]=temp;
    }  
    for(i=0;i<ndim;i++)
    cout<<data[i];
    
}
 }

           


   
