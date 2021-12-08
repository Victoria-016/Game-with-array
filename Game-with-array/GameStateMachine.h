#pragma once
class GameStateMachine
{
public: 
	virtual ~GameStateMachine() = default;
	virtual bool Init() = 0;
	virtual bool UpdateCurrentState(bool proscessInput = true);
	virtual void DrawCurrentState() = 0;
	virtual void CleanUp();
};

