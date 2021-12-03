#include "Route.h"

Route::Route(const std::string & start, const std::string & end, size_t number) 
	: _start(start), _end(end), _number(number) {}

Route Route::make_route(const std::string & start, const std::string & end, size_t number) {
	return Route(start, end, number);
}

const std::string & Route::start() const {
	return this->_start;
}

const std::string & Route::end() const {
	return this->_end;
}

size_t Route::number() const {
	return this->_number;
}
