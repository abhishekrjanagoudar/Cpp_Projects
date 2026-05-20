#ifndef NOTE_H_
#define NOTE_H_

#include <string>
#include "Item.h"

class Topic;

class Note : public Item {
private:
	std::string content;

public:
	/**
	 * Creates a Note with the given title. (1 point)
	 *
	 * @param title the title
	 */
	Note(std::string title);

	/** The destructor */
	virtual ~Note();

	/**
	 * Store the given value in the note's content attribute.
	 *
	 * @param content the content
	 * @return the note
	 */
    Note* setContent(std::string content);

    /**
     * Return the note's content.
     *
     * @return the content
     */
    std::string getContent() const;

    /**
     * Print the note's title and content as specified by the
     * method in the base class. (4 points)
     *
     * @param out the ostream to write to
     * @param indent the indentation
     */
	void printItem(std::ostream& out, int indent) const;

	/**
	 * Writes the note's data as a line, using semicolons as separators.
	 * The format is ("<...>" denotes a placeholder):
	 *
	 * Note;<id>;<parent id>;<title>;<content>
	 *
	 * (3 points)
	 *
	 * @param out the ostream to write to
	 * @param parent a pointer to the parent item, i.e. to the Topic
	 * that this item belongs to. 0 if the is the top level Topic, i.e.
	 * the Notebook.
	 */
	void writeCsv(std::ostream& out, const Item* parent) const;

	/**
	 * Creates an instance of this class from the data passed in parameter
	 * "line", if the value in the type field matches the type identifier
	 * used by this class. The map "topics" associates parent ids found in
	 * the input data with the topics created for that (parent) id while
	 * processing the data. The map is used to find the topic that a
	 * created item must be attached to.
	 *
	 * Implementation hint: you can use std::stol to convert a string
	 * to a long.
	 *
	 * (9 points)
	 *
	 * @param topics a map from ids read as parent ids to instances
	 * @param the line with CSV data
	 * @return true if the line could be processed, false if the
	 * type identifier in the line does not match the type identifier
	 * used by this class
	 */
	static bool fromCsv(std::map<long, Topic*>& topics, std::string line);
};

#endif /* NOTE_H_ */
