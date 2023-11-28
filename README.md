# curly-eureka
a tool for traditional modding, almost every my mod requires this shit,<br>
libraries collected: cocos-headers, gd.h, minhook, imgui-hook, uibuilder, Simple Ini, DiscordRPCSDK<br>
It contains functions related to hooks and interference with the memory of the game, creating an interface etc.<br>

You can create a mod on minhook for Geode without a mess on the layers.<br>
Compatible with other mods? exist some a solution there.<br>

### gd.h
i'll add some things from [geode](https://github.com/geode-sdk/geode/tree/main/bindings) and mat's [func_dump](https://github.com/matcool/re-scripts/blob/main/func_dump.txt)
> *also i will try port it to 2.2*
##### example commits:
[buttons in menulayer](https://github.com/user95401/curly-eureka/commit/ba3b388c5d6cdaf5da8ecadd619629455f21e8ed), 
[CreatorLayer](https://github.com/user95401/curly-eureka/commit/c18f2c57f253a7d3ec33adc41ceef024aaa3d9bd), 
[GameSoundManager](https://github.com/user95401/curly-eureka/commit/50f2a0b4cbe3ef27afcdd4d471222ddb7b39338f), 
**[PlayLayer](https://github.com/user95401/curly-eureka/commit/9611fb9c73c070b1455c89e7c9c9c407a062559e)**, 
[LevelInfoLayer](https://github.com/user95401/curly-eureka/commit/a5f6db2c747187f29c252626a9ea615e3aea477f), 
[GJGarageLayer](https://github.com/user95401/curly-eureka/commit/a5ac06220a0c2de8ece407e2538b0667cefa6123), 
[KeysLayer](https://github.com/user95401/curly-eureka/commit/a24d8c89c7e12ecba4f06bc0360c9e90048d3afc), 
[GameManager](https://github.com/user95401/curly-eureka/commit/ef3da2854a09b4c7d2bf3d9e76da55d7fd2121e2), 
[GameLevelManager](https://github.com/user95401/curly-eureka/commit/8a39ffb97f23ad07b76f3ba697da31c65aac62c3)
##### [org](https://github.com/poweredbypie/gd.h) by [pie](https://github.com/poweredbypie) | based on [HJfod's fork](https://github.com/HJfod/gd.h)

### hooks
it have some tools for hooking like
 - ``MEMBERBYOFFSET(type, class, offset)``
 - ``MH_SafeInitialize()`` - Compatible with other mods, Cvolton's solution
 <br>(makes Sleep() for random ms, so hooks may created at other time)
 - ``HOOK(target, name)``, ``CC_HOOK(symbol, name)``, ``CCEXT_HOOK(symbol, name)``

   ![image](https://github.com/user95401/curly-eureka/assets/90561697/299dbd5f-c3e8-4d6b-b317-9158880d4348)

## modutils
alot of things, just discover [mod_utils.hpp](mod_utils.hpp)
