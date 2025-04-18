#ifndef UTILS_HPP
#define UTILS_HPP

// Useful to Non-useful Utils

namespace Utils {
  class Color {
    public:
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
} // namespace Utils

#endif
