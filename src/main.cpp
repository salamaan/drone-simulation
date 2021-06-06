#include "../inc/drone.hh"
#include "../inc/bottom.hh"
#include "../inc/water_surface.hh"

void wait4key() {
    do {
        std::cout << "\nPress a key to continue...\n";
    } while(std::cin.get() != '\n');
}

int main() {
    std::shared_ptr<drawNS::Draw3DAPI> api(new drawNS::APIGnuPlot3D(-100, 100, -100, 100, -150, 150, -1)); 

    WaterSurface wtr_surf("models/water_surface.dat", api, "blue");
    Bottom bot("models/bottom.dat", api, "yellow");
    wtr_surf.draw();
    bot.draw();

    Drone h("models/drone.dat", api);
    h.draw();

    api->redraw();
    wait4key();

    h.rotate(180.0, 'x');

    api->redraw();
    wait4key();

    return 0;
}