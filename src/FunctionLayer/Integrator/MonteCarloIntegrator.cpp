/**
 * @file MonteCarloIntegrator.h
 * @author Zhimin Fan
 * @brief Integrators
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "MonteCarloIntegrator.h"

MonteCarloIntegrator::MonteCarloIntegrator(std::shared_ptr<Camera> camera, std::unique_ptr<Film> film, std::unique_ptr<TileGenerator> tileGenerator, std::shared_ptr<Sampler> sampler, int spp) : Integrator(camera, std::move(film), std::move(tileGenerator)), sampler(sampler), spp(spp)
{
}

void MonteCarloIntegrator::render(std::shared_ptr<Scene> scene)
{
    int filmWidth = film->getResolution().x;
    int filmHeight = film->getResolution().y;
    const auto &cam = *this->camera;
    for (int y = 0; y < filmHeight; y++)
    {
        for (int x = 0; x < filmWidth; x++)
        {
            for (int i = 0; i < spp; i++)
            {
                Point2d NDC((x + sampler->sample()) / filmWidth, (y + sampler->sample()) / filmHeight);
                auto L = Li(cam.generateRay(NDC, Point2d(sampler->sample(), sampler->sample())), scene);
                film->deposit(Point2d(x, y), L);
            }
        }
    }
}

double MonteCarloIntegrator::randFloat()
{
    // Get a random number WITHOUT using MonteCarloIntegrator::sampler
    return rand() * 1.0 / RAND_MAX; // todo: better solution
}