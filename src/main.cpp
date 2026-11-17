#include <sil/sil.hpp>
#include <iostream>
#include "random.hpp"
#include <cmath>

// ! 1-Star
void keep_green_only(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b = 0.f;
    }
}

void channels_swap(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        glm::vec3 save_color{color};

        color.r = save_color.b;
        color.b = save_color.r;
    }
}

void black_white(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color = glm::vec3{0.2125 * color.r + 0.7154 * color.g + 0.0721 * color.b};
    }
}

void negative(sil::Image& image)
{
    for (glm::vec3& color : image.pixels())
    {
        color = glm::vec3{1-color.r, 1-color.g, 1-color.b};
    }
}

void gradient(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = glm::vec3 {0+((0.0033f) * x)};
        }
    }
}

// ! 2-Stars

void mirror(sil::Image& image)
{
    sil::Image original_image{image};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) = original_image.pixel((image.width()-1-x), y);
        }
    }
}

void noisy_image(sil::Image& image)
{
    for (int i{0}; i < (image.width()*image.height())/8; i++)
    {
        image.pixel(random_int(0, image.width()-1), random_int(0, image.height()-1)) = glm::vec3{random_float(0, 1), random_float(0, 1), random_float(0, 1)};
    }
}

void rotation_90(sil::Image& image)
{
    sil::Image new_image{image.height(), image.width()};
    for (int x{0}; x < new_image.width(); x++)
    {
        for (int y{0}; y < new_image.height(); y++)
        {
            new_image.pixel(x, y) = image.pixel(y, (image.height()-1-x));
        }
    }
    image = new_image;
}

void RGB_split(sil::Image& image)
{
    int const gap{15};
    sil::Image new_image{image};
    for (int x{0}; x < new_image.width(); x++)
    {
        for (int y{0}; y < new_image.height(); y++)
        {
            new_image.pixel(x, y).r = image.pixel((x<=gap ? x : x-gap), y).r;
            new_image.pixel(x, y).b = image.pixel((x>=(image.width()-gap) ? x : x+gap), y).b;
        }
    }
    image = new_image;
}

void brightness(sil::Image& image, bool light)
{
    for (glm::vec3& color : image.pixels())
    {
        color.r = std::pow(color.r, light ? 0.7 : 1.5);
        color.g = std::pow(color.g, light ? 0.7 : 1.5);
        color.b = std::pow(color.b, light ? 0.7 : 1.5);
    }
}

void disk(sil::Image& image)
{
    bool in{};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (std::pow((x-(image.width()/2)), 2)+std::pow((y-(image.height()/2)), 2)<= std::pow(150, 2)){
                in=true;
            } else {
                in=false;
            }
            image.pixel(x, y) = glm::vec3{in ? 1.f : 0.f};
        }
    }
}

void circle(sil::Image& image, int thickness)
{
    disk(image);
    bool in{};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (std::pow((x-(image.width()/2)), 2)+std::pow((y-(image.height()/2)), 2)<= std::pow((150-thickness), 2)){
                image.pixel(x, y) = glm::vec3{0.f};
            }
            
        }
    }
}

void animation(sil::Image& image)
{

}

void rose_window(sil::Image& image)
{

}

void mosaic(sil::Image& image)
{

}

int main()
{
    // ! 1-Star
    // {
    //     sil::Image image{"images/logo.png"};
    //     keep_green_only(image);
    //     image.save("output/1-Star/keep_green_only.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     channels_swap(image);
    //     image.save("output/1-Star/channels_swap.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     black_white(image);
    //     image.save("output/1-Star/black_white/5-black_white.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     negative(image);
    //     image.save("output/1-Star/negative.png");
    // }
    // {
    //     sil::Image image{300/*width*/, 200/*height*/};
    //     gradient(image);
    //     image.save("output/1-Star/gradient/6-gradient.png");
    // }

    // ! 2-Stars
    // {
    //     sil::Image image{"images/logo.png"};
    //     mirror(image);
    //     image.save("output/2-Stars/mirror.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     noisy_image(image);
    //     image.save("output/2-Stars/noisy_image.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     rotation_90(image);
    //     image.save("output/2-Stars/rotation_90.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     RGB_split(image);
    //     image.save("output/2-Stars/RGB_split.png");
    // }
    // {
    //     sil::Image image_light{"images/photo.jpg"};
    //     sil::Image image_dark{"images/photo.jpg"};
    //     brightness(image_light, true);
    //     brightness(image_dark, false);
    //     image_light.save("output/2-Stars/brightness_light.jpg");
    //     image_dark.save("output/2-Stars/brightness_dark.jpg");
    // }
    // {
    //     sil::Image image{500, 500};
    //     disk(image);
    //     image.save("output/2-Stars/disk.png");
    // }
    {
        sil::Image image{500, 500};
        circle(image, 20);
        image.save("output/2-Stars/circle.png");
    }
    // {
    //     sil::Image image{"images/logo.png"};
    //     animation(image);
    //     image.save("output/2-Stars/animation.png");
    // }
    // {
    //     sil::Image image{"images/logo.png"};
    //     rose_window(image);
    //     image.save("output/2-Stars/rose_window.png");
    // }
}