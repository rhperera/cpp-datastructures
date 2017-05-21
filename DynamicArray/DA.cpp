#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
 
template<class DAType> 
class DynamicArray
{
public:
    DynamicArray(int initSize,int incSize);
    //~DynamicArray();
    int setAt(DAType value, int index);
    DAType getAt(int index);
    int length();
    int append(DAType value);
private:
    int m_initSize;
    int m_incSize;
    int m_size;
    int m_maxSize;
    DAType* m_ptr_dArray;
    DynamicArray();
};

template<class DAType> 
DynamicArray<DAType>::DynamicArray(int initSize,int incSize) : m_initSize(initSize), m_incSize(incSize), m_size(0), m_maxSize(initSize)
{
    m_ptr_dArray = new DAType[m_initSize];
}

template<class DAType> 
int DynamicArray<DAType>::setAt(DAType value,int index)
{
    if(index < m_size)
    {
        this->m_ptr_dArray[index] = value;
    }
    else 
    {
        //dostuff
        //m_maxSize = m_maxSize + m_incSize;
        cerr << "index out of bound";
        exit (EXIT_FAILURE);
    }
    return 1;
}

template<class DAType> 
DAType DynamicArray<DAType>::getAt(int index)
{
    if(index < m_size)
    {
        return m_ptr_dArray[index];
    }
    else
    {
       cerr << "index out of bound";
       exit (EXIT_FAILURE);
    }
}

template<class DAType> 
int DynamicArray<DAType>::length()
{
    return this->m_size;
}


template<class DAType>
int DynamicArray<DAType>::append(DAType value)
{
    if(m_size <= m_maxSize)
    {
        m_ptr_dArray[m_size] = value;
    }
    else 
    {
        DAType* temp = new DAType[m_size + m_incSize];
        memcpy(temp, m_ptr_dArray, m_size * sizeof(DAType) );
        delete m_ptr_dArray;
        m_ptr_dArray = temp;
        delete temp;
        m_ptr_dArray[m_size] = value;
        m_maxSize = m_maxSize + m_incSize;
    }
    m_size++;
    return 1;
}


int main()
{
    DynamicArray<int>* da = new DynamicArray<int>(1000,1000);
    for(int i = 0; i < 1006; i++)
    {
        da->append(2);
    }
    
    
    cout << da->getAt(1005) << endl;

    da->setAt(300,1004);

    cout << da->getAt(1004) << endl;

    cout << da->length() << endl;
    return 1;
}