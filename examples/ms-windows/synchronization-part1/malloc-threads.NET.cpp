#using <mscorlib.dll>

#include <stdlib.h>

using namespace System;
using namespace System::Threading;

public __gc class MyThreadExample 
{
public:
	// 
	// Constructor (ctor)
	// 
	// @param cAllocs
	//		Number of allocations to perform
	//
	MyThreadExample(int cAllocs, int id) : m_cAllocs(cAllocs), m_id(id) {}

	//
	// The method that will be called when the thread is started.
	//
	void MyThreadProc()
	{
		int *pInt;
		for (int i=0; i<m_cAllocs; i++) {
			pInt = new int;
			delete pInt;
		}
		Console::Write(S"Thread ");
		Console::Write(m_id);
		Console::WriteLine(S" complete");
	}
	
	
private:

	int m_cAllocs;
	int m_id;
	
};

int main(int argc, char *argv[]) 
{
	// Verify arguments
	if ( argc != 3 ) {
		Console::Write(S"Usage: ");
		Console::Write(argv[0]);
		Console::WriteLine(S" <#threads> <#allocations>");
		return 1;
	}

	int cThreads = atoi(argv[1]);
	int cAllocs = atoi(argv[2]);
	MyThreadExample *myThreadExamples[] = new MyThreadExample * [cThreads];
	Thread *myThreads[] = new Thread * [cThreads];
	
	for (int i=0; i<cThreads; i++) {
		
		// Create the thread example
		myThreadExamples[i] = new MyThreadExample(cAllocs, i);

		// Create the thread object, passing in the MyThreadExample::MyThreadProc method
		// via a ThreadStart delegate.
		myThreads[i] = new Thread(new ThreadStart(myThreadExamples[i], &MyThreadExample::MyThreadProc));

		// Start the thread.
		myThreads[i]->Start();
	}
	
	// Join on the threads
	for (int i=0; i<cThreads; i++) {
		myThreads[i]->Join();
	}
	
	// Free memory
	delete [] myThreadExamples;
	delete [] myThreads;

	return 0;
}
