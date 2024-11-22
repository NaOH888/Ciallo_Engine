#pragma once
#include "IContainer.h"
 class IContext;
class ISystem {

public:

	virtual void initialize() = 0;

	virtual void setLogCallback(void(*)(const char*)) = 0;

	virtual ~ISystem() {}

};

class IFrameUpdateSystem : public ISystem {

public:

	virtual void start(IContext*) = 0;

	virtual void update(IContext*) = 0;

};

class IPassiveSystem : public ISystem {



};

class IGameMemoryAllocator : public IPassiveSystem {
/// IGameMemoryAllocator
/// 
///		[1] Single_Frame_Allocator 
///		[2] 64B Pool Allocator
///		[3] 1kB Pool Allocator
/// 	[4] 64kB Pool Allocator
/// 	[5] 1mB Pool Allocator
/// 	[6] 64mB Pool Allocator
/// 	[7] Large Memory Allocator
public:

	virtual void getCommon(void** buffer, unsigned long long size) const = 0;

	virtual bool retCommon(void* buf) const = 0;

	/// virtual void getFrameStack(void** buffer, unsigned long long size) const = 0;
	/// 该具体怎么设置帧栈的内存分配？
	

	virtual bool memcpy(void* origin, void* des, unsigned long long size) const = 0;

};
 class IString;
class IStringInternManager : public IPassiveSystem {

public:

	virtual int internString(const wchar_t*) = 0;

	virtual int internString(const IString*) = 0;

	virtual const wchar_t* get(int) = 0;

};

 class IAsset;

class IEditorFileSystem : public IPassiveSystem{

public:

	

	virtual const IString* getProjectPath() = 0;

	virtual void updateFiles() = 0;

	virtual unsigned long copyFileToSystem(IString*) = 0;

	/// IEditorFileSystem也是用树结构对文件进行管理的
	virtual void load(ITreeLift<IAsset*>&&, void* buffer) = 0;

	virtual void getRoot(const ITreeLift<IAsset*>**) = 0;

};

 class IEditorUIWidget;
//我是史学家，这就是史👇👇👇👇
class IEditorUIWidgetManager : public IPassiveSystem {

public:

	//一般从这里获取UI树之后给IEditorUIWidgetRenderSystem画
	//当执行错误时，返回的ITreeIterator中的IEditorUIWidget* = nullptr

	/// 
	/// 反正使用方法如下：
	/// 首先，通过find(IEditorUIWidget*)函数获取这个widget在这个系统中的位置
	/// 然后根据需要进行操作，比如需要添加子组件，删除组件等等
	/// 要注意，IEditorUIWidget中setParent的函数不要随便乱用，要不然会出现大问题，特别是在find函数中
	/// 交给IEditorUIWidgetManager就行，只是还没找到一个合适的方法，要不然设置成友元？但又耦合上了

	virtual void getUIRoot(const ITreeLift<IEditorUIWidget*>**) = 0;

	virtual bool contains(IEditorUIWidget*) = 0;

	virtual void find(IEditorUIWidget*, ITreeLift<IEditorUIWidget*>**) = 0;

	IEditorUIWidgetManager(ITree<IEditorUIWidget*>&& widgets){}

	IEditorUIWidgetManager(IEditorUIWidget* root){}

	virtual void addWidget(
		IEditorUIWidget* widget,
		ITreeLift<IEditorUIWidget*> parent,
		ITreeLift<IEditorUIWidget*>** ret
	) = 0;

	virtual void deleteWidget(ITreeLift<IEditorUIWidget*>) = 0;

	virtual void findSameParent(IEditorUIWidget*, IEditorUIWidget*, ITreeLift<IEditorUIWidget*>** ret) = 0;

	virtual void updateDirty() = 0;

	virtual void graft(IEditorUIWidgetManager* kid, ITreeLift<IEditorUIWidget*>&& parent) = 0;


};

 class IGraphics;

class IEditorUIWidgetRenderSystem : public IFrameUpdateSystem {

public:

	virtual void paint(IGraphics*, IIterator<IEditorUIWidget*>&&) = 0;

};