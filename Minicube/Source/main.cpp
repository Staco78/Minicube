#define STB_IMAGE_IMPLEMENTATION

#include "Game.h"


int main() {
	mc::Renderer renderer;
	mc::Game game;
	game.init(&renderer);
	game.start();
	return 0;
}