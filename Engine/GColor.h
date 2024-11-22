#pragma once
struct GColor {

	char R, G, B;
	float A;

	

};

static const GColor WHITE{ 255, 255, 255, 1.0f };
static const GColor BLACK{ 0, 0, 0, 1.0f };
static const GColor RED{ 255, 0, 0, 1.0f };
static const GColor Blue{ 0, 0, 255, 1.0f };
static const GColor Green{ 0, 255, 0, 1.0f };