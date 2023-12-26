#include <iostream>
#include <fstream>
#include <string>
#include "linkedlist.h"
#include "test.h"

using namespace std;

#define DEFAULT_DICT "dictionary1.txt"
#define DEFAULT_OUTPUT_FILE "dict-updated.txt"

// Declared enum actions to use in file.
enum Actions {
    QUIT, COUNT, PRINT_TO_SCREEN, ADD_WORD, LINEAR_SEARCH, DELETE_WORD, BINARY_SEARCH,
    INSERT_IN_ORDER, SWAP, BUBBLE_SORT, SELECTION_SORT, MERGE_DICTS,
    MERGE_SORT, LOAD_NEW_DICT, WRITE_DICT_TO_FILE, UNIT_TEST
};

// Max variables.
int max_menu_option = UNIT_TEST;
int max_dict_option = 10;

string cleanWord(string word) {
    string cleanedWord;

    //  Convert lowercase and remove non-lowercase characters. 
    for (char c : word) {
        // Check if character is uppercase
        if (c >= 'A' && c <= 'Z') {
            // Convert to lowercase
            cleanedWord += (c - 'A' + 'a');
        }
            // Check if haracter is lowercase
        else if (c >= 'a' && c <= 'z') {
            cleanedWord += c;
        }
    }

    return cleanedWord;
}

