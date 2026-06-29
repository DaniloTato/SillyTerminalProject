#pragma once

#include <ROT/Texture.hpp>
#include <ROT/Vec2.hpp>
#include <filesystem>

namespace rot {

class ASCIITexture : public Texture<Cell> {
public:
  ASCIITexture() : Texture(Vec2Int(0, 0)) {}
  ASCIITexture(const std::filesystem::path &path) : Texture(Vec2Int(0, 0)) {
    loadTextureFromTxt(path);
  }

  void loadTextureFromTxt(const std::filesystem::path &path);
};

} // namespace rot