/*
Say you have to create a page which has operations like add, delete, remove and 
also a copy which will have the same operations as the individual pages.
Such situation is the best dealt with the composite pattern.

Now the same operation that can be applied to an individual object and 
can also be applied to the collection of those individual object 
makes it very easy to work with a larger object which is made of the smaller independent objects.
*/

#include <iostream>
#include <vector>

class PageObject {
public:
	virtual void Add(PageObject a) {
	}

	virtual void Remove() {
	}

	virtual void Delete(PageObject a) {
	}
};

class Page : public PageObject {
public:
	void Add(PageObject a) {
		std::cout << "Something is added to the page" << std::endl;
	}

	void Remove() {
		std::cout << "Something is removed from the page" << std::endl;
	}

	void Delete(PageObject a) {
		std::cout << "Something is deleted from page" << std::endl;
	}
};

class Copy : public PageObject {
private:
	std::vector<PageObject> copyPages;

public:
	void AddElement(PageObject a) {
		copyPages.push_back(a);
	}

	void Add(PageObject a) {
		std::cout << "Something is added to the copy" << std::endl;
	}

	void Remove() {
		std::cout << "Something is removed from the copy" << std::endl;
	}

	void Delete(PageObject a) {
		std::cout << "Something is deleted from copy" << std::endl;
	}
};

int main() {
	Page a;
	Page b;
	Copy allcopy;
	allcopy.AddElement(a);
	allcopy.AddElement(b);

	allcopy.Add(a);
	a.Add(b);

	allcopy.Remove();
	b.Remove();

	return 0;
}

/*
* Output:
Something is added to the copy
Something is added to the page
Something is removed from the copy
Something is removed from the page
*/