// Linear search function
Node* findWord(LinkedList* lDict, const string& userWord) {
    string cleanedUserWord = cleanWord(userWord);
    Node* current = lDict->getHead();
    while (current != nullptr) {
        if (cleanWord(current->getWord()) == cleanedUserWord) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

// Function to add word to dictionary
void addWord(LinkedList* lDict, const string& userWord) {
    Node* found = findWord(lDict, userWord);
    if (found == nullptr) {
        // Add the new word
        lDict->push_back(userWord);
        cout << "We did not find your word." << endl;
        cout << "Adding word to dictionary..." << endl;
        cout << "\tAdded!" << endl;

        Node* newNode = findWord(lDict, userWord);
        string prevWordMsg = (newNode && newNode->getPrev())
                             ? (" The previous word would be '" + newNode->getPrev()->getWord() + "'.")
                             : " There is no word before " + userWord + ". It is the first word.";
        string nextWordMsg = (newNode && newNode->getNext())
                             ? (" The next word would be '" + newNode->getNext()->getWord() + "'.")
                             : " There is no word after " + userWord + ". It is the last word.";

        cout << prevWordMsg << endl;
        cout << nextWordMsg << endl;
    } else {
        cout << " The previous word would be '"
             << (found->getPrev() ? found->getPrev()->getWord() : "No previous word")
             << "'." << endl;
        cout << " The next word would be '"
             << (found->getNext() ? found->getNext()->getWord() : "No next word")
             << "'." << endl;
    }
}

// Menu choices to use.
int getMenuChoice() {
    int input;
    do {
        cout << "--------------------------------------------" << endl;
        cout << "Options menu: " << endl;
        cout << "  (" << COUNT << ") Count - get number of words in dictionary list" << endl;
        cout << "  (" << PRINT_TO_SCREEN << ") Print words to screen" << endl;
        cout << "  (" << ADD_WORD << ") Add a word (to end of dictionary list)" << endl;
        cout << "  (" << LINEAR_SEARCH << ") Find a word (Linear Search)" << endl;
        cout << "  (" << DELETE_WORD << ") Find word, delete if found" << endl;
        cout << "  (" << BINARY_SEARCH << ") Find a word - Binary Search (assumes words are sorted alphabetically)" << endl;
        cout << "  (" << INSERT_IN_ORDER << ") Find word, insert if not found (assumes words are sorted alphabetically)" << endl;
        cout << "  (" << SWAP << ") Swap two words" << endl;
        cout << "  (" << BUBBLE_SORT << ") Sort words (Bubble Sort)" << endl;
        cout << "  (" << SELECTION_SORT << ") Sort words (Selection Sort)" << endl;
        cout << "  (" << MERGE_DICTS << ") Merge two dictionaries (assumes words are sorted alphabetically)" << endl;
        cout << "  (" << MERGE_SORT << ") Sort words (Merge Sort)" << endl;
        cout << "  (" << LOAD_NEW_DICT << ") Load a dictionary (closes current dictionary)" << endl;
        cout << "  (" << WRITE_DICT_TO_FILE << ") Write current dictionary to file" << endl;
        cout << "  (" << UNIT_TEST << ") Unit test of data structure" << endl;
        cout << "Enter a number from 1 to " << max_menu_option << ", or 0 to exit: " << endl;
        cin >> input;

        // If statement and while loop to verify if we have errors with user input.
        if (cin.fail() || input < QUIT || input > max_menu_option) {
            cout << "Error! Input must be a number between 1 and " << max_menu_option << ", or 0 to exit." << endl;
            cin.clear();

        }
    } while (cin.fail() || input < QUIT || input > max_menu_option);
    return input;
}

// Function to load any words into a linkedlist.
void loadDictionary(LinkedList* list, const string& filename) {
    ifstream file(filename);
    string word;
    while (file >> word) {
        list->push_back(word);
    }
    file.close();
}

// Function to prompt user for what options to chose.
void promptForDictionary(LinkedList*& list, int& currentDict) {
    while (true) {
        cout << "Which Dictionary should be opened? Enter a number from \"1\", to \"" << max_dict_option << "\": " << endl;
        int dictNumber;
        cin >> dictNumber;

        if (cin.fail()) {
            cin.clear();
            cout << "ERROR! That is not a number. Please enter a number." << endl;
            continue;
        }

        string newFilename = "dictionary" + to_string(dictNumber) + ".txt";
        ifstream test(newFilename);
        if (!test) {
            cout << "ERROR! Cannot read chosen dictionary " << newFilename << ". Dictionary " << currentDict << " remains open." << endl;
            test.close();
            return;
        }

        if (dictNumber == currentDict) {
            cout << "That dictionary is already open! Pick another." << endl;
            test.close();
            continue;
        }

        delete list;
        list = new LinkedList();
        loadDictionary(list, newFilename);
        currentDict = dictNumber;
        cout << "Dictionary " << dictNumber << " is now open." << endl;
        return;
    }
}

// Write dictionary words to file
void writeDictionaryToFile(LinkedList* list) {
    string filename;
    cout << "Enter name of file (.txt will be appended automatically), or enter 'd' to use default filename: ";
    cin >> filename;

    if (filename == "d") {
        filename = DEFAULT_OUTPUT_FILE;
    } else {
        filename += ".txt";
    }

    // Check if the file already exists
    ifstream test(filename);
    if (test.good()) {
        cout << "Error! The File " << filename << " already exists." << endl;
        return;
    }
    test.close();
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error! Unable to create file " << filename << endl;
        return;
    }
    cout << "Writing to file ... " << endl;
    Node* current = list->getHead();
    while (current != nullptr) {
        outFile << current->getWord() << endl;
        current = current->getNext();
    }
    outFile.close();
    cout << "                   ...Done!" << endl;
}

// Main function to tie in functions.
int main() {
    int currentDict = 1;
    LinkedList* myList = new LinkedList();
    loadDictionary(myList, DEFAULT_DICT);

    while (true) {
        int choice = getMenuChoice();

        switch(choice) {
            case QUIT:
                cout << "Thank you! Bye!" << endl;
                break;
            case COUNT:
                cout << "There are " << myList->size() << " words in dictionary #" << currentDict << "." << endl;
                break;
            case PRINT_TO_SCREEN:
                myList->print();
                break;
            case LOAD_NEW_DICT:
                promptForDictionary(myList, currentDict);
                break;
            case WRITE_DICT_TO_FILE:
                writeDictionaryToFile(myList);
                break;
            case UNIT_TEST:
                promptUnitTest();
                break;
            case ADD_WORD: {
                cout << "Enter a word to add to the end of the chosen Dictionary: ";
                string userWord;
                cin >> userWord;
                userWord = cleanWord(userWord);
                cout << "Your word was '" << userWord << "'." << endl;
                addWord(myList, userWord);
                break;
            }
            case LINEAR_SEARCH: {
                cout << "Enter a word to find: ";
                string userWord;
                cin >> userWord;
                userWord = cleanWord(userWord);
                Node* found = findWord(myList, userWord);

                if (found) {
                    cout << "Your word was '" << userWord << "'." << endl;
                    string prevWordMessage = (found->getPrev()) ? "The previous word would be '" + found->getPrev()->getWord() + "'." : "There is no word before " + userWord + ". It is the first word.";
                    string nextWordMessage = (found->getNext()) ? "The next word would be '" + found->getNext()->getWord() + "'." : "There is no word after " + userWord + ". It is the last word.";
                    cout << prevWordMessage << endl;
                    cout << nextWordMessage << endl;
                } else {
                    cout << "Your word was '" << userWord << "'." << endl;
                    cout << "We did not find your word." << endl;
                }
                break;
            }
            case DELETE_WORD: {
                cout << "Enter a word to delete from the chosen Dictionary: ";
                string userWord;
                cin >> userWord;
                userWord = cleanWord(userWord);
                cout << "Your word was '" << userWord << "'." << endl;
                Node* found = findWord(myList, userWord);

                if (found) {
                    string prevWordMessage, nextWordMessage;
                    if (found->getPrev() == nullptr) {
                        prevWordMessage = "There is no word before " + userWord + ". It is the first word.";
                    } else {
                        prevWordMessage = "The previous word would be '" + found->getPrev()->getWord() + "'.";
                    }

                    Node* nextNode = myList->deleteWord(found);

                    if (nextNode == nullptr) {
                        nextWordMessage = "There is no word after " + userWord + ". It is the last word.";
                    } else {
                        nextWordMessage = "The next word would be '" + nextNode->getWord() + "'.";
                    }

                    cout << prevWordMessage << endl;
                    cout << nextWordMessage << endl;
                    cout << "The word '" << userWord << "' has been deleted." << endl;
                } else {
                    cout << "We did not find your word." << endl;
                }
                break;
            }
            case INSERT_IN_ORDER: {
                cout << "Enter a word to insert in order in the chosen Dictionary: ";
                string userWord;
                cin >> userWord;
                userWord = cleanWord(userWord);
                cout << "Your word was '" << userWord << "'." << endl;

                Node* found = findWord(myList, userWord);
                if (!found) {
                    Node* current = myList->getHead();
                    Node* prev = nullptr;
                    while (current != nullptr && current->getWord() < userWord) {
                        prev = current;
                        current = current->getNext();
                    }
                    myList->insert_before(userWord, current);

                    string prevWordMsg = (prev != nullptr) ? " The previous word would be '" + prev->getWord() + "'." : " There is no word before " + userWord + ". It is the first word.";
                    string nextWordMsg = (current != nullptr) ? " The next word would be '" + current->getWord() + "'." : " There is no word after " + userWord + ". It is the last word.";

                    cout << "We did not find your word. Adding word to dictionary..." << endl;
                    cout << "Inserted!" << endl;
                    cout << prevWordMsg << endl;
                    cout << nextWordMsg << endl;
                } else {
                    string prevWordMsg = (found->getPrev() != nullptr) ? " The previous word would be '" + found->getPrev()->getWord() + "'." : " There is no word before " + userWord + ". It is the first word.";
                    string nextWordMsg = (found->getNext() != nullptr) ? " The next word would be '" + found->getNext()->getWord() + "'." : " There is no word after " + userWord + ". It is the last word.";
                    cout << prevWordMsg << endl;
                    cout << nextWordMsg << endl;
                }
                break;
            }
        }
        if(choice == QUIT) {
            break;
        }
    }

    delete myList;
    return 0;
}