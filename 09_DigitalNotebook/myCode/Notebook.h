#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

#include <ostream>
#include "Topic.h"

class Notebook : public Topic {
public:
	/**
	 * Creates a Notebook with the given title. (1 point)
	 */
	Notebook(std::string title = "");

	/** The destructor */
	virtual ~Notebook();

	/**
	 * Prints the notebook on the given output stream.
	 * The method prints as caption "Notebook: " followed the title,
	 * underlined with "-"s with exactly the length of the caption.
	 * This is followed by the content of the notebook, adding 3 spaces
	 * as indent for each subtopic. (See example in test.cpp.)
	 * (6 points)
	 *
	 * @param out the output stream
	 */
	void print(std::ostream& out) const;

	/**
	 * Convenience method to print the notebook on cout. (1 point)
	 */
	void print() const;

	/**
	 * Saves the notebook to an output stream. The format of the data
	 * in the output stream is specified by method writeCsv() in class Item.
	 * (1 point)
	 *
	 * @param out the output stream
	 */
	void saveAsCsv(std::ostream& out) const;

	/**
	 * Restores a notebook from the given input stream. The format of
	 * the data in the input stream is specified by method writeCsv()
	 * in class Item.
	 *
	 * Implementation hint: A Notebook "is a" Topic and simply saved
	 * as Topic in the CSV data (as first line). Processing the first
	 * line with fromCsv of super class Topic thus creates an instance
	 * of Topic, although we need an instance of Notebook. In order to
	 * work around this, use the pointer left in the "id map" by fromCsv
	 * after processing the first line (only entry at that time) to
	 * access the created Topic. Use the data from this Topic to create
	 * an instance of Notebook, delete the original Topic and replace
	 * the entry in the map using the pointer to the Notebook.
	 * (9 points)
	 *
	 * @param in the input stream
     * @return the restored notebook
	 */
	static Notebook* loadFromCsv(std::istream& in);
};

#endif /* NOTEBOOK_H_ */
