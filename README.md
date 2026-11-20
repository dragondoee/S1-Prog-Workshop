# 🐣 S1 | Prog: Workshop

## ⭐ 1-Star

### Green
![Keep green only](/output/1-Star/keep_green_only.png "Keep green only")

### Channel swap
![Channel swap](/output/1-Star/channels_swap.png "Channel swap")

### Black & White
Essai n°1 :
Tout noir

Essai n°2 to 3 :
Tout gris

![Black & White](/output/1-Star/black_white/2-black_white.png "Black & White")

Essai n°4 :
Black and White : color = color.r + color.g + color.b;

![Black & White](/output/1-Star/black_white/4-black_white.png "Black & White")

Essai n°5 :
Source : [transformer une image RGB en niveau de gris](https://www.developpez.net/forums/d534510/general-developpement/algorithme-mathematiques/traitement-d-images/transformer-image-rgb-niveau-gris/)

![Black & White](/output/1-Star/black_white/5-black_white.png "Black & White")

### Negative
![Negative](/output/1-Star/negative.png "Negative")

### Gradient
![Gradient](/output/1-Star/gradient/1-gradient.png "Gradient 1")
![Gradient](/output/1-Star/gradient/2-gradient.png "Gradient 2")
![Gradient](/output/1-Star/gradient/3-gradient.png "Gradient 3")
![Gradient](/output/1-Star/gradient/4-gradient.png "Gradient 4")
![Gradient](/output/1-Star/gradient/5-gradient.png "Gradient 5")
![Gradient](/output/1-Star/gradient/6-gradient.png "Gradient 6")

## ⭐⭐ 2-Stars

### Mirror 
Error : sil::Image::pixel(int, int): Assertion `x < _width' failed.
J'ai finis par faire x+1 avant de changer pour image.width-1.

![Mirror](/output/2-Stars/mirror.png "Mirror")

### Noisy image
![Noisy image](/output/2-Stars/noisy_image.png "Noisy image")

### 90° rotation
![90° rotation](/output/2-Stars/rotation_90.png "90° rotation")

### RGB split
![RGB split](/output/2-Stars/RGB_split.png "RGB split")

### Brightness
![Brightness light](/output/2-Stars/brightness_light.jpg "Brightness light")
![Brightness dark](/output/2-Stars/brightness_dark.jpg "Brightness dark")

### Disk
![Disk](/output/2-Stars/disk.png "Disk")

#####  Circle
![Circle](/output/2-Stars/circle.png "Circle")

##### Animation
![Animation](/output/2-Stars/animation.gif "Animation")

## ⭐⭐⭐ 3-Stars

##### Rose window
![Rose window](/output/3-Stars/rose_window.png "Rose window")

### Glitch
Error : glm::vec3& sil::Image::pixel(int, int): Assertion `x < _width' failed.
Bug : J'avais mal fait ma condition de boucle : x < vector[0] || p1[0]+x < image.width()
C'était pour proteger une sortie de l'image mais l'effet était autre, et j'ai mis la protection à un autre endroit.

![Glitch bug](/output/3-Stars/glitch/bug-glitch.png "Glitch bug")


![Glitch](/output/3-Stars/glitch.png "Glitch")
