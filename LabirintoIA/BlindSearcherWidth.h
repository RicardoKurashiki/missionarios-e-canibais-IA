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
	std::vector<Context> m_contextHistory;
private:
	void removeMovePossibilitie(Context& context, char move);
	char m_lastMovement;
};

