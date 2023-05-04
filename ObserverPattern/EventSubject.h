#pragma once
#include <list>
#include "IEventListener.h"

class EventSubject
{
public:
	void AddListener(IEventListener* listener)
	{
		listeners.push_back(listener);
	}
	void RemoveListener(IEventListener* listener)
	{
		listeners.remove(listener);
	}
protected:
	void NotifyListeners()
	{
		for (auto listener : listeners)
		{
			listener->HandleEvent();
		}
	}

private:
	std::list<IEventListener*> listeners;
};

