# gd.h
just gd.h(windows geometry dash headers) that I use
</br>and i'll add some things from [geode](https://github.com/geode-sdk/geode/tree/main/bindings)

## prepare gd.h for cmake❤️ proj
- **u must have installed [cocos-haders](https://github.com/HJfod/cocos-headers)!!!**
- download code and install it to gd mods sources folder
![image translated (1)](https://user-images.githubusercontent.com/90561697/225808803-f85860f8-5814-4d6a-b251-082e165e1473.jpg)
- to CMakeLists.txt
```cmake
target_include_directories(${PROJECT_NAME} PRIVATE ../curly-eureka/gd.h ../curly-eureka/gd.h/include)
```
- in code
```cpp
#include <cocos2d.h>
#include <gd.h>
```
