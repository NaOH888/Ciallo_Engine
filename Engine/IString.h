#pragma once

class IString {

public:

	virtual const wchar_t* data() = 0;

	virtual void operator=(const wchar_t*) = 0;

	virtual void operator=(const char*) = 0;

	virtual void operator=(const IString*) = 0;

	virtual void operator=(int) = 0;

	virtual void operator=(double) = 0;

	virtual void operator=(float) = 0;

	virtual void operator=(long) = 0;

	virtual bool operator==(const wchar_t*) = 0;

	virtual bool operator==(const char*) = 0;

	virtual bool operator==(const IString*) = 0;

};