#include "EyeGazeWriter.h"
#include "SRanipal.h"
#include "SRanipal_Eye.h"
#include "SRanipal_Enums.h"
#include <sstream>
#pragma comment (lib, "SRanipal.lib")

void EyeGazeWriter::WriteHeader()
{
	// create header and write it.
	header = "gazeX,gazyY,gazeZ,secondsElapsed\n";
	WriteToDataFile(header);
}

bool EyeGazeWriter::InitializeDataProvider()
{
	// Check if headset allows for eye tracking.
	if (!ViveSR::anipal::Eye::IsViveProEye()) {
		printf("\n\nthis device does not have eye-tracker, please change your HMD\n");
		return false;
	}

	// Conditions based on if eye engine can be initialized.
	int error = ViveSR::anipal::Initial(ViveSR::anipal::Eye::ANIPAL_TYPE_EYE, NULL);
	switch (error)
	{
		case (ViveSR::Error::WORK):
			EnableEye = true;
			printf("Successfully initialize Eye engine.\n");
			return true;

		case (ViveSR::Error::RUNTIME_NOT_FOUND):
			printf("please follows SRanipal SDK guide to install SR_Runtime first\n");
			return false;

		default:
			printf("Fail to initialize Eye engine. please refer the code %d of ViveSR::Error.\n", error);
			return false;
	}
}

void EyeGazeWriter::WriteData()
{
	// collect and write eye gaze data.
	ViveSR::anipal::Eye::EyeData eye_data;
	if (EnableEye) 
	{
		int result = ViveSR::anipal::Eye::GetEyeData(&eye_data);
		if (result == ViveSR::Error::WORK) 
		{
			float* gaze = eye_data.verbose_data.left.gaze_direction_normalized.elem_;

			std::ostringstream data;
			data << gaze[0] << ',' << gaze[1] << ',' << gaze[2] << ',' << getSecondsElapsed() << '\n';
			WriteToDataFile(data.str());
		}
	}
}
