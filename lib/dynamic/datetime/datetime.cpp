#include "datetime.h"

#include <iomanip>
#include <ctime>
#include <sstream>

std::string getCurrentDateTime() {
	std::time_t t = std::time(nullptr);
	std::tm local = *std::localtime(&t);

	std::ostringstream oss;
	oss << std::put_time(&local, "%d-%m-%Y_%H-%M-%S");
	return oss.str();
}