#pragma once

#ifndef _ROUTE_H_
#define _ROUTE_H_

#include <string>

class Route {
private:
	std::string _start;
	std::string _end;
	size_t _number = 0;

public:
	Route() = default;
	Route(const std::string & start, const std::string & end, size_t number);

	Route(const Route & route) = default;
	Route & operator=(const Route & route) = default;

	static Route make_route(const std::string & start, const std::string & end, size_t number);

	const std::string & start() const;
	const std::string & end() const;
	size_t number() const;

};

#endif