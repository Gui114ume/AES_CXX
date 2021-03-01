
#ifndef IPadder_HPP
#define IPadder_HPP

class IPadder
{
protected:
    IPadder() {};
public:
    virtual void say_name() = 0;
    virtual ~IPadder(){};
};
#endif