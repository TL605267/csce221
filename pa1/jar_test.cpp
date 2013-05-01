#include <cstdlib>
#include <fstream>
#include <time.h>

#include "vector_jar.h"
#include "llist_jar.h"

void writeJarToFile(Jar& J1, string fileName) {
	char c[] = {'r','b','y','g'};
	char s[] = {'s','m','l'};
	ofstream os;
	os.open(fileName.c_str());
	if(os.fail())
		cout << "ERROR: File write error." << endl;
	for(int i = 0; i < J1.marble_number(); ++i) {
		Marble m = J1.get_elem(i);
		os << c[m.get_color()] << ' ' << s[m.get_size()] << endl;
	}
}

void readJarFromFile(Jar& J2, string fileName) {
	ifstream is;
	is.open(fileName.c_str());
	if(is.fail())
		cout << "ERROR: File read error." << endl;
	string read_str;
	while(getline(is,read_str)) {
		char c = read_str[0];
		char s = read_str[2];
		Marble::Color col;
		Marble::Size siz;
		
		switch(c) {
			case 'r':
				col = Marble::red;
				break;
			case 'b':
				col = Marble::blue;
				break;
			case 'y':
				col = Marble::yellow;
				break;
			case 'g':
				col = Marble::green;
				break;
			default:
				cout << "ERROR: Invalid color: " << c << '.';
		}
		
		switch(s) {
			case 's':
				siz = Marble::small;
				break;
			case 'm':
				siz = Marble::medium;
				break;
			case 'l':
				siz = Marble::large;
				break;
			default:
				cout << "ERROR: Invalid size: " << s << '.';
		}
		
		J2.add(Marble(col,siz));
	}
}

void print_menu() {
	cout << endl << "1) Enter the number of marbles to create a jar (≤ 12)" << endl
	<< "2) Write all the jar marbles to a file" << endl
	<< "3) Read a jar from a file (notation for colors: r,y,b,g; for sizes: s,m,l)" << endl
	<< "4) Remove a marble with specific color" << endl
	<< "5) Remove a marble with specific size" << endl
	<< "6) Merge 2 jars read from 2 files, print the resulting jar to the file named “merge.out”" << endl
	<< "7) Intersect 2 jars read from 2 files, print the resulting jar to the file named “intersection.out”" << endl
	<< "8) Compute difference of 2 jars read from 2 files, print the resulting jar to the file named “completion.out”" << endl
	<< "9) Exit the program" << endl
	<< "Please enter a choice: ";
}

