#pragma once
#ifndef _KEEPER_HANDLER_H_
#define _KEEPER_HANDLER_H_

#include <iostream>

#include "IInput.h"
#include "Route.h"

class IOHandler
{
public:
	enum class Action { ADD = 1, DELETE, EDIT, FIND, SHOW, QUIT };
	Action get_action() const;

	Route get_route() const;
	size_t get_route_number() const;
};

#endif