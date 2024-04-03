# curly-eureka
last stand curse of traditional modding for Geometry Dash.<br>
It contains functions related to hooks and interference with the memory of the game, creating an interface etc.<br>

## features

- independence (don't need anything, just inject built dll)

- libraries collected in that sdk:
  - cocos-headers, gd.h, minhook(multi hook fork)<br>

- creating mods with minhook that dont conflict with others

- make mod that can work on geode and .geode makeup system (in template mod)

- ModUtils that contains some tools for working with ui, string, files.

- HooksUtils that provides tools for hooking
  - CreateHook helper func
  - HOOK, CC_HOOK, CCEXT_HOOK, MEMBERBYOFFSET macroses
  - MappedHooks
