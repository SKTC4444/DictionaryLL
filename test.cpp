#include <iostream>
#include <string>
#include "linkedlist.h"
#include "test.h"

using namespace std;

enum Choices {DONE, PRIVATE, NODE_BASIC, LL_BASIC, NODE_COMP_OPERATORS, RUN_ALL};

int max_test_menu_option = RUN_ALL;

void testPrivate () {
    // everything in this block should fail to compile
    // check the compilation and comment out one at a time as they (properly) fail
/*	{
	Node * tNodePtr = new Node;

	if ((*tNodePtr).word == "") 	cout << "# 1. Word is empty" << endl;
	if ((*tNodePtr).next == NULL) 	cout << "# 2. Next is NULL" << endl;
	if ((*tNodePtr).prev == 0) 	cout << "# 3. Prev is NULL" << endl;
	delete tNodePtr;
	tNodePtr = NULL;
	}

	// everything in this block should fail to compile
	// check the compilation and comment out one at a time as they (properly) fail
	{
	LinkedList * lTestPtr = new LinkedList;

	if ((*lTestPtr).tail == NULL) 	cout << "# 1. Tail is NULL" << endl;
	if ((*lTestPtr).head == NULL) 	cout << "# 2. Head is NULL" << endl;
	if ((*lTestPtr).listSize == 0) 	 	cout << "# 3. size is 0" << endl;
	delete lTestPtr;
	lTestPtr = NULL;
	}
*/
    cout << "Done with \'testPrivate()\'." << endl;
}


void testNodeBasic() {
    // test #A: create Node
    {
        cout << "\n-----Test A --------------------" << endl;
        Node * tNodePtr = new Node("");

        if ((*tNodePtr).getWord() == "") 	cout << "# 1. Word is empty" << endl;
        else 								cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getWord() << endl;
        if ((*tNodePtr).getNext() == NULL) 	cout << "# 2. Next is NULL" << endl;
        else 								cout << "\t\tERROR: # 2. Next is not NULL" << endl;
        if ((*tNodePtr).getPrev() == NULL) 	cout << "# 3. Prev is NULL" << endl;
        else 								cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
        delete tNodePtr;
        tNodePtr = NULL;
    }

    // test #B: create Node with word
    {
        cout << "\n-----Test B --------------------" << endl;
        Node * tNodePtr = new Node("test");

        if ((*tNodePtr).getWord() == "test")cout << "# 1. Word is \'test\'" << endl;
        else 								cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getWord() << endl;
        if ((*tNodePtr).getNext() == NULL) 	cout << "# 2. Next is NULL" << endl;
        else 								cout << "\t\tERROR: # 2. Next is not NULL" << endl;
        if ((*tNodePtr).getPrev() == NULL) 	cout << "# 3. Prev is NULL" << endl;
        else 								cout << "\t\tERROR: # 3. Prev is not NULL" << endl;
        delete tNodePtr;
        tNodePtr = NULL;
    }


    // test #C: create Node with word & update
    {
        cout << "\n-----Test C --------------------" << endl;
        Node * tNodePtr = new Node("test");

        if ((*tNodePtr).getWord() == "test")	cout << "# 1. Word is \'test\'" << endl;
        else 									cout << "\t\tERROR: # 1. Word is " << (*tNodePtr).getWord() << endl;
        (*tNodePtr).setWord("change");
        if ( (*tNodePtr).getWord() == "change")	cout << "# 2. Word is \'change\'" << endl;
        else 									cout << "\t\tERROR: # 2. Word is " << (*tNodePtr).getWord() << endl;

        Node * tNextPtr = new Node("second");
        (*tNodePtr).setNext(tNextPtr);

        Node * tPrevPtr = new Node("first");
        (*tNodePtr).setPrev(tPrevPtr);

        if ( (*tNodePtr).getNext() == tNextPtr  && (*(*tNodePtr).getNext()).getWord() == "second" )
            cout << "# 3. Next is new next pointer whose word is \'" << (*(*tNodePtr).getNext()).getWord() << "\'" << endl;
        else 									cout << "\t\tERROR: # 3. Next fails" << endl;
        if ( (*(*tNodePtr).getNext()).getNext() == NULL ) 	cout << "# 4. Next->next is NULL " << endl;
        else 									cout << "\t\tERROR: # 4. Next->next is not NULL" << endl;
        if ( (*tNodePtr).getPrev() == tPrevPtr	&& (*(*tNodePtr).getPrev()).getWord() == "first" )
            cout << "# 5. Prev is new prev pointer whose word is \'" << (*(*tNodePtr).getPrev()).getWord() << "\'" << endl;
        else 									cout << "\t\tERROR: # 5. Prev is not NULL" << endl;
        if ( (*(*tNodePtr).getPrev()).getPrev() == NULL ) 	cout << "# 6. Prev->prev is NULL " << endl;
        else 									cout << "\t\tERROR: # 6. Prev->prev is not NULL" << endl;
        delete tNodePtr;
        tNodePtr = NULL;
        delete tNextPtr;
        tNextPtr = NULL;
        delete tPrevPtr;
        tPrevPtr = NULL;
    }

} // end testNodeBasic()



