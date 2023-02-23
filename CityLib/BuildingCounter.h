/**
 * @file BuildingCounter.h
 * @author timan
 *
 *A class that handles counting # of buildings
 * derived from TileVisitor
 */

#ifndef CITY_CITYLIB_BUILDINGCOUNTER_H
#define CITY_CITYLIB_BUILDINGCOUNTER_H

#include "TileVisitor.h"

/**
 * A class that gets the count for the number of buildings
 * subclass of TileVisitor
 */
class BuildingCounter : public TileVisitor
{
private:
	/// Buildings counter
	int mNumBuildings = 0;

public:
	/**
	 * Get the number of buildings
	 * @return Number of buildings
	 */
	int GetNumBuildings() const { return mNumBuildings; }

	/**
 	* Visit a TileBuilding object
 	* @param building Building we are visiting
 	*/
	void VisitBuilding(TileBuilding* building)
	{
		mNumBuildings++;
	}


};

#endif //CITY_CITYLIB_BUILDINGCOUNTER_H
