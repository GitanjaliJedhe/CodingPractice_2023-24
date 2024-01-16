#include <iostream>
#include <vector>

class FileSystem {
public:
	virtual void display() const = 0;
};

class File : public FileSystem {
private:
	std::string name;
	int size;

public:
	File(const std::string& name_, int size_) : name(name_), size(size_) {
	}

	void display() const override {
		std::cout << "File: " << name << " (" << size << " bytes)" << std::endl;
	}
};

class Directory : public FileSystem {
private:
	std::string name;
	std::vector<FileSystem*> components;

public:
	Directory(const std::string &name_) : name(name_) {
	}

	void addComponent(FileSystem* component) {
		components.push_back(component);
	}

	void display() const override {
		std::cout << "Directory: " << name << std::endl;
		for (const auto& component : components) {
			component->display();
		}
	}
};

int main() {
	// Create leaf objects (files) 
	FileSystem* file1 = new File("document.txt", 1024);
	FileSystem* file2 = new File("Image.jpg", 2048);

	// Create a composite object (directory) 
	Directory* directory = new Directory("My Documents");

	directory->addComponent(file1);
	directory->addComponent(file2);

	// Display the directory (including its contents) 
	directory->display();

	return 0;
}

/*
Output:
Directory: My Documents
File: document.txt (1024 bytes)
File: Image.jpg (2048 bytes)
*/
