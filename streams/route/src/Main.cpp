#include "RouteArray.h"
#include "IOHandler.h"
#include "RoutesArrayHandler.h"

#include <array>

int main()
{
    RouteArray arr;
    RoutesArrayHandler arr_handler(&arr);
    IOHandler iohandler(&arr_handler);
    while (iohandler.get_action() != IOHandler::Action::QUIT) {
        continue;
    }
    return 0;


    std::array<int, 10> arra;
    arra.data();
}