#include "validate_hardware_timestamp.h"
#include <iostream>

int main()
{

rakurai::connector::validate_hardware_timestamp _validate_time("worldtimeapi.org", "/api/ip", "logger_name");
std::cout<< "System time is: "<< _validate_time.get_unixtime()<< std::endl;
return 0;
}
