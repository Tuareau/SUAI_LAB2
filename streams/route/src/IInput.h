#pragma once
#ifndef _IINPUT_H_
#define _IINPUT_H_

#include <iostream>

template <typename ValueType>
class IInput
{
public:
	enum class mode { clear, skip };

	void clearInput() const {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	ValueType getValueFromInput(mode input_mode = mode::clear) const {
		using std::cin;
		using std::cout;
		using std::endl;

		ValueType value = ValueType();
		while (!(cin >> value)) {
			cout << "\nInvalid input, try again\n";
			clearInput();
		}
		if (input_mode == mode::clear) {
			clearInput();
		}
		return value;
	}
};

#endif