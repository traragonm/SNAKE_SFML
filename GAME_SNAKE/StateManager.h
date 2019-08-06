#pragma once
#include<stack>
#include"State.h"
class StateManager
{
public:
	StateManager();
	~StateManager();
	void AddState(GState s);
	GState& GetCurrState();
	void RemoveState();
	void ClearStack();
private:
	std::stack<GState> _States;
	
};

