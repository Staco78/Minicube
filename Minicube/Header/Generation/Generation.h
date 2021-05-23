#pragma once

#include <vector>
#include <Glm/glm.hpp>

namespace mc {

	namespace Generation {
		class Generator {
		public:
			void init();
			//void perlinNoise2D(int nWidth, int nHeight, float* fSeed, int nOctaves, float fBias, float* fOutput);
			double perlinNoise(double x, double y);
		private:
		};
	}
}