# Use the latest Ubuntu image
FROM ubuntu:latest

# Set the maintainer label
LABEL maintainer="Akeman"

# Update package list and install necessary packages
RUN apt-get update -y && \
    apt-get install -y --no-install-recommends \
    vim \
    build-essential \
    curl \
    wget \
    gdb \
    cmake \
	openssl \
	libcurl4-openssl-dev \
	ca-certificates \
	libssl-dev && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Create a user and group
RUN groupadd -r user && useradd -r -g user user

# Switch to the new user
USER user

# Start with bash shell
CMD ["/bin/bash"]
