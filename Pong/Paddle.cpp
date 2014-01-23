#include "Paddle.h"


Paddle::Paddle(void)
{
	width = 10;
	height = 30;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);
	
	m_vertices[0] = sf::Vector2f(0, 0);
	m_vertices[1] = sf::Vector2f(width, 0);
	m_vertices[2] = sf::Vector2f(width, height);
	m_vertices[3] = sf::Vector2f(0, height);

	speed = 200;
}

void Paddle::update(float deltaTime) {
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		move(0, -speed*deltaTime);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		move(0, speed*deltaTime);
	}
}

Paddle::~Paddle(void)
{
}
