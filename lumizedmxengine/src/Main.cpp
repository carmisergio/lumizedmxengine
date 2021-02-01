#include "headers/Includes.h"
#include "Settings.h"

// Variables

double curLightBright[RENDER_CHANNELS];
double fadeDelta[RENDER_CHANNELS];
int fadeTarget[RENDER_CHANNELS];
bool haLightState[RENDER_CHANNELS];
int haLightBright[RENDER_CHANNELS];


int main()
{
	GenerateStatekeepers();

	fadeDelta[0] = 0.5;
	fadeDelta[1] = 1;
	fadeDelta[2] = 2;

	bool run = true;
	while(run)
	{
			PerformCalculations();
			RenderLights();
			LimitFps(fps);
	}
}