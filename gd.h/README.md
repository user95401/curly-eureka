# gd.h
news 

--------------------------
in audio_nodes\FMODAudioEngine.h
```
bool isBackgroundMusicPlaying() {
	return reinterpret_cast<bool(__thiscall*)(FMODAudioEngine*)>(base + 0xc4fc0)(this);
}
```
from [geode/bindings/GeometryDash.bro#L1593](https://github.com/geode-sdk/geode/blob/main/bindings/GeometryDash.bro#L1593)
```
bool isBackgroundMusicPlaying(const std::string& path) {
	return reinterpret_cast<bool(__thiscall*)(FMODAudioEngine*, std::string)>(base + 0x24080)(this, path);
}
```
from [geode/bindings/GeometryDash.bro#L1594](https://github.com/geode-sdk/geode/blob/main/bindings/GeometryDash.bro#L1594)
--------------------------

--------------------------
in manager_nodes\GameManager.h
```
void setUGV(const char* key, bool value) {
	return reinterpret_cast<void(__thiscall*)(GameManager*, const char*, bool)>(
		base + 0xc9f90
		)(this, key, value);
}
```
from [geode/bindings/GeometryDash.bro#L2854](https://github.com/geode-sdk/geode/blob/main/bindings/GeometryDash.bro#L2854)
--------------------------