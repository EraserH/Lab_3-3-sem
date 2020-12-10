#pragma once
#include <iostream>
#include <utility>

bool DEBUG = false;

template <typename T>
class Vector {
	T* data;
	size_t _size;
	size_t _capacity;

	/*bool reallocate(size_t capacity) {
		if (capacity < _capacity) {

		}
	}*/
public:
	Vector(): data(nullptr), _size(0), _capacity(0){

	}

	Vector(const Vector<T>& _vector): data(new T[_vector._size]), _size(_vector._size), _capacity(_vector._capacity) {
		for (auto i = 0; i < _size; ++i)
			data[i] = _vector.data[i];
	}

	Vector(Vector<T>&& _vector): data(_vector.data), _size(_vector._size), _capacity(_vector._capacity) {
		_vector.data = nullptr;
	}

	Vector<T>& operator=(const Vector<T>& _vector) {
		Vector<T> tmp(_vector); //??
		swap(tmp);
		return *this;
	}

	Vector<T>& operator=(Vector<T>&& _vector) noexcept{
		swap(_vector);
		return *this;
	}

	//��� ���� ������� �������� ���� �������� �� �������
	void reserve(size_t capacity) {
		if (capacity <= _capacity)
			return;

		if (capacity > _capacity) {
			auto tmp = new T[capacity];
			for (auto i = 0; i < _size; ++i) {
				tmp[i] = std::move_if_noexcept(data[i]);
			}
			delete[] data;
			data = tmp;
			_capacity = capacity;
		}
	}

	size_t size() const {
		return _size;
	}

	size_t capacity() const noexcept {
		return _capacity;
	}

	const T& operator[](const size_t index) const {
		if (DEBUG)
			std::cout << std::endl << "\tDEBUG: const operator[] worked here";

		return data[index];
	}

	T& operator[](size_t index) {
		if (DEBUG)
			std::cout << std::endl << "\tDEBUG: operator[] worked here";

		return data[index];
	}

	T* begin() const {
		return data;
	}

	T* end() const {
		return data + _size;
	}

	void swap(Vector<T>& _vector) noexcept {
		std::swap(data, _vector.data);
		std::swap(_size, _vector._size);
		std::swap(_capacity, _vector._capacity);
	}

	/*const T* insert(const T* pos, const T& value) {
		if (pos < begin() || pos > end())
			throw std::logic_error("Iterator out of range");

		size_t posIndex = pos - data; //���� ������ �� ������ ��� ��� ���� �������������? ���������
		//��� �� �������� (�������� ��� pos = begin(), ��������� - ���������)

		if (_size + 1 > _capacity) {
			if (_size == 0)
				resize(1);
			else
				resize(size_t(ceil(double(_size) * 1.6))); // ���������
		}
		else
			++_size;

		for (size_t i = _size - 1; i > posIndex; --i) {
			data[i] = std::move_if_noexcept(data[i - 1]); // ��������� ��� ������
		}
		data[posIndex] = value; //����������: ��������� ������� ��� ������

		return &data[posIndex];
	}*/

	const T* insert(const T* pos, const T& value) {
		if (pos < begin() || pos > end())
			throw std::logic_error("Iterator out of range");

		size_t posIndex = pos - data; 

		if (_size + 1 > _capacity) {
			if (_size == 0)
				reserve(1);
			else
				reserve(size_t(_size * 2));
		}
		++_size;

		T indicator1, indicator2;

		for (size_t i = _size - 1; i > posIndex; --i) {
			indicator1 = data[i];
			indicator2 = data[i - 1];
			data[i] = std::move_if_noexcept(data[i - 1]); 
			indicator1 = data[i];
			indicator2 = data[i - 1];
		}
		data[posIndex] = value; //����������: ��������� ������� ��� ������

		return &data[posIndex];
	}

	const T* erase(const T* pos) {
		if (pos < begin() || pos > end())
			throw std::logic_error("Iterator out of range");

		size_t posIndex = pos - data; 

		for (size_t i = posIndex; i < _size - 1; ++i) {
			data[i] = std::move_if_noexcept(data[i + 1]); 
		}
		--_size;

		return &data[posIndex];
	}

	void resize(size_t size, T value = T()) { 
		if (size == _size) 
			return;

		if (size <= _capacity) {
			_size = size;
		}

		else if (size > _capacity) {
			auto tmp = new T[size];
			/*if (_size != 0) //��� ������� �������
				for (size_t i = 0; i < size; ++i) //��� ������ _size ��������. ���������
					tmp[i] = std::move_if_noexcept(data[i]); //��� ���������� ���������� (��������� ������� ��� ������)*/
			for (size_t i = 0; i < _size; ++i)
				tmp[i] = std::move_if_noexcept(data[i]);
			delete[] data;
			data = tmp;
			_size = size;
			_capacity = size; 
		}
	}

	void clear() {
		delete[] data;
		data = nullptr;
		_size = 0;
		_capacity = 0;
	}

	~Vector() {
		delete[] data;
	}
};