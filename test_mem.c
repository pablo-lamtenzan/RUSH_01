

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <memory.h>

# define SIZE 32768

#ifndef SIZE
 # define SIZE 1024
#endif


/*
// 0.21s user 1.15s system 57% cpu 2.356 total
int main()
{
    uint_fast32_t*const matrix = malloc(sizeof(uint_fast32_t) * SIZE);
    
    for (uint_fast32_t* i = matrix ; i < matrix + SIZE ; i++)
        printf("%u\n", *i);

    free (matrix);
    return (0);
}
*/


/*
// 0.00s user 0.00s system 91% cpu 0.002 total
int main()
{
    uint_fast32_t*const matrix = malloc(sizeof(uint_fast32_t) * SIZE);
    uint_fast32_t chunck[64];// WITH / SIZEOF: ./a.out  0.00s user 0.00s system 93% cpu 0.002 total

    for (uint_fast32_t index = 0 ; index < SIZE ; index += sizeof(chunck) / sizeof(*chunck))
    {
        memcpy(chunck, matrix + index, sizeof(chunck) / sizeof(*chunck));
        for (uint_fast64_t* i = chunck ; i < chunck + sizeof(chunck) / sizeof(*chunck) ; i++)
            printf("%u\n", *i);
    }

    return (0);
}
*/

/*
int main()
{
    uint_fast32_t*const matrix = malloc(sizeof(uint_fast32_t) * SIZE);
    uint_fast32_t chunck[64];
    uint_fast64_t chunck_size = sizeof(chunck) / sizeof(*chunck);
    uint_fast64_t iterations = 0;

    for (uint_fast32_t index = 0 ; index < SIZE ; index += chunck_size)
    {
        memcpy(chunck, matrix + index, chunck_size);
        for (uint_fast64_t* i = chunck ; i < chunck + chunck_size ; i++)
        {
            printf("%u\n", *i);
            ++iterations;
        }
    }
    printf("[ %u ]\n", iterations);
    free(matrix);

    return (0);
}
*/

# include <unistd.h>

int main()
{
    int ret = read(1, NULL, 12);
    printf ("%d\n", ret);
}
