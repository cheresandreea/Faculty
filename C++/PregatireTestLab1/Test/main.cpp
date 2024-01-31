#include "Car.h"
#include "Tests.h"
#include "Repo.h"
#include "Service.h"
#include "UI.h"

int main()
{
	Repo repo;
	Service service = Service(repo);
	UI ui = UI(service);
	ui.start();

	//runAll();
}