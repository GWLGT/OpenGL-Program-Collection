#pragma once

#include <string>

// Useful to Non-useful Utils

namespace Utils {

#ifdef _WIN32
  /// Terminal color is Not Supported on Windows (without additional Setup/WSL)
  struct Color {
    public:
      // All Empty
      std::string Red = "";

      std::string Green = "";

      std::string Orange = "";

      std::string Reset = "";
  };
#else
  /// Struct for Custom Color (Terminal Output, Linux/MacOS-only)
  struct Color {
    public:
      // Bright Red
      std::string Red = "\033[1;91m";

      // Bright Green
      std::string Green = "\033[1;92m";

      // Bright Orange
      std::string Orange = "\033[1;93m";

      // Reset to White (Default)
      std::string Reset = "\033[0m";
  };
#endif

} // namespace Utils
