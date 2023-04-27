#include "GameObject.h"
#include "Component.h"
#include <iterator>

GameObject::GameObject() : isDead(false) {}

GameObject::~GameObject() {
	std::vector<Component*>::reverse_iterator it;
	for (it = components.rbegin(); it != components.rend(); it++) {
		delete *it;
	}
	components.clear();
}

void GameObject::Update(float dt) {
	for (auto it = components.begin(); it != components.end(); it++) {
		(*it)->Update(dt);
	}
}

void GameObject::Render() {
	for (auto it = components.begin(); it != components.end(); it++) {
		(*it)->Render();
	}
}

bool GameObject::IsDead() {
	return isDead;
}

void GameObject::RequestDelete() {
	isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
	components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
	components.erase(std::remove(components.begin(), components.end(), cpt), components.end());
}

Component* GameObject::GetComponent(std::string type) {
	for (auto it = components.begin(); it != components.end(); it++) {
		if ((*it)->Is(type)) {
			return *it;
		}
	}
	return nullptr;
}