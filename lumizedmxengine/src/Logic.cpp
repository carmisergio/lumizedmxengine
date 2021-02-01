#include "headers/Includes.h"

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

void GenerateStatekeepers()
{
	if(verbose)
        std::cout << "Generating Statekeeper arrays "<< std::endl;
    
    for (int i = 0; i < RENDER_CHANNELS; i++)
    {
        // Only set those which are not at their default value
        fadeTarget[i] = 255;
        haLightBright[i] = 255;
    }
}

void LimitFps(int fps) {
	double frameTime = 1000 / fps;

    // Maintain designated frequency of {fps} Hz ({frameTime}ms per frame)
    a = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> work_time = a - b;

    if (work_time.count() < frameTime)
    {
        std::chrono::duration<double, std::milli> delta_ms(frameTime - work_time.count());
        auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
        std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
    }

    b = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> sleep_time = b - a;

    if (loopverbose)
        printf("Time: %f \n", (work_time + sleep_time).count());
}

void PerformCalculations()
{
	for (int i = 0; i < RENDER_CHANNELS; i++)
	{
		if (fadeDelta[i] != 0)
		{
			if (fadeDelta[i] > 0)
			{
				if (curLightBright[i] < fadeTarget[i])
				{
					curLightBright[i] = curLightBright[i] + fadeDelta[i];
					if (curLightBright[i] > 255)
					{
						curLightBright[i] = 255.0;
					}
				}
				else
				{
					fadeDelta[i] = 0;
					if (verbose)
						std::cout << "Finished Fade on CH" << i + 1 << std::endl;
				}
			}
		}

		if (fadeDelta[i] < 0)
		{
			if (curLightBright[i] > fadeTarget[i])
			{
				curLightBright[i] = curLightBright[i] + fadeDelta[i];
				if (curLightBright[i] < 0)
				{
					curLightBright[i] = 0.0;
				}
			}
			else
			{
				fadeDelta[i] = 0;
				if (verbose)
					std::cout << "Finished Fade on CH" << i + 1 << std::endl;
			}
		}
	}
}
