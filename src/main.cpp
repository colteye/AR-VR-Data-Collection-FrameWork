#include "EyeGazeWriter.h"
#include "HeadPoseWriter.h"
#include <time.h> //for delay

void delay(int milliseconds)
{
	long pause;
	clock_t now, then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	now = then = clock();
	while ((now - then) < pause)
		now = clock();
}

int main() {
	EyeGazeWriter eyeWriter;
	HeadPoseWriter headWriter;

	if (headWriter.Initialize("head_data.csv"))
	{
		printf("starting data collection");
		for (int i = 0; i < 100; ++i) {
			headWriter.WriteData();
			delay(100);
		}


		printf("closing data writer");
		headWriter.Close();
	}
	else printf("could not be initialized!");

	printf("done");
	while (true); // infinite loop to pause.
}