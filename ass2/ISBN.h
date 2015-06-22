/*Hyungi kim
025 741 125
assignment 3
ISBN.h*/
bool isValid(const char* str);
class ISBN{
	char ISBNcd[11];
	char area[6];
	char publisher[8];
	char title[7];
	bool registered;
	bool &isRegistered(const ISBNPrefix);
public:
	ISBN();
	ISBN(const char* str, const ISBNPrefix& list);
	 bool isRegistered() const;
	 bool isRegistered(const ISBNPrefix& list);
	 bool empty() const;
	 void tostr(char* str) const;
	 void toStrWithStyle(char* str) const;
	 bool read(istream& is, const ISBNPrefix& list);
	 void display(ostream& os) const;
	 bool operator ==(const ISBN& left, const ISBN7 right);
	 ~ISBN();
};
 ostream& operator<<(ostream& os, const ISBN& isbn);
