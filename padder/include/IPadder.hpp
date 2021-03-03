
#ifndef IPadder_HPP
#define IPadder_HPP

#ifndef CHUNK_DEF
#define CHUNK_DEF

#define COMPLETE_CHUNK 16 // bytes

typedef unsigned char byte;

typedef struct chunk_s
{
    byte part[16];
    unsigned size;
} chunk_t;

#endif

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