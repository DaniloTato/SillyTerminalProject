#include <ROT/ASCIITexture.hpp>

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

namespace rot {

void ASCIITexture::loadTextureFromTxt(const std::filesystem::path &path) {
  std::ifstream file(path);

  if (!file) {
    throw std::runtime_error("Failed to open texture file: " +
                             std::string(path));
  }

  std::vector<std::string> lines;
  std::string line;

  std::size_t width = 0;

  while (std::getline(file, line)) {
    width = std::max(width, line.size());
    lines.push_back(std::move(line));
  }

  resize(
      Vec2Int(static_cast<int32_t>(width), static_cast<int32_t>(lines.size())));

  for (std::size_t y = 0; y < lines.size(); ++y) {
    const std::string &row = lines[y];

    for (std::size_t x = 0; x < row.size(); ++x) {
      getBuffer().set(Vec2Int(static_cast<int32_t>(x), static_cast<int32_t>(y)),
                      Cell(row[x], Color::White, false, false));
    }
  }
}

} // namespace rot