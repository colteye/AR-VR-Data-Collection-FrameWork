#ifndef DATAWRITER_H_   /* Include guard */
#define DATAWRITER_H_
#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

/*
Struct for each service that provides data to a user.
*/
class DataWriter {
public:
    bool Initialize(std::string fn);
    virtual void WriteData() = 0;
    void Close();
    void Upload();

protected:
    std::string fileName;
    std::string header;

    virtual bool InitializeDataProvider() = 0;
    virtual void WriteHeader() = 0;
    void WriteToDataFile(std::string data);
    float getSecondsElapsed();

private:
    time_t startTime;
    clock_t clockStart;
    std::ofstream dataFile;
    std::string timeDateString(time_t time);
};

#endif // DATAWRITERFUNCTIONS_H_


