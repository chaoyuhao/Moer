/**
 * @file PathIntegrator.h
 * @author Zhimin Fan
 * @brief Path Integrator
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <cmath>
#include "AbstractPathIntegrator.h"
#include "../Core/FunctionLayer/Ray.h"

class PathIntegrator : public AbstractPathIntegrator
{
protected:
    const int nPathLengthLimit = 20;
    const double pRussianRoulette = 0.95;
public:
    // todo: constructor

    // @brief Return the radiance along given ray, emitted from given intersection.
    // @param scene     Ptr to scene.
    // @param its       Intersection hit by ray.
    // @param ray       Ray to evaluate.
    // @return          Direction of given ray, incident radiance at origin of ray, pdf of direct light sampling.
    virtual PathIntegratorLocalRecord evalEmittance(std::shared_ptr<Scene> scene,
                                                std::optional<Intersection> its,
                                                const Ray &ray) override;


    // @brief Sample incident direction of direct lighting. 
    // @param scene     Ptr to scene.
    // @param its       Reference point.
    // @param ray       Ray, used to specify wo (out direction).
    // @return          Sampled incident direction, incident radiance and pdf per solid angle.
    virtual PathIntegratorLocalRecord sampleDirectLighting(std::shared_ptr<Scene> scene,
                                                  const Intersection &its,
                                                  const Ray &ray) override;

    // @brief Return scatter value of BSDF or phase function.
    // @param scene     Ptr to scene.
    // @param its       Reference point.
    // @param ray       Ray, used to specify wo (out direction).
    // @param wi        Incident direction wi.
    // @return          Incident direction, scatter throughput f, pdf per solid angle.
    //                  For surface, f is the product of BSDF value and cosine term.
    //                  For medium, f is the value of phase function.
    virtual PathIntegratorLocalRecord evalScatter(std::shared_ptr<Scene> scene,
                                                  const Intersection &its,
                                                  const Ray &ray,
                                                  const Vec3d &wi) override;

    // @brief Sample incident direction by scatter value of BSDF or phase function.
    // @param scene     Ptr to scene.
    // @param its       Reference point.
    // @param ray       Ray, used to specify wo (out direction).
    // @return          Sampled incident direction, scatter throughput f, pdf per solid angle.
    //                  For surface, f is the product of BSDF value and cosine term.
    //                  For medium, f is the value of phase function.
    virtual PathIntegratorLocalRecord sampleScatter(std::shared_ptr<Scene> scene,
                                                    const Intersection &its,
                                                    const Ray &ray);

    // @brief Return survive probability of Russian roulette.
    virtual double russianRoulette(std::shared_ptr<Scene> scene,
                                   const Intersection &its,
                                   const Spectrum &T,
                                   int nBounce) override;

    // todo: move light sampling into a new class (called LightDistribution?)
    // @brief Sample a light, by some weight distribution
    virtual std::shared_ptr<Light> chooseOneLight(std::shared_ptr<Scene> scene,
                                                  const Intersection &its,
                                                  const Ray &ray,
                                                  double lightSample);

    // @brief Evaluate radiance of env lights
    virtual PathIntegratorLocalRecord evalEnvLights(std::shared_ptr<Scene> scene,
                                   const Ray &ray);
};
