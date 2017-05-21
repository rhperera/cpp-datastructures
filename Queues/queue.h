template<class QType>
class Queue {
private:
  int m_size;
  int m_initSize;
  QType* m_ptr_array;
  QType* m_ptr_head;
  QType* m_ptr_tail;
  int m_headPos;
  int m_tailPos;
  int m_itrPos;
  QType* m_ptr_itr;

public:
  Queue(int size);
  bool enqueue(int value);
  QType dequeue();
  QType get();
  bool itrReset();
};
