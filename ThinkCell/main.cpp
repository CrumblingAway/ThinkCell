#include <iostream>

#include "tests.h"

struct Key
{
	Key(int a) : _a(a) {}
	Key(const Key& other) : _a(other._a) {}

	bool operator<(const Key& other) const { return _a < other._a; }
	Key operator=(const Key& other) { _a = other._a; return *this; }

	int _a;
};

struct Value
{
	Value(char a) : _a(a) {}
	Value(const Value& other) : _a(other._a) {}

	bool operator==(const Value& other) const { return _a == other._a; }
	Value operator=(const Value& other) { _a = other._a; return *this; }

	char _a;
};

int main()
{
	IntervalMapTest<int, char>();
	//auto intervalMap = interval_map<Key, Value>(Value('.'));
	//intervalMap.assign(Key(2), Key(5), Value('A'));

	return 0;
 }
