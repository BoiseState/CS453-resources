#include <stdio.h>

enum utype {
    INT,
    DOUBLE,
    STRING
};

struct data {
    union udata {
        int ival;
        double dval;
        char *sval;
    } data;
    enum utype storedType;
};


void printData(struct data value)
{
    switch (value.storedType) {
    case INT:
        printf("ival = %d \n", value.data.ival);
        break;
    case DOUBLE:
        printf("fval = %f \n", value.data.dval);
        break;
    case STRING :
        printf("sval = %s \n", value.data.sval);
        break;
    }
}


int main(int argc, char **argv)
{

    struct data myCloset;

    myCloset.data.ival = 10;
    myCloset.storedType = INT;
    printData(myCloset);

    myCloset.data.dval = 3.14159;
    myCloset.storedType = DOUBLE;
    printData(myCloset);

    myCloset.data.sval = "Cool!";
    myCloset.storedType = STRING;
    printData(myCloset);

    return 0;
}
