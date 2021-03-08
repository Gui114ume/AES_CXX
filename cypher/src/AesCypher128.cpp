#include <AesCypher128.hpp>

#include <fstream>

AesCypher128::AesCypher128(ConfigReader& config)
: m_config{config}
{
    getKey();
    verify_key_size();
    set_Nb();
    set_Nk();
    set_Nr();
    make_key_sched();
    std::cout << "AesCypher128 constructor" << std::endl; 
}

AesCypher128::~AesCypher128()
{
    std::cout << "AesCypher128 destructor" << std::endl; 
}


namespace Aes128
{
  SBox_t sbox[256] = { 0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
                    ,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
                    ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
                    ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
                    ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
                    ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
                    ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
                    ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
                    ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
                    ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
                    ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
                    ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
                    ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
                    ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
                    ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
                    ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16};

  rcon_t rcon[255] = {0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a,
0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39,
0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a,
0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8,
0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef,
0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc,
0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b,
0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3,
0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94,
0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20,
0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6, 0x97, 0x35,
0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd, 0x61, 0xc2, 0x9f,
0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb, 0x8d, 0x01, 0x02, 0x04,
0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63,
0xc6, 0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91, 0x39, 0x72, 0xe4, 0xd3, 0xbd,
0x61, 0xc2, 0x9f, 0x25, 0x4a, 0x94, 0x33, 0x66, 0xcc, 0x83, 0x1d, 0x3a, 0x74, 0xe8, 0xcb};

void RotWord(byte* word)
{
    byte tmp = 0;
    tmp = word[0];

    word[0] = word[1];
    word[1] = word[2];
    word[2] = word[3];
    word[3] = tmp;

    return (void)0;
}

void SubWord(byte* word,
             SBox_t* sbox)
{
    byte* tmp_word = new byte[4];
    u32 n = 16; // nb d'element par ligne
    tmp_word[0] = sbox[   ((word[0] & 0b11110000) >> 4 ) * (n ) +  ( (word[0] & 0b00001111))];
    tmp_word[1] = sbox[   ((word[1] & 0b11110000) >> 4 ) * (n ) +  ( (word[1] & 0b00001111))];
    tmp_word[2] = sbox[   ((word[2] & 0b11110000) >> 4 ) * (n ) +  ( (word[2] & 0b00001111))];
    tmp_word[3] = sbox[   ((word[3] & 0b11110000) >> 4 ) * (n ) +  ( (word[3] & 0b00001111))];

    memcpy(word,tmp_word,4 * sizeof(byte));
    delete [] tmp_word;
    return (void)0;
}

void SubBytes(chunk_t* chunk,
              SBox_t* sbox)
{
    u32 n = 16;

    byte I = 0;
    byte J = 0;
    for(i32 i = 0 ; i < 16 ; i++)
    {
        I = (chunk->value[i] & 0b11110000) >> 4;
        J = chunk->value[i] & 0b00001111;
        chunk->value[i] = sbox[ I * ( n ) + J ];
    }

    return (void)0;
}

void ShiftRows(chunk_t* chunk)
{
    byte tmp1 = 0;
    byte tmp2 = 0;
    byte tmp3 = 0;
    byte tmp4 = 0;
    i32 i = 0;
    i32 j = 0;

    for(i = 0,j = 0 ; j < 4 ; j++)
    {

        tmp1 = chunk->value[i + 0];
        tmp2 = chunk->value[i + 4];
        tmp3 = chunk->value[i + 8];
        tmp4 = chunk->value[i + 12];
        switch (j)
        {
            case 0:
                chunk->value[ i + 0] += 0;
                chunk->value[ i + 4] += 0;
                chunk->value[ i + 8] += 0;
                chunk->value[ i + 12] += 0;
                i += 1;
                break;
            case 1:
                chunk->value[i + 0]     = tmp2;
                chunk->value[i + 4] = tmp3;
                chunk->value[i + 8] = tmp4;
                chunk->value[i + 12] = tmp1;

                i += 1;
                break;
            case 2:
                chunk->value[i + 0]     = tmp3;
                chunk->value[i + 4] = tmp4;
                chunk->value[i + 8] = tmp1;
                chunk->value[i + 12] = tmp2;
                i += 1;
                break;
            case 3:
                chunk->value[i]     = tmp4;
                chunk->value[i + 4] = tmp1;
                chunk->value[i + 8] = tmp2;
                chunk->value[i + 12] = tmp3;
                i += 1;

                break;
            default:
                perror("ShiftRows error : switch case");
                abort();
                break;

        }

    }

    return (void)0;
}

//merci gogole
byte gmul(byte a, byte b)
{
    byte p = 0;
    byte counter;
    byte hi_bit_set;
    for(counter = 0; counter < 8; counter++) {
        if((b & 1) == 1)
            p ^= a;
        hi_bit_set = (a & 0x80);
        a <<= 1;
        if(hi_bit_set == 0x80)
            a ^= 0x1b;
        b >>= 1;
    }
    return p;
}

void MixColumns(chunk_t* chunk)
{
    chunk_t* tmp_chunk = new chunk_t;

    for(int i = 0 ; i < 16 ; )
    {
        tmp_chunk->value[i + 0]   = gmul( 2 , chunk->value[i + 0] ) ^ gmul(3 , chunk->value[i + 1]) ^ gmul(1 , chunk->value[i + 2]) ^ gmul(1 , chunk->value[i + 3]);
        tmp_chunk->value[i + 1]   = gmul( 1 , chunk->value[i + 0] ) ^ gmul(2 , chunk->value[i + 1]) ^ gmul(3 , chunk->value[i + 2]) ^ gmul(1 , chunk->value[i + 3]);
        tmp_chunk->value[i + 2]   = gmul( 1 , chunk->value[i + 0] ) ^ gmul(1 , chunk->value[i + 1]) ^ gmul(2 , chunk->value[i + 2]) ^ gmul(3 , chunk->value[i + 3]);
        tmp_chunk->value[i + 3]   = gmul( 3 , chunk->value[i + 0] ) ^ gmul(1 , chunk->value[i + 1]) ^ gmul(1 , chunk->value[i + 2]) ^ gmul(2 , chunk->value[i + 3]);
        i += 4;
    }
    memcpy(chunk->value, tmp_chunk->value, 16);

    return (void)0;
}

void AddRoundKey(chunk_t* chunk,
                 aes_key_t*   RoundKey)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        chunk->value[0  + i] = chunk->value[0  + i] ^ (RoundKey+0)->arr_key[i];
        chunk->value[4  + i] = chunk->value[4  + i] ^ (RoundKey+1)->arr_key[i];
        chunk->value[8  + i] = chunk->value[8  + i] ^ (RoundKey+2)->arr_key[i];
        chunk->value[12 + i] = chunk->value[12 + i] ^ (RoundKey+3)->arr_key[i];
    }

    return (void)0;
}

};

