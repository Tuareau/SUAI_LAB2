#pragma once
#ifndef _ROUTES_ARRAY_HANDLER_H_
#define _ROUTES_ARRAY_HANDLER_H_

#include <string>

#include "RouteArray.h"

class RoutesArrayHandler
{
private:
	RouteArray * _route_array;

	Route get_route() const;

public:
	explicit RoutesArrayHandler(RouteArray * route_array);

	void add_route();
	void delete_route();
	void edit_route();

	void find_route() const;
	void show_routes() const;

};

#endif
