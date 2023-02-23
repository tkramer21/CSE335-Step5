/**
 * @file HasStarship.cpp
 * @author timan
 */

#include "pch.h"
#include "HasStarship.h"
#include "TileStarshipPad.h"

/**
* Visit a TileStarshipPad object
* @param pad starshipPad tile we are visiting
*
**/
void HasStarship::VisitStarshipPad(TileStarshipPad *pad)
{
	if(pad->GetStarship() != nullptr)
	{
		mStarship = pad->GetStarship();
		mStarshipTile = pad;
	}
}