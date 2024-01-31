#include "Bill.h"
#include <vector>

using namespace std;

class Repo
{
private:
	vector<Bill> v;
public:
	Repo();
	~Repo();

	vector<Bill> getAll();
	void add(Bill b);
};