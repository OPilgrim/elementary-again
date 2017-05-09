#ifndef Language_h
#define Language_h
#include <string>
using namespace std;

class LANGUAGE
{
private:
	string* Resource;
	int language_;
public:
	void language_1();
	void set(string* resource,int language_2)
	{
		language_ = language_2;
		Resource = resource;
		return;
	}
};


#endif
