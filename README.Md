# Dining Philosophers Problem Solver

## Table of Contents

1. [Introduction](#introduction)
2. [Problem Description](#problem-description)
3. [How to Execute](#how-to-execute)
4. [Program Arguments](#program-arguments)
5. [Optional Argument](#optional-argument)
6. [Contributing](#contributing)

## Introduction

This repository contains a solution to the famous Dining Philosophers problem implemented in C. The Dining Philosophers problem is a classic synchronization and concurrency problem in computer science and is used to illustrate the challenges of managing resources among multiple processes.

## Problem Description

In the Dining Philosophers problem, a certain number of philosophers sit around a circular dining table with a bowl of spaghetti in front of each one. There are only as many chopsticks as there are philosophers. To eat, a philosopher must pick up two chopsticks. They can only pick up one chopstick at a time, and they must release the chopsticks when they are done eating. The problem is to come up with a protocol that allows the philosophers to dine without deadlock (where no philosopher can eat) and without any two philosophers trying to eat simultaneously.

## How to Execute

To compile and execute the Dining Philosophers problem solver, follow these steps:

1. Clone this repository:

   ```bash
   git clone https://github.com/alifertah/Philosophers.git
   cd Philosophers` 

2.  Compile the program:
    
    sh
    

-   `make` 
    
-   Run the program:
    
    sh
    

2.  `bash ./philo [number of philosophers] [time_to_die] [number_of_meals] [time_to_sleep] [optional - number_of_times_to_eat]` 
    

## Program Arguments

-   `number of philosophers`: The total number of philosophers participating in the dinner.
    
-   `time_to_die`: The maximum time a philosopher can stay without eating. If a philosopher doesn't eat within this time, the program will terminate.
    
-   `number_of_meals`: The number of meals each philosopher must eat before the program terminates.
    
-   `time_to_sleep`: The time a philosopher spends sleeping after eating or thinking.
    

## Optional Argument

-   `number_of_times_to_eat`: (Optional) The number of times a philosopher must eat before they consider themselves done. If not provided, the philosopher will eat `number_of_meals` times.

## Contributing

Contributions to this project are welcome. If you find any issues, have suggestions, or would like to enhance the project, please feel free to create a pull request or open an issue.
