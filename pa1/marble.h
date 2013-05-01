// The class Marble is defined here 
// 

#ifndef MARBLE_H_ 
#define MARBLE_H_

#include <iostream> 

using namespace std;

class Marble { 
public: 
   class Bad_input {}; // exception class
   enum Color {red, blue, yellow, green}; 
   enum Size {small, medium, large}; 

private: 
   Color color; 
   Size size; 
   // internal functions 
   int random_color(); 
   int random_size(); 

public: 
	Marble();
	Marble(Color c);
	Marble(Size s);
	Marble(Color c, Size s);

   Color get_color() const;   
   Size get_size() const; 
   void set_color(Color c);
   void set_size(Size s);
};

// helper functions
bool operator==(const Marble& m1, const Marble& m2);      
ostream& operator<<(ostream& os, const Marble& m); 
istream& operator>>(istream& is, Marble& m);

#endif // end of the file marble.h 
