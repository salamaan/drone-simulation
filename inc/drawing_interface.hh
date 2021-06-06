#ifndef DRAWING_INTERFACE_HH
#define DRAWING_INTERFACE_HH

#include "Dr3D_gnuplot_api.hh"

/**
 * @brief Class representing drawing interface with basic drawing functionalities 
 */
class DrawingInterface {
    protected:
        /**
         * @brief Pointer to a class connected with gnuplot
         */
        std::shared_ptr<drawNS::Draw3DAPI> api_ptr;
        /**
         * @brief Object index
         */
        uint object_index;
        
    public:
        /**
         * @brief Draw object on the scene
         */
        virtual void draw() = 0;
        /**
         * @brief Erase object from a scene
         */
        void erase();
};

#endif