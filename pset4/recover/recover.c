#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ../recover/image");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("File read fill");
        return 2;
    }
    BYTE by[512];
    int count = 0;
    FILE *write = NULL;
    char fileName[8];
    bool val = true;
    while (val)
    {
        size_t read = fread(&by, sizeof(BYTE), 512, file);
        if (read == 0 && feof(file))
        {
            val = false;
        }
        bool isJpeg = by[0] == 0xff && by[1] == 0xd8 && by[2] == 0xff && (by[3] & 0xf0) == 0xe0;
        if (isJpeg)
        {
            if (write != NULL)
            {
                fclose(write);
                count++;
            }
            sprintf(fileName, "%03i.jpg", count);
            write = fopen(fileName, "w");
            fwrite(&by, sizeof(BYTE), read, write);
        }
        else
        {
            if (write != NULL)
            {
                fwrite(&by, sizeof(BYTE), read, write);
            }

        }
    }
    fclose(write);
    fclose(file);
    return 0;
}
