#include <iostream>
#include <fstream>
#include <string>

#define LAYERS_COUNT 3
using namespace std;

const string PATH = "C:/Users/ether/CLionProjects/untitled1/";
const string FILE_REPORT_PATH = PATH + "training_report";
const string FILE_WEIGHTS_PATH = PATH + "weigths_neutral_network";

const int width = 28, height = 28;
const int neuron_layer[LAYERS_COUNT]{width*height, 128, 26};
const int epochs = 100, countTraining = 88800, countTest = 14800;

int image[width][height];
double *w1[neuron_layer[0]], *delta1[neuron_layer[0]], *n1;
double *w2[neuron_layer[1]], *delta2[neuron_layer[1]], *n2;
double exp[neuron_layer[2]], *delta3[neuron_layer[2]], *n3;
fstream file_report, file_weights, file_labels, file_image;

void init() {
    for (int i = 0; i < neuron_layer[0]; i++)
    {
        w1[i] = new double[neuron_layer[1]];
        delta1[i] = new double[neuron_layer[1]];
    }

    for (int i = 0; i < neuron_layer[1]; i++)
    {
        w2[i] = new double[neuron_layer[2]];
        delta2[i] = new double[neuron_layer[2]];
    }

    n1 = new double[neuron_layer[0]];
    n2 = new double[neuron_layer[1]];
    n3 = new double[neuron_layer[2]];

    for (int i = 0; i < neuron_layer[0]; i++)
        for (int j = 0; j < neuron_layer[1]; j++)
        {
            int sign = (rand() % 2 == 1? -1 : 1);
            w1[i][j] = sign * ( (rand() % 10 + 1.) / (10. * neuron_layer[1]) );
        }

    for (int i = 0; i < neuron_layer[1]; i++)
        for (int j = 0; j < neuron_layer[2]; j++)
        {
            int sign = (rand() % 2 == 1? -1 : 1);
            w2[i][j] = sign * ( (rand() % 10 + 1.) / (10. * neuron_layer[2]) );
        }
}

double ReLU(double x){
    if (x < 0) x *= 0.01;
    else if (x > 1) x = 1. + (x - 1)* 0.01;
    return x;
}