void AesCypher128::say_name()
{
    std::cout << "AesCypher128" << std::endl;
}

void AesCypher128::getKey()
{
    m_key = new aes_key_t;
    m_key->arr_key = new byte[AES_KEY_128_SIZE];
    std::fstream in(m_config.key_filename(), std::ios::in | std::ios::binary );
    in.read((char*)(m_key->arr_key), AES_KEY_128_SIZE); // segfault
    m_key->key_length = in.gcount();
}

chunk_t& AesCypher128::apply(chunk_t& chunk)
{
    //std::cout << "clear chunk size: " << chunk.size << std::endl;
    Aes128::AddRoundKey(&chunk, &(m_key_tab->tab[0]));

    int i = 0;
    for(i = 4 ; i < 4 * get_Nr() ;)
    {

        Aes128::SubBytes(&chunk, Aes128::sbox);
    
        Aes128::ShiftRows(&chunk);

        Aes128::MixColumns(&chunk);

        Aes128::AddRoundKey(&chunk, &(m_key_tab->tab[i]));

        i += 4;
    }
    Aes128::SubBytes(&chunk, Aes128::sbox);
    Aes128::ShiftRows(&chunk);
    Aes128::AddRoundKey(&chunk, &(m_key_tab->tab[ 4 * get_Nr()]));
    //std::cout << "encrypted chunk size: " << chunk.size << std::endl; // problem !
    return chunk;
}

void AesCypher128::make_key_sched()
{
    m_key_tab = new key_sched_t;
    m_key_tab->tab = new aes_key_t[get_Nb() * (1 + get_Nr())];
    for(i32 i = 0 ; i < (get_Nb() * (1 + get_Nr())) ; i++)
        m_key_tab->tab[i].arr_key = new byte[4];
    u32 i = 0;
    byte* temp = new byte[4];

    while(i < get_Nk())
    {
        m_key_tab->tab[i].arr_key[0] = m_key->arr_key[4 * i];
        m_key_tab->tab[i].arr_key[1] = m_key->arr_key[4 * i + 1];
        m_key_tab->tab[i].arr_key[2] = m_key->arr_key[4 * i + 2];
        m_key_tab->tab[i].arr_key[3] = m_key->arr_key[4 * i + 3];
        i = i + 1;
    }

    i = get_Nk();
    while( i < get_Nb() * (get_Nr() + 1) ) 
    {
        memcpy(temp,m_key_tab->tab[i - 1].arr_key,sizeof(byte)*4);
        if( (i % get_Nk()) == 0)
        {
            Aes128::RotWord(temp);
            Aes128::SubWord(temp, Aes128::sbox); 
            for(int j = 0 ; j < 4 ; j++)
                temp[j] = (j == 0) ? temp[j] ^ Aes128::rcon[i/get_Nk()] : temp[j] ^ 0b00000000;

        }
        else if (  (get_Nk() > 6) && (  (i % get_Nk()) == 4)  )
        {
            Aes128::SubWord(temp,Aes128::sbox);
        }
        for(int j = 0 ; j < 4 ; j++)
            m_key_tab->tab[i].arr_key[j] = m_key_tab->tab[i - get_Nk()].arr_key[j] ^ temp[j];

        i = i + 1;
    }
    std::cout << "AesCypher128::make_key_sched() implemented" <<std::endl;
}

void AesCypher128::verify_key_size()
{
    if( m_key->key_length != AES_KEY_128_SIZE)
        {
            std::cout << "m_key->key_length != AES_KEY_128_SIZE, try another keyfile" << std::endl;
            std::cout << m_key->key_length << " != " << AES_KEY_128_SIZE << std::endl;
            exit(-1);
        }
    std::cout << "AesCypher128::verify_key_size() implemented" <<std::endl;
}

void AesCypher128::set_Nb()
{
    m_Nb = 4;
}

i32 AesCypher128::get_Nb()
{
    return m_Nb;
}

void AesCypher128::set_Nk()
{
    m_Nk = m_key->key_length;
}

i32 AesCypher128::get_Nk()
{
    return m_Nk;
}

void AesCypher128::set_Nr()
{
    m_Nr = get_Nb() + get_Nk() + 2;
}

i32 AesCypher128::get_Nr()
{
    return m_Nr;
}