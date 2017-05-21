#include "queue.h"
#include <iostream>


template<class QType>
Queue<QType>::Queue(int size) : m_initSize(size), m_size(0), m_headPos(0), m_tailPos(size), m_itrPos(0)
{
  m_ptr_array = new QType[m_initSize];
  m_ptr_head = m_ptr_array;
  m_ptr_itr = m_ptr_array;
}

template<class QType>
bool Queue<QType>::enqueue(int value)
{
  if (m_size < m_initSize)
  {
    if(m_tailPos < m_initSize)
    {
      m_ptr_tail++;
      m_tailPos++;
    }
    else
    {
      m_tailPos = 1;
      m_ptr_tail = m_ptr_array;
    }

    m_size++;
    *m_ptr_tail = value;
    return true;
  }
  else
  {
    std::cout << "queue is full" << '\n';
    return false;
  }
}

template<class QType>
QType Queue<QType>::dequeue()
{
  if(m_size > 0)
  {
    QType temp;
    if(m_headPos < m_initSize)
    {
      temp = *m_ptr_head;
      m_ptr_head++;
      m_headPos++;
    }
    else
    {
      m_headPos = 1;
      m_ptr_head = m_ptr_array;
      temp = *m_ptr_head;
    }

    if (m_headPos > m_itrPos)
    {
      m_itrPos = m_headPos;
      m_ptr_itr = m_ptr_head;
    }

    m_size--;
    return temp;
  }
  else
  {
    std::cout << "queue is empty" << '\n';
  }
}

//iterator
template<class QType>
QType Queue<QType>::get()
{
  QType temp;
  if(m_size > 0)
  {
    if(m_itrPos < m_size)
    {
      temp = *m_ptr_itr;
      *m_ptr_itr++;
      m_itrPos++;
    }
    else
    {
      m_itrPos = 1;
      m_ptr_itr = m_ptr_array;
      temp = *m_ptr_itr;
    }
    return temp;
  }
}

template<class QType>
bool Queue<QType>::itrReset()
{
  m_ptr_itr = m_ptr_head;
  m_itrPos = m_headPos;
  return true;
}

int main(int argc, char const *argv[]) {
  Queue<int>* q_ptr = new Queue<int>(3);
  q_ptr->enqueue(45);
  q_ptr->enqueue(46);
  q_ptr->enqueue(47);
  std::cout << q_ptr->dequeue() << '\n';
  q_ptr->enqueue(48);
  std::cout << q_ptr->get() << '\n';
  std::cout << q_ptr->get() << '\n';
  std::cout << q_ptr->get() << '\n';
  return 1;
}
