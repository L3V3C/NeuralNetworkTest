/* MNIST_reader program
 * @L3V3C
 * */

#include "mnist_reader.h"
#include <fstream> // for reading binary files
#include <stdexcept> // to throw readable errors
#include <iostream> 

using namespace std;

// function to read a 4-byte big-endian integer 
static int read_int(ifstream& ifs) {
  uint8_t bytes[4];
  ifs.read(reinterpret_cast<char*>(bytes), 4);
  return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

std::vector<std::vector<uint8_t>> load_mnist_images(const std::string& filepath, int& number_of_images, int& rows, int& cols) {
    std::ifstream file(filepath, std::ios::binary); // opens the binary file for reading 
    if (!file.is_open()) throw std::runtime_error("Unable to open file: " + filepath); // if it cant be open, throw error 

    int magic = read_int(file); // images start with magic number, which is 0x00000803 -DEC-> 2051
    if (magic != 2051) throw std::runtime_error("Invalid magic number in image file!"); // check the filetype 

    // read the header, how many images and the size of them
    number_of_images = read_int(file);
    rows = read_int(file); // dimension
    cols = read_int(file);

    // alocate a 2D array [numOfImg][rows*cols]
    std::vector<std::vector<uint8_t>> images(number_of_images, std::vector<uint8_t>(rows * cols));
    for (int i = 0; i < number_of_images; ++i)
        file.read(reinterpret_cast<char*>(&images[i][0]), rows * cols);

    return images; // returns the image vector nodes
}

std::vector<uint8_t> load_mnist_labels(const std::string& filepath, int& number_of_labels) {
    std::ifstream file(filepath, std::ios::binary); // same opening as before
    if (!file.is_open()) throw std::runtime_error("Unable to open file: " + filepath);

    int magic = read_int(file); // the magic number here is 0x00000801 -DEC-> 2049 (BladeRunner reference :)
    if (magic != 2049) throw std::runtime_error("Invalid magic number in label file!");

    // reads all labels into a flat vector
    number_of_labels = read_int(file);
    std::vector<uint8_t> labels(number_of_labels);
    file.read(reinterpret_cast<char*>(&labels[0]), number_of_labels);

    return labels; // return all of the labels
}
