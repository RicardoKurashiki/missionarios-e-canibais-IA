#pragma once

#include "Searcher.h"
#include "vector"

class BlindSearcherWidth : public Searcher
{
public:
	BlindSearcherWidth();
	void receiveContext(Context recContext);
	Coordinate makeMovement();
	void handle();
private:
	void removeMovePossibilitie(Context& context, char move);
	std::vector<Context> m_contextHistory;
	char m_lastMovement;
};

