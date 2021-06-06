# drone-simulation
Project made in C++ language at programming course provided at Wrocław University of Science and Technology, underwater drone simulation using ``` gnuplot ```(work in progress). Right now im fixing a bug with 3D rotations. Most of the classes are ready. Collision detection with obstacles is not implemented yet.

## Setup
Clone this repository:
```
$ git clone https://github.com/salamaan/drone-simulation.git
```

Install gnuplot:
```
$ sudo apt-get install gnuplot
```

Create directory for object files:
```
$ make build
```

Then compile entire program:
```
$ make
```
This command will create an ``` run ``` executable.

## Running the program
To run this app just use this command:
```
$ ./run
```

## Work in progress
At this moment you can only move a drone. however there is a bug with rotors. In the future the drone will be able to detect a collision with obstacles(that are not implemented yet).
There will be user menu with options of moving and rotating a drone. The drone will turn red when it detects a collision.

## Documentation
The current state of the program is fully documented in English.

## License 
MIT License.

## Authors
* Marcin Salamandra - all functionalities connected with drone
* MSc Arkadiusz Mielczarek - gnuplot API files

