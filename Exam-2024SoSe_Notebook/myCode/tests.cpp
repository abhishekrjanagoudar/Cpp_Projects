#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>

#include "Notebook.h"
#include "Note.h"

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage) {
    if (!condition) {
        cout << failedMessage << endl;
    }
}

/**
 * Basic tests for Note (6 points)
 */
void noteTests() {
	/*
	 * Create an instance of Note with title "Test Note" and
	 * set content "Lorem ipsum". Assert that getting the title
	 * and content returns the values that were set.
	 */
	// TODO

    /**
     * Assert that printing the note to a stringstream with an
     * indent of 7 spaces produces the expected output. I.e. two
     * lines with (remove quotes, shown only to indicate limits):
     * "        - Test note"
     * "          Lorem ipsum"
     */
    // TODO

    /**
     * Create another instance of Note and assert that its id
     * is one bigger than the id of the note created above.
     */
	// TODO

}

/**
 * Basic tests for Topic (15 points)
 */
void topicTests() {
	/*
	 * Create an instance of Topic with title "Test Topic".
	 * Assert that getting the title returns the value that was set
	 * and that the topic has no items.
	 */
    // TODO

    /*
     * Assert that invoking writeCsv() on the topic with no
     * parent produces the expected output:
     *
     * Topic;9999;-1;Test Topic;
     *
     * Replace "9999" with the topic's id when invoking
     * the assertion. (Hint: use the topic's getId() method and
     * std::to_string to evaluate the string to compare with.)
     */
    // TODO

    /*
     * Add an instance of Note to the topic (copy the code for
     * creating the first note from the noteTests)and assert that
     * the topic now has exactly one item. Also assert that this
     * item is the one that was added.
     */
    // TODO

    /*
     * Assert that invoking writeCsv() on the note produces
     * the expected output:
     *
     * Note;8888;9999;Test Note;Lorem ipsum
     *
     * Replace "8888" and "9999" with the note's and topic's id
     * when invoking the assertion. (Hint: again, build the
     * string to compare with at run-time.)
     */
    // TODO

}

/**
 * Basic tests for Notebook (10 points)
 */
void notebookTests() {
	/*
	 * The given code creates a Notebook with some notes and topics.
	 * Write it to a file with saveToCsv() and then read it back
	 * with loadFromCsv(). Use Notebook::print(ostream& out) to
	 * assert that the restored (loaded) notebook and the original
	 * notebook are identical.
	 */
	Notebook *notebook = new Notebook("Studies Notebook");
	notebook->add(std::unique_ptr<Item>((new Note("Work consistently"))
		->setContent("Plan ahead!")));
	Topic* apt = new Topic("APT");
	apt->add(std::unique_ptr<Item>((new Note("Learn C++"))
		->setContent("Remember that this takes some time!")));
	apt->add(std::unique_ptr<Item>(new Note("Learn about libraries")));
	notebook->add(std::unique_ptr<Item>(apt));
	Topic* other = new Topic("Other");
	other->add(std::unique_ptr<Item>(new Note("Learn Something")));
	other->add(std::unique_ptr<Item>(new Note("Learn more about something")));
	notebook->add(std::unique_ptr<Item>(other));
	notebook->add(std::unique_ptr<Item>(new Note("Finish the studies")));

	// TODO

}

void allTests() {
    noteTests();
    topicTests();
    notebookTests();
}
