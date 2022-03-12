#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>


class Wordnode {
	public:
		Wordnode();
		~Wordnode();
		int insert(char*);
		int remove(char*);
		bool randomOut(char*);
		bool findandOutput(int, char*);
	private:
		char * data;
		Wordnode * child;
};
