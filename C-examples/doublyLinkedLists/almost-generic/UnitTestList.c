/*
 * UnitTestList.c
 *
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "Job.h"
#include "Node.h"
#include "List.h"

/* 
 * macro to mimic the functionality of assert() from <assert.h>. The difference is that this version doesn't exit the program entirely.
 * It will just break out of the current function (or test case in this context).
 */
#define myassert(expr) if(!(expr)){ fprintf(stderr, "\t[assertion failed] %s: %s\n", __PRETTY_FUNCTION__, __STRING(expr)); return FALSE; }

ListPtr testlist;

int testCount = 0;
int passCount = 0;

void printTestInfo(char* testName, char *info)
{
	fprintf(stdout, "%s - %s\n", testName, info);
}

void printTestResult(char* testName, Boolean passed)
{
	if(passed == TRUE)
		fprintf(stdout, "%s - %s\n\n", "[PASSED]", testName);
	else
		fprintf(stdout, "%s - %s\n\n", "[FAILED]", testName);
}

NodePtr createTestNode(int jobid)
{
	JobPtr job = createJob(jobid, "cmd args");
	NodePtr node = createNode(job);
	return node;
}

Boolean addAtFrontWithNoNodes()
{
	NodePtr node = createTestNode(1);

	addAtFront(testlist, node);

	myassert(testlist->size == 1)
	myassert(testlist->head == node)
	myassert(testlist->tail == node)
	myassert(testlist->head->next == NULL)
	myassert(testlist->head->prev == NULL)

	return TRUE;
}

Boolean addAtFrontWithOneNode()
{
	printTestInfo("addAtFrontWithOneNode", "(not implemented)");
	return FALSE;
}

Boolean addAtRearWithNoNodes()
{
	printTestInfo("addAtRearWithNoNodes", "(not implemented)");
	return FALSE;
}

Boolean addAtRearWithOneNode()
{
	printTestInfo("addAtRearWithOneNode", "(not implemented)");
	return FALSE;
}

Boolean removeFromListWithOneNode()
{
	printTestInfo("removeFromListWithOneNode", "(not implemented)");
	return FALSE;
}

Boolean nullNodeTest()
{
	printTestInfo("nullNodeTest", "(not implemented)");
	return FALSE;
}

void beforeTest(char* testName)
{
	printTestInfo(testName, "Running...");
	testlist = createList();
	testCount++;
}
void afterTest(char* testName, Boolean result)
{
	printTestResult(testName, result);
	freeList(testlist);
	passCount += result;
}
/*
 * etc...
 */

void runUnitTests()
{
	Boolean result;
	char *testName;

	testName = "addAtFrontWithNoNodes";
	beforeTest(testName);
	result = addAtFrontWithNoNodes();
	afterTest(testName, result);

	testName = "addAtFrontWithOneNode";
	beforeTest(testName);
	result = addAtFrontWithOneNode();
	afterTest(testName, result);

	testName = "addAtRearWithNoNodes";
	beforeTest(testName);
	result = addAtRearWithNoNodes();
	afterTest(testName, result);

	testName = "addAtRearWithOneNode";
	beforeTest(testName);
	result = addAtRearWithOneNode();
	afterTest(testName, result);

	testName = "removeFromListWithOneNode";
	beforeTest(testName);
	result = removeFromListWithOneNode();
	afterTest(testName, result);

	testName = "nullNodeTest";
	beforeTest(testName);
	result = nullNodeTest();
	afterTest(testName, result);

	//etc...

	fprintf(stdout, "Test Cases: %d\n",  testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

int main(int argc, char *argv[])
{
	runUnitTests();
	exit(0);
}
