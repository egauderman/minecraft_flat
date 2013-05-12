// Copyright (C) 2013 Eric Gauderman



#include "steve.h"
#include "mainwindow.h"
#include "gamespace.h" // for use of parent pointer



/** Constructor. Calls Thing constructor, and initializes values for motion
* @param picture The picture for this to display
* @param parent Pointer to the GameSpace that holds this item.
*/
Steve::Steve(QPixmap& picture, GameSpace* parent)
:
	Thing(picture, parent, NULL) // pass NULL as the player pointer to Thing because this is the player
{
	health_ = 10;
	moveToX_ = parent->width()/2;
	moveToY_ = parent->height()/2;
	setZValue(1);
	speedLimit_ = .2; // note: this does not directly correspond with enemies' speed because the player's move function is called more frequently than the enemies.
	invincible_ = 0; // starts out not invincible
}

/** Called every clock pulse.  Player moves toward the cursor with a limited speed; player slows down when close to pointer.
* @param windowMaxX Sets the maximum x-position of the player
* @param windowMaxY Sets the maximum y-position of the player
*/
void Steve::updatePrecisePos(const int& windowMaxX, const int& windowMaxY)
{
	// Find the difference between the player's position and the desired position
	double deltaX = (moveToX_ - x()),
	       deltaY = (moveToY_ - y());
	
	// Set the radius to move
	double r = std::sqrt(deltaX*deltaX + deltaY*deltaY)/160;
	
	// Set the angle theta at which the player will move for this frame
	double th;
	if(deltaX == 0) {th = PI/2;} // make sure we don't divide by zero
	else {th = std::atan(deltaY/deltaX);}
	// Check whether or not to move in the opposite direction (because atan() only works from -PI to PI)
	if(deltaX < 0) th += PI;
	
	// Move the player by r if it is less than the speed limit and 
	if(r > speedLimit_) r = speedLimit_;
	xPrecise_ += r * std::cos(th);
	yPrecise_ += r * std::sin(th);
	
	// Make sure player does not go offscreen (no bounce)
	checkEdgesSlide(windowMaxX, windowMaxY);
}

/** Sets the player's target coordinates to move to (player does not move instantly to this position)
* @param x The x-position for the player to move to
* @param y The y-position for the player to move to
*/
void Steve::moveTo(double x, double y)
{ moveToX_ = x; moveToY_ = y; }

/** Changes the player's health by the passed-in amount
* @param delta The change in the player's health to be applied
*/
void Steve::changeHealth(int delta)
{
	health_ += delta;
	parent()->parent()->healthUI->setNum(health_);
	if(health_ <= 0) parent()->parent()->gameOver();
}
