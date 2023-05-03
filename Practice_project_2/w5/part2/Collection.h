/*Workshop 5 part 2
Name: Juan Pablo Martinez Carett
Email : jpmartinez - carett@myseneca.ca
Student ID : 112494216
Date : 02 / 19 / 2023/
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/
#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>

namespace sdds {
	template<typename T>
	class Collection {
		std::string _name_colle{};
		T* _array{};
		//the weird variable
		void(*_observer)(const Collection<T>&, const T&) {};
		size_t m_idx = 0;

	public:
		Collection(const std::string& name) :_name_colle(name) { }
		~Collection() { delete[] _array; };
		// OK
		const std::string& name() const { return _name_colle; };
		size_t size() const { return m_idx; };
		
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			_observer = observer;
		};
		//By instrucction
		Collection(const Collection& src) = delete;
		Collection& operator=(const Collection& src) = delete;
		Collection(Collection&& src) = delete;
		Collection& operator=(Collection&& src) = delete;
		
		// CHECK THIS FUNCTION AT THE END
		Collection<T>& operator+=(const T& item) {

			bool flag = false;
			size_t i = 0;
			for (i = 0; i < m_idx; ++i) {
				if (_array[i].title() == item.title())
					flag = true;
			}

			if (!flag) {

				if (m_idx == 0) {
					//start the first elemment
					_array = new T[++m_idx];
					_array[0] = item;
				}
				else {
					//add more element
					T* hope = new T[m_idx];

					for (i = 0; i < m_idx; ++i)
						hope[i] = _array[i];
					delete[] _array;
					_array = nullptr;
					m_idx++;
					_array = new T[m_idx];
					for (i = 0; i < (m_idx - 1); ++i)
						_array[i] = hope[i];
					_array[m_idx - 1] = item;
					delete[] hope;
					hope = nullptr;

					if (_observer)
						_observer(*this, item);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= size()) {
				std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
				throw std::out_of_range(err);
			}
			return _array[idx];
		}
		T* operator[](const std::string& title) const {
			bool flag = false;
			size_t helper = 0;
			size_t i;
			for (i = 0; i < m_idx; ++i) {
				if (_array[i].title() == title) {
					helper = i;
					i = m_idx;
					flag = true;
				}
			}
			if (!flag)
			{
				return nullptr;
			}
			return &_array[helper];
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& ost, const Collection<T>& tempT) {
		size_t i;
		size_t temp = tempT.size();
		for (i = 0; i < temp; i++)
		{
			ost << tempT[i];
		}
		return ost;
	};
}
#endif // !SDDS_COLLECTION_H