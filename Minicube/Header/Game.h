#pragma once

#include "Renderer/Renderer.h"
#include "Player.h"
#include "Textures.h"
#include "World/World.h"

#include "Blocks/Dirt.h"

namespace mc {
	class Game {
	public:
		~Game();

		void init(Renderer* renderer);
		void start();
		void release();
	private:
		Renderer* m_renderer = nullptr;
		Player m_player;

		World m_world;
	};
}