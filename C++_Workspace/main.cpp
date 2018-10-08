#include <iostream>

template <class T> Vec {
  public:
	using iterator = T*;
	using const_iterator = const T*;
	using size_type = size_t;
	using value_type = T;
	Vec() {create();}
	explicit Vec(size_type n, const T &val = T()) {create(n, val);}
	Vec(const Vec &v) {create(v.begin(), v.end());} // copy constructor
	Vec &operator=(const Vec &v);
	void push_back(const T &v) {
	  if(avail == limit) { // check if we need to reallocate memory
		grow();
		unchecked_append(val); // append the new element
	  }
	}
  private:
	std::iterator data;
	std::iterator limit;
};

int main() {

  return 0;
}

template <class T> Vec<T> &Vec<T>::operator=(const Vec &v) {
  if(&v != this) {
	uncreate();
	create(v.begin(), v.end());
  }
  retun *this;

