#include "Game.h"

int main() {
	Game game;
	while (game.getWindow().isOpen()) {
		game.update();
	}
	return 0;
}