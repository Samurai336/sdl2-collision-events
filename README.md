sdl2-collision-events
=====================

Tutorial from http://www.sdltutorials.com/sdl-collision-events converted to use SDL2 RC.

to compile create build folder in the directory, put you platform specific build tatget there with cmake 
then move the folders maps/ tilesets/ and the file yoshi.png into build/. Then compile and run. 


Note on SDL2: 
not in repos yes so you will probably have to build from scratch. There are pre build binaries for windows and both bin and source can be found at http://www.libsdl.org/tmp/download-2.0.php
You will also need SDL2_image wich can be aquired here. http://www.libsdl.org/tmp/SDL_image/. 

cmake command sequence: 
$mkdir build 
$cd build 
$ cmake .. -DOption_SDL_Dev=ON 

OR just use the cmake gui

