#include <iostream>
#include "mnist_reader.h"

int main() {

  // current code for testing mnist_reader
  int num_images, rows, cols;
  int num_labels;

  auto images = load_mnist_images("../TRAIN IMAGES/train-images-idx3-ubyte", num_images, rows, cols);
  auto labels = load_mnist_labels("../TRAIN IMAGES/train-labels-idx1-ubyte", num_labels);

  std::cout << "Loaded " << num_images << " images of size " << rows << "x" << cols << "\n";
  std::cout << "Loaded " << num_labels << " labels\n";
  std::cout << "First label: " << static_cast<int>(labels[0]) << "\n";

  return 0;
}

