#include "Service.h"

class UI
{
private:
	Service service;
public:
	UI();
	UI(Service& service);
	~UI();
	void menu();
	void addB();
	void add();
	void seePaid();
	void seeAll();
	void start();

};