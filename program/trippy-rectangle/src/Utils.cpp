#include "Utils.hpp"

void Utils::PrintLog(const int Type, const std::string LogString) {
  if (Type == MESSAGE_ERROR) {
    std::cerr << Utils::Color::Red << "ERROR: " << LogString << " EXITING... " << Utils::Color::Orange << "CODE 2" << Utils::Color::Reset << std::endl;
  } else if (Type == MESSAGE_WARNING) {
    std::clog << Utils::Color::Orange << "WARNING: " << LogString << Utils::Color::Reset << std::endl;
  } else if (Type == MESSAGE_OK) {
    std::cout << Utils::Color::Green << "MESSAGE: " << LogString << Utils::Color::Reset << std::endl;
  } else {
    std::clog << Utils::Color::Orange << "WARNING: Invalid Log Type, real Log Message won't be Displayed! " << Utils::Color::Reset << std::endl;
  }
}
