# How to bring up Jupyter Lab

## Setup environment

1. Run Senzing gRPC Server Docker container.

   ```console
   docker run -it --name senzing-serve-grpc -p 8261:8261 --read-only --rm senzing/serve-grpc:latest
   ```

1. If a Python virtual environment is used, activate it.

   Example:

   ```console
   source ~/.venv/bin/activate
   ```

1. Install the senzing-grpc Python package.

   ```console
   python3 -m pip install --upgrade senzing-grpc
   ```

## Example notebooks

Steps in this section are optional.
They download example Jupyter notebooks.

1. Clone the Git repository hosting the example Jupyter notebooks.

   ```console
   git clone git@github.com:senzing-garage/playground.git ~/my-senzing-playground
   ```

1. Enter the directory containing the Jupyter notebooks.

   ```console
   cd ~/my-senzing-playground/rootfs/examples/notebooks/
   ```

## Run Jupyter Lab

1. Start Jupyter Lab.

   ```console
   jupyter lab
   ```
