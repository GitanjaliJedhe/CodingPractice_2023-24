/*
In the C++11 threading library, the mutexes are in the <mutex> header file. The class representing a mutex is the std::mutex class.

There are two important methods of mutex:
1.) lock()
2.) unlock()
*/

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Wallet {
private:
	int mMoney;
	std::mutex mutex;

public:
	Wallet() : mMoney(0) {
	}

	int getMoney() {
		return mMoney;
	}

	void addMoney(int money) {
		mutex.lock();

		for (int i = 0; i < money; i++) {
			mMoney++;
		}

		mutex.unlock();
	}
};

int testMultithreadedWallet() {
	Wallet walletObject;

	std::vector<std::thread> threads;

	for (int i = 0; i < 5; i++) {
		threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
	}

	for (int i = 0; i < threads.size(); i++) {
		threads.at(i).join();
	}

	return walletObject.getMoney();
}

int main() {
	int val = 0;

	for (int k = 0; k < 1000; k++) {
		if ((val = testMultithreadedWallet()) != 5000) {
			std::cout << "Error at count = " << k << " Money in Wallet = " << val << std::endl;
		}
	}

	return 0;
}

/* 
* Output:
* 
*/
