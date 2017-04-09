# ft_contrast
### Apply contrast to images

#### Overview
The goal of this project is to take a `.pgm` type image file, calculate the
given contrast and output to the given filename. These images can be quite large,
so we'll have to use multi-threading in order to calculate the final product
in a realistic amount of time.

#### Format

`ft_contrast -f [source .pgm] -c [contrast amount] -o [destination .pgm]`

#### Threading

In order to develop an algorithm that takes advantage of the resources available
to it, we need to keep spinning up new threads and assigning a task to that thread.
However, spinning up threads and then letting them die is not efficient as it
takes time to initialize new threads. The solution? Keep the threads alive while
they wait for new jobs. This can be done a couple ways. Method one, preemptively
start several threads and wait for jobs to assign to each, and method two, spin
up new threads as the job requires and keep them running.

#### Mandatory

Create the functions listed below

- `ft_contrast_th` - execute parallel threads to calculate the contrast
- `ft_contrast_tp` - same as the above but with our own thread library(?)

Other requirements

- Must have a Makefile to generate the lib and the executable
- Must be able to re-use the (thread) library
- The thread library must have at least the following functions:
	- `tp_create` - create a thread pool
	- `tp_exec_queue_add` - add job to the queue
	- `tp_wait_for_queue` - blocking function which is unblocked when the all
		jobs in the queue are executed
- The pthread must work, each should be able to handle a job
- Testing main must be included for the corrector

#### Authorized Functions

**stdlib.h**

- `malloc`
- `free`

**fctl.h**

- `open`
- `close`

**unistd.h**

- `write`
- `read`
- `lseek`
- `fork`

**stdio.h**

- `printf`

**pthread.h**

- `pthread_create`
- `pthread_cleanup_push`
- `pthread_detach`
- `pthread_exit`
- `pthread_join`
- `pthread_mutex_init`
- `pthread_cond_init`
- `pthread_cond_wait`
- `pthread_cond_signal`

***

#### Optional Functionality - TBC
