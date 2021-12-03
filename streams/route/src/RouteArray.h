#pragma once

#ifndef _ROUTE_ARRAY_H_
#define _ROUTE_ARRAY_H_

#include <string>
#include <stdexcept>

#include "Route.h"

class RouteArray
{
public:
	static const size_t SIZE = 8;

private:
	size_t _size = 0;
	Route * _routes[SIZE];

public:
	RouteArray() = default;
	~RouteArray();

	const Route & operator[](size_t i) const;

	size_t size() const;

	void insert(const Route & route);
	void erase(const Route & route);

	Route & find(const Route & route);

};

#endif