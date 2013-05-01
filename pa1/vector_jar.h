#include <vector>
#include "jar.h"
#include "marble.h"

using namespace std;

struct VectorJar : public Jar {
	VectorJar() {};
    VectorJar(int len);
    
    VectorJar(const VectorJar& jar);
    
    const Marble& get_elem(int i) const;

	void add(const Marble& m);
	bool is_in_jar(const Marble& m) const;
	void remove(const Marble& m);
	Marble remove_any();
	void clear();
	int marble_number() const;
	int marble_nsize(Marble::Size s) const;
	int marble_ncolor(Marble::Color c) const;
	bool is_empty() const;
	void merge(const Jar& jar1, const Jar& jar2);
	void intersect(const Jar& jar1, const Jar& jar2);
	void difference(const Jar& jar1, const Jar& jar2);

private:
	vector<Marble> vec;
};

ostream& operator<<(ostream& os, const VectorJar& jar);
