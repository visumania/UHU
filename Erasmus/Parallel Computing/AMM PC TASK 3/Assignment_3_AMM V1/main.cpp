#include <iostream>
#include <random>
#include <vector>
#include <omp.h>
#include "lodepng.h"

using namespace std;

struct Triangle
{
    float x0=0.0f, y0=0.5f; //Parte superior del triangulo
    float x1=0.5f, y1=-0.5f; //Parte inferior derecha del triangulo
    float x2=-0.5f, y2=-0.5f; //Parte inferior izquierda del triangulo

    //Scales (enlarges) the triangle by the given factor
    void scale(float factor) //Tamaño del triangulo
    {
        x0*=factor; y0*=factor;
        x1*=factor; y1*=factor;
        x2*=factor; y2*=factor;
    }

    //Translates (shifts) the triangle by the given vector [x,y]
    void translate(float x, float y) //Posicion del triangulo
    {
        x0+=x; y0+=y;
        x1+=x; y1+=y;
        x2+=x; y2+=y;
    }

    //Returns true, if the point (x,y) is inside the triangle. It requires that
    //the vertices (x0,y0), (x1,y1), (x2,y2) are given in counter-clockwise order.
    bool is_point_inside(float x, float y)
    {
        float area = 0.5f * (-y1*x2 + y0*(-x1 + x2) + x0*(y1 - y2) + x1*y2);
        float s = 1/(2*area) * (y0*x2 - x0*y2 + (y2 - y0)*x + (x0 - x2)*y);
        float r = 1/(2*area) * (x0*y1 - y0*x1 + (y0 - y1)*x + (x1 - x0)*y);

        return s > 0 && r > 0 && (1 - s - r > 0);
    }
};

struct Tree
{
    float position_x = 0;
    float position_y = 0;
    float size = 1;
};

vector<uint32_t>draw_image(int width, int height, const vector<Tree> &trees)
{
    vector<uint32_t> pixels(width * height); //Create a vector with 1024*1024 positions

    #pragma omp parallel for //Program parallelization, if you remove it the execution the time will increases
    for (int y = 0; y < height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
            //Color of the pixel is set based on Red Green Blue (RGB) components
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            for(auto tree : trees)
            {
                //Here we check whether (x,y) belongs to the current tree, i.e.
                //whether it is inside one of its three triangles
                //If it is we set color to white (or some other color)
                Triangle t1;
                t1.scale(tree.size);
                t1.translate(tree.position_x, tree.position_y);

                if(t1.is_point_inside(x,y))
                    red = green = blue = 255;

                Triangle t2;
                t2.scale(tree.size);
                t2.translate(tree.position_x, tree.position_y-0.5*tree.size);

                if(t2.is_point_inside(x,y))
                    red = green = blue = 255;

                Triangle t3;
                t3.scale(tree.size);
                t3.translate(tree.position_x, tree.position_y-tree.size);

                if(t3.is_point_inside(x,y))
                    red = green = blue = 255;
            }

            uint32_t color = (255u<<24) | (blue<<16) | (green<<8) | red;
            pixels[(height-y-1) * width + x] = color;
        }
    }

    return pixels;
}

int main()
{
    const int Width = 1024;
    const int Height = Width;

    //Positions and sizes of the trees are generated randomly
    uniform_int_distribution<int> random_position(10,Width-10);
    uniform_int_distribution<int> random_size(20,Width/10);
    random_device generator;

    const int NTrees = 20;
    vector<Tree> trees;

    for(int i=0 ; i<NTrees ; i++)
    {
        float x = random_position(generator);
        float y = random_position(generator);
        float size = random_size(generator);
        trees.push_back({x,y,size});
    }

    auto start_time = omp_get_wtime();
    auto pixels = draw_image(Width, Height, trees);
    auto calc_time = omp_get_wtime() - start_time;

    cout << "Calc. time: " << calc_time << " seg.\n";

    lodepng_encode_file("christmas_tree.png", (const unsigned char*)pixels.data(), Width, Height, LCT_RGBA,8);

    return 0;
}
