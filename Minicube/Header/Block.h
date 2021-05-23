#pragma once
#include <Glm/glm.hpp>

#include "Utils.h"
#include "Textures.h"

namespace mc {

	class Face {
	public:
		void init(utils::Side side, unsigned int textureID) {
			m_textureID = textureID;

			if (side == utils::Side::front)
				m_vertices = &vertices::cube::front;
			else if (side == utils::Side::back)
				m_vertices = &vertices::cube::back;
			else if (side == utils::Side::left)
				m_vertices = &vertices::cube::left;
			else if (side == utils::Side::right)
				m_vertices = &vertices::cube::right;
			else if (side == utils::Side::bottom)
				m_vertices = &vertices::cube::bottom;
			else if (side == utils::Side::top)
				m_vertices = &vertices::cube::top;
		}
		std::vector<float>* getVertices() { return m_vertices; }
		std::vector<float>* getChunkVertices(const glm::uvec3& pos) {
			std::vector<float>* r = new std::vector<float>;

			for (unsigned int i = 0; i < m_vertices->size(); i += 5) {
				r->push_back(m_vertices->at(i) + pos.x);
				/*if (pos.x == 15)
					std::cout << r[i] << std::endl;*/
				r->push_back(m_vertices->at(i + 1) + pos.y);
				r->push_back(m_vertices->at(i + 2) + pos.z);
				r->push_back(m_vertices->at(i + 3));
				r->push_back(m_vertices->at(i + 4));
				r->push_back(m_textureID);

				/*if (m_textureID == 1)
					assert(false);*/

				//std::cout << pos.x << ":" << pos.y << ":" << pos.z << std::endl;
			}

			return r;
		}
	private:
		std::vector<float>* m_vertices;
		unsigned int m_textureID;
	};

	class Faces {
	public:
		void init(const std::string& name) {
			front.init(utils::Side::front, Textures::getTextureNumber(name));
			back.init(utils::Side::back, Textures::getTextureNumber(name));
			left.init(utils::Side::left, Textures::getTextureNumber(name));
			right.init(utils::Side::right, Textures::getTextureNumber(name));
			bottom.init(utils::Side::bottom, Textures::getTextureNumber(name));
			top.init(utils::Side::top, Textures::getTextureNumber(name));
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
		virtual void init(const glm::uvec3& pos);
		Faces* getFaces() { return &m_faces; }
	protected:
		void setName(const std::string& name) { m_name = name; }

	private:
		glm::uvec3 m_pos;
		Faces m_faces;
		std::string m_name;
	};	
}