# Particus

A SWENG452W Production
By Luke Westfall

## Setup

### 1. Clone Repository

`git clone https://github.com/lwestfall/Particus`

### 2. Install dependencies

This command installs a few things (some of these might already be installed, that's fine):

- cmake which is a build tool
- libglew-dev, libglfw3-dev, and libglm-dev are needed for the OpenGL display simulator.
- wiringpi is a package that helps interface with I/O devices

`sudo apt install cmake libglew-dev libglfw3-dev libglm-dev wiringpi`

This next library requires a few commands to install. It's for the GPIO library to help control the pins of the Raspberry Pi.

```bash
wget https://github.com/joan2937/pigpio/archive/master.zip
unzip master.zip
cd pigpio-master
make
sudo make install
```

For the next step, you should be back at the parent directory (where the Particus and pigpio-master directory live):

`cd ..`

### 3. Clone additional library sources

There are two libraries needed for interacting with the MPU9250 over I2C. **It is very important that the following commands are run from the parent directory.** Confirm with the command `ls`. You should see the Particus directory. If you don't see it, navigate to the directory containing it.

Then run:

```bash
git clone https://github.com/simondlevy/MPU.git
git clone https://github.com/simondlevy/CrossPlatformDataBus.git
```

## Build

Finally, we can try to build! Start by creating and going into the build directory:

```bash
cd Particus
mkdir build
cd build
```

Then try to build:

```bash
cmake ..
cmake --build .
```

If everything went well, we should be able to run now. Note that the initialization of the hardware can take a few seconds, so have patience!

*NOTE: you must include sudo for permissions to use the GPIO*

`sudo ./Particus`
