#include "RoutesArrayHandler.h"

RoutesArrayHandler::RoutesArrayHandler(IOHandler iohandler)
	: _iohandler(iohandler) 
{
	this->_route_array = new Array<Element, SIZE>;
	Element el = {
		Route(), Some::EMPTY
	};
	this->_route_array->fill(el);
}

RoutesArrayHandler::~RoutesArrayHandler() {
	delete this->_route_array;
}

void RoutesArrayHandler::run() {
	auto action = this->_iohandler.get_action();
	while (action != IOHandler::Action::QUIT) {
		switch (action) {
		case IOHandler::Action::ADD:
		{
			auto route = this->_iohandler.get_route();
			this->add_route(route);
			break;
		}
		case IOHandler::Action::DELETE:
		{
			auto number = this->_iohandler.get_route_number();
			this->delete_route(number);
			break;
		}
		case IOHandler::Action::EDIT:
		{
			auto number = this->_iohandler.get_route_number();
			auto route = this->find_route(number);
			this->edit_route(route);
			break;
		}
		case IOHandler::Action::FIND:
		{
			auto place = this->_iohandler.get_place_name();
			this->show_routes_with_place(place);
		}
		case IOHandler::Action::SHOW:
		{
			this->show_routes();
			break;
		}
		default: break;
		}
	}
}

void RoutesArrayHandler::add_route(const Route & route) {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	auto added = false;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EMPTY) {
			iter->route = route;
			iter->filled = Some::EXIST;
			added = true;
		}
	}
	if (!added) {
		std::cout << "\n\tArray of routes is full\n";
	}
	else {
		std::sort(begin, end, [](auto & l, auto & r) { return l.route.number() < r.route.number(); });
	}
}

void RoutesArrayHandler::delete_route(size_t number) {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	auto deleted = false;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST && iter->route.number() == number) {
			iter->route = Route();
			iter->filled = Some::EMPTY;
			deleted = true;
		}
	}
	if (!deleted) {
		std::cout << "\n\tRoute not found\n";
	}
	else {
		std::sort(begin, end, [](auto & l, auto & r) { return l.route.number() < r.route.number(); });
	}
}

bool RoutesArrayHandler::contains_route(size_t number) const {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	auto deleted = false;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST && iter->route.number() == number) {
			return true;
		}
	}
	return false;
}

void RoutesArrayHandler::edit_route(Route & route) {
	IInput<std::string> str_in;
	std::cout << "\nPut new start, end and number:\n";
	auto start = str_in.getValueFromInput();
	auto end = str_in.getValueFromInput();
	auto number = IInput<size_t>().getValueFromInput();

	this->delete_route(number);
	this->add_route(Route(start, end, number));
}

Route & RoutesArrayHandler::find_route(size_t number) {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST && iter->route.number() == number) {
			return iter->route;
		}
	}
	throw std::logic_error("RoutesArrayHandler::find_route(): no route in array, check with contains() before using");
}

void RoutesArrayHandler::show_routes() const {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	auto deleted = false;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST) {
			this->show_route(iter->route);
		}
	}
}

void RoutesArrayHandler::show_routes_with_place(const std::string & place) {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	auto found = false;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST) {
			auto start = iter->route.start();
			auto end = iter->route.end();
			if (place == start || place == end) {
				this->show_route(iter->route);
				found = true;
			}
		}
	}
	if (!found) {
		std::cout << "\n\t- no routes\n";
	}
}