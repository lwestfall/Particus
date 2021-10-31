INCLUDE=-I include

CXXFLAGS=-Wall -Werror -std=c++2a $(INCLUDE) src/*.cpp

particus: src/particus.cpp
	$(CXX) $(CXXFLAGS) -o $@

clean:
	rm particus