/**
 * @file TileStarshipPad.cpp
 *
 * @author Charles B. Owen
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "City.h"
#include "TileStarshipPad.h"
#include "MemberReport.h"
#include "City.h"
#include "Starship.h"
#include "StarshipCheck.h"
#include "HasStarship.h"
#include "EmptyTileVisitor.h"


/// The image to display for the starship pad
const std::wstring StarshipPadImage = L"pad.png";


/** Constructor
* @param city The city this is a member of
*/
TileStarshipPad::TileStarshipPad(City* city) : Tile(city)
{
	HasStarship visitor;

	// create a visitor that checks if any other Starships exist in the city
	city->Accept(&visitor);

	if(visitor.GetStarship() == nullptr)
	{
		std::shared_ptr<Starship> ship = std::make_shared<Starship>(city);
		ship->SetLaunchingPad(this);
		mStarship = ship;
	}
	SetImage(StarshipPadImage);

}


/**  Save this item to an XML node
* @param node The node we are going to be a child of
* @return Allocated node
*/
wxXmlNode* TileStarshipPad::XmlSave(wxXmlNode* node)
{
    auto itemNode = Tile::XmlSave(node);

    itemNode->AddAttribute(L"type", L"starship-pad");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void TileStarshipPad::Report(std::shared_ptr<MemberReport> report)
{
    std::wstringstream str;
    str << L"Starship Pad";

    report->SetReport(str.str());
}

/**
 * Indicate that this object is about to be deleted by
 * begin dragged into the trash can. If the function
 * override returns false, the delete will not occur.
 * @return true if okay to delete.
*/
bool TileStarshipPad::PendingDelete()
{
	if(this->mStarship != nullptr){
		EmptyTileVisitor visitor;
		this->GetCity()->Accept(&visitor);

		if(visitor.IsEmpty())
		{
			HasStarship shipVisitor;
			this->GetCity()->Accept(&shipVisitor);

			visitor.GetStarshipPad()->mStarship = shipVisitor.GetStarship();
			visitor.GetStarshipPad()->mStarship->SetLaunchingPad(visitor.GetStarshipPad());
			shipVisitor.GetStarshipTile()->mStarship = nullptr;
		}
		else
		{
			StarshipCheck tileVisitor;
			this->Accept(&tileVisitor);

			this->mStarship->SetLaunchingPad(visitor.GetStarshipPad());

		}
	}
    return true;
}

/**
 * This function is called when the Starship has
 * landed on some other pad. It is no longer accessible to
 * this pad.
*/
void TileStarshipPad::StarshipIsGone()
{
	if(this->mStarship)
	{
		this->mStarship = nullptr;
	}
}

/**
 * This function is called when the Starship has landed on this
 * pad. This pad should now become the launching pad.
*/
void TileStarshipPad::StarshipHasLanded()
{
	HasStarship visitor;
	this->GetCity()->Accept(&visitor);

	visitor.GetStarship()->SetLaunchingPad(this);
}

/**
 * Draws the TileStarshipPad on the City view
 * will also call draw function if Starship is associated
 * @param dc Device context to draw the tile on
 */
void TileStarshipPad::Draw(wxDC* dc)
{
	Tile::Draw(dc);
	StarshipCheck tileVisitor;
	this->Accept(&tileVisitor);
	if(tileVisitor.IsStarshipPad())
	{
		HasStarship shipVisitor;
		this->Accept(&shipVisitor);
		if(shipVisitor.GetStarship() != nullptr)
		{
			mStarship->Draw(this, dc);
		}
	}
}

/**
 * A function that updates the TileStarshipPad
 * will call the update function for Starship object if associated
 * @param elapsed double containing time since last update
 */
void TileStarshipPad::Update(double elapsed)
{
	if(mStarship != nullptr)
	{
		mStarship->Update(this, elapsed);
	}
}

