#include <iostream>
template <class T>
struct Element
{
	T data;
	Element* next;
	Element* prev;
};
template <class T>
class TwoListIter {
private:
	Element<T>* current;
public:
	TwoListIter(Element<T>* start) : current(start) {}
	bool operator!=(const TwoListIter& other) const {
		return current != other.current;
	}
	int& operator*() const {
		return current->data;
	}
	TwoListIter& operator++() {

		current = current->next;
		return *this;
	}
	TwoListIter& operator--() {
		current = current->prev;
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
class TwoList
{
public:
	TwoList();
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
	TwoListIter<T> beg() {
		return TwoListIter<T>(begin);
	}

	TwoListIter<T> en() {
		return TwoListIter<T>(end);
	}
private:
	Element<T>* begin;
	Element<T>* end;
	int count;
};
template <class T>
TwoList<T>::TwoList()
{
	count = 0;
	begin = nullptr;
	end = nullptr;
}
template <class T>
void TwoList<T>::push_back(T _data)
{
	Element<T>* elem = new Element<T>;
	elem->data = _data;
	elem->next = nullptr;
	if (begin == nullptr) {
		begin = end = elem;
	}
	else {
		end->next = elem;
		elem->prev = end;
		end = elem;
	}
	count++;
}
template <class T>
void TwoList<T>::print()
{
	Element<T>* elem = begin;
	for (int i = 0; i < count; i++) {
		printf("%c", elem->data);
		elem = elem->next;
	}
}
template <class T>
void TwoList<T>::push_front(T _data)
{
	Element<T>* elem = new Element<T>;
	elem->data = _data;
	elem->prev = nullptr;
	if (begin == nullptr) {
		begin = end = elem;
	}
	else {
		elem->next = begin;
		begin->prev = elem;
		begin = elem;
	}
	count++;
}
template <class T>
void TwoList<T>::insert(int n, T _data)
{
	if (begin == nullptr) {
		TwoList<T>::push_front(_data);
	}
	if (n == 0) {
		Element<T>* elem = new Element<T>;
		elem->data = _data;
		elem->prev = nullptr;
		elem->next = begin;
		begin->prev = elem;
		begin = elem;
		count++;
	}
	else
	{
		
		Element<T>* elem = new Element<T>;
		elem->data = _data;
		Element<T>* elemPrev = Move(n - 1);
		Element<T>* elemCur = Move(n);
		elem->next = elemCur;	
		elem->prev = elemPrev;
		elemPrev->next = elem;
		elemCur->prev = elem;
		count++;
	}
}
template <class T>
Element<T>* TwoList<T>::Move(int index) {
	Element<T>* idx = begin;
	for (int i = 0; i < index; i++) {
		idx = idx->next;
	}
	return idx;
}
template <class T>
void TwoList<T>::pop_front()
{
	Element<T>* delElem = begin;
	if (begin != nullptr) {
		begin = begin->next;
		delete delElem;
		count--;
	}
}
template <class T>
void TwoList<T>::pop_back()
{
	if (begin != nullptr) {
		Element<T>* elemPrev = end->prev;
		Element<T>* elemDel = end;
		elemPrev->next = nullptr;
		end = elemPrev;
		delete elemDel;
		count--;
	}
}
template <class T>
void TwoList<T>::remove(T el) {

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
int TwoList<T>::size() {
	return count;
}
template <class T>
Element<T>* TwoList<T>::front() {
	return begin;
}
template <class T>
Element<T>* TwoList<T>::back() {
	return end;
}
template <class T>
bool TwoList<T>::empty() {
	if (begin == nullptr) {
		return false;
	}
	else
	{
		return true;
	}

}
void main() {
	TwoList<char> a;
	int n = 0;
	char input;
	while ((input = getchar()) != '\n') {
		a.push_back(input);
		n++;
	}
	a.push_back('\0');
	a.push_front('\0');
	n++;
	TwoListIter<char> b = a.beg();
	n++;
	for (int i = 0; i < n; i++) {

		if (b[i] >= '0' && b[i] <= '9') {
			if ((b[i] - '0') % 2 == 0) {
				a.insert(i + 1, '+');
				a.insert(i + 2, '+');
				i += 2;
				n += 2;
			}
			else {
				a.remove(b[i]);
				n--;
				i--;
			}
		}

	}
	a.print();
}