#ifndef BOTTOM_HH
#define BOTTOM_HH

#include "surface.hh"

/**
 * @brief Class representing bottom surface
 */
class Bottom : public Surface {
    public:
        /**
         * @brief Parametric constructor with file name and pointer to gnuplot api
         * @param file_name file name in which bottom surface is saved
         * @param api pointer to a class that is connected with gnuplot
         */
        Bottom(std::string file_name, std::shared_ptr<drawNS::Draw3DAPI> api, std::string colour);
        /**
         * @brief Nonparameric constructor
         */
        Bottom() = default;
        /**
         * @brief Copy constructor
         * @param B Bottom object
         */
        Bottom(const Bottom & B) = default;
        /**
         * @brief Destructor
         */
        ~Bottom() = default;
};

#endif
