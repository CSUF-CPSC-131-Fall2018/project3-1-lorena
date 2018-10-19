
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

  size_t size() const{  //overall size of the minideque
    return fronthalf_.size() + backhalf_.size();
  }

  size_t fronthalfsize() const{ //only returns the size of fronthalf deque
    return fronthalf_.size();
  }

  size_t backhalfsize() const{ //only returns the backhalf of the deque
    return backhalf_.size();
  }

  bool empty()  const{ //checks if the overall dequeue is empty
    return (fronthalf_.empty() == true && backhalf_.empty() == true);
  }


  void pop_front(){
    int split; //i'm using this to know # of elements in each vector after split
    if (fronthalfsize() == 0) {
			backhalf_.erase(backhalf_.begin()); //erase the front of backhalf
			split = backhalfsize() / 2;
			for (int i = 0; i < split; i++) {
				fronthalf_.insert(fronthalf_.begin(), backhalf_.front() ); //assign the back elements of backhalf to fronthalf
				backhalf_.erase(backhalf_.begin());                        //delete the elements of backhalf that were copied
			}
		}
		else {
			fronthalf_.pop_back();
		}
  }

  void pop_back(){            //basically the same as po_front but for pop_back
    int split;                //i'm using this to know # of elements in each vector after split
    if (backhalfsize() == 0) {
			fronthalf_.pop_back();
			split = fronthalfsize() / 2;
			for (int i = 0; i < split; i++)
			{
				backhalf_.push_back(fronthalf_.back());
				fronthalf_.erase(fronthalf_.back());
			}
		}
		else {
			backhalf_.pop_back();
		}
  }

  void push_front(const T& value){
    fronthalf_.push_back(value); //the back of the vector is the 'front'
  }

  void push_back(const T& value){ //add an element to the back
    backhalf_.push_back(value);
  }

  const T& front() const{ //returns the value of hte front
    if (fronthalfsize() == 0) {
			return backhalf_.front();
		}
		else {
			return fronthalf_.back();
		}
  }

  const T& back() const{  //returns the value at the back of the minideque
    if (backhalfsize() == 0) {
			return fronthalf_.front();
		}

		else {
		return backhalf_.back();
    }
  }

  T& front(){
    if (fronthalfsize() == 0) {
			return backhalf_.front();
		}
		else {
			return fronthalf_.back();
		}
  }

  T& back(){
    if (backhalfsize() == 0) {
      return fronthalf_.front();
    }

    else {
      return backhalf_.back();
    }
  }

  const T& operator[](size_t index) const{           //returns element given the location
    if( index < fronthalfsize() ){                  //if the index is smaller than size of firsthalf then
      return fronthalf_[fronthalfsize() - index - 1];//index is in the firsthalf
    }
    else{
      return backhalf_[index - fronthalfsize()];  //if index is larger, its in backhalf_
    }
  }
  T& operator[](size_t index){
    if( index < fronthalfsize() ){
      return fronthalf_[fronthalfsize() - index - 1];
    }
    else{
      return backhalf_[index - fronthalfsize()];
    }
  }

  void clear(){         //clear the contents inside both vectors
    backhalf_.clear();
    fronthalf_.clear();
  }

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

#endif /* minideque_h */
