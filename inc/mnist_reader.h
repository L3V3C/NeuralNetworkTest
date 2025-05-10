/* MNIST_reader
 * The header file which defines the interface for reading MNIST image and label from disk.
 * @L3V3C
 */

#pragma once // the file is only included once during compilation

#include <string> // for file paths
#include <vector> // returning image and label data using vector
#include <cstdint>

using namespace std;

// function reads train-images-idx3-ubyte
// returns 2D vector; one image per element, (rows * cols) bytes
vector<vector<uint8_t>> load_mnist_images(
  const string& filepath,
  int& number_of_images, // total
  int& rows, // image dimensions
  int& cols
);

// function reads trail-labels-idx1-ubyte
// returns one label per image (vector of 8-bit integers)
vector<uint8_t> load_mnist_labels(
  const string& filepath,
  int& number_of_labels
);
