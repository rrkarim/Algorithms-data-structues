/************************************************************************/
/* Iterator Test.cpp                                                    */
/************************************************************************/
#include <iostream>
#include <string>
#include "Aggregate.h"
using namespace std;

class Money
{
public:
	Money(int a = 0): m_data(a) {}

	void SetMoney(int a)
	{
		m_data = a;
	}

	int GetMoney()
	{
		return m_data;
	}
	
private:
	int m_data;
};

class Name
{
public:
	Name(string name): m_name(name) {}

	const string &GetName() const
	{
		return m_name;
	}

	friend ostream &operator<<(ostream& out, Name name)
	{
		out << name.GetName();
		return out;
	}

private:
	string m_name;
};

struct NameLess
{
	bool operator()(const Name &lhs, const Name &rhs) const
	{
		return (lhs.GetName() < rhs.GetName());
	}
};

int main()
{
	//sample 1
	cout << "________________Iterator with int______________________________________" << endl;
	aggregate<int> agg;
	
	for (int i = 0; i < 10; i++)
		agg.add(i);

	Iterator< int,aggregate<int> > *it = agg.create_iterator();
	for(it->first(); !it->isDone(); it->next())
		cout << *it->current() << endl;	

	//sample 2
	aggregate<Money> agg2;
	Money a(100), b(1000), c(10000);
	agg2.add(a);
	agg2.add(b);
	agg2.add(c);

	cout << "________________Iterator with Class Money______________________________" << endl;
	Iterator<Money, aggregate<Money> > *it2 = agg2.create_iterator();
	for (it2->first(); !it2->isDone(); it2->next())
		cout << it2->current()->GetMoney() << endl;

	//sample 3
	cout << "________________Set Iterator with Class Name______________________________" << endl;
	
	aggregateSet<Name, NameLess> aset;
	aset.add(Name("Qmt"));
	aset.add(Name("Bmt"));
	aset.add(Name("Cmt"));
	aset.add(Name("Amt"));

	setIterator<Name, NameLess, aggregateSet<Name, NameLess> > *it3 = aset.create_iterator();
	for (it3->first(); !it3->isDone(); it3->next())
		cout << (*it3->current()) << endl;
}