#pragma once 
#include <exception>

namespace curves 
{


class CurveException : public std::exception
{
private:
    const char* what_;
public:
    CurveException(const char* what ) : what_(what) {}
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return what_;
    }
};


class ValueError : public CurveException
{
public:
    ValueError(const char* what) : CurveException(what)
    {}
};




}