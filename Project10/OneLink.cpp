#include <iostream>
template <class T>
struct Element
{
	T data;
	Element* next;
};
template <class T>
class OneListIter {
private:
	Element<T>* current;
public:
	OneListIter(Element<T>* start) : current(start) {}
	bool operator!=(const OneListIter& other) const {
		return current != other.current;
	}
	int& operator*() const {
		return current->data;
	}
	OneListIter& operator++() {
		current = current->next;
		return *this;
	}
	T& operator[](int index) const {
		Element<T>* elem = current;
		for (int i = 0; i < index; i++) {
			elem = elem->next;
		}
		return elem->data;
	}
};
template <class T>
class OneList
{
public:
	OneList();
	void push_front(T);
	void push_back(T);
	void insert(int, T);
	void print();
	void pop_back();
	void pop_front();
	void remove(T);
	int size();
	Element<T>* front();
	Element<T>* back();
	bool empty();
	Element<T>* Move(int);
	OneListIter<T> beg() {
		return OneListIter<T>(begin);
	}

	OneListIter<T> en() {
		return OneListIter<T>(end->next);
	}
private:
	Element<T>* begin;
	Element<T>* end;
	int count;
};
template <class T>
OneList<T>::OneList()
{
	count = 0;
	begin = nullptr;
	end = nullptr;
}
template <class T>
void OneList<T>::push_back(T _data)
{
	Element<T>* elem = new Element<T>;
	elem->data = _data;
	elem->next = nullptr;
	if (begin == nullptr) {
		begin = end = elem;
	}
	else {
		end->next = elem;
		end = elem;
	}
	count++;
}
template <class T>
void OneList<T>::print()
{
	Element<T>* elem = begin;
	for (int i = 0; i < count; i++) {
		printf("%c", elem->data);
		elem = elem->next;
	}
}
template <class T>
void OneList<T>::push_front(T _data)
{
	Element<T>* elem = new Element<T>;
	elem->data = _data;
	if (begin == nullptr) {
		begin = end = elem;
	}
	else {
		elem->next = begin;
		begin = elem;
	}
	count++;
}
template <class T>
void OneList<T>::insert(int n, T _data)
{
	if (begin == nullptr) {
		OneList<T>::push_front(_data);
	}
	else
	{
		if (n == 0) {
			OneList<T>::push_front(_data);
		}
		else
		{
			Element<T>* elem = new Element<T>;
			elem->data = _data;
			Element<T>* elemPrev = Move(n - 1);
			elem->next = elemPrev->next;
			elemPrev->next = elem;
		}
	}
	count++;
}
template <class T>
Element<T>* OneList<T>::Move(int index) {
	Element<T>* idx = begin;
	for (int i = 0; i < index; i++) {
		idx = idx->next;
	}
	return idx;
}
template <class T>
void OneList<T>::pop_front()
{
	Element<T>* delElem = begin;
	if (begin != nullptr) {
		begin = begin->next;
		delete delElem;
		count--;
	}
}
template <class T>
void OneList<T>::pop_back()
{
	int index = count - 1;
	if (begin != nullptr) {
		Element<T>* elemPrev = Move(index - 1);
		Element<T>* elemDel = elemPrev->next;
		elemPrev->next = elemDel->next;
		delete elemDel;
		count--;
	}
}
template <class T>
void OneList<T>::remove(T el) {

	if (begin->data == el) {
		pop_front();
	}
	int r = 0;
	Element<T>* elemPrev = begin;
	Element<T>* idx = begin->next;
	for (int i = 1; i < count; i++) {
		if (idx->data == el) {
			elemPrev->next = idx->next;
			delete idx;
			r++;
			idx = elemPrev->next;
		}
		else
		{
			elemPrev = elemPrev->next;
			idx = idx->next;
		}
	}
	for (int i = 0; i < r; i++) {
		count--;
	}
}
template <class T>
int OneList<T>::size() {
	return count;
}
template <class T>
Element<T>* OneList<T>::front() {
	return begin;
}
template <class T>
Element<T>* OneList<T>::back() {
	return end;
}
template <class T>
bool OneList<T>::empty() {
	if (begin == nullptr) {
		return false;
	}
	else
	{
		return true;
	}
}