void testNodeCompOperators () {
    // test #D: test comparison operators, Node v Node
    {
        cout << "\n-----Test D --------------------" << endl;
        Node * tNodeAptr = new Node("apple");
        Node * tNodeBptr = new Node("banana");
        Node * tNodeB2ptr = new Node("banana");
        Node * tNodeCptr = new Node("cherry");

        if ( *tNodeAptr == *tNodeBptr)		cout << "\t\tERROR: # 1. \'apple\' should NOT == \'banana\'" << endl;
        else 								cout << "# 1. (\'apple\' == \'banana\') is FALSE" << endl;
        if ( *tNodeAptr != *tNodeBptr)		cout << "# 2. (\'apple\' != \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 2. \'apple\' should != \'banana\'" << endl;
        if ( *tNodeBptr == *tNodeB2ptr)		cout << "# 3. (\'banana\' == \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 3. \'banana\' should == \'banana\'" << endl;
        if ( *tNodeBptr != *tNodeB2ptr)		cout << "\t\tERROR: # 4. \'banana\' should NOT != \'banana\'" << endl;
        else 								cout << "# 4. (\'banana\' != \'banana\') is FALSE" << endl;
        cout << endl;

        if ( *tNodeAptr > *tNodeBptr)		cout << "\t\tERROR: # 5. \'apple\' is NOT > \'banana\'" << endl;
        else 								cout << "# 5. (\'apple\' > \'banana\') is FALSE" << endl;
        if ( *tNodeCptr > *tNodeBptr)		cout << "# 6. (\'cherry\' > \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 6. \'cherry\' should be > \'banana\'" << endl;
        if ( *tNodeBptr > *tNodeB2ptr)		cout << "\t\tERROR: # 7. \'banana\' should NOT > \'banana\'" << endl;
        else 								cout << "# 7. (\'banana\' > \'banana\') is FALSE" << endl;
        cout << endl;


        if ( *tNodeAptr < *tNodeBptr)		cout << "# 8. (\'apple\' < \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 8. \'apple\' is  < \'banana\'" << endl;
        if ( *tNodeCptr < *tNodeBptr)		cout << "\t\tERROR: # 9. \'cherry\' should NOT be < \'banana\'" << endl;
        else 								cout << "# 9. (\'cherry\' < \'banana\') is FALSE" << endl;
        if ( *tNodeBptr < *tNodeB2ptr)		cout << "\t\tERROR: # 10. \'banana\' should NOT < \'banana\'" << endl;
        else 								cout << "# 10. (\'banana\' < \'banana\') is FALSE" << endl;
        cout << endl;


        if ( *tNodeAptr >= *tNodeBptr)		cout << "\t\tERROR: # 11. \'apple\' is NOT >= \'banana\'" << endl;
        else 								cout << "# 11. (\'apple\' >= \'banana\') is FALSE" << endl;
        if ( *tNodeCptr >= *tNodeBptr)		cout << "# 12. (\'cherry\' >= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 12. \'cherry\' should be >= \'banana\'" << endl;
        if ( *tNodeBptr >= *tNodeB2ptr)		cout << "# 13. (\'banana\' >= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 13. \'banana\' is >= \'banana\'" << endl;
        cout << endl;


        if ( *tNodeAptr <= *tNodeBptr)		cout << "# 14. (\'apple\' <= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 14. \'apple\' is  <= \'banana\'" << endl;
        if ( *tNodeCptr <= *tNodeBptr)		cout << "\t\tERROR: # 15. \'cherry\' should NOT be <= \'banana\'" << endl;
        else 								cout << "# 15. (\'cherry\' <= \'banana\') is FALSE" << endl;
        if ( *tNodeBptr <= *tNodeB2ptr)		cout << "# 16. (\'banana\' <= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 16. \'banana\' is <= \'banana\'" << endl;


        delete tNodeAptr;
        tNodeAptr = NULL;
        delete tNodeBptr;
        tNodeBptr = NULL;
        delete tNodeB2ptr;
        tNodeB2ptr = NULL;
        delete tNodeCptr;
        tNodeCptr = NULL;
    }

    // test #E: test comparison operators, Node v String
    {
        cout << "\n-----Test E --------------------" << endl;
        Node * tNodeAptr = new Node("apple");
        Node * tNodeBptr = new Node("banana");
        Node * tNodeB2ptr = new Node("banana");
        Node * tNodeCptr = new Node("cherry");

        string	strB = "banana";

        if ( *tNodeAptr == strB)		cout << "\t\tERROR: # 1. \'apple\' should NOT == \"banana\"" << endl;
        else 								cout << "# 1. (\'apple\' == \"banana\") is FALSE" << endl;
        if ( *tNodeAptr != strB)		cout << "# 2. (\'apple\' != \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 2. \'apple\' should != \"banana\"" << endl;
        if ( *tNodeBptr == strB)		cout << "# 3. (\'banana\' == \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 3. \"banana\" should == \"banana\"" << endl;
        if ( *tNodeBptr != strB)		cout << "\t\tERROR: # 4. \'banana\' should NOT != \"banana\"" << endl;
        else 								cout << "# 4. (\'banana\' != \"banana\") is FALSE" << endl;
        cout << endl;

        if ( *tNodeAptr > strB)		cout << "\t\tERROR: # 5. \'apple\' is NOT > \"banana\"" << endl;
        else 								cout << "# 5. (\'apple\' > \"banana\") is FALSE" << endl;
        if ( *tNodeCptr > strB)		cout << "# 6. (\'cherry\' > \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 6. \'cherry\' should be > \"banana\"" << endl;
        if ( *tNodeBptr > strB)		cout << "\t\tERROR: # 7. \'banana\' should NOT > \"banana\"" << endl;
        else 								cout << "# 7. (\'banana\' > \"banana\") is FALSE" << endl;
        cout << endl;


        if ( *tNodeAptr < strB)		cout << "# 8. (\'apple\' < \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 8. \'apple\' is  < \"banana\"" << endl;
        if ( *tNodeCptr < strB)		cout << "\t\tERROR: # 9. \'cherry\' should NOT be < \"banana\"" << endl;
        else 								cout << "# 9. (\'cherry\' < \"banana\") is FALSE" << endl;
        if ( *tNodeBptr < strB)		cout << "\t\tERROR: # 10. \'banana\' should NOT < \"banana\"" << endl;
        else 								cout << "# 10. (\'banana\' < \"banana\") is FALSE" << endl;
        cout << endl;


        if ( *tNodeAptr >= strB)		cout << "\t\tERROR: # 11. \'apple\' is NOT >= \"banana\"" << endl;
        else 								cout << "# 11. (\'apple\' >= \"banana\") is FALSE" << endl;
        if ( *tNodeCptr >= strB)		cout << "# 12. (\'cherry\' >= \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 12. \'cherry\' should be >= \"banana\"" << endl;
        if ( *tNodeBptr >= strB)		cout << "# 13. (\'banana\' >= \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 13. \'banana\' is >= \"banana\"" << endl;
        cout << endl;


        if ( *tNodeAptr <= strB)		cout << "# 14. (\'apple\' <= \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 14. \'apple\' is  <= \"banana\"" << endl;
        if ( *tNodeCptr <= strB)		cout << "\t\tERROR: # 15. \'cherry\' should NOT be <= \"banana\"" << endl;
        else 								cout << "# 15. (\'cherry\' <= \"banana\") is FALSE" << endl;
        if ( *tNodeBptr <= strB)		cout << "# 16. (\'banana\' <= \"banana\") is TRUE" << endl;
        else 								cout << "\t\tERROR: # 16. \'banana\' is <= \"banana\"" << endl;


        delete tNodeAptr;
        tNodeAptr = NULL;
        delete tNodeBptr;
        tNodeBptr = NULL;
        delete tNodeB2ptr;
        tNodeB2ptr = NULL;
        delete tNodeCptr;
        tNodeCptr = NULL;
    }



    // test #F: test comparison operators, Node v Node
    {
        cout << "\n-----Test F --------------------" << endl;
        Node * tNodeAptr = new Node("apple");
        Node * tNodeBptr = new Node("banana");
        Node * tNodeB2ptr = new Node("banana");
        Node * tNodeCptr = new Node("cherry");

        string	strA = "apple",
                strB = "banana",
                strC = "cherry";

        if ( strA == *tNodeBptr)		cout << "\t\tERROR: # 1. \"apple\" should NOT == \'banana\'" << endl;
        else 								cout << "# 1. (\"apple\" == \'banana\') is FALSE" << endl;
        if ( strA != *tNodeBptr)		cout << "# 2. (\"apple\" != \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 2. \"apple\" should != \'banana\'" << endl;
        if ( strB == *tNodeB2ptr)		cout << "# 3. (\"banana\" == \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 3. \"banana\" should == \'banana\'" << endl;
        if ( strB != *tNodeB2ptr)		cout << "\t\tERROR: # 4. \"banana\" should NOT != \'banana\'" << endl;
        else 								cout << "# 4. (\"banana\" != \'banana\') is FALSE" << endl;
        cout << endl;

        if ( strA > *tNodeBptr)		cout << "\t\tERROR: # 5. \"apple\" is NOT > \'banana\'" << endl;
        else 								cout << "# 5. (\"apple\" > \'banana\') is FALSE" << endl;
        if ( strC > *tNodeBptr)		cout << "# 6. (\"cherry\" > \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 6. \"cherry\" should be > \'banana\'" << endl;
        if ( strB > *tNodeB2ptr)		cout << "\t\tERROR: # 7. \"banana\" should NOT > \'banana\'" << endl;
        else 								cout << "# 7. (\"banana\" > \'banana\') is FALSE" << endl;
        cout << endl;


        if ( strA < *tNodeBptr)		cout << "# 8. (\"apple\" < \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 8. \"apple\" is  < \'banana\'" << endl;
        if ( strC < *tNodeBptr)		cout << "\t\tERROR: # 9. \"cherry\" should NOT be < \'banana\'" << endl;
        else 								cout << "# 9. (\"cherry\" < \'banana\') is FALSE" << endl;
        if ( strB < *tNodeB2ptr)		cout << "\t\tERROR: # 10. \"banana\" should NOT < \'banana\'" << endl;
        else 								cout << "# 10. (\"banana\" < \'banana\') is FALSE" << endl;
        cout << endl;


        if ( strA >= *tNodeBptr)		cout << "\t\tERROR: # 11. \"apple\" is NOT >= \'banana\'" << endl;
        else 								cout << "# 11. (\"apple\" >= \'banana\') is FALSE" << endl;
        if ( strC >= *tNodeBptr)		cout << "# 12. (\"cherry\" >= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 12. \"cherry\" should be >= \'banana\'" << endl;
        if ( strB >= *tNodeB2ptr)		cout << "# 13. (\"banana\" >= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 13. \"banana\" is >= \'banana\'" << endl;
        cout << endl;


        if ( strA <= *tNodeBptr)		cout << "# 14. (\"apple\" <= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 14. \"apple\" is  <= \'banana\'" << endl;
        if ( strC <= *tNodeBptr)		cout << "\t\tERROR: # 15. \"cherry\" should NOT be <= \'banana\'" << endl;
        else 								cout << "# 15. (\"cherry\" <= \'banana\') is FALSE" << endl;
        if ( strB <= *tNodeB2ptr)		cout << "# 16. (\"banana\" <= \'banana\') is TRUE" << endl;
        else 								cout << "\t\tERROR: # 16. \"banana\" is <= \'banana\'" << endl;


        delete tNodeAptr;
        tNodeAptr = NULL;
        delete tNodeBptr;
        tNodeBptr = NULL;
        delete tNodeB2ptr;
        tNodeB2ptr = NULL;
        delete tNodeCptr;
        tNodeCptr = NULL;
    }



} //end testNodeCompOperators()


