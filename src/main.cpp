#include "EyeGazeWriter.h"
#include "HeadPoseWriter.h"

int main() {
	EyeGazeWriter eyeWriter;
	HeadPoseWriter headWriter;

	/*if (eyeWriter.Initialize("eye_data.csv"))
	{
		for (int i = 0; i < 100; ++i) eyeWriter.WriteData();
		eyeWriter.Close();
	}*/

	if (headWriter.Initialize("head_data.csv"))
	{
		for (int i = 0; i < 1000; ++i) headWriter.WriteData();
		headWriter.Close();
	}
	else printf("not initialized!");
}