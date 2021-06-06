CPPFLAGS=-c -g -Wall -pedantic -std=c++17
OBJS=$(BUILD)/main.o $(BUILD)/Dr3D_gnuplot_api.o $(BUILD)/vector.o $(BUILD)/matrix.o $(BUILD)/rotary_matrix.o $(BUILD)/cuboid.o $(BUILD)/bottom.o $(BUILD)/water_surface.o $(BUILD)/drawing_interface.o $(BUILD)/surface.o $(BUILD)/hex_prism.o $(BUILD)/rotor.o $(BUILD)/drone.o
EXEC=run
BUILD=build

$(EXEC): $(OBJS)
	g++ -o $(EXEC) $(OBJS) -lpthread

$(BUILD)/main.o: src/main.cpp inc/drone.hh inc/bottom.hh inc/water_surface.hh
	g++ ${CPPFLAGS} -o $(BUILD)/main.o src/main.cpp

$(BUILD)/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o $(BUILD)/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

$(BUILD)/drawing_interface.o: src/drawing_interface.cpp inc/drawing_interface.hh
	g++ ${CPPFLAGS} -o $(BUILD)/drawing_interface.o src/drawing_interface.cpp

$(BUILD)/vector.o: src/vector.cpp inc/vector.hh
	g++ ${CPPFLAGS} -o $(BUILD)/vector.o src/vector.cpp

$(BUILD)/matrix.o: src/matrix.cpp inc/matrix.hh
	g++ ${CPPFLAGS} -o $(BUILD)/matrix.o src/matrix.cpp

$(BUILD)/rotary_matrix.o: src/rotary_matrix.cpp inc/rotary_matrix.hh
	g++ ${CPPFLAGS} -o $(BUILD)/rotary_matrix.o src/rotary_matrix.cpp	

$(BUILD)/cuboid.o: src/cuboid.cpp inc/cuboid.hh
	g++ ${CPPFLAGS} -o $(BUILD)/cuboid.o src/cuboid.cpp

$(BUILD)/hex_prism.o: src/hex_prism.cpp inc/hex_prism.hh
	g++ ${CPPFLAGS} -o $(BUILD)/hex_prism.o src/hex_prism.cpp

$(BUILD)/rotor.o: src/rotor.cpp inc/rotor.hh
	g++ ${CPPFLAGS} -o $(BUILD)/rotor.o src/rotor.cpp

$(BUILD)/drone.o: src/drone.cpp inc/drone.hh
	g++ ${CPPFLAGS} -o $(BUILD)/drone.o src/drone.cpp

$(BUILD)/bottom.o: src/bottom.cpp inc/bottom.hh
	g++ ${CPPFLAGS} -o $(BUILD)/bottom.o src/bottom.cpp

$(BUILD)/surface.o: src/surface.cpp inc/surface.hh
	g++ ${CPPFLAGS} -o $(BUILD)/surface.o src/surface.cpp

$(BUILD)/water_surface.o: src/water_surface.cpp inc/water_surface.hh
	g++ ${CPPFLAGS} -o $(BUILD)/water_surface.o src/water_surface.cpp

build:
	mkdir -p $(BUILD)

clear:
	rm $(EXEC) $(OBJS)
	rm -r $(BUILD)
