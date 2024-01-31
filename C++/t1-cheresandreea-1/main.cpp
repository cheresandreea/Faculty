#include "UI.h"

int main()
{
	Repo repo = Repo();
	Service service = Service(repo);
	UI ui = UI(service);
	ui.start();
}