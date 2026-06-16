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
    // Construct note and inject sample body content
    Note note("Test Note");
    note.setContent("Lorem ipsum");

    // Verify title integrity
    assertTrue(note.getTitle() == "Test Note",
            "ERROR: Note title");

    // Verify content payload extraction
    assertTrue(note.getContent() == "Lorem ipsum",
            "ERROR: Note content");

    /**
     * Assert that printing the note to a stringstream with an
     * indent of 7 spaces produces the expected output. I.e. two
     * lines with (remove quotes, shown only to indicate limits):
     * "        - Test note"
     * "          Lorem ipsum"
     */
    stringstream ss;
    // Serialize structure to evaluate spacing logic
    note.printItem(ss, 7);

    string expected =
            "       - Test Note\n"
            "          Lorem ipsum\n";

    // Validate textual representation matching formatting requirements
    assertTrue(ss.str() == expected,
            "ERROR: Note print");

    /**
     * Create another instance of Note and assert that its id
     * is one bigger than the id of the note created above.
     */
    // Produce secondary item to observe automated ID scaling behavior
    Note note2("Another Note");

    // Ensure consecutive IDs assign linearly upward
    assertTrue(note2.getId() == note.getId() + 1,
            "ERROR: Note id");
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
    Topic topic("Test Topic");

    // Verify title access
    assertTrue(topic.getTitle() == "Test Topic",
            "ERROR: Topic title");

    // Ensure freshly instantiated topic correctly initializes with no nested structures
    assertTrue(topic.getItems().size() == 0,
            "ERROR: Topic should be empty");

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
    stringstream ss;

    // Trigger serialization to analyze structural output
    topic.writeCsv(ss, nullptr);

    string expectedTopic =
            "Topic;" +
            to_string(topic.getId()) +
            ";0;Test Topic;\n";

    // Validate the resultant root object's CSV schema footprint
    assertTrue(ss.str() == expectedTopic,
            "ERROR: Topic CSV");

    /*
     * Add an instance of Note to the topic (copy the code for
     * creating the first note from the noteTests)and assert that
     * the topic now has exactly one item. Also assert that this
     * item is the one that was added.
     */
    auto note =
        unique_ptr<Item>(
            (new Note("Test Note"))
            ->setContent("Lorem ipsum"));

    Item* addedNote = note.get();

    // Lodge sample note into the parent topic container
    topic.add(std::move(note));

    // Confirm addition modified the parent structural count
    assertTrue(topic.getItems().size() == 1,
            "ERROR: Topic item count");

    // Check pointer consistency after relocation semantics applied
    assertTrue(topic.getItems()[0] == addedNote,
            "ERROR: Wrong item stored");

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
    stringstream ss2;

    // Instruct nested child to produce its own row accounting for parent reference
    addedNote->writeCsv(ss2, &topic);

    string expectedNote =
            "Note;" +
            to_string(addedNote->getId()) +
            ";" +
            to_string(topic.getId()) +
            ";Test Note;Lorem ipsum\n";

    // Ensure correct relationship mapped correctly through ID references
    assertTrue(ss2.str() == expectedNote,
            "ERROR: Note CSV");
}
/**
 * Basic tests for Notebook (10 points)
 */
void notebookTests() {

    // Bootstrap overall hierarchy with sample branches and nested item depths
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

    // Persist complete structure out onto the file system 
    ofstream out("notebook.csv");
    notebook->saveAsCsv(out);
    out.close();

    ifstream in("notebook.csv");

    // Reload raw stream back into corresponding memory object tree
    Notebook* restored =
            Notebook::loadFromCsv(in);

    in.close();

    stringstream originalText;
    stringstream restoredText;

    // Trigger full recursive print for both memory footprints to compare equality
    notebook->print(originalText);
    restored->print(restoredText);

    // Verify parsed data flawlessly matches structural serialization output
    assertTrue(
        originalText.str() == restoredText.str(),
        "ERROR: Notebook restore"
    );

    // Free dynamic allocations explicitly
    delete notebook;
    delete restored;
}

void allTests() {
    noteTests();
    topicTests();
    notebookTests();
}
