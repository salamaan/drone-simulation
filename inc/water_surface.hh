#ifndef WATER_SURFACE_HH
#define WATER_SURFACE_HH

#include "surface.hh"

/**
 * @brief Class representing water surface
 */
class WaterSurface : public Surface {
    public:
        /**
         * @brief Parametric constructor with file name and pointer to gnuplot api
         * @param file_name file name in which water surface is saved
         * @param api pointer to a class that is connected with gnuplot
         */
        WaterSurface(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api, std::string colour);
        /**
         * @brief Nonparameric constructor
         */
        WaterSurface() = default;
        /**
         * @brief Copy constructor
         * @param W_S WaterSurface object
         */
        WaterSurface(const WaterSurface & W_S) = default;
        /**
         * @brief Destructor
         */
        ~WaterSurface() = default;
};

#endif