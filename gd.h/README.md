# gd.h
news 

--------------------------
in audio_nodes\FMODAudioEngine.h
```
bool isBackgroundMusicPlaying() {
	return reinterpret_cast<bool(__thiscall*)(FMODAudioEngine*)>(base + 0xc4fc0)(this);
}
bool isBackgroundMusicPlaying(const std::string& path) {
	return reinterpret_cast<bool(__thiscall*)(FMODAudioEngine*, std::string)>(base + 0x24080)(this, path);
}
```
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
--------------------------