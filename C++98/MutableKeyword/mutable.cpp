/*
mutable storage class specifier
auto, register, static and extern are the storage class specifiers

What is the need of mutable?
Sometimes there is requirement to modify one or more data members of class / struct through const function
*/

#include <iostream>

class Customer {
private:
	std::string name;
	int tablenum;
	mutable std::string order;
	mutable int bill;

public:
	Customer(std::string name_, int tablenum_, std::string order_, int bill_) {
		name = name_;
		tablenum = tablenum_;
		order = order_;
		bill = bill_;
	}

	void changeOrder(std::string newOrder) const {
		order = newOrder;
	}

	void changeBill(int newBill) const {
		bill = newBill;
	}

	void display() {
		std::cout << "Customer Details: " << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Table Number: " << tablenum << std::endl;
		std::cout << "Order: " << order << std::endl;
		std::cout << "Bill: " << bill << std::endl;
	}
};

int main() {
	Customer cust1("Gitanjali Jedhe", 21, "Ice Cream", 150);
	cust1.display();

	cust1.changeOrder("Gulab Jamun");
	cust1.changeBill(200);

	cust1.display();

	return 0;
}

/*
Output:
Customer Details:
Name: Gitanjali Jedhe
Table Number: 21
Order: Ice Cream
Bill: 150
Customer Details:
Name: Gitanjali Jedhe
Table Number: 21
Order: Gulab Jamun
Bill: 200
*/
