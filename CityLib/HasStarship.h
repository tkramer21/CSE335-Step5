/**
 * @file HasStarship.h
 * @author timan
 *
 * A visitor class that retrieves the starship of the tile
 */

#ifndef CITY_CITYLIB_HASSTARSHIP_H
#define CITY_CITYLIB_HASSTARSHIP_H

#include "TileVisitor.h"
#include "Starship.h"

/**
 * A visitor class that determines whether a tile has
 * a starship object associated with it
 */
class HasStarship : public TileVisitor
{
public:
	void VisitStarshipPad(TileStarshipPad *pad);

	/**
	 * Getter to return the member mStarship
	 * @return a shared_ptr to a Starship object
	 */
	std::shared_ptr<Starship> GetStarship() {return mStarship;}

	/**
	 * A getter for a TileStarship object
	 * @return a TileStarshipPad pointer
	 */
	TileStarshipPad* GetStarshipTile() {return mStarshipTile;}

private:
	/// a shared_ptr holding a Starship object
	std::shared_ptr<Starship> mStarship;

	/// a pointer to a TileStarshipPad object
	TileStarshipPad* mStarshipTile;

};

#endif //CITY_CITYLIB_HASSTARSHIP_H
