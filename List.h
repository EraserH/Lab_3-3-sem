#pragma once
#include <iostream>

template<typename T>
class List {
	struct Node {
		T data;
		Node* prev;
		Node* next;

		Node(const T& data, Node* prev, Node* next) : data(data), prev(prev), next(next) { }
	};

	Node* _dummy;
	Node* _head;
	Node* _tail;
	size_t _size;

public:
	class ConstIterator {
		Node* node;

		ConstIterator(Node* node) : node(node) { }

	public:
		/*
		using difference_type = ptrdiff_t;
		using value_type = T;
		using pointer = const T*;
		using reference = const T&;
		using iterator_category = std::bidirectional_iterator_tag;
		*/

		friend class List<T>;

		ConstIterator& operator++() {
			node = node->next;
			return *this;
		}

		ConstIterator operator++(int) {
			auto result(*this);
			node = node->next;
			return result;
		}

		ConstIterator operator--() {
			node = node->prev;
			return *this;
		}

		ConstIterator operator--(int) {
			auto result(*this);
			node = node->prev;
			return result;
		}

		const T& operator*() {
			return node->data;
		}

		//СТРЕЛОЧКА
		T* operator->() const {
			return &(node->data); 
		}

		bool operator==(ConstIterator rhs) {
			return node == rhs.node;
		}

		bool operator!=(ConstIterator rhs) {
			return node != rhs.node;
		}
	};

	List() : _dummy(new Node(T(), nullptr, nullptr)), _head(_dummy), _tail(_dummy), _size(0) { //с dummy возможны беды
		_dummy->prev = _dummy;
		_dummy->next = _dummy; 
	}

	//с dummy возможны беды
	List(const List<T>& rhs): _dummy(new Node(T(), nullptr, nullptr)), _head(_dummy), _tail(_dummy), _size(rhs.size()) {
		//Node* subnode = (rhs.end()).node->prev;
		Node* subnode = rhs._dummy->prev;
		Node* tmp = _dummy;//new Node(subnode1.data, nullptr, nullptr);

		for (size_t i = 0; i < rhs.size(); ++i) {
			tmp->prev = new Node(subnode->data, nullptr, tmp);
			tmp = tmp->prev;
			subnode = subnode->prev;
		}
		_head = tmp;
		_head->prev = _dummy;
		//_tail = end().node->prev;
		_tail = _dummy->prev;
	}

	List(List<T>&& rhs)noexcept : _dummy(rhs._dummy), _head(rhs._head), _tail(rhs._dummy), _size(rhs._size) {
		//_head = rhs._head;
		//_tail = rhs._tail;
		//_dummy = rhs._dummy;
		//_size = rhs._size;

		rhs._head = nullptr;
		rhs._tail = nullptr;
		rhs._dummy = nullptr;
	}

	List<T>& operator=(const List<T>& rhs) {
		auto temp(rhs);
		swap(temp);
		return *this;
	}

	List<T>& operator=(List<T>&& rhs) noexcept {
		swap(rhs);
		return *this;
	}

	void swap(List<T>& rhs) noexcept {
		std::swap(_head, rhs._head);
		std::swap(_tail, rhs._tail);
		std::swap(_dummy, rhs._dummy); //ПРОВЕРИТЬ
		std::swap(_size, rhs._size);
	}

	size_t size() const noexcept {
		return _size;
	}

	ConstIterator begin() const {
		return ConstIterator(_head);
	}

	ConstIterator end() const {
		return ConstIterator(_dummy);
	}

	ConstIterator insert(ConstIterator pos, T& value) {
		Node* _node = pos.node;

		Node* tmp;
		if (pos == _head) {
			tmp = new Node(value, _node->prev, _node);
			_node->prev = tmp;
			_head = tmp;
		}
		else {
			tmp = new Node(value, _node->prev, _node); 
			tmp->prev->next = tmp;
			_node->prev = tmp;
		}

		if (pos == end()) {
			_tail = tmp;
		}

		++_size;

		return --pos; 
	}

	/*
	ConstIterator erase(ConstIterator pos) {
		if (pos == end())
			return _dummy;

		if (pos == _head) {
			pos->next->prev = pos->prev;
			_head = pos->next;
		}
		else {
			pos->prev->next = pos->next;
			pos->next->prev = pos->prev;
		}

		if (pos == _tail) {
			_tail = pos->prev;
		}

		--_size;
		delete pos; //ПРОВЕРИТЬ, работает ли такое с pos


		// TODO List<T>::erase  ___DONE___

		// Операция должна работать за O(1)!
		// Не забыть --_size!
	}
	*/

	ConstIterator erase(ConstIterator pos) {
		if (pos == end())
			return _dummy;

		Node* _node = pos.node;

		if (pos == _head) {
			_node->next->prev = _node->prev;
			_head = _node->next;
		}
		else {
			_node->prev->next = _node->next; //ИСКЛЮЧЕНИЕ
			_node->next->prev = _node->prev;
		}

		if (pos == _tail) {
			_tail = _node->prev;
		}

		--_size;

		delete _node; 

		return ++pos; 
	}

	void clear() noexcept {
		for (int i = 0; i < _size; ++i) {
			auto tmp = _head;
			_head = _head->next;
			delete tmp;
		}
		_size = 0;
		_tail = _head;
		_dummy->prev = _dummy;
	}

	~List() {
		clear();
	}
};