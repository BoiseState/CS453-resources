
import java.io.*;

/**
	A holder class for methods that check primality and compute prime factors.
	@author Amit Jain
	@date Fall, 2000
*/

public class Primes
{

	/**
		Check if input parameter is prime or not.
		@param n Must be greater than zero.
		@return  True if n is a prime false otherwise.
	*/
	public static boolean isPrime(long n)
	{
	    // take care of simple cases first
		if ((n == 1) || (n ==2))
			return true;

		if (n % 2 == 0) return false; // n is even

		// now n must be odd and has only odd factors (if any )
		long k = 3;
		long sqrtn = (long) Math.ceil(Math.sqrt(n));
		boolean notDivisibleYet = true;

		// assume that the number is a prime and see we if
		// can find a  factor that contardicts the assumption.

		while (notDivisibleYet && k <= sqrtn)
		{
			if (n % k == 0)
				notDivisibleYet = false;
			k = k + 2;
		}
		return notDivisibleYet;
	}

	/**
		Compute the prime factorization of specified number.
		@param n Must be greater than zero.
		@return The prime factorization is returned as a string.
	*/
	public static String primeFactorization(long n)
	{
		if (n == 1) return "1";

		String result = "";
		long sqrtn = (long) Math.ceil(Math.sqrt(n));
		long number = n;

		for (int i=2; i<=sqrtn; i++)
		{
			// if i is prime, see how many times it divides into number
			if (isPrime(i))
			{
				while (number % i == 0)
				{
					result = result + i;
					number = number/i;
					if (number != 1) 
						result = result + " * ";
				}
			}
			if (number == 1) break;
		}
		if (number > 1) 
			result = result + number;
		return result;
	}

	/**
		Faster prime factorization method.
	*/
	public static String fasterPrimeFactorization(long n)
	{	
		// simple cases
		if (n == 1) return "1";
		if (isPrime(n)) return n + "";

		String result = "";
		long sqrtn = (long) Math.ceil(Math.sqrt(n));
		long number = n;
		
		// see how many times 2 divides into n
		while (number % 2 == 0)
		{
			result = result + 2;
			number = number/2;
			if (number != 1) 
				result = result + " * ";
		}

		// find the remaining factors (all odd)
		for (int i=3; i<=sqrtn+2; i=i+2)
		{
			// if i is prime, see how many times it divides into number
			if (isPrime(i))
			{
				while (number % i == 0)
				{
					/*System.out.println(result);*/
					result = result + i;
					number = number/i;
					if (number != 1) 
						result = result + " * ";
				}
			}
			if (number == 1) break;
			if (isPrime(number)) break;
		}
		if (number > 1) 
			result = result + number;
		return result;
	}


	public static void main (String [] argv)
	throws IOException
	{
		long n = Long.parseLong(argv[0]);

		long startTime = System.currentTimeMillis();
		String factors = Primes.fasterPrimeFactorization(n);
		long totalTime = System.currentTimeMillis() - startTime;

		System.out.println("The factors are "+factors);
		System.out.println("Time to factor was: "+totalTime/1000.0+" seconds");
	}
}
