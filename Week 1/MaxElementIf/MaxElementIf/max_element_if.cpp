#include "test_runner.h"

#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std;

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_elem(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
{
	if (first == last)
	{
		return last;
	}

	ForwardIterator max = first;
	++first;

	for (; first != last; ++first)
	{
		if (*max < *first && pred(*first))
		{
			max = first;
		}
	}

	return max;
}

template<typename ForwardIterator, typename UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
{

	ForwardIterator max = max_elem(first, last, pred);

	if (max == last)
	{
		return max;
	}

	ForwardIterator it;
	for (it = max; it != last; ++it)
	{
		if (pred(*max))
		{
			return max;
		}
		max = max_elem(it, last, pred);
	}

	if (pred(*max) != true)
	{
		return last;
	}

	return max;

}

void TestUniqueMax() {
	auto IsEven = [](int x) {
		return x % 2 == 0;
	};

	const list<int> hill{ 2, 4, 8, 9, 6, 4, 2 };
	auto max_iterator = hill.begin();
	advance(max_iterator, 2);

	vector<int> numbers(10);
	iota(numbers.begin(), numbers.end(), 1);

	/*
	  �� �� ���������� AssertEqual, ������ ��� ��� ����������
	  ����������� ���������� ��������� ������ � ����� ostream.
	  ������������� ����� ����� �����������, ��� ��� ��� ����� �������
	  �������������� ���������, ���� ������� max_element_if, � �������,
	  ������� ��������, ����������� �� ����� ����������.
	*/
	Assert(
		max_element_if(numbers.begin(), numbers.end(), IsEven) == --numbers.end(),
		"Expect the last element"
	);
	Assert(
		max_element_if(hill.begin(), hill.end(), IsEven) == max_iterator,
		"Expect the maximal even number"
	);
}

void TestSeveralMax() {
	struct IsCapitalized {
		bool operator()(const string &s) {
			return !s.empty() && isupper(s.front());
		}
	};

	const forward_list<string> text{ "One", "two", "Three", "One", "Two",
	  "Three", "one", "Two", "three" };
	auto max_iterator = text.begin();
	advance(max_iterator, 4);

	Assert(
		max_element_if(text.begin(), text.end(), IsCapitalized()) == max_iterator,
		"Expect the first \"Two\""
	);
}

void TestNoMax() {
	const vector<int> empty;
	const string str = "Non-empty string";

	auto AlwaysTrue = [](int) {
		return true;
	};
	Assert(
		max_element_if(empty.begin(), empty.end(), AlwaysTrue) == empty.end(),
		"Expect end for empty container"
	);

	auto AlwaysFalse = [](char) {
		return false;
	};
	Assert(
		max_element_if(str.begin(), str.end(), AlwaysFalse) == str.end(),
		"Expect end for AlwaysFalse predicate"
	);
}

int main() {
	TestRunner tr;
	tr.RunTest(TestUniqueMax, "TestUniqueMax");
	tr.RunTest(TestSeveralMax, "TestSeveralMax");
	tr.RunTest(TestNoMax, "TestNoMax");
	return 0;
}

