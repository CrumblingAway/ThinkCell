#include <map>

#include <iostream>

template<typename K, typename V>
class interval_map
{
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;

public:
	// constructor associates whole range of K with val
	interval_map(const V& val):
		m_valBegin(val)
	{

	}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(
		const K& keyBegin,
		const K& keyEnd,
		const V& val
	)
	{
		if (!(keyBegin < keyEnd))
		{
			return;
		}

		// Find value for adjacent right bound.
		V endVal;
		auto rightIt = m_map.find(keyEnd);
		if (rightIt == m_map.end())
		{
			rightIt = m_map.lower_bound(keyEnd);
			if (rightIt == m_map.end())
			{
				endVal = m_valBegin;
			}
			else
			{
				endVal = std::prev(rightIt)->second;
			}
		}
		else
		{
			endVal = rightIt->second;
		}

		// Set new key value mappings.
		auto beginIt = m_map.find(keyBegin);
		if (beginIt == m_map.end())
		{
			m_map.insert(std::make_pair(keyBegin, val));
		}
		else
		{
			beginIt->second = val;
		}

		auto endIt = m_map.find(keyEnd);
		if (endIt == m_map.end())
		{
			m_map.insert(std::make_pair(keyEnd, endVal));
		}
		else
		{
			endIt->second = endVal;
		}

		// CANNOT USE. [] OPERATOR REQUIRES DEFAULT CONSTRUCTION.
		//m_map[keyBegin] = val;
		//m_map[keyEnd] = endVal;

		// Canonize.

		// Handle same value.
		auto it = m_map.find(keyBegin);
		if (it == m_map.begin())
		{
			if (it->second == m_valBegin)
			{
				m_map.erase(it);
			}
		}
		else
		{
			if (it->second == std::prev(it)->second)
			{
				m_map.erase(it);
			}
		}

		// Find left bound.
		if (m_map.find(keyBegin) == m_map.end())
		{
			it = m_map.lower_bound(keyBegin);
		}
		else
		{
			++it;
		}

		// Erase overwritten values.
		auto lastIt = m_map.find(keyEnd);
		m_map.erase(it, lastIt);
	}

	// look-up of the value associated with key
	V const& operator[](K const& key) const
	{
		auto it = m_map.upper_bound(key);
		if (it == m_map.begin())
		{
			return m_valBegin;
		}
		else
		{
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.