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
			if (!this->contains_route(route.number())) {
				this->add_route(route);
			}
			else {
				std::cout << "\n\tRoute with this number is added already\n";
			}
			break;
		}
		case IOHandler::Action::DELETE:
		{
			auto number = this->_iohandler.get_route_number();
			if (this->contains_route(number)) {
				this->delete_route(number);
			}
			else {
				std::cout << "\n\tRoute with this number don't exist\n";
			}
			break;
		}
		case IOHandler::Action::EDIT:
		{
			auto number = this->_iohandler.get_route_number();
			if (this->contains_route(number)) {
				auto route = this->find_route(number);
				this->edit_route(route);
			}
			else {
				std::cout << "\n\tRoute with this number don't exist\n";
			}			
			break;
		}
		case IOHandler::Action::FIND:
		{
			auto place = this->_iohandler.get_place_name();
			this->show_routes_with_place(place);
			break;
		}
		case IOHandler::Action::SHOW:
		{
			this->show_routes();
			break;
		}
		default:
		{
			throw std::logic_error("RoutesArrayHandler::run(): action type mismatch");
			break;
		}
		}
		action = this->_iohandler.get_action();
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
			break;
		}
	}
	if (!added) {
		std::cout << "\n\tArray of routes is full\n";
	}
	else {
		std::cout << "\n\tSuccessfuly added\n";
		this->_route_array->sort([](auto & l, auto & r) { return l.route.number() < r.route.number(); });
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
			break;
		}
	}
	if (!deleted) {
		std::cout << "\n\tRoute not found\n";
	}
	else {
		std::cout << "\n\tSuccessfuly deleted\n";
		this->_route_array->sort([](auto & l, auto & r) { return l.route.number() < r.route.number(); });
	}
}

bool RoutesArrayHandler::contains_route(size_t number) const {
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST && iter->route.number() == number) {
			return true;
		}
	}
	return false;
}

void RoutesArrayHandler::edit_route(Route & route) {
	std::cout << "\nPut new start, end and number:\n";
	auto new_route = this->_iohandler.get_route();
	this->delete_route(route.number());
	this->add_route(new_route);
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
	std::cout << "\n\tRoutes:\n";
	auto begin = this->_route_array->begin();
	auto end = this->_route_array->end();
	auto found = false;
	for (auto iter = begin; iter != end; ++iter) {
		if (iter->filled == Some::EXIST) {
			found = true;
			this->show_route(iter->route);
		}
	}
	if (!found) {
		std::cout << "\n\t- no routes in array\n";
	}
}

void RoutesArrayHandler::show_routes_with_place(const std::string & place) const {
	std::cout << "\n\tRoutes with place " << place << std::endl;
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

void RoutesArrayHandler::show_route(const Route & route) const {
	auto indent = std::setw(12);
	std::cout << "\n" << indent << "Route #" << route.number() << std::endl;
	std::cout << "\n" << indent << "Start:" << indent << route.start() << std::endl;
	std::cout << indent << "End:" << indent << route.end() << std::endl;

}