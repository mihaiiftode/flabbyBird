#pragma once

#include "Component.hpp"

class BirdGame;

class BirdController : public Component
{
public:
	explicit BirdController(GameObject* gameObject);

	bool onKey(SDL_Event& event) override;

	void onCollisionStart(PhysicsComponent* comp) override;

	void onCollisionEnd(PhysicsComponent* comp) override;

private:
	const float velocityX = 1;
	const float impulseY = 0.1f;
};
