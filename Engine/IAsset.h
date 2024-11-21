#pragma once

class IEditorFileSystem;
class IString;

class IEditorAsset {

	virtual IEditorFileSystem* getEditorFileSystem() = 0;

	virtual unsigned long getFileIndex() = 0;

	virtual const IString* getFilePath() = 0;

	virtual const IString* getFileMetaPath() = 0;


};