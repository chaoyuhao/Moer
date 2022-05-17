/**
 * @file BxDF.h
 * @author orbitchen
 * @brief BxDF, including BRDF and BTDF.
 * @version 0.1
 * @date 2022-04-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "../CoreLayer/Color.h"
#include "../CoreLayer/Geometry.h"

struct BxDFSampleResult
{
	Spectrum s;
	Vec3d directionIn;
	double pdf;
	bool isSpecular;
};

// @brief BxDF. out == rays from/to camera, in == rays from/to objects/lights.
class BxDF
{

public:
	virtual Spectrum f(const Vec3d &out, const Vec3d &in) const = 0;

	virtual Vec3d sampleWi(const Vec3d &out) const = 0;

	virtual double pdf(const Vec3d &out, const Vec3d &in) const = 0;

	virtual BxDFSampleResult sample(const Vec3d &out) const = 0;

	virtual bool isSpecular() const = 0;
};