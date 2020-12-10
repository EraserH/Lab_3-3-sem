#include <iostream>
#include <list>
#include <vector>

#include "list.h"
#include "vector.h"

using namespace std;

template<typename T>
//using CollectionType = Vector<T>;
using CollectionType = List<T>;

//template<typename Z>
//using _CollectionType = List<Z>;

template<typename T>
void printCollection(CollectionType<T>& container) {
	for (auto i = container.begin(); i != container.end(); ++i) {
		cout << " " << *i;
	}
}

template<typename T>
void fillCollection(CollectionType<T>& container, int size, int a) {
	//int a;
	for (int i = 0; i < size; ++i) {
		a = a - i;
		container.insert(container.begin(), a);
	}
}

template<typename T>
void userClear(CollectionType<T>& container) {
	for (size_t i = 0; i < container.size(); ++i) {
		container.erase(container.begin());
	}
}

template<typename T>
void reverseCollection(CollectionType<T>& container) {
	return reverse(container.begin(), container.end());
}

int main()
{
	//ВЕКТОРЫ
	/*CollectionType<int> v1;

	fillCollection(v1, 15, 30);
	cout << endl << "Vector1: ";
	printCollection(v1);

	cout << endl << "Size: " << v1.size() << "   Capacity: " << v1.capacity() << endl;

	userClear(v1);
	cout << endl << endl << "Vector1: ";
	printCollection(v1);

	cout << endl << "Size: " << v1.size() << "   Capacity: " << v1.capacity() << endl;

	CollectionType<int> v2;
	v2 = v1;
	cout << endl << endl << "Vector1: ";
	printCollection(v1);
	cout << endl << "Size: " << v1.size() << "   Capacity: " << v1.capacity() << endl;

	cout << endl << endl << "Vector2: ";
	printCollection(v2);
	cout << endl << "Size: " << v2.size() << "   Capacity: " << v2.capacity() << endl;

	v1.clear();
	cout << endl << endl << "Vector1: ";
	printCollection(v1);
	cout << endl << "Size: " << v1.size() << "   Capacity: " << v1.capacity() << endl;

	v1.reserve(10);
	cout << endl << "Size: " << v1.size() << "   Capacity: " << v1.capacity() << endl;

	v1 = move(v2);

	cout << endl << endl << "Vector1: ";
	printCollection(v1);
	cout << endl << "Size: " << v1.size() << "   Capacity: " << v1.capacity() << endl;

	cout << endl << endl << "Vector2: ";
	printCollection(v2);
	cout << endl << "Size: " << v2.size() << "   Capacity: " << v2.capacity() << endl;

	v2 = v1;
	reverseCollection(v2);

	cout << endl << endl << "Vector2: ";
	printCollection(v2);
	cout << endl << "Size: " << v2.size() << "   Capacity: " << v2.capacity() << endl;
	*/

	//СПИСКИ
	CollectionType<int> v1;
	fillCollection(v1, 15, 30);
	cout << endl << "List1: ";
	printCollection(v1);

	cout << endl << "Size: " << v1.size() << endl;

	userClear(v1);
	cout << endl << endl << "List1: ";
	printCollection(v1);

	cout << endl << "Size: " << v1.size() << endl;

	CollectionType<int> v2;
	v2 = v1;
	cout << endl << endl << "List1: ";
	printCollection(v1);
	cout << endl << "Size: " << v1.size() << endl;

	cout << endl << endl << "List2: ";
	printCollection(v2);
	cout << endl << "Size: " << v2.size() << endl;

	v1.clear();
	cout << endl << endl << "List1: ";
	printCollection(v1);
	cout << endl << "Size: " << v1.size() << endl;

	v1 = move(v2);

	cout << endl << endl << "List1: ";
	printCollection(v1);
	cout << endl << "Size: " << v1.size() << endl;

	cout << endl << endl << "List2: ";
	printCollection(v2);
	cout << endl << "Size: " << v2.size() << endl;

	v2 = v1;
	//reverseCollection(v2);

	cout << endl << endl << "List2: ";
	printCollection(v2);
	cout << endl << "Size: " << v2.size() << endl;



	//У ВЕКТОРА ПРОВЕРИТЬ end() и вообще итераторы
	/*vector<double> v1;

	std::cout << v1.size() << std::endl << v1.capacity() << std::endl;

	std::cout << std::endl << (v1.begin()) << " " << (v1.end()) << std::endl;


	v1.insert(v1.begin(), 15);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 16);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 17);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 18);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 19);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 25);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 26);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 27);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 28);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v1.insert(v1.begin(), 29);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;


	try {
		for (size_t i = 0; i < 15; ++i) {
			v1.insert(v1.begin(), i);
			std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
		}
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: An exception was caught" << std::endl;
	}

	try {
		v1.insert(v1.begin() + 2, 120);
		v1.insert(v1.begin() - 190, 180);
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: An exception was caught" << std::endl;
	}

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";


	v1.erase(v1.begin());
	v1.erase(v1.begin() + 7);
	v1.erase(v1.begin() + 5);
	v1.erase(v1.begin());
	v1.erase(v1.begin());


	try {
		for (size_t i = 0; i < 6; ++i) {
			v1.erase(v1.begin());
		}
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: An exception was caught while Erase" << std::endl;
	}

	try {
		v1.erase(v1.begin() + 7);
		v1.erase(v1.begin() + 5);
		v1.erase(v1.begin() + 100);
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: _____An exception was caught while Erase" << std::endl;
	}

	std::cout << std::endl << "Vector 1 ( before Erase end() ): ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	try {
		v1.erase(v1.end());
		//v1.erase(v1.begin() - 1);
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: __An exception was caught while Erase" << std::endl;
	}

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	vector <double>v2;

	v2.insert(v2.begin(), 119.3);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v2.insert(v2.begin(), 120.5);
	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	v2.insert(v2.begin(), 121.7);

	std::cout << std::endl << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	v1.swap(v2); //смена местами

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	v1 = v2; //присваивание копированием

	std::cout << std::endl << std::endl;

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	v2.clear();

	v2 = std::move(v1); //присваивание перемещением

	std::cout << std::endl << std::endl;

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";





	/*v1.resize(20);

	std::cout << std::endl << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	v1.resize(30);

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	v1.resize(10);

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	v1.resize(70);

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	v1.resize(200);

	std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;

	//std::cout << std::endl << v1[0] << " " << v1[1] << " " << v1[2] << std::endl;

	std::cout << std::endl;
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	*/

/*
	CollectionType<int> v1;

	cout << v1.size() << endl << v1.capacity() << endl;
	cout << endl << (v1.begin()) << " " << (v1.end()) << endl;

	for (size_t i = 0; i < 15; ++i) {
		v1.insert(v1.begin(), i);
		std::cout << std::endl << v1.size() << std::endl << v1.capacity() << std::endl;
	}

	try {
		v1.insert(v1.begin() + 2, 120);
		v1.insert(v1.begin() - 190, 180);
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: An exception was caught" << std::endl;
	}

	cout << endl << v1.size() << endl << v1.capacity() << endl;

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	
	for (size_t i = 0; i < 6; ++i)
		v1.erase(v1.begin());

	try {
		v1.erase(v1.begin() + 7);
		v1.erase(v1.begin() + 5);
		v1.erase(v1.begin() + 100);
	}
	catch (std::logic_error) {
		std::cout << std::endl << "DEBUG: _____An exception was caught while Erase" << std::endl;
	}

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	CollectionType<int> v2;
	for (size_t i = 0; i < 20; ++i) {
		v2.insert(v2.begin(), 100 - i);
		std::cout << std::endl << v2.size() << std::endl << v2.capacity() << std::endl;
	}

	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	v1.swap(v2);

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	v2 = v1;

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	cout << endl << v1.size() << endl << v1.capacity() << endl;
	cout << endl << v2.size() << endl << v2.capacity() << endl;

	v1.clear();

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";

	cout << endl << v1.size() << endl << v1.capacity() << endl;

	v1 = move(v2);

	std::cout << std::endl << "Vector 1: ";
	for (size_t i = 0; i < v1.size(); ++i)
		std::cout << v1[i] << " ";
	std::cout << std::endl << "Vector 2: ";
	for (size_t i = 0; i < v2.size(); ++i)
		std::cout << v2[i] << " ";

	cout << endl << v1.size() << endl << v1.capacity() << endl;
	cout << endl << v2.size() << endl << v2.capacity() << endl;

	// --------- ДАЛЕЕ ИДУТ СПИСКИ --------- 
	_CollectionType<int> l1, l2;

	//_CollectionType<int>::ConstIterator it0 = l1.begin();

	for (int i = 0; i < 15; ++i) {
		l1.insert(l1.begin(), i);
		//it0 = l1.begin();
		cout << endl << "data: " << *(l1.begin());
		std::cout << std::endl << l1.size() << std::endl;
	}

	cout << endl << endl << "List 1: ";

	_CollectionType<int>::ConstIterator it1 = l1.begin();

	for (size_t i = 0; i < l1.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}

	//УДАЛЕНИЕ ПОЭЛЕМЕНТНО ИЗ СПИСКА l1 ( erase() )
	/*
	for (size_t i = 0; i < l1.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		l1.erase(l1.begin());
	}
	//ПОСЛЕ ЭТОГО ЧТО_ТО РАБОТАЕТ НЕПРАВИЛЬНО: РАЗМЕР УМЕНЬШАЕТСЯ, НО НЕ ДО НУЛЯ
	cout << endl << endl << "List 1: ";

	for (size_t i = 0; i < l1.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}

	for (int i = 15; i < 30; ++i) {
		l1.insert(l1.begin(), i);
		//it0 = l1.begin();
		cout << endl << "data: " << *(l1.begin());
		std::cout << std::endl << l1.size() << std::endl;
	}

	//ПРИСВАИВАНИЕ КОПИРОВАНИЕМ
	l2 = l1;

	it1 = l1.begin();

	cout << endl << endl << "List 1: ";

	for (size_t i = 0; i < l1.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}

	cout << endl << endl << "List 2: ";

	it1 = l2.begin();

	for (size_t i = 0; i < l2.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}


	//УДАЛЕНИЕ ВСЕГО СПИСКА l1
	l1.clear();

	it1 = l1.begin();

	cout << endl << endl << "List 1: ";

	for (size_t i = 0; i < l1.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}


	//ОПЕРАЦИЯ ПРИСВАИВАНИЯ ПЕРЕМЕЩЕНИЕМ
	l1 = move(l2);

	it1 = l1.begin();

	cout << endl << endl << "List 1: ";

	for (size_t i = 0; i < l1.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}

	it1 = l2.begin();

	cout << endl << endl << "List 2: ";

	for (size_t i = 0; i < l2.size(); ++i) {
		//_CollectionType<int>::ConstIterator = l1.begin();
		std::cout << *it1 << " ";
		++it1;
	}
	*/

	return 0;
}