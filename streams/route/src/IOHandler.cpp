#include "IOHandler.h"

Route IOHandler::get_route() const {
	using std::cout;
	cout << "\n\tCREATE ROUTE\n";
	cout << "\n\tUp to 8 routes can be created\n";

	IInput<std::string> str_in;
	cout << "\nPut start, end and number:\n";
	auto start = str_in.getValueFromInput();
	auto end = str_in.getValueFromInput();
	auto number = IInput<size_t>().getValueFromInput();

	return Route::make_route(start, end, number);
}

size_t IOHandler::get_route_number() const {
	std::cout << "\nPut number of route: ";
	auto number = IInput<size_t>().getValueFromInput();
	return number;
}

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
		case 1: return IOHandler::Action::ADD;
		case 2: return IOHandler::Action::DELETE;
		case 3: return IOHandler::Action::EDIT;
		case 4: return IOHandler::Action::FIND;
		case 5:  return IOHandler::Action::SHOW;
		default: break;
		}
	}
	return Action::QUIT;
}