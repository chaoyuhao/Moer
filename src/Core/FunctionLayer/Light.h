/**
 * @file Intersection.h
 * @author orbitchen
 * @brief Light representation.
 * @version 0.1
 * @date 2022-04-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "../CoreLayer/Geometry.h"
#include "../CoreLayer/Color.h"
#include "Ray.h"

struct LightSampleResult
{
	// @brief Spectrum from light.
	Spectrum s;

	// @brief Point on an object where receives light.
	Point3f src;

	// @brief Point on a light where emits light.
	Point3f dst;

	Normal3f dstNormal;

	double pdf;

	Point2f uv;
};

class Light
{
public:
	
	LightSampleResult sampleAll(const Ray& r) const = 0;
};