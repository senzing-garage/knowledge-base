#! /usr/bin/env python3

import json
import os
import pathlib

root_directory = "."

for root, dirs, files in os.walk(root_directory, topdown=False):
    for name in files:
        relative_filename = os.path.join(root, name)
        file_extension = pathlib.Path(relative_filename).suffix
        if file_extension == ".json":
            with open(relative_filename, "r") as file:
                try:
                    data = json.load(file)
                except:
                    print("Incorrect JSON in {0}".format(relative_filename))
