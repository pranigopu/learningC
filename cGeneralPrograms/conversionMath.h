#include <stdio.h>

double binToDec(char *bin)
{
    int i;
    float dec = 0, fpdec = 0, n = 2;
    (bin[0] == '-')? (i = 1) : (i = 0);
    while(bin[i])
    {
        dec *= 2;
        switch(bin[i])
        {
            case '0': break;
            
            case '1': dec++; break;
            
            case '.': dec /= 2; i++;
            /*
            dec /= 2 is done because dec is multiplied by 2 even if bin[i] is a point.
            This means that before dec /= 2, dec is double of what it should be, because the unit place has already been reached.
            */
            while(bin[i])
            {
                switch(bin[i])
                {
                    case '0': break;
                    case '1': fpdec += 1 / n; break;
                    default: return -1;
                }
                n *= 2;
                i++;
            }
            if(fpdec < 0)
                return -1;
            return dec + fpdec;

            default: return -1;
        }
        i++;
    }
    return dec;
}

