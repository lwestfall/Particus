INCLUDE=-I include

CXXFLAGS=-Wall -Werror -Wno-psabi -std=c++2a $(INCLUDE) src/*.cpp

particus: src/particus.cpp
	$(CXX) $(CXXFLAGS) -o $@

clean:
	rm particus