
CXX= g++
CXXFLAGS = -Wall -pedantic -ansi -g -std=c++0x
main : Test_pdf TestCases_rokas TestCases_jijo
clean	all: 
		-rm -f Test_pdf TestCases_rokas TestCases_jijo
