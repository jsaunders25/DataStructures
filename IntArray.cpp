#include <iostream>

class IndexOutOfBoundsException{};

class IntArray {
private:
    int* m_ptr{nullptr};
    int m_size{0};

    bool isValidIndex(int index) const
    {
        return (index >= 0) && (index < m_size);
    }

public:
    IntArray() = default;

    explicit IntArray(int size)
    {
        if(size != 0)
        {
            m_ptr  = new int[size]{};
            m_size = size;
        }
    }

    ~IntArray()
    {
        delete[] m_ptr;
    }

    int size() const
    {
        return m_size;
    }

    bool isEmpty() const
    {
        return (m_size == 0);
    }

    int& operator[](int index)
    {
        if(!isValidIndex(index))
            throw IndexOutOfBoundsException{};
        return m_ptr[index];
    }

    int operator[](int index) const
    {
        if(!isValidIndex(index))
            throw IndexOutOfBoundsException{};
        return m_ptr[index];
    }
};

int main()
{
    using std::cout;

    IntArray a{3};
    a[0] = 10;
    cout << "a[0] is: " << a[0];

    return 0;
}
