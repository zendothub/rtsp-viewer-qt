#!/bin/bash

# Update system packages
echo "Updating system packages..."
sudo apt update -y

# Install CMake and Ninja for building Qt projects
echo "Installing CMake and Ninja..."
sudo apt install -y cmake ninja-build

# Install Qt5 core development packages (without qmake)
echo "Installing Qt5 core development packages..."
sudo apt install -y qtbase5-dev qtchooser qtbase5-dev-tools

# Install Qt Multimedia for RTSP support
echo "Installing Qt Multimedia dependencies..."
sudo apt install -y qtmultimedia5-dev libqt5multimedia5-plugins \
                    libqt5multimedia5 libqt5multimediawidgets5

# Install GStreamer dependencies for RTSP support
echo "Installing GStreamer dependencies..."
sudo apt install -y libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev \
                    gstreamer1.0-plugins-good gstreamer1.0-plugins-bad \
                    gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools

# Install Qt WebEngine for web rendering support
echo "Installing Qt WebEngine dependencies..."
sudo apt install -y qtwebengine5-dev libqt5webengine5 libqt5webenginecore5 libqt5webenginewidgets5

echo "All dependencies installed successfully!"
