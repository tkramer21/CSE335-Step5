/**
 * @file TileStarshipPad.h
 *
 * @author Charles B. Owen
 *
 * Class that implements a Starship pad.
 */

#pragma once

#include "Tile.h"
#include "Starship.h"

/**
 * Class that implements a Starship pad.
 * 
 * This is where Starships take off and land.
*/
class TileStarshipPad : public Tile
{
private:
	/// A shared_ptr to the starship object
	std::shared_ptr<Starship> mStarship;

public:
    explicit TileStarshipPad(City* city);

    ///  Default constructor (disabled)
    TileStarshipPad() = delete;

    ///  Copy constructor (disabled)
    TileStarshipPad(const TileStarshipPad&) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;

	void Draw(wxDC* dc) override;
	void Update(double elapsed) override;


	void Report(std::shared_ptr<MemberReport> report) override;

    bool PendingDelete() override;

    void StarshipIsGone();
    void StarshipHasLanded();

	/**
	 * Getter for tile-associated starship
	 * @return a shared ptr of type Starship
	 */
	std::shared_ptr<Starship> GetStarship(){return mStarship;}

	/**
	 * A setter for the starship object
	 * @param ship a shared_ptr to the starship object
	 */
	void SetStarship(std::shared_ptr<Starship> ship) {mStarship = ship;}

	/**
	 * Accept a visitor
 	* @param visitor The visitor we accept
 	*/
	void Accept(TileVisitor* visitor) override { visitor->VisitStarshipPad(this); }
};

