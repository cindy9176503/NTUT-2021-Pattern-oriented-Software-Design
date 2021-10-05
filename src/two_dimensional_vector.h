#ifndef TWODIMANSIONALVECTOR_H
#define TWODIMANSIONALVECTOR_H

#include <cmath>
#include <sstream>

class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y) : _x(x), _y(y) {
        if(_x == 0 && _y == 0) { throw "Not a non-zero vector"; }
    }

    double x() const { return _x; }

    double y() const { return _y; }

    double length() const { return sqrt( pow(_x, 2) + pow(_y, 2)); }

    double dot(TwoDimensionalVector vec) const { return _x * vec.x() + _y * vec.y(); }

    double cross(TwoDimensionalVector vec) const { return _x * vec.y() - _y * vec.x(); }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const { 
        TwoDimensionalVector vec_res(_x - vec.x(), _y - vec.y());
        return  vec_res;
    }

    std::string info() const {
        std::stringstream stream1, stream2;
        stream1 << std::fixed << std::setprecision(2) << _x;
        stream2 << std::fixed << std::setprecision(2) << _y;
        std::string info = "[" + stream1.str() + "," + stream2.str() + "]";

        return info;  
    }

private:
    double _x, _y;
};

#endif