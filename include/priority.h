/**                                                                                                 
 * Data Structures: Assignment 3 - Priority Queue & Dijkstra
 *                                                                                                  
 * MinPriorityQueue: Implementation of a PriorityItem & Min Priority Queue using a
 *                   binary heap (array). Through the use of member functions, the
 *                   API allows PriorityItems to be inserted, the item with the lowest
 *                   priority (first element in array) to be queried & deleted, as well
 *                   as can the Priority Queue be queried if it's empty.
 *                   Operators (<, >, ==, <=, >=) are overloaded for easy comparison
 *                   of PriorityItems.
 *                                                                                                  
 * @author Efraim Lumunon (s1077694)                                                                
 * @file priority.h                                                                                 
 * @date 29-11-2019                                                                                 
 **/    

#ifndef MIN_PRIORITY_QUEUE_H_
#define MIN_PRIORITY_QUEUE_H_

#define MAX 1000

#include <iostream>
#include <cmath> // floor

template<class T>
struct PriorityItem {
  T key;
  int priority;
  PriorityItem(){};
  PriorityItem(T key, int priority):key(key), priority(priority){}
  ~PriorityItem(){};

  bool operator<(const PriorityItem &other) const {
    return priority < other.priority;
  }
  bool operator>(const PriorityItem &other) const {
    return priority > other.priority;
  }
  bool operator==(const PriorityItem &other) const {
    return priority == other.priority;
  }
  bool operator<=(const PriorityItem &other) const {
    return *this < other || *this == other;
  }
  bool operator>=(const PriorityItem &other) const {
    return *this > other || *this == other;
  }
};

template<class T>
class MinPriorityQueue {
public:
  MinPriorityQueue();
  ~MinPriorityQueue();

  /**
   * @function IsEmpty
   * @abstract Check if MinPriorityQueue is empty.
   * @param -
   * @return Boolean indicating whether MinPriorityQueue is empty.
   * @pre -
   * @post -
   **/
  bool IsEmpty() const;

  /**
   * @function GetSize
   * @abstract Get count of elements currently in MinPriorityQueue.
   * @param -
   * @return Integer indicating the count of elements in MinPriorityQueue (last_position+1).
   * @pre -
   * @post -
   **/
  int GetSize() const;

  /**
   * @function GetMinimum
   * @abstract Get PriorityItem with the lowest priority; first element in binary heap.
   * @param -
   * @return PriorityItem of type T with the lowest priority.
   * @pre -
   * @post If binary heap is empty, exception is thrown: "Binary Heap is empty".
   **/
  PriorityItem<T> GetMinimum() const;

  /**
   * @function DeleteMinimum
   * @abstract Delete PriorityItem with lowest priority (first item in binary heap) by
   *           swapping item with last item in binary heap (last item in binary heap),
   *           then decreasing last_position, and finally resorting binary heap using
   *           member function TrickleDown.
   * @param -
   * @return -
   * @pre -
   * @post Binary heap has changed; next lowest PriorityItem now first in array,
   *       or binary heap remains unchanged (binary heap was already empty).
   **/
  void DeleteMinimum();

  /**
   * @function Insert
   * @abstract Insert new PriorityItem after last_position in binary heap, increases
   *           last_position, and finally resorting binary heap using member function
   *           TrickleUp.
   * @param Value of type T to serve as key of PriorityItem, int value indicating priority.
   * @return -
   * @pre Parameter key must be of type T.
   * @post Size of MinPriorityQueue has increased by 1, and PriorityItem has been added at
   *       right position in binary heap; or binary heap remains unchanged, exception is
   *       thrown: "Binary Heap is full".
   **/
  void Insert(const T &key, const int &prio);

private:
  PriorityItem<T> heap[MAX];
  int last_position;

  /**
   * @function Swap
   * @abstract Swap position of two items in MinPriorityQueue.
   * @param Int values of index of first & second items to swap.
   * @return -
   * @pre Parameters must be within bounds of amount of items contained within
   *      MinPriorityQueue.
   * @post PriorityItems at indices have swapped positions.
   **/
  void Swap(const int &from, const int &to);

  /**
   * @function TrickleDown
   * @abstract Sort PriorityItem downward using recursion based on its priority
   *           compared to its current children. Necessary for resorting after
   *           deletion of PriorityItem.
   * @param Int value of index of item from where to start sorting process.
   * @return -
   * @pre Parameter parent must be within bounds of amount of items contained
   *      within MinPriorityQueue.
   * @post Items in MinPriorityQueue have been sorted.
   **/
  void TrickleDown(const int &parent);

  /**
   * @function TrickleUp
   * @abstract Sort PriorityItem upward using recursion based on its priority
   *           compared to its parent. Necessary for resorting after inserting
   *           new PriorityItem.
   * @param Int value of index of item from where to start sorting process.
   * @return -
   * @pre Parameter parent must be within bounds of amount of items contained
   *      within MinPriorityQueue.
   * @post Items in MinPriorityQueue have been sorted.
   **/
  void TrickleUp(const int &position);
};

template<class T>
MinPriorityQueue<T>::MinPriorityQueue(){
  last_position = -1;
}

template<class T>
MinPriorityQueue<T>::~MinPriorityQueue(){
  last_position = -1;
}

template<class T>
bool MinPriorityQueue<T>::IsEmpty() const {
  if(last_position == -1)
    return true;
  else
    return false;
}

template<class T>
int MinPriorityQueue<T>::GetSize() const {
  return last_position + 1;
}

template<class T>
PriorityItem<T> MinPriorityQueue<T>::GetMinimum() const {
  if(this->IsEmpty()){
    throw "Binary Heap is empty";
  } else {
    return heap[0];
  }
}

template<class T>
void MinPriorityQueue<T>::DeleteMinimum(){
  if(!this->IsEmpty()){
    Swap(0, last_position--);
    TrickleDown(0);
  }
}

template<class T>
void MinPriorityQueue<T>::Insert(const T &key, const int &prio){
  if(last_position == MAX-1){
    throw "Binary Heap is full";
  } else {
    PriorityItem<T> item_to_add = PriorityItem<T>(key, prio);
    heap[++last_position] = item_to_add;
    TrickleUp(last_position);
  }
}

template<class T>
void MinPriorityQueue<T>::Swap(const int &from, const int &to){
  PriorityItem<T> temp = heap[from];
  heap[from] = heap[to];
  heap[to] = temp;
}

template<class T>
void MinPriorityQueue<T>::TrickleDown(const int &parent){
  int left_child = 2 * parent + 1;
  int right_child = 2 * parent + 2;

  if(left_child == last_position && heap[parent] > heap[left_child]){
    Swap(parent, left_child);
    return;
  
  } else if(right_child == last_position && heap[parent] > heap[right_child]){
    Swap(parent, right_child);
    return;
  
  } else if(left_child >= last_position || right_child >= last_position){
    return;
  
  } else if(heap[left_child] < heap[right_child] && heap[parent] > heap[left_child]){
    Swap(parent, left_child);
    TrickleDown(left_child);
  
  } else if(heap[parent] > heap[right_child]){
    Swap(parent, right_child);
    TrickleDown(right_child);
  }
}

template<class T>
void MinPriorityQueue<T>::TrickleUp(const int &position){
  if(position == 0){
    return;
  } else {
    int parent = (int)floor((position-1)/2);
    if(heap[position] < heap[parent]){
      Swap(position, parent);
      TrickleUp(parent);
    }
  }
}

#endif // MIN_PRIORITY_QUEUE_H_
