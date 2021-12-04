#include "IOHandler.h"
#include "RoutesArrayHandler.h"

int main()
{
    IOHandler ioh;
    RoutesArrayHandler arr_handler(ioh);
    arr_handler.run();
    return 0;
}