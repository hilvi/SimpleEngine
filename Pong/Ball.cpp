#include "Ball.h"
#include <cmath>
#include <cstdlib>

#include <iostream>

const float PI=3.14159265358979f;

Ball::Ball(void)
{
	width = 10;
	height = 10;

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);
	
	m_vertices[0] = sf::Vector2f(0, 0);
	m_vertices[1] = sf::Vector2f(width, 0);
	m_vertices[2] = sf::Vector2f(width, height);
	m_vertices[3] = sf::Vector2f(0, height);

	speed = 200;

	reset(1);
}

void Ball::update(float deltaTime) {
	move(velocity.x*deltaTime, velocity.y*deltaTime);
	if(getPosition().x < 0) {
		//player won
		reset(1);
	}
	if(getPosition().x > 600) {
		//enemy won
		reset(-1);
	}
}

void Ball::onCollision(GameObject *collider)
{
	if(getLastCollision() == collider)
		return;
	if(collider->getName() == "Paddle") {
		paddleCollision(collider->getCenter());
	} else if(collider->getName() == "HWall") {
		velocity.y = -velocity.y;
	}
	setLastCollision(collider);
}

void Ball::paddleCollision(const sf::Vector2f &paddle) {
	sf::Vector2f ball = this->getCenter();
	
	sf::Vector2f distance = ball - paddle;

	float angle = atan2f(distance.y, distance.x);

	velocity.x = cosf(angle)*speed;
	velocity.y = sinf(angle)*speed;
}

void Ball::reset(int direction)
{
	setPosition(300, 200);

	int x = std::rand() % (int)(speed/4) + speed*3/4;
	int y = (int)sqrtf(speed*speed - x*x);

	velocity.x = (float)direction * x;
	direction = std::rand() % 2 == 0 ? -1 : 1;
	velocity.y = (float)direction * y;

	setLastCollision(NULL);
}

Ball::~Ball(void)
{
}
