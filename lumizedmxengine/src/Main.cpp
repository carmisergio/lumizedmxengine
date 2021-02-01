#include "headers/Includes.h"

// Variables
int curLightBright[100];
int fadeDelta[100];
int fadeTarget[100];
int haLightState[100];
int haLightBright[100];

int main()
{
	GenerateStatekeepers(15);
	
	for (int i = 0; i < 1000; i++)
	{
		RenderLights();
	}
}