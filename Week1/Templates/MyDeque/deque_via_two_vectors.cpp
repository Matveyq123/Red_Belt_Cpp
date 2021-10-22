#include <vector>
#include <exception>
#include <iostream>

template<typename T>
class Deque
{
public:
    Deque() = default;

    bool Empty() const
    {
        return _head.empty() && _tail.empty();
    }

    size_t Size() const
    {
        return _head.size() + _tail.size();
    }

    const T& operator [] (size_t index) const {
        if (index < _head.size())
        {
            return _head[_head.size() - index - 1];
        }

        return _tail[index - _head.size()];
    }

    T& operator [] (size_t index) {
        if (index < _head.size())
        {
            return _head[_head.size() - index - 1];
        }

        return _tail[index - _head.size()];
    }

    const T& At(size_t index) const
    {
        if (index >= Size())
        {
            throw std::out_of_range("Wrong index value");
        }

        return (*this)[index];
    }

    T& At(size_t index) 
    {
        if (index >= Size())
        {
            throw std::out_of_range("Wrong index value");
        }

        return (*this)[index];
    }

    const T& Front() const
    {
        if (_head.empty())
        {
            return _tail.front();
        }

        return _head.back();
    }

    T& Front()
    {
        if (_head.empty())
        {
            return _tail.front();
        }

        return _head.back();
    }

    const T& Back() const
    {
        if (_tail.empty())
        {
            return _head.front();
        }
        return _tail.back();
    }

    T& Back()
    {
        if (_tail.empty())
        {
            return _head.front();
        }
        return _tail.back();
    }

    void PushFront(const T& value) {
        _head.push_back(value);
    }

    void PushBack(const T& value) {
        _tail.push_back(value);
    }

private:
    std::vector<T> _head;
    std::vector<T> _tail;
};
//

template <typename It>
struct IteratorRange {
    It first, last;

    IteratorRange(It begin, It end)
        : first(begin)
        , last(end)
    {
    }
};

template <typename T>
struct ReadOnlyValue {
    const T value;
};

template <typename T>
ReadOnlyValue<T> MakeReadOnly(T x) {
    return { x };
}

int main()
{
    ReadOnlyValue<std::vector<int>> v{ {4,5,6} };
    IteratorRange<int> index_range(1, 5);
//    std::deque<int> deq;
//    deq.push_back(5);
//    deq.push_back(2);
//    deq.push_back(3);
//    deq.push_front(6);
//    deq.push_front(1);
//    deq.push_front(12);
//    for (const auto& item : deq)
//    {
//        std::cout << item << " ";
//    }
//    std::cout << std::endl;
//    Deque<int> d;
//    d.PushBack(5);
//    d.PushBack(2);
//    d.PushBack(3);
//    d.PushFront(6);
//    d.PushFront(1);
//    d.PushFront(12);
//    std::cout << d.Size() << std::endl;
//    //d.PrintDeque();
   return 0;
//
}

