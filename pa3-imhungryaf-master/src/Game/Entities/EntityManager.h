#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {
private:

	int numOfClients=0;

public:
	Client* firstClient;
	int getNumOfClients(){return numOfClients;}
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;

};