# curly-eureka
last stand curse of traditional modding for Geometry Dash.<br>
It contains functions related to hooks and interference with the memory of the game, creating an interface etc.<br>

## features

- independence (don't need anything, just inject built dll, i mean single dll)

- libraries collected in that sdk:
  - cocos-headers, gd.h, minhook(multi hook fork)<br>

- creating mods using minhook that dont conflict with others (fixed overhook problem)

- make mod that can work on geode (two times call escape and other)

- ModUtils that contains some tools for working with ui, string, files.

- HooksUtils that provides tools n' helpers for hooking
  - CreateHook helper func
  - HOOK, CC_HOOK, CCEXT_HOOK, MEMBERBYOFFSET macroses
  - MappedHooks

# MinHook is safe
Yea, the problem u cant hook already hooked function got absolutely soloved with big thanks to m417z's (Michael Maltsev) [fork of minhook](https://github.com/m417z/minhook).
Soo that is, u can hook stuff and dont give a shit about other mods because they will be fine with the with ur mod.
