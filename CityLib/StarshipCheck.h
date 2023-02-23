/**
 * @file StarshipCheck.h
 * @author timan
 *
 * A class that handles visiting a starship pad tile
 */

#ifndef CITY_CITYLIB_STARSHIPCHECK_H
#define CITY_CITYLIB_STARSHIPCHECK_H
#include "TileVisitor.h"
#include "TileStarshipPad.h"

/**
 * a visitor class that determines if a tile is a starship pad
 * subclass of tile visitor
 */
class StarshipCheck : public TileVisitor
{
public:

	virtual void VisitStarshipPad(TileStarshipPad *pad) override;

	/**
	 * A function that checks if the pad is a StarshipPad
	 * @return a boolean
	 */
	bool IsStarshipPad() {return mIsStarship;}

	/**
	 * A getter for the StarshipPad member
	 * @return a pointer to a TileStarshipPad object
	 */
	TileStarshipPad* GetStarshipPad() {return mStarshipPad;}


private:
	/// a boolean determining if the Tile is a StarshipTile
	bool mIsStarship = false;

	/// a pointer to a TileStarshipPad object
	TileStarshipPad* mStarshipPad;

};

#endif //CITY_CITYLIB_STARSHIPCHECK_H
