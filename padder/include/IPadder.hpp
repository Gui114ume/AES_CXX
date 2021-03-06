#ifndef IPadder_HPP
#define IPadder_HPP

#include <AesTypes.hpp>


class IPadder
{
protected:
    IPadder() {};
public:
    virtual void say_name() = 0;
    virtual void pad(chunk_t& chunk) = 0;
    virtual ~IPadder(){};
};
#endif