void testLinkedListBasic () {
    // test #X: create empty list, check NULL
    {
        cout << "\n-----Test LL_A --------------------" << endl;
        LinkedList * lTestPtr = new LinkedList;

        if ((*lTestPtr).getTail() == NULL) 	cout << "# 1. Tail is NULL" << endl;
        else 								cout << "\t\tERROR: # 1. Tail is not NULL" << endl;
        if ((*lTestPtr).getHead() == NULL) 	cout << "# 2. Head is NULL" << endl;
        else 								cout << "\t\tERROR: # 2. Head is not NULL" << endl;
        if ((*lTestPtr).size() == 0) 	 	cout << "# 3. size is 0" << endl;
        else 								cout << "\t\tERROR: # 3. size is " << (*lTestPtr).size() << endl;
        delete lTestPtr;
        lTestPtr = NULL;
    }

    // test #Y: create list, check NULL
    {
        cout << "\n-----Test LL-B --------------------" << endl;
        LinkedList * lTestPtr = new LinkedList("word");

        if ((*lTestPtr).getTail() == NULL) 	cout << "\t\tERROR: # 1. Tail is NULL" << endl;
        else 								cout << "# 1. Tail is not NULL, points to \'" << (*(*lTestPtr).getTail()).getWord() << "\'" << endl;
        if ((*lTestPtr).getHead() == NULL) 	cout << "\t\tERROR: # 2. Head is NULL" << endl;
        else 								cout << "# 2. Head is not NULL, points to \'" << (*(*lTestPtr).getHead()).getWord() << "\'" << endl;
        if ((*lTestPtr).size() == 0) 	 	cout << "\t\tERROR: # 3. size is 0" << endl;
        else 								cout << "# 3. size is " << (*lTestPtr).size() << endl;
        delete lTestPtr;
        lTestPtr = NULL;
    }


} //end testLinkedListBasic()

