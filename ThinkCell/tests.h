#pragma once

#include <iostream>

#include "interval_map.cpp"

#define MIN_KEY (-2)
#define MAX_KEY (15)
#define TEST_SUCCESS "Test passed!"
#define TEST_FAILURE "Test failed!"

template<typename K, typename V>
void printMaps(std::map<K, V>& map1, std::map<K, V>& map2)
{
	for (int i = MIN_KEY; i < MAX_KEY; ++i)
	{
		std::cout << i << " -> " << "\'" << map1[i] << "\' | \'" << map2[i] << "\'" << std::endl;
	}
}

template<typename K, typename V>
std::map<K, V> intervalMapToMap(const interval_map<K, V>& intervalMap)
{
	auto result = std::map<K, V>();
	for (int i = MIN_KEY; i <= MAX_KEY; ++i)
	{
		result[i] = intervalMap[i];
	}

	return result;
}

template<typename K, typename V>
void testEmptyInsert()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'A'},
		{  3, 'A'},
		{  4, 'A'},
		{  5, 'A'},
		{  6, 'A'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Empty insert test." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
 	intervalMap.assign(1, 3, 'A');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testSingleInsert()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'A'},
		{  5, 'A'},
		{  6, 'A'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Single insert test." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(2, 4, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testTwoAdjacentInserts()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'C'},
		{  5, 'A'},
		{  6, 'A'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test two adjacent inserts." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(2, 4, 'B');
	intervalMap.assign(4, 5, 'C');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testInsertFromLeftSameValue()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'B'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'A'},
		{  5, 'A'},
		{  6, 'A'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test insert from left same value." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(1, 3, 'B');
	intervalMap.assign(3, 4, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testInsertFromRightSameValue()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'A'},
		{  6, 'A'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test insert from right same value." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(3, 5, 'B');
	intervalMap.assign(2, 3, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testInsertBetweenSameValue()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test insert between same value." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(2, 4, 'B');
	intervalMap.assign(6, 7, 'B');
	intervalMap.assign(4, 6, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testOverlapSingleRangeCompletely()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test overlap single range completely." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(4, 6, 'C');
	intervalMap.assign(2, 7, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testOverlapMultipleRangesCompletely()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'B'},
		{  8, 'B'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test overlap multiple ranges completely." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(3, 4, 'C');
	intervalMap.assign(6, 8, 'D');
	intervalMap.assign(2, 9, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testOverlapAdjacentLeft()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test overlap adjacent from left." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(2, 4, 'C');
	intervalMap.assign(2, 7, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testOverlapAdjacentRight()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test overlap adjacent from right." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(3, 7, 'C');
	intervalMap.assign(2, 7, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testOverlapSameRange()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test overlap same range." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(2, 7, 'B');
	intervalMap.assign(2, 7, 'B');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testDeleteFromLeft()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test delete from left." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(0, 7, 'B');
	intervalMap.assign(-1, 2, 'A');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testDeleteFromRight()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'B'},
		{  3, 'B'},
		{  4, 'B'},
		{  5, 'B'},
		{  6, 'B'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test delete from right." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(2, 9, 'B');
	intervalMap.assign(7, 11, 'A');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void testDeleteSameRange()
{
	auto correctIntervalMap = std::map<K, V>{
		{ -2, 'A'},
		{ -1, 'A'},
		{  0, 'A'},
		{  1, 'A'},
		{  2, 'A'},
		{  3, 'A'},
		{  4, 'A'},
		{  5, 'A'},
		{  6, 'A'},
		{  7, 'A'},
		{  8, 'A'},
		{  9, 'A'},
		{ 10, 'A'},
		{ 11, 'A'},
		{ 12, 'A'},
		{ 13, 'A'},
		{ 14, 'A'},
		{ 15, 'A'},
	};

	std::cout << "Test delete same range." << std::endl;
	std::cout << "=============================" << std::endl;

	auto intervalMap = interval_map<K, V>('A');
	intervalMap.assign(0, 7, 'B');
	intervalMap.assign(0, 7, 'A');

	auto output = intervalMapToMap(intervalMap);
	if (output == correctIntervalMap)
	{
		std::cout << TEST_SUCCESS << std::endl;
	}
	else
	{
		std::cout << TEST_FAILURE << std::endl;
		printMaps(correctIntervalMap, output);
	}

	std::cout << "=============================" << std::endl;
}

template<typename K, typename V>
void IntervalMapTest()
{
	testEmptyInsert<K, V>();
	testSingleInsert<K, V>();
	testTwoAdjacentInserts<K, V>();

	testInsertFromLeftSameValue<K, V>();
	testInsertFromRightSameValue<K, V>();
	testInsertBetweenSameValue<K, V>();

	testOverlapSingleRangeCompletely<K, V>();
	testOverlapMultipleRangesCompletely<K, V>();
	testOverlapAdjacentLeft<K, V>();
	testOverlapAdjacentRight<K, V>();
	testOverlapSameRange<K, V>();

	testDeleteFromLeft<K, V>();
	testDeleteFromRight<K, V>();
	testDeleteSameRange<K, V>();
}
