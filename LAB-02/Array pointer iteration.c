#include <stdio.h>

/**
 * Afisati adresele elementelor din vectorul "v" impreuna cu valorile
 * de la acestea.
 * Parcurgeti adresele, pe rand, din octet in octet,
 * din 2 in 2 octeti si apoi din 4 in 4.
 */

int main()
{
    int v[] = {0xCAFEBABE, 0xDEADBEEF, 0x0B00B135, 0xBAADF00D, 0xDEADC0DE};
    
    // int print (4 bytes)
    for(int i = 0; i < sizeof(v) / sizeof(*v); ++i) {
        printf("Adresa elementului %d este %p!\n", *(v+i), (v+i));
    }

    // short print (2 bytes)
    printf("\n------------------------------------------\n\n");
    short* ptr2bytes = (short*) v;
    for(int i = 0; i < sizeof(v) / sizeof(*v) * 2; ++i) {
        printf("Adresa elementului %d este %p!\n", *(ptr2bytes + i), (ptr2bytes + i));
    }

    // char print (1 byte)
    printf("\n------------------------------------------\n\n");
    char* ptr1byte = (char*) v;
    for(int i = 0; i < sizeof(v); ++i) {
        printf("Adresa elementului %d este %p!\n", *(ptr1byte + i), (ptr1byte+ i));
    }

    return 0;
}
