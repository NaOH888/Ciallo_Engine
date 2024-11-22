#pragma once

class IEditorFileSystem;
class IString;
template <typename T> class IIterator;

class IEditorAsset {

	virtual IEditorFileSystem* getEditorFileSystem() = 0;

	virtual unsigned long getFileIndex() = 0;

	virtual const IString* getFilePath() = 0;

	virtual const IString* getFileMetaPath() = 0;

	//要用这种方式进行遍历吗？
	virtual IIterator<IEditorAsset> getReferenceStart() = 0;

	virtual IIterator<IEditorAsset> getReferenceEnd() = 0;
};