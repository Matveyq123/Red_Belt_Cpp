#include "test_runner.h"

using namespace std;

template<typename T>
class Table
{
public:
    explicit Table(size_t rows, size_t columns) : _rows(rows), _columns(columns)
    {
        Resize(_rows, _columns);
    }

    void Resize(size_t rows, size_t columns)
    {
        _rows = rows;
        _columns = columns;
        _table.resize(_rows);
        for (auto& item : _table)
        {
            item.resize(_columns);
        }
    }

    const std::vector<T>& operator [](const size_t& index) const
    {
        return _table[index];
    }

    std::vector<T>& operator [](const size_t& index)
    {
        return _table[index];
    }

    std::pair<size_t, size_t> Size() const
    {
        if (!_table.empty() && !_table[0].empty()) {
            return { _table.size(), _table[0].size() };
        }

        return  { 0, 0 };
    }

private:
    std::vector<std::vector<T>> _table;
    size_t _rows;
    size_t _columns;
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}
