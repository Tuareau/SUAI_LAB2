#include "IOHandler.h"

IOHandler::IOHandler(RoutesArrayHandler * route_array_handler) 
	: _handler(route_array_handler) {}

IOHandler::Action IOHandler::get_action() const {
	using std::cout;
	cout << "\n\tROUTES\n";
	cout << "\n\tRouteArray keeps 8 routes you can edit\n";

	int choice = 0;
	while (choice != int(IOHandler::Action::QUIT)) {
		cout << "\nChoose action:\n";
		cout << "1 - add route\n";
		cout << "2 - delete route\n";
		cout << "3 - edit route\n";
		cout << "4 - find route by place\n";
		cout << "5 - show routes\n";
		cout << "6 - quit\n";

		IInput<int> input;
		choice = input.getValueFromInput();
		if (choice < 0 || choice > 6) {
			system("cls");
			cout << "\nWrong choice, try again\n";
			continue;
		}

		system("cls");
		switch (choice) {
		case 1: 
		{
			this->_handler->add_route();
			break;
		}
		case 2:
		{
			this->_handler->delete_route();
			break;
		}
		case 3:
		{
			this->_handler->edit_route();
			break;
		}
		case 4:
		{
			this->_handler->find_route();
			break;
		}
		case 5: 
		{
			this->_handler->show_routes();
			break;
		}
		default: break;
		}
	}
	return Action::QUIT;
}