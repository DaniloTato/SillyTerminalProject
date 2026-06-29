#pragma once

#include <filesystem>

class SafePath {
private:
  std::filesystem::path safePath;

public:
  SafePath(const std::filesystem::path &path);
  [[nodiscard]] const std::filesystem::path &get() const;
};