
#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include "Utility.h"

using namespace std;



/**
	A holder class for methods that check primality and compute prime factors.
	@author Amit Jain
	@date Fall, 2000
*/


class Primes {
  public:

    /**
    	Check if input parameter is prime or not.
    	@param n Must be greater than zero.
    	@return  True if n is a prime false otherwise.
    */
    static bool isPrime(long n) {
        // take care of simple cases first
        if ((n == 1) || (n ==2))
            return true;

        if (n % 2 == 0) return false; // n is even

        // now n must be odd and has only odd factors (if any )
        long k = 3;
        long sqrtn = (long) ceil(sqrt((double)n));
        bool notDivisibleYet = true;

        // assume that the number is a prime and see we if
        // can find a  factor that contardicts the assumption.

        while (notDivisibleYet && k <= sqrtn) {
            if (n % k == 0)
                notDivisibleYet = false;
            k = k + 2;
        }
        return notDivisibleYet;
    }

    /**
    	Faster prime factorization method.
    */
    static string primeFactorization(long n) {
        // simple cases
        if (n == 1) return "1";
        if (isPrime(n)) return Utility::itos(n) + "";

        string result = "";
        long sqrtn = (long) ceil(sqrt((double)n));
        long number = n;

        // see how many times 2 divides into n
        while (number % 2 == 0) {
            result = result + Utility::itos(2);
            number = number/2;
            if (number != 1)
                result = result + " * ";
        }

        // find the remaining factors (all odd)
        for (int i=3; i<=sqrtn+2; i=i+2) {
            // if i is prime, see how many times it divides into number
            if (isPrime(i)) {
                while (number % i == 0) {
                    /*cout << result << endl;;*/
                    result = result + Utility::itos(i);
                    number = number/i;
                    if (number != 1)
                        result = result + " * ";
                }
            }
            if (number == 1) break;
            if (isPrime(number)) break;
        }
        if (number > 1)
            result = result + Utility::itos(number);
        return result;
    }


};


int main (int argc, char * argv[]) {
    long n = atol(argv[1]);

    string factors = Primes::primeFactorization(n);

    cout << "The factors are " << factors << endl;
}

