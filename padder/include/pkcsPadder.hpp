#ifndef pkcsPadder_HPP
#define pkcsPadder_HPP

#include <IPadder.hpp>

#include <iostream>

class pkcsPadder : public IPadder
{
private:
    /* data */
public:
    pkcsPadder();
    virtual void say_name() override;
    virtual ~pkcsPadder();
};

#endif