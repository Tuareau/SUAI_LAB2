#pragma once
#ifndef _ROUTES_ARRAY_HANDLER_H_
#define _ROUTES_ARRAY_HANDLER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

#include "IOHandler.h"
#include "Route.h"
#include "Array.h"

class RoutesArrayHandler
{
private:
	IOHandler _iohandler;

	enum class Some { EXIST, EMPTY };
	struct Element {
		Route route;
		Some filled = Some::EMPTY;
	};

	static const size_t SIZE = 8;
	Array<Element, SIZE> * _route_array;

	Route & find_route(size_t number);
	void show_route(const Route & route) const;

public:
	RoutesArrayHandler(IOHandler iohandler);
	~RoutesArrayHandler();

	void add_route(const Route & route);
	void delete_route(size_t number);
	void edit_route(Route & route);

	bool contains_route(size_t number) const;

	void show_routes() const;
	void show_routes_with_place(const std::string & place);

	void run();

};

#endif
