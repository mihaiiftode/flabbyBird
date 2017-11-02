//
// Created by Morten Nobel-Jørgensen on 19/10/2017.
//

#include <SDL_events.h>
#include <iostream>
#include "BirdController.hpp"
#include "GameObject.hpp"
#include "SpriteComponent.hpp"
#include "PhysicsComponent.hpp"
#include "SpriteComponent.hpp"
#include "BirdGame.hpp"

BirdController::BirdController(GameObject* gameObject) : Component(gameObject)
{
	auto phys = gameObject->getComponent<PhysicsComponent>();
	phys->setLinearVelocity({velocityX, 0});
	// initiate bird physics
}

bool BirdController::onKey(SDL_Event& event)
{
	if (event.key.keysym.sym != SDLK_SPACE) return false;
	auto phys = gameObject->getComponent<PhysicsComponent>();
	if (event.type == SDL_KEYDOWN)
	{
		phys->addImpulse({0, impulseY});
	}
	else if (event.type == SDL_KEYUP)
	{
	}
	return false;
}

void BirdController::onCollisionStart(PhysicsComponent* comp)
{
	if (comp->getGameObject()->name == "Wall bottom" || comp->getGameObject()->name == "Wall top")
	{
		BirdGame::instance->setGameState(GameState::GameOver);
	}
}

void BirdController::onCollisionEnd(PhysicsComponent* comp)
{
}
