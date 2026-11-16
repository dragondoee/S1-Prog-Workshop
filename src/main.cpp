#include <sil/sil.hpp>

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
}