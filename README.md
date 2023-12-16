# curly-eureka
last stand curse of traditional modding for Geometry Dash.<br>
It contains functions related to hooks and interference with the memory of the game, creating an interface etc.<br>

## features

- independence (don't need anything, just inject built dll)

- libraries collected in that sdk:
  - cocos-headers, gd.h, minhook(multi hook fork), imgui-hook, uibuilder, Simple Ini, DiscordRPCSDK, jute, kuba--zip<br>

- creating mods with minhook that dont conflict with others

- make mod that can work on geode and .geode makeup system (in template mod)

- updated gd.h
<br>example commits:
[buttons in menulayer](https://github.com/user95401/curly-eureka/commit/ba3b388c5d6cdaf5da8ecadd619629455f21e8ed), 
[CreatorLayer](https://github.com/user95401/curly-eureka/commit/c18f2c57f253a7d3ec33adc41ceef024aaa3d9bd), 
[GameSoundManager](https://github.com/user95401/curly-eureka/commit/50f2a0b4cbe3ef27afcdd4d471222ddb7b39338f), 
**[PlayLayer](https://github.com/user95401/curly-eureka/commit/9611fb9c73c070b1455c89e7c9c9c407a062559e)**, 
[LevelInfoLayer](https://github.com/user95401/curly-eureka/commit/a5f6db2c747187f29c252626a9ea615e3aea477f), 
[GJGarageLayer](https://github.com/user95401/curly-eureka/commit/a5ac06220a0c2de8ece407e2538b0667cefa6123), 
[KeysLayer](https://github.com/user95401/curly-eureka/commit/a24d8c89c7e12ecba4f06bc0360c9e90048d3afc), 
[GameManager](https://github.com/user95401/curly-eureka/commit/ef3da2854a09b4c7d2bf3d9e76da55d7fd2121e2), 
[GameLevelManager](https://github.com/user95401/curly-eureka/commit/8a39ffb97f23ad07b76f3ba697da31c65aac62c3)

- ModUtils that contains some tools for working with ui, string, files. [Watch more >>](https://github.com/user95401/curly-eureka/wiki/ModUtils)

- HooksUtils that provides tools for hooking
  - CreateHook helper func
  - HOOK, CC_HOOK, CCEXT_HOOK, MEMBERBYOFFSET macroses
  - MappedHooks
