#pragma once
#include <Glm/glm.hpp>

#include "Utils.h"

namespace mc {

	class Face {
	public:
		void init(utils::Side side) {
			if (side == utils::Side::front)
				m_vertices = vertices::cube::front;
			else if (side == utils::Side::back)
				m_vertices = vertices::cube::back;
			else if (side == utils::Side::left)
				m_vertices = vertices::cube::left;
			else if (side == utils::Side::right)
				m_vertices = vertices::cube::right;
			else if (side == utils::Side::bottom)
				m_vertices = vertices::cube::bottom;
			else if (side == utils::Side::top)
				m_vertices = vertices::cube::top;
		}
		std::vector<float>* getVertices() { return &m_vertices; }
		std::vector<float> getChunkVertices(const glm::uvec3& pos) {
			std::vector<float> r;

			for (unsigned int i = 0; i < m_vertices.size(); i += 5) {
				r.push_back(m_vertices[i] + pos.x);
				/*if (pos.x == 15)
					std::cout << r[i] << std::endl;*/
				r.push_back(m_vertices[i + 1] + pos.y);
				r.push_back(m_vertices[i + 2] + pos.z);
				r.push_back(m_vertices[i + 3]);
				r.push_back(m_vertices[i + 4]);

				//std::cout << pos.x << ":" << pos.y << ":" << pos.z << std::endl;
			}

			return r;
		}
	private:
		std::vector<float> m_vertices;
	};

	class Faces {
	public:
		void init() {
			front.init(utils::Side::front);
			back.init(utils::Side::back);
			left.init(utils::Side::left);
			right.init(utils::Side::right);
			bottom.init(utils::Side::bottom);
			top.init(utils::Side::top);
		}
		Face* get(utils::Side side) {
			if (side == utils::Side::front)
				return &front;
			else if (side == utils::Side::back)
				return &back;
			else if (side == utils::Side::left)
				return &left;
			else if (side == utils::Side::right)
				return &right;
			else if (side == utils::Side::bottom)
				return &bottom;
			else if (side == utils::Side::top)
				return &top;
		}
	private:
		Face front;
		Face back;
		Face left;
		Face right;
		Face bottom;
		Face top;
	};

	class Block {
	public:
		void init(int x, int y, int z) { init(glm::uvec3(x, y, z)); }
		void init(glm::uvec3 pos);
		Faces* getFaces() { return &m_faces; }
	private:
		glm::uvec3 m_pos;
		Faces m_faces;
	};	
}