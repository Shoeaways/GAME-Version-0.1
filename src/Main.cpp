#include "Functions.hpp"
#include "Platform/Platform.hpp"

using namespace std;

int main()
{

/* Output this message if runnign in debug mode */
#if defined(_DEBUG)
	cout << "Booting Up!" << endl
		 << endl;
#endif
	srand(static_cast<unsigned>(time(NULL)));

	Game game;

	//Game Loop
	while (game.Running())
	{
		//Update
		game.update();
		//Render
		game.render();
	}

#if defined(_DEBUG)
	cout << "Closing!";
#endif

	return 0;
}
