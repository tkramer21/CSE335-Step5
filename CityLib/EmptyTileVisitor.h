/**
 * @file EmptyTileVisitor.h
 * @author timan
 *
 *
 */

#ifndef CITY_CITYLIB_EMPTYTILEVISITOR_H
#define CITY_CITYLIB_EMPTYTILEVISITOR_H
#include "TileVisitor.h"

/**
 * A visitor class that finds a starship pad
 * that doesn't have a starship associated with it
 */
class EmptyTileVisitor : public TileVisitor
{
public:

	/**
	 *  function that visits the a TileStarshipPad and sets the class members
	 * @param pad a TileStarship Pad pointer
	 */
	void VisitStarshipPad(TileStarshipPad* pad) override;

	/**
	 * 	 Getter for the TileStarshipPad member
	 * @return a TileStarshipPad pointer
	 */
	TileStarshipPad* GetStarshipPad(){return mStarshipPad;}

	/**
	 *  function that determines if the Pad has a starship
	 * @return a boolean
	 */
	bool IsEmpty(){return mEmpty;}

private:
	/// a TileStarshipPad pointer that tracks atile
	TileStarshipPad* mStarshipPad = nullptr;

	/// a boolean tracking if the tile has a starship
	bool mEmpty = false;

};

#endif //CITY_CITYLIB_EMPTYTILEVISITOR_H
