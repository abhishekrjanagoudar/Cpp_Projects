#ifndef TOPIC_H_
#define TOPIC_H_

#include <memory>
#include <vector>
#include "Item.h"

class Topic : public Item {
private:
	std::vector<std::unique_ptr<Item>> items;

public:
	/**
	 * Creates a Topic with the given title. (1 point)
	 */
	Topic(std::string title);

	/** The destructor */
	virtual ~Topic();

	/**
	 * Add an item to this Topic. (2 points)
	 *
	 * @param item the item to add
	 */
	virtual void add(std::unique_ptr<Item>& item);

	/**
	 * Add an item to this Topic. (2 points)
	 *
	 * @param item the item to add
	 */
	virtual void add(std::unique_ptr<Item>&& item);

	/**
	 * Return pointers to the items in this topic. (3 points)
	 */
	virtual std::vector<const Item*> getItems() const;

	/**
	 * Output this Topic using the given indentation. (3 points)
	 */
	void printItem(std::ostream& out, int indent) const;

	/**
	 * Writes the topic's data as a line, using semicolons as separators.
	 * The format is ("<...>" denotes a placeholder):
	 *
	 * Topic;<id>;<parent id>;<title>;<N/A>
	 *
	 * The last field is not needed for this content and therefore left
	 * empty.
     *
     * (5 points)
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
	 * used by this class. The map "topics" associates parent ids found
	 * in the input data with the topics created for that (parent) id
	 * while processing the data. The map is used to find the topic that
	 * a created item must be attached to.
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

#endif /* TOPIC_H_ */
