#include "Generation/Generation.h"

namespace mc {
	namespace Generation {
		
		namespace {
			class Vector2D : public glm::vec2 {
			public:
				Vector2D(double a, double b) : glm::vec2(a, b) {}
				double dot(glm::vec2 other) {
					return x * other.x + y * other.y;
				}
			private:

			};

			void Shuffle(std::vector<int>* tab) {
				for (int e = tab->size() - 1; e > 0; e--) {
					int index = round((double)rand() / (double)RAND_MAX  * (e - 1));
					int temp = tab->at(e);

					tab->operator[](e) = tab->operator[](index);
					tab->operator[](index) = temp;
				}
			}

			std::vector<int> MakePermutation() {
				srand(1);
				std::vector<int> P ;
				for (int i = 0; i < 256; i++) {
					P.push_back(i);
				}
				Shuffle(&P);
				for (int i = 0; i < 256; i++) {
					P.push_back(P[i]);
				}

				return P;
			}
			std::vector<int> P;

			glm::vec2 GetConstantVector(int v) {
				//v is the value from the permutation table
				int h = v % 4;
				if (h == 0)
					return glm::vec2(1.0, 1.0);
				else if (h == 1)
					return glm::vec2(-1.0, 1.0);
				else if (h == 2)
					return glm::vec2(-1.0, -1.0);
				else
					return glm::vec2(1.0, -1.0);
			}

			double Fade(double t) {
				return ((6 * t - 15) * t + 10) * t * t * t;
			}

			double Lerp(double t, double a1, double a2) {
				return a1 + t * (a2 - a1);
			}

			
		}

		void Generator::init() {
			P = MakePermutation();
		}


		double Generator::perlinNoise(double x, double y) {
			double X = (int)floor(x) & 255;
			double Y = (int)floor(y) & 255;

			double xf = x - (int)floor(x);
			double yf = y - (int)floor(y);

			Vector2D topRight(xf - 1.0, yf - 1.0);
			Vector2D topLeft(xf, yf - 1.0);
			Vector2D bottomRight(xf - 1.0, yf);
			Vector2D bottomLeft(xf, yf);

			//Select a value in the array for each of the 4 corners
			int valueTopRight = P[P[X + 1] + Y + 1];
			int valueTopLeft = P[P[X] + Y + 1];
			int valueBottomRight = P[P[X + 1] + Y];
			int valueBottomLeft = P[P[X] + Y];

			double dotTopRight = topRight.dot(GetConstantVector(valueTopRight));
			double dotTopLeft = topLeft.dot(GetConstantVector(valueTopLeft));
			double dotBottomRight = bottomRight.dot(GetConstantVector(valueBottomRight));
			double dotBottomLeft = bottomLeft.dot(GetConstantVector(valueBottomLeft));

			double u = Fade(xf);
			double v = Fade(yf);

			double n = Lerp(u,
				Lerp(v, dotBottomLeft, dotTopLeft),
				Lerp(v, dotBottomRight, dotTopRight)
			);

			n += 1.0;
			n /= 2.0;

			return n;

		}


		//void Generator::perlinNoise2D(int nWidth, int nHeight, float* fSeed, int nOctaves, float fBias, float* fOutput)
		//{
		//	// Used 1D Perlin Noise
		//	for (int x = 0; x < nWidth; x++)
		//		for (int y = 0; y < nHeight; y++)
		//		{
		//			float fNoise = 0.0f;
		//			float fScaleAcc = 0.0f;
		//			float fScale = 1.0f;

		//			for (int o = 0; o < nOctaves; o++)
		//			{
		//				int nPitch = nWidth >> o;
		//				int nSampleX1 = (x / nPitch) * nPitch;
		//				int nSampleY1 = (y / nPitch) * nPitch;

		//				int nSampleX2 = (nSampleX1 + nPitch) % nWidth;
		//				int nSampleY2 = (nSampleY1 + nPitch) % nWidth;

		//				float fBlendX = (float)(x - nSampleX1) / (float)nPitch;
		//				float fBlendY = (float)(y - nSampleY1) / (float)nPitch;

		//				float fSampleT = (1.0f - fBlendX) * fSeed[nSampleY1 * nWidth + nSampleX1] + fBlendX * fSeed[nSampleY1 * nWidth + nSampleX2];
		//				float fSampleB = (1.0f - fBlendX) * fSeed[nSampleY2 * nWidth + nSampleX1] + fBlendX * fSeed[nSampleY2 * nWidth + nSampleX2];

		//				fScaleAcc += fScale;
		//				fNoise += (fBlendY * (fSampleB - fSampleT) + fSampleT) * fScale;
		//				fScale = fScale / fBias;
		//			}

		//			// Scale to seed range
		//			fOutput[y * nWidth + x] = fNoise / fScaleAcc;
		//		}

		//}



	}
}
