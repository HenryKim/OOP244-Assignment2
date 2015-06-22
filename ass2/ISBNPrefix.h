/*Hyungi kim
025 741 125
assignment 2
ISBNPrefix.h*/
class ISBNPrefix{
FILE *fp;
public:
ISBNPrefix();
ISBNPrefix(const char* prefixRanges[]);
bool isRegistered(int area) const;
int minNoDigits(int area) const;
bool isRegistered(int area, const char* publisher) const;
 ~ISBNPrefix();
};