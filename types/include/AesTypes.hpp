#ifndef AES_TYPES_HPP
#define AES_TYPES_HPP

#define COMPLETE_CHUNK 16

typedef unsigned char byte;

typedef struct chunk_s
{
    byte value[16];
    int size;
} chunk_t;

typedef struct key_s
{
    byte* arr_key;
    unsigned int key_length;
} aes_key_t;

typedef struct key_sched_s
{
    aes_key_t* tab;
    // 1 word -> 4 bytes
} key_sched_t;


typedef byte rcon_t;
typedef byte SBox_t;

#endif