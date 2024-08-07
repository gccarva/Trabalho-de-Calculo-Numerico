cppfiles = $(wildcard *.cpp)
Obj = $(cppfiles:.cpp=.o)
main : $(Obj)
	g++ $(Obj) -Wall -Wextra -g -o main
%.o: %.cpp %.hpp
	g++ -g -Wall -Wextra $< -c 
