# PID controller

Self-Driving Car Engineer Nanodegree Program

The goal of the project is to implement a PID controller 
for calculating the steering control input for the vehicle given a cross-track error.

This project should be run in the Simulator which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)

## Compiling and building

The project has been tested / run on Ubuntu.

* cmake >= 3.5
* make >= 4.1 (Linux, Mac),
* gcc/g++ >= 5.4

Cmake is used as a build system for the project. 
In order to compile the code run the commands below in the bash shell in the root project directory:
1. `mkdir build`
2. `cd build`
3. `cmake ../src/`
4. `make`
5. `./particle_filter`

Create Eclipse project files:
1. `cd build`
2. `cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ../src/`

## Implementation

The code follows standard implementation of the PID controller. 
Given a cross-track error (CTE) at each time stamp, 
the `ComputeSteering` method computes the control 
input based on the `Kp`, `Ki`, and `Kd` gains.
This input is then applied to steer the vehicle in the simulator.
As mentioned in the description, the control input is also bounded to `[-1;1]`.

## Reflection

1. Describe the effect each of the P, I, D components had in your implementation.
---

* `P` - magnitude of correction to the target point,
* `I` - removing systematic bias,
* `D` - adds smoothness when correction to the target point.

2. Describe how the final hyper-parameters were chosen.
---

I have used manual version of the twiddle algorithm described in the lecture.
So essentially I started with a parameter guess that was shown in the lecture, 
and then manually tune the parameters until reaching a satisfactory performance.

The problem of applying twiddle, gradient descent or similar parameter space search algorithms
is that the simulator is buried inside the Unity 3D GUI (i.e. one should launch the binary, then `click-click-click`, 
and only then the track simulator will pop up), and cannot be launched as a binary. 
In this respect the manual tuning is faster.
