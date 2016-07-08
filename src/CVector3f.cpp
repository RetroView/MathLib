#include "zeus/CVector3f.hpp"
#include <memory.h>
#include <cmath>
#include <assert.h>
#include "zeus/Math.hpp"

namespace zeus
{
const CVector3f CVector3f::skOne = CVector3f(1.f);
const CVector3f CVector3f::skNegOne = CVector3f(-1.f);
const CVector3f CVector3f::skZero;

const CVector3f kUpVec(0.f, 0.f, 1.f);
const CVector3f kDownVec(0.f, 0.f, -1.f);
const CVector3f kForwardVec(0.f, 1.f, 0.f);
const CVector3f kBackVec(0.f, -1.f, 0.f);
const CVector3f kRightVec(1.f, 0.f, 0.f);
const CVector3f kLeftVec(-1.f, 0.f, 0.f);
const CVector3f kRadToDegVec(180.0f / M_PIF);
const CVector3f kDegToRadVec(M_PIF / 180.0f);

float CVector3f::getAngleDiff(const CVector3f& a, const CVector3f& b)
{
    float mag1 = a.magnitude();
    float mag2 = b.magnitude();

    if (!mag1 || !mag2)
        return 0.f;

    float dot = a.dot(b);
    float theta = std::acos(dot / (mag1 * mag2));
    return theta;
}

CVector3f CVector3f::slerp(const CVector3f& a, const CVector3f& b, float t)
{
    if (t <= 0.0f)
        return a;
    if (t >= 1.0f)
        return b;

    CVector3f ret;

    float mag = std::sqrt(a.dot(a) * b.dot(b));

    float prod = a.dot(b) / mag;

    if (std::fabs(prod) < 1.0f)
    {
        const double sign = (prod < 0.0f) ? -1.0f : 1.0f;

        const double theta = acos(sign * prod);
        const double s1 = sin(sign * t * theta);
        const double d = 1.0 / sin(theta);
        const double s0 = sin((1.0 - t) * theta);

        ret.x = (float)(a.x * s0 + b.x * s1) * d;
        ret.y = (float)(a.y * s0 + b.y * s1) * d;
        ret.z = (float)(a.z * s0 + b.z * s1) * d;

        return ret;
    }
    return a;
}
}
