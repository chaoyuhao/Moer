/**
 * @file Filter.h
 * @author Zhimin Fan
 * @brief Linear filters
 * @version 0.1
 * @date 2022-05-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "../CoreLayer/Geometry.h"

// ! Note that we cannot use any non-linear "filter" here, such as bilteral and etc

// @brief: Base class for linear filter used for film
class Filter
{
public:
    virtual float eval(const Point2f &pos) = 0;

    // @brief: also known as Kernel Size
    virtual Point2f support() = 0;
};

class BoxFilter : public Filter
{
    // todo
public:
    virtual float eval(const Point2f &pos);
    // @brief: also known as Kernel Size
    virtual Point2f support();
};

class GaussianFilter : public Filter
{
    // todo
public:
    virtual float eval(const Point2f &pos);
    // @brief: also known as Kernel Size
    virtual Point2f support();
};

class SincFilter : public Filter
{
    // todo
public:
    virtual float eval(const Point2f &pos);
    // @brief: also known as Kernel Size
    virtual Point2f support();
};