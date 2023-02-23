/**
 * @file StarshipCheck.cpp
 * @author timan
 */

#include "pch.h"
#include "StarshipCheck.h"
#include "TileStarshipPad.h"

/** Visit a TileStarshipPad object
* @param pad starshipPad tile we are visiting
**/
void StarshipCheck::VisitStarshipPad(TileStarshipPad *pad)
{
	mIsStarship = true;
	mStarshipPad = pad;
}