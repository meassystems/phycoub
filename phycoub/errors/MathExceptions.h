#pragma once

#include <exception>

namespace phycoub
{

/*
 * Деление на ноль
 */
class DivisionByZeroException : public std::exception
{
  public:
    DivisionByZeroException() = default;
    virtual ~DivisionByZeroException() override = default;
};

} // namespace phycoub