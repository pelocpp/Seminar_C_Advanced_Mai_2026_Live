// ===========================================================================
// UnionsBitFieldsEnums.c // Unions, Bitfields and Enums
// ===========================================================================

#include <stdio.h>
#include <string.h>

// ===========================================================================
// bitfields: conceptual example

/* define simple structure */
struct Status1
{
    unsigned int widthValidated;
    unsigned int heightValidated;
    unsigned int positionValidated;
};

/* define same simple structure with bit fields */
struct Status2
{
    unsigned char widthValidated : 1;
    unsigned char heightValidated : 1;
    unsigned char positionValidated : 4;
};

static void bitfields()
{
    printf("Memory size occupied by status1 : %zu\n", sizeof(struct Status1));
    printf("Memory size occupied by status2 : %zu\n", sizeof(struct Status2));

    struct Status1 s1 = { 0, 0, 0 };
    s1.widthValidated = 1;
    s1.heightValidated = 0;
    s1.positionValidated = 7;

    struct Status2 s2 = { 0, 0, 0 };
    s2.widthValidated = 1;
    s2.heightValidated = 0;
    s2.positionValidated = 7;
}

// ===========================================================================
// bitfields: a comparison

struct Flags
{
    unsigned char flag_01;   // ja, Nein,  True, False
    unsigned char flag_02;
    unsigned char flag_03;
    unsigned char flag_04;
    unsigned char flag_05;
    unsigned char flag_06;
    unsigned char flag_07;
    unsigned char flag_08;
};

struct FlagsWithBitfield
{
    unsigned char flag_01 : 1;
    unsigned char flag_02 : 1;
    unsigned char flag_03 : 1;
    unsigned char flag_04 : 1;
    unsigned char flag_05 : 1;
    unsigned char flag_06 : 1;
    unsigned char flag_07 : 1;
    unsigned char flag_08 : 1;
};

// ===========================================================================
// unions: conceptual example

union FirstUnionExample
{
    char   member1;
    short  member2;
    float  member3;
    double member4;
};

union SecondUnionExample
{
    unsigned int  value;
    unsigned char bytes_of_value[4];  // sizeof (unsigned int) // unsigned char: 8 Bits
};

static void unions()
{
    // defining a union variable
    union SecondUnionExample var = { 0 };

    var.value = 0x00AA0000;

    unsigned char byte1 = var.bytes_of_value[0];
    unsigned char byte2 = var.bytes_of_value[1];
    unsigned char byte3 = var.bytes_of_value[2];
    unsigned char byte4 = var.bytes_of_value[3];
}

// -----------------------------------------------------------------------
// unions: red, green and blue color scheme // ohne Alpha

union rgb
{
    unsigned int  color;
    unsigned char bytes_of_color[4];
};

typedef union rgb RGB;

static void unions_rgb()
{
    RGB red = { .color = 0x00FF0000 };

    printf("Red:     0x%0X\n", red.color);

    unsigned char a = red.bytes_of_color[3];
    unsigned char r = red.bytes_of_color[2];
    unsigned char g = red.bytes_of_color[1];
    unsigned char b = red.bytes_of_color[0];

    RGB magenta =
    {
        .bytes_of_color[3] = 0,    // a
        .bytes_of_color[2] = 255,  // r
        .bytes_of_color[1] = 0,    // g 
        .bytes_of_color[0] = 255   // b
    };

    printf("Magenta: 0x%0X\n", magenta.color);

    RGB yellow = { .color = 0x00FFFF00 };

    printf("Yellow:  Red=0x%02X - Green=0x%02X - Blue=0x%02X\n",
        yellow.bytes_of_color[2],
        yellow.bytes_of_color[1],
        yellow.bytes_of_color[0]
    );
}

// -----------------------------------------------------------------------
// unions: modelling a char as a byte and as bits

union chararacter
{
    struct Bits
    {
        unsigned char bit0 : 1;
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
    } bits;

    unsigned char ch;   // 0 .. 255 / 0 .. 0xFF

};

typedef union chararacter Char;

static void unions_character()
{
    Char ch = { .ch = 0 };

    ch.ch = 'A';

    printf("%c - %d\n", ch.ch, ch.ch);

    Char value = { .ch = 0 };

    value.bits.bit0 = 1;
    value.bits.bit1 = 1;
    value.bits.bit2 = 1;
    value.bits.bit3 = 1;

    printf("%d\n", value.ch);
}

// -----------------------------------------------------------------------
// unions: modelling an IP address 

union ipAddress
{
    unsigned int  address;
    unsigned char octets[4];
};

typedef union ipAddress IPAddress;

static void unions_ip_adress()
{
    IPAddress localHost = {
        .octets[0] = 1,
        .octets[1] = 0,
        .octets[2] = 0,
        .octets[3] = 127
    };

    unsigned int localHostAddress = localHost.address;

    printf("Localhost: %u.%u.%u.%u\n",
        localHost.octets[3],
        localHost.octets[2],
        localHost.octets[1],
        localHost.octets[1]
    );

    printf("Localhost: %u - %X\n", localHostAddress, localHostAddress);

    // ---------------------

    IPAddress anotherIPAddress = {
        .octets[0] = 1,
        .octets[1] = 254,
        .octets[2] = 16,
        .octets[3] = 172
    };

    printf("Another IPAddress: %u.%u.%u.%u\n",
        anotherIPAddress.octets[3],
        anotherIPAddress.octets[2],
        anotherIPAddress.octets[1],
        anotherIPAddress.octets[0]
    );

    unsigned int address = anotherIPAddress.address;

    printf("Another IPAddress: %u - %X\n", address, address);
}

// =======================================================================
// enums

#define LOW    1
#define MEDIUM 2
#define HIGH   3

// better alternative

enum level
{
    Low,
    Medium,
    High
};

typedef enum level Level;

// does not compile
//enum LevelExtended {
//    VeryLow = 10,
//    VeryMedium = 50,
//    High = 100  // schon vergeben      
//};

static void enums()
{
    Level level = Medium;

    switch (level)
    {
    case Low:
        printf("Low Level\n");
        break;
    case Medium:
        printf("Medium Level\n");
        break;
    case High:
        printf("High Level\n");
        break;
    }

    printf("Level: %d\n", level);
}

// =======================================================================

void mainUnionsBitfieldsEnums()
{
    bitfields();
    unions();
    unions_rgb();
    unions_character();
    unions_ip_adress();
    enums();
}

// ===========================================================================
// End-of-File
// ===========================================================================