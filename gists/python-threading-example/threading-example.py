#! /usr/bin/env python3

import random
import threading
import time


class TestThread(threading.Thread):

    def run(self):

        for loop_number in range(10):
            print("{0} Loop: {1}".format(self.name, loop_number))
            time.sleep(random.randint(1, 5))

# Construct threads.


threads = []
for thread_number in range(5):
    thread = TestThread()
    thread.name = "thread-{0}".format(thread_number)
    threads.append(thread)

# Start threads.

for thread in threads:
    thread.start()

# Wait for threads to stop.

for thread in threads:
    thread.join()
