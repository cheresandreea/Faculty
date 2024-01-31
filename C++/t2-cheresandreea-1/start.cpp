#include "UI.h"

int main()
{
	Service service = Service();
	UI ui = UI(service);
	ui.start();
}