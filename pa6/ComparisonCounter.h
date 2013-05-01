//
//  ComparisonCounter.h
//  
//
//  Created by Devin Tuchsen on 4/29/13.
//
//

#ifndef _ComparisonCounter_h
#define _ComparisonCounter_h

class ComparisonCounter {
	int cmps;
public:
	ComparisonCounter() {
		cmps = 0;
	}
	void addCmp() {++cmps;}
	void reset() {cmps = 0;}
	int getCmps() {return cmps;}
};

#endif
