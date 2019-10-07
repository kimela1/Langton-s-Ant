CXX = g++
VARNAME = value
CXXFLAGS = -std=c++0x

project: antMain.o Ant.o
	$(CXX) $(CXXFLAGS) -o project1 antMain.o Ant.o
antMain.o: antMain.cpp Ant.hpp
	$(CXX) $(CXXFLAGS) -c antMain.cpp
Ant.o: Ant.hpp
clean:
	rm *.o project1
