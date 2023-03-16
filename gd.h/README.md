# gd.h
news 

--------------------------
```
in audio_nodes\FMODAudioEngine.h
bool isBackgroundMusicPlaying() {
			return reinterpret_cast<bool(__thiscall*)(FMODAudioEngine*)>(base + 0xc4fc0)(this);
		}
		bool isBackgroundMusicPlaying(const std::string& path) {
			return reinterpret_cast<bool(__thiscall*)(FMODAudioEngine*, std::string)>(base + 0x24080)(this, path);
		}
```
--------------------------