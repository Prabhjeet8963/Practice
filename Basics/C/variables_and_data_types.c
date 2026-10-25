// Variables , Data Types , and Format Specifiers in C


// Variables store data values in memory with a specific data type

    // Declaration: specify type and name (int age;)
    // Initialization: assign a value (age = 21;)

// Use format specifiers to display variables
// (%d for int, %f for float, %c for char, %s for string)
    /*
     %d - signed integer
     %u - unsigned integer
     %f - float
     %lf - double
     %c - character
     %s - string
     %x - hexadecimal
     %o - octal

     %lld - long long integer
     %llu - unsigned long long
     %ld - long integer
     %lu - unsigned long
     %hd - short integer
     %hu - unsigned short 
Format specifier modifiers:
    %.2f - displays 2 decimal places
    %8d - allocates 8 spaces (right-aligned)
    %-8d - allocates 8 spaces (left-aligned)
    */

// char stores single characters, int stores whole numbers, float/double store decimals
// Arrays of char can store strings (char name;)
// Variables must be declared before use


// Data type determines memory size and what values can be stored
    /* 
    char: stores single character, 1 byte memory
    Range: -128 to 127 (signed) or 0 to 255 (unsigned)
    Format specifier: %c for character, %d for integer value
    */

    /* 
    char array: stores strings (multiple characters)
    Example: char name; allocates 25 bytes
    Format specifier: %s
    Null terminator '\0' marks end of string
    */

    /* 
    int: stores whole numbers, 4 bytes memory
    Range: approximately -2 billion to +2 billion
    Format specifier: %d
    Most commonly used integer type
    */

    /* 
    unsigned int: only positive integers, 4 bytes
    Range: 0 to approximately 4 billion
    Format specifier: %u
    Doubles positive range by removing negatives
    */

    /* 
    short: smaller integer type, 2 bytes memory
    Range: -32,768 to 32,767
    Format specifier: %d
    Use when memory conservation is important
    */

    /* 
    unsigned short: positive integers only, 2 bytes
    Range: 0 to 65,535
    Format specifier: %d
    */

    /* 
    long long: very large integers, 8 bytes memory
    Range: approximately -9 quintillion to +9 quintillion
    Format specifiers: %lld (signed), %llu (unsigned)
    Add 'u' suffix for unsigned literals (123456789u)
    */

    /* 
    float: decimal numbers, 4 bytes memory
    Precision: 6-7 significant digits
    Format specifier: %f
    Less precise but uses less memory than double
    */

    /* 
    double: decimal numbers with higher precision, 8 bytes
    Precision: 15-16 significant digits
    Format specifier: %lf
    Preferred over float for most applications
    */

    /* 
    bool: stores true/false values (1/0)
    Requires: #include <stdbool.h>
    Format specifier: %d (displays 1 or 0)
    Uses 1 byte despite only needing 1 bit
    */

    /* 
    sizeof() operator: returns size in bytes
    Example: sizeof(int) returns 4
    Useful for calculating array sizes
    */

    /* 
    unsigned keyword: removes negative range
    Doubles positive range for integer types
    Example: unsigned int, unsigned char
    */

    /* 
    Type casting: converts one type to another
    Syntax: (datatype)variable
    Example: (float)5 converts int to float
    Important for division to avoid integer truncation
    */

    /* 
    Choosing data types:
    - Consider value range needed
    - Balance precision vs memory usage
    - Use appropriate signedness (signed/unsigned)
    - Avoid overflow by selecting adequate size
    */

    /* 
    Common pitfalls:
    - Integer division truncates decimals
    - Mixing signed/unsigned causes unexpected behavior
    - Exceeding range causes overflow/wraparound
    - Float precision loss in comparisons
    */