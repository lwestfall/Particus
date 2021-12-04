# Particus

A SWENG452W Production
By Luke Westfall

## Setup

### Clone Repository

`git clone https://github.com/lwestfall/Particus`

### Install dependencies

This command installs a few things:

- cmake which is a build tool
- libglew-dev, libglfw3-dev, and libglm-dev are needed for the OpenGL display simulator.

`sudo apt install cmake libglew-dev libglfw3-dev libglm-dev`

This next library requires a few commands to install. It's for the GPIO library to help control the pins of the Raspberry Pi.

```bash
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
```

### Build

Finally, we can try to build! Start by creating and going into the build directory:

```bash
mkdir build
cd build
```

Then try to build:

```bash
cmake ..
cmake --build .
```

If everything went well, we should be able to run now:
`./Particus`
