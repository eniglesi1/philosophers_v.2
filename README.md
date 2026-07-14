*This project has been created as part of the 42 curriculum by eiglesia.*

# Philosophers

## Description

**Philosophers** is a concurrency project based on the classic dining
philosophers problem. Its goal is to introduce the fundamentals of concurrent
programming, thread management, mutexes, and shared-resource protection.

A group of philosophers sits around a circular table. Each philosopher runs in
a separate thread and repeatedly performs three actions: eating, sleeping, and
thinking. There is one fork between each pair of philosophers, and a philosopher
must acquire both adjacent forks before eating.

In this implementation, every fork is protected by a `pthread_mutex_t`.
Additional mutexes protect the simulation state and the program output, helping
to prevent data races and interleaved messages. The scheduling strategy assigns
eating turns to the philosophers to avoid deadlocks.

The simulation ends when:

- a philosopher exceeds `time_to_die` without starting another meal; or
- every philosopher has eaten the number of times given by the optional
  argument.

### Main concepts

- creating and joining POSIX threads;
- synchronizing threads with mutexes;
- preventing data races and deadlocks;
- measuring elapsed time in milliseconds;
- protecting shared resources and state;
- cleaning up allocated memory and synchronization resources.

### Project structure

```text
philosophers_v.2/
├── README.md
└── philo/
    ├── Makefile
    ├── includes/
    │   └── philo.h
    └── src/
        ├── day.c
        ├── main.c
        ├── parseo.c
        ├── turn.c
        └── utils.c
```

## Instructions

### Requirements

The project requires:

- a C compiler;
- GNU Make;
- an implementation of POSIX Threads.

### Compilation

Clone the repository, enter the project directory, and run:

```bash
cd philo
make
```

The project is compiled with the flags required by 42:

```text
-Wall -Wextra -Werror -pthread
```

The Makefile provides the following rules:

| Rule | Description |
|---|---|
| `make` or `make all` | Builds the `philo` executable. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the executable. |
| `make re` | Performs a clean rebuild. |

### Execution

Run the program using the following syntax:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All time values are expressed in milliseconds. Every argument must be a
strictly positive integer.

| Argument | Description |
|---|---|
| `number_of_philosophers` | Number of philosophers and forks. |
| `time_to_die` | Maximum time a philosopher may spend without starting a meal. |
| `time_to_eat` | Time a philosopher spends eating. |
| `time_to_sleep` | Time a philosopher spends sleeping. |
| `number_of_times_each_philosopher_must_eat` | Optional number of meals each philosopher must complete before the simulation stops. |

Example:

```bash
./philo 5 800 200 200 7
```

This starts a simulation with five philosophers. Each philosopher has 800 ms
before dying, spends 200 ms eating, sleeps for 200 ms, and must complete seven
meals.

### Output format

Each state change is printed in the following format:

```text
timestamp_in_ms philosopher_id has taken right fork
timestamp_in_ms philosopher_id has taken left fork
timestamp_in_ms philosopher_id is eating
timestamp_in_ms philosopher_id is sleeping
timestamp_in_ms philosopher_id is thinking
timestamp_in_ms philosopher_id died
```

The timestamp represents the number of milliseconds elapsed since the start of
the simulation. Output is protected by a mutex so that complete messages are
printed without overlapping.

### Suggested tests

```bash
# A single philosopher cannot acquire two forks
./philo 1 800 200 200

# The simulation should continue while every philosopher remains alive
./philo 5 800 200 200

# The simulation should stop after every philosopher completes seven meals
./philo 5 800 200 200 7

# Tight but viable timing
./philo 4 410 200 200

# A philosopher should die
./philo 4 310 200 100
```

If the corresponding tools are installed, the code can also be checked with:

```bash
norminette .
valgrind --leak-check=full ./philo 5 800 200 200 7
valgrind --tool=helgrind ./philo 5 800 200 200 7
```

## Resources

The following references were used to understand the dining philosophers
problem, POSIX threads, mutexes, and time management:

- [The Dining Philosophers Problem — E. W. Dijkstra](https://www.cs.utexas.edu/~EWD/transcriptions/EWD03xx/EWD310.html)
- [POSIX Threads Programming — Lawrence Livermore National Laboratory](https://hpc-tutorials.llnl.gov/posix/)
- [pthread_create(3) — Linux man-pages](https://man7.org/linux/man-pages/man3/pthread_create.3.html)
- [pthread_join(3) — Linux man-pages](https://man7.org/linux/man-pages/man3/pthread_join.3.html)
- [pthread_mutex_lock(3) — Linux man-pages](https://man7.org/linux/man-pages/man3/pthread_mutex_lock.3.html)
- [gettimeofday(2) — Linux man-pages](https://man7.org/linux/man-pages/man2/gettimeofday.2.html)
- the official **Philosophers** subject available on the 42 intranet.

### Use of AI

AI was used to reorganize, translate, and improve the wording and structure of
this README. It was also used to compare the documented commands and behaviour
with the existing source files. AI was not used to generate or modify the
project's C implementation as part of this documentation update. The author is
responsible for understanding and verifying the implementation, synchronization
strategy, and test results before submission.
