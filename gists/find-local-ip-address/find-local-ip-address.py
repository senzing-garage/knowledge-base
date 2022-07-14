#! /usr/bin/env python3

import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.connect(("8.8.8.8", 80))
print("{0}".format(sock.getsockname()[0]))
sock.close()
