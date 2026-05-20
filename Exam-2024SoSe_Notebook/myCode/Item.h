#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <map>

class Item {
private:
	/** Counter for creating ids */
	static long idCounter;

	/** The item's id */
	long id;
	/** The item's title */
	std::string title;

public:
	/**
	 * Initializes an Item using the given title. (2 points)
	 *
	 * @param title the title
	 */
	Item(std::string title);

	/** The destructor */
	virtual ~Item();

	/**
	 * Returns the instance's id. (1 point)
	 *
	 * @return the id
	 */
	long getId() const;

	/**
	 * Returns the item's title. (1 point)
	 *
	 * @return the title
	 */
	virtual std::string getTitle() const;

	/**
	 * Prints the item on the given ostream. The first line consists of
	 * "indent" spaces, followed by " - " and the title. If derived
	 * classes have more information to print, they must (for each line)
	 * first print "indent + 3" spaces and then the information.
	 * (2 points)
	 */
	virtual void printItem(std::ostream& out, int indent) const;

	/**
	 * Writes the item's data as a line, using semicolons as separators,
	 * terminated with an "endl". The general format is ("<...>"
	 * denotes a placeholder):
	 *
	 * <type>;<id>;<parent id>;<title>;<item specific data>
	 *
	 * "<type>" is the item's type identifier, "<id>" the item's id,
	 * "<parent id>" the id of the Topic that this item belongs to and
	 * "<title>" the Item's title. If the Item does not have a parent,
	 * -1 is used as parent id.
	 *
	 * See the derived classes' method descriptions for their specific
	 * details.
	 *
	 * @param out the ostream to write to
	 * @param parent a pointer to the parent item, i.e. to the Topic
	 * that this item belongs to. Use nullptr (a.k.a. NULL) if the is
	 * the top level Topic, i.e. the Notebook.
	 */
	virtual void writeCsv(std::ostream& out, const Item* parent) const = 0;
};

#endif /* ITEM_H_ */
