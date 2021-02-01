#include "headers/Includes.h"

void RenderLights()
{
	ComputeInts();
	std::string jsonData = GenerateJson();
	
	std::cout << jsonData << std::endl;

	if(loopverbose)
		std::cout << "Rendering light frame." << std::endl;
}

std::string GenerateJson() {
	std::string jsonData = "{\"data\": [";

	for (int i = 0; i < RENDER_CHANNELS; i++)
	{
		jsonData.append(std::to_string(ints[i]));
	}
	return jsonData;
}

void ComputeInts()
{
	//int returnArray[RENDER_CHANNELS];

	for (int i = 0; i < RENDER_CHANNELS; i++)
	{
		double x = curLightBright[i];
		x = x + 0.5 - (x < 0);
		ints[i] = (int)x;
	}
}