#include "marble.h"

int main() {
	srand(time(0));

    Marble m1;
    Marble m2(Marble::red);
    Marble m3(Marble::medium);
    Marble m4(Marble::red, Marble::medium);
	Marble m5;
	Marble m6;

    cout << "Test output:" << endl <<
			m1 << endl <<
            m2 << endl <<
            m3 << endl <<
            m4 << endl << endl;

	cout << "NOTE: Format for marbles is ( color , size ) with spaces." << endl;
	while(true) {
		cin.clear();
		cout << "Enter marble 1: ";
		cin >> m5;
		cout << "Enter marble 2: ";
		cin >> m6;

		if(cin.fail())
			break;

		if(m5 == m6)
			cout << "Your marbles are equal." << endl;
		else
			cout << "Your marbles are not equal." << endl; 
	}
	return 0;
}