int getTestMenuChoice () {

    int choiceOption;

    do {
        choiceOption = -678123; //init with unlikely value so it will loop again if no valid input is entered
        cout << "\n--------------------------------------------\n"
             << "Test options menu: \n"
             << "  (" << PRIVATE <<") Run public/private tests\n"
             << "  (" << NODE_BASIC <<") Run basic Node tests\n"
             << "  (" << LL_BASIC <<") Run basic Linked List tests\n"
             << "  (" << NODE_COMP_OPERATORS <<") Test comparison operator overload of Node\n"
             << "  (" << RUN_ALL <<") Run all tests \n"
             << "Enter a number from 1 to " << max_test_menu_option << ", or " << DONE << " to exit: ";
        cin >> choiceOption;
        /* check for failure of cin (for instance, when data type read in is not int */
        if (cin.fail()) {
            cin.clear();
            //discard bad characters
            /*zyBooks rejects: cin.ignore (numeric_limits<streamsize>::max(), '\n');
             */
        }
        /* check if input is in valid range */
        if ( (choiceOption < 0) || (choiceOption > max_test_menu_option) ) {
            cout << "\nError! Input must be a number between 1 and " << max_test_menu_option
                 << ", or " << DONE << " to exit." << endl;
            choiceOption = -678123; // loop again.
        }
        cout << endl;
    } while (choiceOption == -678123);


    return choiceOption;


} // end getTestMenuChoice()


void promptUnitTest() {
    /* variables */
    int menuChoice;

    do {
        menuChoice = getTestMenuChoice ();

        switch (menuChoice) {
            case PRIVATE:
                testPrivate ();
                break;
            case NODE_BASIC:
                testNodeBasic();
                break;
            case LL_BASIC:
                testLinkedListBasic ();
                break;
            case NODE_COMP_OPERATORS:
                testNodeCompOperators ();
                break;
            case RUN_ALL:
                testPrivate ();
                testNodeBasic();
                testLinkedListBasic ();
                testNodeCompOperators ();
                break;
            default: 	//DONE entered zero, exit
                cout << "Returning to main menu." << endl;
                menuChoice = 0;				//in case it was a non-listed option
        } //end switch


    } while (menuChoice != 0);

} //end promptUnitTest()
