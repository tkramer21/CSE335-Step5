/**
 * @file EmptyTileVisitor.cpp
 * @author timan
 */
#include "pch.h"
#include "EmptyTileVisitor.h"
#include "TileStarshipPad.h"

void EmptyTileVisitor::VisitStarshipPad(TileStarshipPad* pad)
{
	if(pad->GetStarship() == nullptr)
	{
		mStarshipPad = pad;
		mEmpty = true;
	}
	else if(!mEmpty && !mStarshipPad)
	{
		mStarshipPad = pad;
	}
}
