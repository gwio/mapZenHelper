### mapZenHelper

A basic helper sketch to load and stitch mapzen terrain tiles into an ofImage for openframeworks.
It only loads Terrarium and Normal format tiles for the moment...

[https://mapzen.com/documentation/terrain-tiles/formats/](https://mapzen.com/documentation/terrain-tiles/formats/)

_Terrarium format PNG tiles contain raw elevation data in meters, in Web Mercator projection (EPSG:3857). All values are positive with a 32,768 offset, split into the red, green, and blue channels, with 16 bits of integer and 8 bits of fraction._

_Normal format PNG tiles are processed elevation data with the the red, green, and blue values corresponding to the direction the pixel “surface” is facing (its XYZ vector), in Web Mercator projection (EPSG:3857). The alpha channel contains quantized elevation data with values suitable for common hypsometric tint ranges._

Updated to work with Nextzen alternative:
[https://mapzen.com/blog/migration/](https://mapzen.com/blog/migration/)
You can get an API key here
[https://www.nextzen.org/](https://www.nextzen.org/)
---
![raw](https://c1.staticflickr.com/1/423/32135137881_8f484c642c_z.jpg)
![converted](https://c1.staticflickr.com/1/594/31878384940_659b95de0e_z.jpg)
![normal](https://c1.staticflickr.com/1/302/32115617622_86c03cf354_z.jpg)
