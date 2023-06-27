#ifndef STACK_MYSTACK_H
#define STACK_MYSTACK_H

#include <vector>

template <typename T>
class CMyStack
{
public:
    CMyStack() = default;
    ~CMyStack();

    CMyStack(CMyStack const& other) : m_data(other.m_data) {};
    CMyStack(CMyStack&& other) noexcept : m_data(other.m_data)
    {
        std::vector<T>().swap(other.m_data);
    };

    void Push(T const& item);
    void Pop();
    T Top() const;
    [[nodiscard]] bool IsEmpty() const;
    void Clear();

    T& operator=(T const& other);
    CMyStack& operator=(CMyStack&& other) noexcept;
private:
    std::vector<T> m_data;
};

template<typename T>
CMyStack<T> &CMyStack<T>::operator=(CMyStack &&other) noexcept
{
    if (std::addressof(other) != this)
    {
        CMyStack<T> tmpCopy(other);
        std::swap(m_data, other.m_data);
        std::vector<T>().swap(other.m_data);
//        m_data = std::move(other.m_data);
    }
    return *this;
}

template<typename T>
T &CMyStack<T>::operator=(const T &other)
{
    if (std::addressof(other) != this)
    {
        CMyStack<T> tmpCopy(other);
        std::swap(m_data, tmpCopy.m_data);
    }
    return *this;
}

template<typename T>
void CMyStack<T>::Clear()
{
    std::vector<T>().swap(m_data);
}

template<typename T>
void CMyStack<T>::Pop()
{
    if (!IsEmpty())
    {
        m_data.pop_back();
    }
}

template<typename T>
T CMyStack<T>::Top() const
{
    if (!IsEmpty())
    {
        return m_data.back();
    }
    throw std::out_of_range("Stack is empty");
}

template<typename T>
void CMyStack<T>::Push(const T &item)
{
    m_data.push_back(item);
}

template<typename T>
CMyStack<T>::~CMyStack()
{
    std::vector<T>().swap(m_data);
}

template<typename T>
bool CMyStack<T>::IsEmpty() const
{
    return m_data.empty();
}

#endif //STACK_MYSTACK_H
