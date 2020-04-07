#include "DataWriter.h"

void DataWriter::WriteToDataFile(std::string data)
{
	if (dataFile.is_open()) dataFile << data;
}

bool DataWriter::Initialize(std::string fn)
{
	if (InitializeDataProvider())
	{
		fileName = fn;
		dataFile.open(fn, std::ofstream::out);
		WriteHeader();
		return true;
	}
	else return false;
}

void DataWriter::Close()
{
	if (dataFile.is_open()) dataFile.close();
}

void DataWriter::Upload()
{

}
