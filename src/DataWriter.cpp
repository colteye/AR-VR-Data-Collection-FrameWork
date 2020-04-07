#include "DataWriter.h"

void DataWriter::WriteToDataFile(std::string data)
{
	if (dataFile.is_open()) dataFile << data;
}

float DataWriter::getSecondsElapsed()
{
	return ((float)(clock() - clockStart)) / CLOCKS_PER_SEC;
}

std::string DataWriter::timeDateString(time_t time)
{
	struct tm curr_tm;

	// Make sure that C++11 compliant if using unix/linux.
	#ifdef _WIN32
		if (localtime_s(&curr_tm, &time)) return "invalid date";
	#else
		if (localtime_s(&time, &curr_tm)) return "invalid date";
	#endif

	// Create date and time string, and return.
	char dateTime_string[100];
	strftime(dateTime_string, 100, "%B-%d-%Y-%T\n", &curr_tm);

	return std::string(dateTime_string);
}

bool DataWriter::Initialize(std::string fn)
{
	// make sure data provide is successfully initialized.
	if (InitializeDataProvider())
	{
		// initialize file and open.
		fileName = fn;
		dataFile.open(fn, std::ofstream::out);

		// init start time.
		time(&startTime);
		clockStart = clock();

		// write time to data file in readable format.
		WriteToDataFile(timeDateString(startTime));

		// write header.
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
