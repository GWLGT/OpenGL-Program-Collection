#ifndef UTILS
#define UTILS

// Useful to Non-useful Utils

#include <iostream>
#include <string>

#define MESSAGE_ERROR 0x0F1232
#define MESSAGE_WARNING 0x0F1231
#define MESSAGE_OK 0x0F1230

namespace Utils {
  struct Color {
#ifdef _WIN32
      /// Terminal color is Not Supported on Windows (without additional Setup/WSL)

      // All Empty
      static constexpr const char* Red = "";

      static constexpr const char* Green = "";

      static constexpr const char* Orange = "";

      static constexpr const char* Reset = "";
#else
      /// Struct for Custom Color (Terminal Output, Linux/MacOS-only)

      // Bright Red
      static constexpr const char* Red = "\033[1;91m";

      // Bright Green
      static constexpr const char* Green = "\033[1;92m";

      // Bright Orange
      static constexpr const char* Orange = "\033[1;93m";

      // Reset to White (Default)
      static constexpr const char* Reset = "\033[0m";
#endif
  };

  /// Function to Print Log Message Based on the Type Specified
  void PrintLog(const int Type, const std::string LogString);
} // namespace Utils

#endif
