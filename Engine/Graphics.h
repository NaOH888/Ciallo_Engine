#pragma once
#include "Vector.h"

class IGraphics;

#include "GColor.h"

class IGBrush {

public:

	virtual float getOpacity() = 0;

	virtual void setOpacity(float) = 0;

	virtual IGraphics* getGContext() = 0;

};

class IGSolidColorBrush : public IGBrush{

public:

	virtual GColor getColor() = 0;

	virtual void setColor() = 0;

};

class IGraphics {

public:

	virtual void drawRect(
		Vector2&& coord1, 
		Vector2&& coord2,
		int thickness,
		float relative,
		IGBrush* brush
	) = 0;

	virtual void fillRect(
		Vector2&& coord1,
		Vector2&& coord2,
		IGBrush* brush
	) = 0;

	virtual void drawCircle(
		Vector2&& coord,
		int radius,
		int thickness,
		float relative,
		IGBrush* brush) = 0;

};