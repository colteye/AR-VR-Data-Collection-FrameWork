#ifndef EYEGAZEWRITER_H_   /* Include guard */
#define EYEGAZEWRITER_H_
#pragma once

#include "DataWriter.h"

class EyeGazeWriter : public DataWriter
{
public:
	void WriteData();
protected:
	void WriteHeader();
	bool InitializeDataProvider();
private:
	bool EnableEye = false;
};

#endif // EYEGAZEWRITER_H_
