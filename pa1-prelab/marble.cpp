#include "marble.h"

int Marble::random_color() {
	return rand() % 4;
}

int Marble::random_size() {
	return rand() % 3;
}

Marble::Marble() {
	color = (Marble::Color)random_color();
	size = (Marble::Size)random_size();
}

Marble::Marble(Marble::Color c) : color(c) {
	size = (Marble::Size)random_size();
}

Marble::Marble(Marble::Size s) : size(s) {
	color = (Marble::Color)random_color();
}

Marble::Marble(Marble::Color c, Marble::Size s) : color(c), size(s) {}

Marble::Color Marble::get_color() const{
	return color;
}

Marble::Size Marble::get_size() const{
	return size;
}

void Marble::set_color(Color c) {
	color = c;
}

void Marble::set_size(Size s) {
	size = s;
}

bool operator==(const Marble& m1, const Marble& m2) {
    return m1.get_color() == m2.get_color() && m1.get_size() == m2.get_size();
}

ostream& operator<<(ostream& os, const Marble& m) {
    string color_strs[] = {"red", "blue", "yellow", "green"};
    string size_strs[] = {"small", "medium", "large"};
    
    return os << "( " << color_strs[m.get_color()] << " , " << size_strs[m.get_size()] << " )";
}

istream& operator>>(istream& is, Marble& m) {
	string c_str,s_str;
	char c1,c2,c3;
	Marble::Color c;
	Marble::Size s;

	is >> c1 >> c_str >> c2 >> s_str >> c3;
	if(!is) return is;
	if(c1 != '(' || c2 != ',' || c3 != ')') {
		is.clear(ios_base::failbit);
		return is;
	}

	if(c_str == "red")
		c = Marble::red;
	else if(c_str == "blue")
		c = Marble::blue;
	else if(c_str == "yellow")
		c = Marble::yellow;
	else if(c_str == "green")
		c = Marble::green;
	else {
		is.clear(ios_base::failbit);
		return is;
	}

	if(s_str == "small")
		s = Marble::small;
	else if(s_str == "medium")
		s = Marble::medium;
	else if(s_str == "large")
		s = Marble::large;
	else {
		is.clear(ios_base::failbit);
		return is;
	}

	m = Marble((Marble::Color)c,(Marble::Size)s);
	return is;
}