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
    virtual void pad(chunk_t& chunk) override;
    virtual ~pkcsPadder();
};

#endif