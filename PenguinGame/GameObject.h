#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <vector>
#include <string>
#include "Rect.h"

class Component;

// class that organizes the components
class GameObject
{
public:
	GameObject();
	~GameObject();
	void Start();
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    void NotifyCollision(GameObject& other);
	Component* GetComponent(std::string type);
	Rect box;	// position of GameObject in game

private:
	std::vector<Component*> components;
	bool isDead;
	bool started;
};

#endif // GAME_OBJECT_H