int main()
{
	srand(time(0));  // for random marbles
	int jarflag;
	
	// if the user enter 1, then you should test vector jars;
	// otherwise, enter 2 to test list jars.
	cout << "Which kind of jar do you want to test? "
	"(1: vector jar; 2: list jar)" << endl
	<< "Enter choice: ";
	cin >> jarflag;
	
	if(jarflag==1)
	{
		// jarflag = 1, do testing as instructed;
		// show a menu with choices to let the user to choose ways
		// to generate vector jar objects: VectorJar
		VectorJar* jar;
		while(true) {
			print_menu();
			int choice;
			cin >> choice;
			cout << endl;
			switch(choice) {
				case 1: {
					int num = 0;
					while(true) {
						cout << "Enter a number from 1 to 12: ";
						cin >> num;
						if(num < 1 || num > 12)
							cout << "ERROR: Number not in range." << endl;
						else
							break;
					}
					jar = new VectorJar(num);
					cout << "Jar created." << endl;
					break;
				}
				case 2: {
					string filename;
					cout << "Enter a name for the jar file: ";
					cin >> filename;
					writeJarToFile(*jar, filename);
					cout << "File '" << filename << "' created." << endl;
					break;
				}
				case 3: {
					jar = new VectorJar;
					string filename;
					cout << "Enter a file to read: ";
					cin >> filename;
					readJarFromFile(*jar,filename);
					cout << "Done." << endl;
					break;
				}
				case 4: {
					char c;
					Marble::Color col;
					bool fail = false;
					cout << "Enter a color: ";
					cin >> c;
					
					switch(c) {
						case 'r':
							col = Marble::red;
							break;
						case 'b':
							col = Marble::blue;
							break;
						case 'y':
							col = Marble::yellow;
							break;
						case 'g':
							col = Marble::green;
							break;
						default:
							cout << "ERROR: Invalid color: " << c << '.' << endl;
							fail = true;
					}
					
					if(!fail) {
						Marble m(col);
						jar->remove(m);
						cout << "Marble removed." << endl;
					}
					break;
				}
				case 5: {
					char s;
					Marble::Size siz;
					bool fail = false;
					cout << "Enter a size: ";
					cin >> s;
					
					switch(s) {
						case 's':
							siz = Marble::small;
							break;
						case 'm':
							siz = Marble::medium;
							break;
						case 'l':
							siz = Marble::large;
							break;
						default:
							cout << "ERROR: Invalid size: " << s << '.';
					}
					
					if(!fail) {
						Marble m(siz);
						jar->remove(m);
						cout << "Marble removed." << endl;
					}
					break;
				}
				case 6: {
					string file1, file2;
					cout << "Enter the first file to read: ";
					cin >> file1;
					cout << "Enter the second file to read: ";
					cin >> file2;
					VectorJar jar1, jar2;
					readJarFromFile(jar1, file1);
					readJarFromFile(jar2, file2);
					jar = new VectorJar;
					jar->merge(jar1,jar2);
					writeJarToFile(*jar,"merge.out");
					cout << "File 'merge.out' created." << endl;
					break;
				}
				case 7: {
					string file1, file2;
					cout << "Enter the first file to read: ";
					cin >> file1;
					cout << "Enter the second file to read: ";
					cin >> file2;
					VectorJar jar1, jar2;
					readJarFromFile(jar1, file1);
					readJarFromFile(jar2, file2);
					jar = new VectorJar;
					jar->intersect(jar1,jar2);
					writeJarToFile(*jar,"intersection.out");
					cout << "File 'intersection.out' created." << endl;
					break;
				}
				case 8: {
					string file1, file2;
					cout << "Enter the first file to read: ";
					cin >> file1;
					cout << "Enter the second file to read: ";
					cin >> file2;
					VectorJar jar1, jar2;
					readJarFromFile(jar1, file1);
					readJarFromFile(jar2, file2);
					jar = new VectorJar;
					jar->difference(jar1,jar2);
					writeJarToFile(*jar,"completion.out");
					cout << "File 'completion.out' created." << endl;
					break;
				}
				case 9:
					cout << "Goodbye!" << endl << endl;
					delete jar;
					exit(0);
				default:
					cout << "ERROR: Invalid input." << endl;
			}
		}
	}
    else if(jarflag==2)
	{
		// jarflag = 2, do testing as instructed;
		// show a menu with choices to let the user to choose
		
        LListJar* jar;
		while(true) {
			print_menu();
			int choice;
			cin >> choice;
			cout << endl;
			switch(choice) {
				case 1: {
					int num = 0;
					while(true) {
						cout << "Enter a number from 1 to 12: ";
						cin >> num;
						if(num < 1 || num > 12)
							cout << "ERROR: Number not in range." << endl;
						else
							break;
					}
					jar = new LListJar(num);
					cout << "Jar created." << endl;
					break;
				}
				case 2: {
					string filename;
					cout << "Enter a name for the jar file: ";
					cin >> filename;
					writeJarToFile(*jar, filename);
					cout << "File '" << filename << "' created." << endl;
					break;
				}
				case 3: {
					jar = new LListJar;
					string filename;
					cout << "Enter a file to read: ";
					cin >> filename;
					readJarFromFile(*jar,filename);
					cout << "Done." << endl;
					break;
				}
				case 4: {
					char c;
					Marble::Color col;
					bool fail = false;
					cout << "Enter a color: ";
					cin >> c;
					
					switch(c) {
						case 'r':
							col = Marble::red;
							break;
						case 'b':
							col = Marble::blue;
							break;
						case 'y':
							col = Marble::yellow;
							break;
						case 'g':
							col = Marble::green;
							break;
						default:
							cout << "ERROR: Invalid color: " << c << '.' << endl;
							fail = true;
					}
					
					if(!fail) {
						Marble m(col);
						jar->remove(m);
						cout << "Marble removed." << endl;
					}
					break;
				}
				case 5: {
					char s;
					Marble::Size siz;
					bool fail = false;
					cout << "Enter a size: ";
					cin >> s;
					
					switch(s) {
						case 's':
							siz = Marble::small;
							break;
						case 'm':
							siz = Marble::medium;
							break;
						case 'l':
							siz = Marble::large;
							break;
						default:
							cout << "ERROR: Invalid size: " << s << '.';
					}
					
					if(!fail) {
						Marble m(siz);
						jar->remove(m);
						cout << "Marble removed." << endl;
					}
					break;
				}
				case 6: {
					string file1, file2;
					cout << "Enter the first file to read: ";
					cin >> file1;
					cout << "Enter the second file to read: ";
					cin >> file2;
					LListJar jar1, jar2;
					readJarFromFile(jar1, file1);
					readJarFromFile(jar2, file2);
					jar = new LListJar;
					jar->merge(jar1,jar2);
					writeJarToFile(*jar,"merge.out");
					cout << "File 'merge.out' created." << endl;
					break;
				}
				case 7: {
					string file1, file2;
					cout << "Enter the first file to read: ";
					cin >> file1;
					cout << "Enter the second file to read: ";
					cin >> file2;
					LListJar jar1, jar2;
					readJarFromFile(jar1, file1);
					readJarFromFile(jar2, file2);
					jar = new LListJar;
					jar->intersect(jar1,jar2);
					writeJarToFile(*jar,"intersection.out");
					cout << "File 'intersection.out' created." << endl;
					break;
				}
				case 8: {
					string file1, file2;
					cout << "Enter the first file to read: ";
					cin >> file1;
					cout << "Enter the second file to read: ";
					cin >> file2;
					LListJar jar1, jar2;
					readJarFromFile(jar1, file1);
					readJarFromFile(jar2, file2);
					jar = new LListJar;
					jar->difference(jar1,jar2);
					writeJarToFile(*jar,"completion.out");
					cout << "File 'completion.out' created." << endl;
					break;
				}
				case 9:
					cout << "Goodbye!" << endl << endl;
					delete jar;
					exit(0);
				default:
					cout << "ERROR: Invalid input." << endl;
			}
		}
	}
	else
	{
		cout<<"wrong number entered"<<endl;
	}
	return 0;
}
