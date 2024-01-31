#include "Repo.h"

class Service
{
private:
	Repo repo;
public:
	Service();
	Service(Repo& repo);
	~Service();
	vector<Bill> getAll();
	void add(Bill b);
};