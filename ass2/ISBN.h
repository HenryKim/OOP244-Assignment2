/*Hyungi kim
025 741 125
assignment 2
ISBN.h*/
#include <iostream>
#include <cstring>
using namespace std;
int isValid(const char* str);
class ISBN{
	char ISBNcd[11];
	char area[6];
	char publisher[8];
	char title[7];
	bool registered;
	bool isregistered(const ISBNPrefix& list);
public:
	ISBN();
	ISBN(const char* str, const ISBNPrefix& list);
	 bool isRegistered() const;
	 bool isRegistered(const ISBNPrefix& list);
	 bool empty() const;
	 void toStr(char* str) const;
	 void toStrWithStyle(char* str) const;
	 bool read(istream& is, const ISBNPrefix& list);
	 void display(ostream& os) const;
};

