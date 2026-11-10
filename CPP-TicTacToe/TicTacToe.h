#pragma once

#include "Game.h"

class TicTacToe : public Game
{

public: 

	TicTacToe() {}
	TicTacToe(const TicTacToe&) = delete;
	//Virtual destructor to clean up any resources used by the TicTacToe class.
	virtual ~TicTacToe() {}

	TicTacToe& operator=(const TicTacToe&) = delete;		

	/*Looking at the Game class, you will see that it has three pure virtual functions that you must implement in 
	your TicTacToe class :*/

	bool IsGameOver() const override;

	void TakeTurn() override;

	void Display() const override;		
};
