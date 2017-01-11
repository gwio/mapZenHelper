### mapZenHelper

A basic helper sketch to load and stitch mapzen terrain tiles into an ofImage for openframeworks.
It only loads Terrarium format tiles for the moment...

[https://mapzen.com/documentation/terrain-tiles/formats/](https://mapzen.com/documentation/terrain-tiles/formats/)

_Terrarium format PNG tiles contain raw elevation data in meters, in Web Mercator projection (EPSG:3857). All values are positive with a 32,768 offset, split into the red, green, and blue channels, with 16 bits of integer and 8 bits of fraction._


---
![raw](https://c1.staticflickr.com/1/423/32135137881_8f484c642c_z.jpg)
![converted](https://c1.staticflickr.com/1/594/31878384940_659b95de0e_z.jpg)
