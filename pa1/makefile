VEC_SOURCE = marble.cpp vector_jar.cpp jar_test.cpp
VEC_TARGET = jar_test

LL_SOURCE = marble.cpp jar_test.cpp llist_jar.cpp
LL_TARGET = ll_jar_test

all:
	g++ $(VEC_SOURCE) llist_jar.cpp -o jar.o

$(VEC_TARGET): $(VEC_SOURCE)
	g++ $(VEC_SOURCE) -o $@.o
	
$(LL_TARGET): $(LL_SOURCE)
	g++ $(LL_SOURCE) -o $@.o
		
clean:
	rm -f $(VEC_TARGET).o $(LL_TARGET).o jar.o