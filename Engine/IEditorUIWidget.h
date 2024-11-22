#pragma once

#include "Vector.h"
#include "GColor.h"
 class IGraphics;
 class IString;
 class IContext;


class IEditorUIWidget {

public:

	virtual Vector2 getAbsolutePosition() = 0;

	virtual Vector2 getRelativePosition() = 0;

	virtual void setAbsolutePosition(Vector2&&) = 0;

	virtual void setRelativePosition(Vector2&&) = 0;

	virtual bool isDirty() = 0;

	virtual void setDirty(bool) = 0;

	virtual void onMouseIn(int x, int y, IContext*) = 0;

	virtual void onMouseOut(int x, int y, IContext*) = 0;

	virtual void onMouseDown(int x, int y, IContext*) = 0;

	virtual void onMouseUp(int x, int y, IContext*) = 0;

	virtual void onMouseClick(int x, int y, IContext*) = 0;

	virtual void setEnable(bool) = 0;

	virtual bool getEnable() = 0;

	virtual void setVisibility(bool) = 0;

	virtual bool getVisibility() = 0;

	virtual IEditorUIWidget* getParent() = 0;

	virtual void setParent(IEditorUIWidget*) = 0;
	//请在IEditorUIWidgetManager中添加或删除Kid，执行这样的操作之后就会调用父节点的onKidAdd或onKidDelete
	virtual void onKidAdd(const IEditorUIWidget*) = 0;

	virtual void onKidDelete(const IEditorUIWidget*) = 0;

	virtual Vector4 getAABB() = 0;

};

class IEditorLayoutablePanel : public IEditorUIWidget {

public:



};

class IEditorButton : public IEditorUIWidget{

public:

	virtual void setSize(Vector2&&) = 0;

	virtual Vector2 getSize() const = 0;

	virtual void setText(const IString*) = 0;

	virtual const IString* getText() const = 0;

	virtual struct GColor getBackgroundColor() const = 0;

	virtual void setBackgroundColor(const struct GColor&&) = 0;

	virtual struct GColor getForegroundColor() const = 0;

	virtual void setForegroundColor(const struct GColor&&) = 0;



};