#pragma once

#include "zeus/CVector2f.hpp"

namespace zeus {

class CVector2i {
public:
  union {
    struct {
      int x, y;
    };
    int v[2];
  };

  constexpr CVector2i() : x(0), y(0) {}

  constexpr CVector2i(int xin, int yin) : x(xin), y(yin) {}

  CVector2i(const CVector2f& vec) : x(int(vec.x())), y(int(vec.y())) {}

  CVector2f toVec2f() const { return CVector2f(x, y); }

  CVector2i operator+(const CVector2i& val) const { return CVector2i(x + val.x, y + val.y); }

  CVector2i operator-(const CVector2i& val) const { return CVector2i(x - val.x, y - val.y); }

  CVector2i operator*(const CVector2i& val) const { return CVector2i(x * val.x, y * val.y); }

  CVector2i operator/(const CVector2i& val) const { return CVector2i(x / val.x, y / val.y); }

  bool operator==(const CVector2i& other) const { return x == other.x && y == other.y; }

  bool operator!=(const CVector2i& other) const { return x != other.x || y != other.y; }

  CVector2i operator*(int val) const { return CVector2i(x * val, y * val); }
};
} // namespace zeus
