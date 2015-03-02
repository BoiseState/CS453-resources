/*
 * UnitTestList.c
 *
 *      Author: marissa
 */

#include <stdio.h>
#include <stdlib.h>

#include "Object.h"
#include "Node.h"
#include "List.h"

#define SUCCESS 1
#define FAIL 0

/*
 * macro to mimic the functionality of assert() from <assert.h>. The difference is that this version doesn't exit the program entirely.
 * It will just break out of the current function (or test case in this context).
 */
#define myassert(expr) if(!(expr)){ fprintf(stderr, "\t[assertion failed] %s: %s\n", __PRETTY_FUNCTION__, __STRING(expr)); return 0; }

struct list *testlist;

int testCount = 0;
int passCount = 0;

void printTestInfo(char* testName, char *info)
{
	fprintf(stdout, "%s - %s\n", testName, info);
}

void printTestResult(char* testName, int passed)
{
	if(passed){
		fprintf(stdout, "%s - %s\n\n", "[PASSED]", testName);
	}else{
		fprintf(stdout, "%s - %s\n\n", "[FAILED]", testName);
	}
}

struct node *createTestNode(int jobid)
{
	struct object * job = createObject(jobid, "cmd args");
	struct node *node = createNode(job);
	return node;
}

int addAtFrontToNullListTest()
{
	struct node *node = createTestNode(1);
	addAtFront(NULL, node);
	freeNode(node, testlist->freeObject);
	return 1;
}

int addAtFrontWithNoNodes()
{
	struct node *node = createTestNode(1);
	addAtFront(testlist, node);
	myassert(testlist->size == 1);
	myassert(testlist->head == node)
	myassert(testlist->head->next == NULL)
	return 1;
}

int addAtFrontWithOneNode()
{
	struct node *node = createTestNode(1);
	addAtFront(testlist, node);
	myassert(testlist->size == 1);

	struct node *node2 = createTestNode(2);
	addAtFront(testlist, node2);

	myassert(testlist->size == 2);
	myassert(testlist->head == node2)
	myassert(node2->next == node)
	myassert(testlist->head->next->next == NULL)
	return 1;
}

int addAtRearWithNoNodes()
{
	printTestInfo("addAtRearWithNoNodes", "(not implemented)");
	return 0;
}

int addAtRearWithOneNode()
{
	printTestInfo("addAtRearWithOneNode", "(not implemented)");
	return 0;
}

int removeFromListWithOneNode()
{
	printTestInfo("removeFromListWithOneNode", "(not implemented)");
	return 0;
}

int nullNodeTest()
{
	printTestInfo("nullNodeTest", "(not implemented)");
	return 0;
}

int searchNullListTest()
{
	struct object *job = createObject(1, "");
	struct node *found = searchList(NULL, job);
	myassert(found == NULL);

	freeObject(job); // clean up after ourselves because we didn't add it to the list.
	return 1;
}

int searchEmptyListTest()
{
	return 1;
}

int searchListNotFound()
{
	return 1;
}

int searchListFound()
{
	return 1;
}









void beforeTest(char* testName)
{
	printTestInfo(testName, "Running...");
	testlist = createList(equals, toString, freeObject);
	testCount++;
}
void afterTest(char* testName, int result)
{
	printTestResult(testName, result);
	freeList(testlist);
	passCount += result;
}
/*
 * TODO: Write your test functions here
 */

void runUnitTests()
{
	int result;
	char *testName;

	testName = "addAtFrontToNullListTest";
	beforeTest(testName);
	result = addAtFrontToNullListTest();
	afterTest(testName, result);


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

	//TODO: Add in your tests here

	testName = "searchNullListTest";
	beforeTest(testName);
	result = searchNullListTest();
	afterTest(testName, result);


	fprintf(stdout, "Test Cases: %d\n",  testCount);
	fprintf(stdout, "Passed: %d\n", passCount);
	fprintf(stdout, "Failed: %d\n", testCount - passCount);
}

int main(int argc, char *argv[])
{
	runUnitTests();
	exit(0);
}
