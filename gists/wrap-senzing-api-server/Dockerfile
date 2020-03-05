ARG BASE_IMAGE=senzing/senzing-api-server:1.7.10
FROM ${BASE_IMAGE}

# Need to be root to do "apt" operations.

USER root

# Install packages via apt.

RUN apt update \
 && apt -y install \
    apt-transport-https \
    curl \
    gnupg \
    sudo \
    wget

# Install Senzing repository index.

RUN curl \
    --output /senzingrepo_1.0.0-1_amd64.deb \
    https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb \
 && apt -y install \
    /senzingrepo_1.0.0-1_amd64.deb \
 && apt update \
 && rm /senzingrepo_1.0.0-1_amd64.deb

# Install Senzing.

ENV SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA
RUN apt -y install senzingapi

# Now do any additional configuration needed.


# Finally, make the container a non-root container again.

USER 1001
