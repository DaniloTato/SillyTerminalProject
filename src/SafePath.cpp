#include "SafePath.hpp"

#if defined(__APPLE__)
#include <mach-o/dyld.h>
#elif defined(__linux__)
#include <unistd.h>
#elif defined(_WIN32)
#include <windows.h>
#endif

namespace {

std::filesystem::path getExecutableDir() {
#if defined(__APPLE__)
  uint32_t size = 0;
  _NSGetExecutablePath(nullptr, &size);
  std::string buffer(size, '\0');
  _NSGetExecutablePath(buffer.data(), &size);
  return std::filesystem::path(buffer).parent_path();

#elif defined(__linux__)
  char result[1024];
  ssize_t count = readlink("/proc/self/exe", result, sizeof(result));
  return std::filesystem::path(std::string(result, count)).parent_path();

#elif defined(_WIN32)
  char buffer[MAX_PATH];
  GetModuleFileNameA(nullptr, buffer, MAX_PATH);
  return std::filesystem::path(buffer).parent_path();
#endif
}

std::filesystem::path getPath(const std::filesystem::path &relativePath) {
  std::filesystem::path base = getExecutableDir();

  std::filesystem::path full = base / relativePath;

  return full.make_preferred().string();
}

} // namespace

SafePath::SafePath(const std::filesystem::path &path)
    : safePath(getPath(path)) {}

const std::filesystem::path &SafePath::get() const { return safePath; }