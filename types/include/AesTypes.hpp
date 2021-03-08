#ifndef AES_TYPES_HPP
#define AES_TYPES_HPP

#define COMPLETE_CHUNK 16 // bytes

#define AES_KEY_128_SIZE 16 // bytes
#define AES_KEY_192_SIZE 24 // bytes
#define AES_KEY_256_SIZE 32 // bytes

typedef unsigned char      byte;
typedef char               ascii;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef char       i8;
typedef short      i16;
typedef int        i32;
typedef long long  i64;



typedef struct chunk_s
{
    byte value[16];
    i32 size;
} chunk_t;

typedef struct key_s
{
    byte* arr_key;
    u32 key_length;
} aes_key_t;

typedef struct key_sched_s
{
    aes_key_t* tab;
} key_sched_t;


typedef byte rcon_t;
typedef byte SBox_t;

#endif