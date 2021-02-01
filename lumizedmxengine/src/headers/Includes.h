#pragma once

// Defines
#define RENDER_CHANNELS 100

// External modules
#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>
#include <array>

// Local includes
#include "Lights.h"
#include "Logic.h"
#include "Mqtt.h"

// Global Variables
extern bool verbose;
extern bool loopverbose;
extern double curLightBright[RENDER_CHANNELS];
extern double fadeDelta[RENDER_CHANNELS];
extern int fadeTarget[RENDER_CHANNELS];
extern bool haLightState[RENDER_CHANNELS];
extern int haLightBright[RENDER_CHANNELS];