//
//  PQComp.h
//  
//
//  Created by Devin Tuchsen on 3/28/13.
//
//

#ifndef _PQComp_h
#define _PQComp_h

#include "Item.h"

template<typename ElemType >
struct PQComp {
	int operator()(const Item<ElemType>& e1, const Item<ElemType>& e2) {
		return e1.getKey() - e2.getKey();
	}
};

#endif
