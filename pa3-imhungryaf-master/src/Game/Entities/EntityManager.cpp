#include "EntityManager.h"

void EntityManager::tick()
{
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        entities[i]->tick();
    }
    if (firstClient != nullptr)
    {
        firstClient->tick();
    }
    removeLeavingClients();
}

void EntityManager::removeLeavingClients()
{
    Client *tempClient = nullptr;

    while (firstClient != nullptr && firstClient->isLeaving && firstClient->beenServed==false)
    {
        if (firstClient->getPatience() == 0)
        {
            numOfClients++;
        }
        tempClient = firstClient->nextClient;
        delete firstClient;
    
        firstClient = tempClient;
    }
}
void EntityManager::render()
{
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        entities[i]->render();
    }
    if (firstClient != nullptr)
    {
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e)
{
    entities.push_back(e);
}

void EntityManager::addClient(Client *c)
{
    if (firstClient == nullptr)
    {
        firstClient = c;
    }
    else
    {
        Client *tempClient = firstClient;
        tempClient->setY(tempClient->getY() + 72);
        while (tempClient->nextClient != nullptr)
        {
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY() + 72);
        }
        tempClient->nextClient = c;
    }
}
