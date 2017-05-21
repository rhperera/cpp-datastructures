#include<iostream>

#define MAX_SIZE 100

template <typename CAType>
class CyclicArray {
private:
	int m_arrayPos;
	CAType* m_ptr_array;
public:
	CyclicArray();
  int getArrayPos();
	void append(CAType value);
	CAType get(int index);
};

template<typename CAType>
CyclicArray<CAType>::CyclicArray() :m_arrayPos(0)
{
	m_ptr_array = new CAType[MAX_SIZE];
}

template<typename CAType>
int CyclicArray<CAType>::getArrayPos()
{
  if(m_arrayPos >= MAX_SIZE)
  {
    m_arrayPos = 0;
  }
	return m_arrayPos;
}

template<typename CAType>
void CyclicArray<CAType>::append(CAType value)
{
	m_ptr_array[getArrayPos()] = value;
  m_arrayPos++;
}

template<typename CAType>
CAType CyclicArray<CAType>::get(int index)
{
	return m_ptr_array[index % MAX_SIZE];
}

int main(int argc, char const *argv[]) {
  CyclicArray<int>* ptr_ca = new CyclicArray<int>();
  for (size_t i = 0; i < 150; i++) {
    ptr_ca->append(i);
  }
  for (size_t i = 0; i < 101; i++) {
    std::cout << ptr_ca->get(i) << '\n';
  }
  return 0;
}
