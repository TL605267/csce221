// Linked Queue

#include "LinkedQueue.h"
#include <iostream>

using namespace std;

int main()
try {
  LinkedQueue queue;
  LinkedQueue queue_copy;

  //===== enqueue() =====

  string s1("1");
  queue.enqueue(s1);
  string s2("22");
  queue.enqueue(s2);
  string s3("333");
  queue.enqueue(s3);
  string s4("4444");
  queue.enqueue(s4);
  string s5("55555");
  queue.enqueue(s5);
  string s6("123456");
  queue.enqueue(s6);

  cout << "queue = " << queue << endl;
  cout << "size of queue = " << queue.size() << endl;
  cout << "first of queue = " << queue.first() << endl << endl;
     
  //===== assignment operator =====
   
  queue_copy = queue;
  cout << "assigning queue to queue_copy, queue_copy = ";
  cout << queue_copy << endl;
  cout << "size of queue_copy = " << queue_copy.size() << endl;
  cout << "first of queue_copy = " << queue_copy.first() << endl << endl;
   
  //===== copy constructor =====
   
  LinkedQueue queue_copy2(queue);
  cout << "copy constructor queue = ";
  cout << queue_copy2 << endl;
  cout << "size of queue_copy2 = " << queue_copy2.size() << endl;
  cout << "first of queue_copy2 = " << queue_copy2.first() << endl << endl;
   
  //===== dequeue() =====
   
  while (!queue_copy2.isEmpty()) {
    cout << queue_copy2.dequeue() << endl;
  }   

  cout << "dequeueing all elements from queue_copy2, queue_copy2 = ";
  cout << queue_copy2 << endl;
   
  //queue_copy2.dequeue(); Throws exception

  cout << endl;
   
  cout << "original queue:" << endl;
  cout << queue << endl;

  return 0;
 } catch(RuntimeException &e) {
   cout << e << endl;
 }
