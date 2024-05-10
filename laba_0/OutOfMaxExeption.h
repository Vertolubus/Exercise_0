#pragma once
#include <exception>

class OutOfMaxExeption : public std::exception {
public:
	OutOfMaxExeption(const char* theMessage) : exception(theMessage) { }
};