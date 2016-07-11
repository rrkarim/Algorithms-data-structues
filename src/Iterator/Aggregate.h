/************************************************************************/
/* Aggregate.h                                                          */
/************************************************************************/
#ifndef MY_DATACOLLECTION_HEADER
#define MY_DATACOLLECTION_HEADER
#include "Iterator.h"

template <class T>
class aggregate
{
	friend class Iterator<T, aggregate>;
public:
	void add(T a)
	{
		m_data.push_back(a);
	}

	Iterator<T, aggregate> *create_iterator()
	{
		return new Iterator<T, aggregate>(this);
	}
	

private:
	std::vector<T> m_data;
};
template <class T, class U>
class aggregateSet
{
	friend class setIterator<T, U, aggregateSet>;
public:
	void add(T a)
	{
		m_data.insert(a);
	}

	setIterator<T, U, aggregateSet> *create_iterator()
	{
		return new setIterator<T,U,aggregateSet>(this);
	}

	void Print()
	{
		copy(m_data.begin(), m_data.end(), std::ostream_iterator<T>(std::cout, "\n"));
	}

private:
	std::set<T,U> m_data;
};

#endif