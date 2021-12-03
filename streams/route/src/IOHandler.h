#pragma once
#ifndef _KEEPER_HANDLER_H_
#define _KEEPER_HANDLER_H_

#include <iostream>

#include "IInput.h"
#include "RoutesArrayHandler.h"

class IOHandler
{
private:
	RoutesArrayHandler * _handler;

public:
	explicit IOHandler(RoutesArrayHandler * route_array_handler);

	enum class Action { ADD = 1, DELETE, EDIT, FIND, SHOW, QUIT };
	Action get_action() const;
};

#endif