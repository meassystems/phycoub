/*
 * @Author: Sergey Frantsishkov, mgistrser@gmail.com
 * @Date: 2020-03-15 13:05:05
 * @Last Modified by: Sergey Frantsishkov, mgistrser@gmail.com
 * @Last Modified time: 2020-03-15 14:35:52
 */

#pragma once

#define PROGRAMMING_ASSERT( x )                                                          \
    if ( !( x ) )                                                                        \
        throw ProgrammingException();

#include <exception>

namespace phycoub
{

/*
 * Исключение для сигнализирования о неправильном использовании кода
 */
class ProgrammingException : public std::exception
{
  public:
    ProgrammingException() = default;
    virtual ~ProgrammingException() override = default;
};

} // namespace phycoub