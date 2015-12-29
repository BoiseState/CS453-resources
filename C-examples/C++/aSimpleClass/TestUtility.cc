
#include "Utility.h"

int main(int argc, char *argv[]) {

    Utility *printer = new Utility(20);

    printer->println(5);
    printer->println(14.455);
    printer->println('a');
    printer->println("abracadabra", 20);
}
