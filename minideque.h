//
//  minideque.h
//  minidequeproject
//

#ifndef minideque_h
#define minideque_h

#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <iostream>


template <typename T>
class minideque {
private:
  std::vector<T> fronthalf_;
  std::vector<T> backhalf_;

public:
  minideque() = default;                                   // do not change, C++ defaults are ok
  minideque(const minideque<T>& other) = default;          // rule of three
  minideque& operator=(const minideque<T>& other) = default;
  ~minideque() = default;

  size_t size() const;             // TODO
  size_t fronthalfsize() const;    // TODO
  size_t backhalfsize() const;     // TODO
  bool empty()  const;              // TODO
  
  int split; //i'm using this to know # of elements in each vector after split

  // balance queue across both vectors if pop_front/back is requested on an empty vector
  // e.g., minideque has this:                  | ABCDEFG
  // after pop_front                        BCD | EFG (A discarded)
  // symmetric logic for converse case: ABCDEFG | ===> ABC | DEF (G discarded) after pop_back
  void pop_front();  // TODO
  void pop_back();   // TODO

  void push_front(const T& value);   // TODO
  void push_back(const T& value);    // TODO

  const T& front() const;   // TODO
  const T& back() const;    // TODO
  T& front();               // TODO
  T& back();                // TODO

  const T& operator[](size_t index) const;  // TODO
  T& operator[](size_t index);              // TODO

  void clear();  // TODO

  friend std::ostream& operator<<(std::ostream& os, const minideque<T>& dq) {    // do not change
    if (dq.empty()) { return os << "minideque is empty"; }

    dq.printFronthalf(os);
    os << "| ";
    dq.printBackhalf(os);
    os << ", front:" << dq.front() << ", back:" << dq.back() << ", size:" << dq.size();
    return os;
  }

  void printFronthalf(std::ostream& os=std::cout) const {                    // do not change
    if (empty()) { std::cout << "fronthalf vector is empty"; }

    for (typename std::vector<T>::const_reverse_iterator crit = fronthalf_.crbegin();
         crit != fronthalf_.crend(); ++crit) {
      os << *crit << " ";
    }
  }

  void printBackhalf(std::ostream& os=std::cout) const {                     // do not change
    if (empty()) { os << "backhalf vector is empty"; }

    for (typename std::vector<T>::const_iterator cit = backhalf_.cbegin();
         cit != backhalf_.cend(); ++cit) {
      os << *cit << " ";
    }
  }
};

size_t minideque::size() const{
  return fronthalf_.size() + backhalf_.size();
}

size_t minideque::fronthalfsize() const {
		return fronthalf_.size();
}

size_t minideque::backhalfsize() const {
		return backhalf_.size();
	}

bool minideque::empty()  const {
		if (fronthalf_.empty() == true && backhalf_.empty() == true)
			return true;
		else {
			return false;
		}
}

void minideque::pop_front() {

		if (fronthalfsize() == 0) {
			backhalf_.erase(vec.begin()); //erase the front of backhalf 
			split = backhalfsize() / 2;
			for (int i = 0; i < split; i++) {
				fronthalf_[i].push_back( backhalf_.begin() ); //assign the back elements of backhalf to fronthalf
				backhalf_.erase(backhalf_.begin()); //delete the elements of backhalf that were copied
			}
		}
		else {
			fronthalf_.pop_back();
		}
}

void minideque::pop_back() {

		if (backhalfsize() == 0) {
			fronthalf_.pop_back();
			split = fronthalfsize() / 2;
			for (int i = 0; i < split; i++)
			{
				backhalf_[i].push_back(fronthalf_.back());
				fronthalf_.erase(fronthalf_.back());
			}
		}
		else {
			backhalf_.pop_back();
		}
}

void minideque::push_front(const T& value) {
		fronthalf_.push_back(value); //the back of the vector is the 'front'
	}

void minideque::push_back(const T& value) {
		backhalf_.push_back(value)
	}

const T& minideque::front() const {
		if (fronthalfsize() == 0) {
			return backhalf_.front();
		}
		else {
			return fronthalf_.back();
		}
}

const T& minideque::back() const {
		if (backhalfsize() == 0) {
			return fronthalf_.front();
		}

		else {
		return backhalf_.back();
    }
}

T& minideque::front() {
		if (fronthalfsize() == 0) {
			return backhalf_.front();
		}
		else {
			return fronthalf_.back();
		}
	}

T& minideque::back() {
		if (backhalfsize() == 0) {
			return fronthalf_.front();
		}

		else {
			return backhalf_.back();
		}
}



#endif /* minideque_h */
